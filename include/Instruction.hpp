#ifndef _INSTRUCTION_HPP_
#define _INSTRUCTION_HPP_

#include <cstdio>

namespace RecursiveTraversal {

	class AbstractInstructionProcessor;

	class Instruction {
	public:
		Instruction(size_t length = 0);
		
		inline size_t length() const {
			return m_length;
		}
		
		void setLength(size_t length);
		
		virtual void getExecuted(AbstractInstructionProcessor&);
		
	protected:
		size_t m_length;

	};
}

#endif /* _INSTRUCTION_HPP_ */