#ifndef _REFERENCING_INSTRUCTION_HPP_
#define _REFERENCING_INSTRUCTION_HPP_

#include <stdint.h>
#include "Instruction.hpp"

namespace RecursiveTraversal {

	class ReferencingInstruction : public Instruction {
	public:
		ReferencingInstruction(size_t length = 0, const int64_t& referenced_address = 0);
		
		inline const int64_t& referencedAddress() const {
			return m_referencedAddress;
		}
		
		void setReferencedAddress(const int64_t& referenced_address);
		
		virtual void getExecuted(AbstractInstructionProcessor&);
		
	protected:
		int64_t m_referencedAddress;
	};
}

#endif /* _REFERENCING_INSTRUCTION_HPP_ */