#ifndef _FLOW_INSTRUCTION_HPP_
#define _FLOW_INSTRUCTION_HPP_

#include "ReferencingInstruction.hpp"

class FlowInstruction : public ReferencingInstruction {
public:
	FlowInstruction(size_t length = 0, const int64_t& referenced_address = 0);

};

#endif /* _FLOW_INSTRUCTION_HPP_ */