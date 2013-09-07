#ifndef _HIJACK_FLOW_INSTRUCTION_HPP_
#define _HIJACK_FLOW_INSTRUCTION_HPP_

#include "FlowInstruction.hpp"

class HijackFlowInstruction : public FlowInstruction {
public:
	HijackFlowInstruction(size_t length = 0, const int64_t& referenced_address = 0);
	
};

#endif /* _HIJACK_FLOW_INSTRUCTION_HPP_ */