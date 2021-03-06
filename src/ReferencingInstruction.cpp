#include "ReferencingInstruction.hpp"
#include "AbstractInstructionProcessor.hpp"

namespace RecursiveTraversal {

	ReferencingInstruction::ReferencingInstruction(size_t length, const int64_t& referenced_address)
		: Instruction(length), m_referencedAddress(referenced_address)
	{

	}

	void ReferencingInstruction::setReferencedAddress(const int64_t& referenced_address) {
		m_referencedAddress = referenced_address;
	}

	void ReferencingInstruction::getExecuted(AbstractInstructionProcessor& instructionProcessor) {
		instructionProcessor.processReferencingInstruction(*this);
	}
}