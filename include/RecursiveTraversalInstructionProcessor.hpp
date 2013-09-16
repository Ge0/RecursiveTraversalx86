#ifndef _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_
#define _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_

#include "AbstractInstructionProcessor.hpp"
#include <stdio.h>
#include <cstdint>
#include <stack>

class BinaryRegion;

class RecursiveTraversalInstructionProcessor : public AbstractInstructionProcessor {
public:
	RecursiveTraversalInstructionProcessor(const BinaryRegion* const& = NULL, const int64_t& = 0);
	
	virtual void processInstruction(const Instruction&);
	virtual void processReferencingInstruction(const ReferencingInstruction&);
	virtual void processFlowInstruction(const FlowInstruction&);
	virtual void processHijackFlowInstruction(const HijackFlowInstruction&);
	
	void pushAddressToDisassemble(const int64_t& address);
	
	inline const BinaryRegion* const& binaryRegion() const {
		return m_binaryRegion;
	}
	
	inline const int64_t& currentAddress() const {
		return m_currentAddress;
	}
	
	inline const std::stack<int64_t>& addressesToDisassemble() const {
		return m_addressesToDisassemble;
	}
	
	void incrementCurrentAddress(int offset);
	void setCurrentAddressToDisassemble(const int64_t&);
	void setBinaryRegion(const BinaryRegion* const& binaryRegion);
	int64_t popLastAddressToDisassemble();
private:
	const BinaryRegion* m_binaryRegion;
	std::stack<int64_t> m_addressesToDisassemble;
	int64_t m_currentAddress;
};

#endif /* _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_ */