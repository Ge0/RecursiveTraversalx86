#include "HijackFlowInstruction.hpp"
#include "AbstractInstructionProcessor.hpp"

namespace RecursiveTraversal {

	HijackFlowInstruction::HijackFlowInstruction(size_t length, const int64_t& referenced_address)
		: FlowInstruction(length, referenced_address), m_ret(false)
	{

	}

	void HijackFlowInstruction::getExecuted(AbstractInstructionProcessor& instructionProcessor) {
		instructionProcessor.processHijackFlowInstruction(*this);
	}
	
	void HijackFlowInstruction::setIsRet(bool ret) {
		m_ret = ret;
	}
}