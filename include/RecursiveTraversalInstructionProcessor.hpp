#ifndef _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_
#define _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_

#include "AbstractInstructionProcessor.hpp"
#include <stack>

class RecursiveTraversalInstructionProcessor : public AbstractInstructionProcessor {
public:
	virtual void processInstruction(const Instruction&);
	virtual void processReferencingInstruction(const ReferencingInstruction&);
	virtual void processFlowInstruction(const FlowInstruction&);
	virtual void processHijackFlowInstruction(const HijackFlowInstruction&);
	
private:
	std::stack<int64_t> m_addressesToDisassemble;
};

#endif /* _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_ */