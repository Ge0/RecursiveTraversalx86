#ifndef _ABSTRACT_BINARY_BLOCK_DISASSEMBLER_HPP_
#define _ABSTRACT_BINARY_BLOCK_DISASSEMBLER_HPP_

namespace RecursiveTraversal {

	class BinaryCodeBlock;
	class BinaryDataBlock;

	class AbstractBinaryBlockDisassembler {
	public:
		virtual void disassembleBinaryCodeBlock(const BinaryCodeBlock& binaryCodeBlock) const = 0;
		virtual void disassembleBinaryDataBlock(const BinaryDataBlock& binaryDataBlock) const = 0;
	};
}

#endif /* _ABSTRACT_BINARY_BLOCK_DISASSEMBLER_HPP_ */