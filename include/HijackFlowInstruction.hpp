#ifndef _HIJACK_FLOW_INSTRUCTION_HPP_
#define _HIJACK_FLOW_INSTRUCTION_HPP_

#include "FlowInstruction.hpp"

namespace RecursiveTraversal {
	class HijackFlowInstruction : public FlowInstruction {
	public:
		HijackFlowInstruction(size_t length = 0, const int64_t& referenced_address = 0);
		
		virtual void getExecuted(AbstractInstructionProcessor&);
		
	};
}

#endif /* _HIJACK_FLOW_INSTRUCTION_HPP_ */