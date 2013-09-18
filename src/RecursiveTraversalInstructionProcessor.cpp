#include "RecursiveTraversalInstructionProcessor.hpp"
#include "HijackFlowInstruction.hpp"
#include "BinaryCodeBlock.hpp"
#include "BinaryRegion.hpp"

#include <iostream>

namespace RecursiveTraversal {


	RecursiveTraversalInstructionProcessor::RecursiveTraversalInstructionProcessor
		(const BinaryRegion* const& binary_region, const int64_t& current_address)
		: m_currentBinaryBlock(NULL), m_binaryRegion(binary_region), m_currentAddress(current_address)
	{
		// Should start with a binary code block
		m_currentBinaryBlock = new BinaryCodeBlock(m_currentAddress);
	}
	
	RecursiveTraversalInstructionProcessor::~RecursiveTraversalInstructionProcessor() {
		/*
		if(m_currentBinaryBlock != NULL) {
			delete m_currentBinaryBlock;
		}
		*/
	}
		

	void RecursiveTraversalInstructionProcessor::processInstruction(const Instruction& instruction) {
		m_currentBinaryBlock->incrementLength(instruction.length());
		m_currentAddress += instruction.length();
	}

	void RecursiveTraversalInstructionProcessor::processReferencingInstruction(const ReferencingInstruction& instruction) {
		m_currentBinaryBlock->incrementLength(instruction.length());
		m_currentAddress += instruction.length();
	}

	void RecursiveTraversalInstructionProcessor::processFlowInstruction(const FlowInstruction& instruction) {
		m_currentBinaryBlock->incrementLength(instruction.length());
		
		// if the destination address hasn't been analysed yet, record it for further analysis
		if(!isAddressWithinBlocks(instruction.referencedAddress())) {
			pushAddressToDisassemble(instruction.referencedAddress());
		}
		
		m_currentAddress += instruction.length();
	}

	void RecursiveTraversalInstructionProcessor::processHijackFlowInstruction(const HijackFlowInstruction& instruction) {
		m_currentBinaryBlock->incrementLength(instruction.length());
		
		// if the destination address hasn't been analysed yet, start a new block
		std::cout << "Referenced Address:" << instruction.referencedAddress() << std::endl;
		if(!isAddressWithinBlocks(instruction.referencedAddress())) {
			m_binaryBlocks->insert(m_currentBinaryBlock);
			m_currentBinaryBlock = new BinaryCodeBlock(instruction.referencedAddress());
			setCurrentAddressToDisassemble(instruction.referencedAddress());
		}
	}
	
	bool RecursiveTraversalInstructionProcessor::isAddressWithinBlocks(const int64_t& address) const {
		bool match = false;
		if(m_binaryRegion->hasAddress(address)) {
			std::set<BinaryBlock*>::const_iterator it = m_binaryBlocks->begin();
			
			
			while(!match && it != m_binaryBlocks->end()) {
				if(address >= (*it)->address() && address <= (*it)->address() + (*it)->length()) {
					match = !match;
				}
				++it;
			}
		}
		
		return match;
	}

	void RecursiveTraversalInstructionProcessor::pushAddressToDisassemble(const int64_t& address) {
		m_addressesToDisassemble.push(address);
	}

	void RecursiveTraversalInstructionProcessor::setBinaryRegion(const BinaryRegion* const& binary_region) {
		m_binaryRegion = binary_region;
	}

	void RecursiveTraversalInstructionProcessor::incrementCurrentAddress(int offset) {
		m_currentAddress += offset;
	}
	
	void RecursiveTraversalInstructionProcessor::setBinaryBlocks(std::set<BinaryBlock*>* const& binary_blocks) {
		m_binaryBlocks = binary_blocks;
	}

	int64_t RecursiveTraversalInstructionProcessor::popLastAddressToDisassemble() {
		int64_t address(std::forward<int64_t>(m_addressesToDisassemble.top()));
		m_addressesToDisassemble.pop();
		
		return address;
	}

	void RecursiveTraversalInstructionProcessor::setCurrentAddressToDisassemble(const int64_t& address) {
		m_currentAddress = address;
	}
}