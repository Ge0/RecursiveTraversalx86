#include "RecursiveTraversalInstructionProcessor.hpp"
#include "HijackFlowInstruction.hpp"

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