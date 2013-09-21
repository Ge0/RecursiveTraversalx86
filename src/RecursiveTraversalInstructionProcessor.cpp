#include "RecursiveTraversalInstructionProcessor.hpp"

<<<<<<< HEAD
namespace RecursiveTraversal {

	RecursiveTraversalInstructionProcessor::RecursiveTraversalInstructionProcessor
		(const BinaryRegion* const& binary_region, const int64_t& current_address)
		: m_binaryRegion(binary_region), m_currentAddress(current_address)
	{

	}
		

	void RecursiveTraversalInstructionProcessor::processInstruction(const Instruction& instruction) {

	}

	void RecursiveTraversalInstructionProcessor::processReferencingInstruction(const ReferencingInstruction& instruction) {

	}

	void RecursiveTraversalInstructionProcessor::processFlowInstruction(const FlowInstruction& instruction) {

	}

	void RecursiveTraversalInstructionProcessor::processHijackFlowInstruction(const HijackFlowInstruction& instruction) {

	}

	void RecursiveTraversalInstructionProcessor::pushAddressToDisassemble(const int64_t& address) {
		m_addressesToDisassemble.push(address);
	}

	void RecursiveTraversalInstructionProcessor::setBinaryRegion(const BinaryRegion* const& binaryRegion) {
		m_binaryRegion = binaryRegion;
	}

	void RecursiveTraversalInstructionProcessor::incrementCurrentAddress(int offset) {
		m_currentAddress += offset;
	}

	int64_t RecursiveTraversalInstructionProcessor::popLastAddressToDisassemble() {
		int64_t address(std::forward<int64_t>(m_addressesToDisassemble.top()));
		m_addressesToDisassemble.pop();
		
		return address;
	}

	void RecursiveTraversalInstructionProcessor::setCurrentAddressToDisassemble(const int64_t& address) {
		m_currentAddress = address;
	}
=======
#include "BinaryCodeBlock.hpp"
#include "BinaryDataBlock.hpp"
#include "BinaryRegion.hpp"
#include "HijackFlowInstruction.hpp"

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
			std::cout << "Insert a new block." << std::endl;
			m_binaryBlocks->insert(m_currentBinaryBlock);
			m_currentBinaryBlock = new BinaryCodeBlock(instruction.referencedAddress(), 0);
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
	
	void RecursiveTraversalInstructionProcessor::fillBinaryBlocks() {
		// Insert the current block into the set
		m_binaryBlocks->insert(m_currentBinaryBlock);
		
		std::cout << "There are " << m_binaryBlocks->size() << " blocks." << std::endl;
		
		if(m_binaryBlocks->size() > 1) {
			
			// fill the set with binary data blocks
			std::set<BinaryBlock*>::const_iterator it_prev = m_binaryBlocks->begin(), it = it_prev;
			++it;
			
			while(it != m_binaryBlocks->end()) {
				std::cout << "prev block: " << (*it_prev)->address() << std::endl;
				std::cout << "current: " << (*it)->address() << std::endl;
			
				// not contiguous?
				if(((*it_prev)->address() + (*it_prev)->length()) != (*it)->address()) {
					// Create a new binary data block that fits in
					BinaryDataBlock* data_block = new BinaryDataBlock(
						(*it_prev)->address() + (*it)->length(), // computed address
						(*it)->address() - ((*it_prev)->address() + (*it_prev)->length()) // computed length
					);
					std::cout << "Before: " << (*it_prev)->address() << std::endl;
					// Insert the block into the set
					it_prev = m_binaryBlocks->insert(it_prev,data_block);
					std::cout << "After: " << (*it_prev)->address() << std::endl;
					// update the prev_it iterator so it points right to the new block
					// ++it_prev;
					++it;
				}
			
				++it_prev;
				++it;
			}
		}
	}
>>>>>>> origin/Ge0
}