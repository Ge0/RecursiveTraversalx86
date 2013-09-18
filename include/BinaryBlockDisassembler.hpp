#ifndef _BINARY_BLOC_DISASSEMBLER_HPP_
#define _BINARY_BLOC_DISASSEMBLER_HPP_

#include "AbstractBinaryBlockDisassembler.hpp"

namespace RecursiveTraversal {

	class BinaryBlockDisassembler : public AbstractBinaryBlockDisassembler {
	public:
		BinaryBlockDisassembler();
		virtual void disassembleBinaryCodeBlock(const BinaryCodeBlock& binaryCodeBlock) const;
		virtual void disassembleBinaryDataBlock(const BinaryDataBlock& binaryDataBlock) const;
	private:

	};
}

#endif /* _BINARY_BLOC_DISASSEMBLER_HPP_ */