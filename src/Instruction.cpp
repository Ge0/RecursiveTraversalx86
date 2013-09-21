#include "Instruction.hpp"
#include "AbstractInstructionProcessor.hpp"

namespace RecursiveTraversal {

	Instruction::Instruction(size_t length)
		: m_length(length)
	{

	}

	void Instruction::setLength(size_t length) {
		m_length = length;
	}

	void Instruction::getExecuted(AbstractInstructionProcessor& instructionProcessor) {
		instructionProcessor.processInstruction(*this);
	}

}