#ifndef _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_
#define _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_

#include "AbstractInstructionProcessor.hpp"
#include "BinaryBlock.hpp"
#include <stdio.h>
#include <cstdint>
#include <stack>
#include <set>

namespace RecursiveTraversal {

	class BinaryRegion;

	class RecursiveTraversalInstructionProcessor : public AbstractInstructionProcessor {
	public:
		RecursiveTraversalInstructionProcessor(const BinaryRegion* const& = NULL, const int64_t& = 0);
		virtual ~RecursiveTraversalInstructionProcessor();
		
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
		
		inline const std::set<BinaryBlock*>* binaryBlocks() const {
			return m_binaryBlocks;
		}
		
		void incrementCurrentAddress(int offset);
		void setCurrentAddressToDisassemble(const int64_t&);
		void setBinaryRegion(const BinaryRegion* const& binary_region);
		void setBinaryBlocks(std::set<BinaryBlock*>* const& binary_blocks);
		int64_t popLastAddressToDisassemble();
		
		void fillBinaryBlocks();
		
	private:
	
		bool isAddressWithinBlocks(const int64_t& address) const;
	
		BinaryBlock* m_currentBinaryBlock;
		const BinaryRegion* m_binaryRegion;
		std::stack<int64_t> m_addressesToDisassemble;
		std::set<BinaryBlock*>* m_binaryBlocks;
		int64_t m_currentAddress;
	};
}

#endif /* _RECURSIVE_TRAVERSAL_PROCESSOR_INSTRUCTION_HPP_ */