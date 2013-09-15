#include "FlowInstruction.hpp"
#include "AbstractInstructionProcessor.hpp"

FlowInstruction::FlowInstruction(size_t length, const int64_t& referenced_address)
	: ReferencingInstruction(length, referenced_address)
{

}

void FlowInstruction::getExecuted(AbstractInstructionProcessor& instructionProcessor) {
	instructionProcessor.processFlowInstruction(*this);
}