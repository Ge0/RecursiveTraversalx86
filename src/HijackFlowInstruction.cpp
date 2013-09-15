#include "HijackFlowInstruction.hpp"
#include "AbstractInstructionProcessor.hpp"

HijackFlowInstruction::HijackFlowInstruction(size_t length, const int64_t& referenced_address)
	: FlowInstruction(length, referenced_address)
{

}

void HijackFlowInstruction::getExecuted(AbstractInstructionProcessor& instructionProcessor) {
	instructionProcessor.processHijackFlowInstruction(*this);
}