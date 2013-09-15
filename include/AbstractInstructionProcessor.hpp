#ifndef _INSTRUCTION_PROCESSOR_HPP_
#define _INSTRUCTION_PROCESSOR_HPP_

class Instruction;
class ReferencingInstruction;
class FlowInstruction;
class HijackFlowInstruction;

class AbstractInstructionProcessor {
public:
	virtual void processInstruction(const Instruction&) = 0;
	virtual void processReferencingInstruction(const ReferencingInstruction&) = 0;
	virtual void processFlowInstruction(const FlowInstruction&) = 0;
	virtual void processHijackFlowInstruction(const HijackFlowInstruction&) = 0;
};

#endif /* _INSTRUCTION_PROCESSOR_HPP_ */