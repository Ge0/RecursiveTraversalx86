#ifndef _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_
#define _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_

#include "AbstractInstructionProcessor.hpp"

class RecursiveTraversalInstructionProcessor : public AbstractInstructionProcessor {
public:
	virtual void processInstruction(const Instruction&);
	virtual void processReferencingInstruction(const ReferencingInstruction&);
	virtual void processFlowInstruction(const FlowInstruction&);
	virtual void processHijackFlowInstruction(const HijackFlowInstruction&);
};

#endif /* _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_ */