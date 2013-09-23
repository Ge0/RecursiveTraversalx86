#ifndef _HIJACK_FLOW_INSTRUCTION_HPP_
#define _HIJACK_FLOW_INSTRUCTION_HPP_

#include "FlowInstruction.hpp"

namespace RecursiveTraversal {
	class HijackFlowInstruction : public FlowInstruction {
	public:
		HijackFlowInstruction(size_t length = 0, const int64_t& referenced_address = 0);
		
		inline bool isRet() const {
			return m_ret;
		}
		
		void setIsRet(bool ret);
		
		virtual void getExecuted(AbstractInstructionProcessor&);
		
	private:
		bool m_ret; /* Ugly, shall figure this out later.. */
	};
}

#endif /* _HIJACK_FLOW_INSTRUCTION_HPP_ */