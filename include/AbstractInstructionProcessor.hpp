#ifndef _INSTRUCTION_PROCESSOR_HPP_
#define _INSTRUCTION_PROCESSOR_HPP_

namespace RecursiveTraversal {
<<<<<<< HEAD

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
}
=======

	class Instruction;
	class ReferencingInstruction;
	class FlowInstruction;
	class HijackFlowInstruction;

	class AbstractInstructionProcessor {
	public:
		virtual ~AbstractInstructionProcessor() { };
		virtual void processInstruction(const Instruction&) = 0;
		virtual void processReferencingInstruction(const ReferencingInstruction&) = 0;
		virtual void processFlowInstruction(const FlowInstruction&) = 0;
		virtual void processHijackFlowInstruction(const HijackFlowInstruction&) = 0;
	};

}


>>>>>>> origin/Ge0

#endif /* _INSTRUCTION_PROCESSOR_HPP_ */