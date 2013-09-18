#include "BinaryDataBlock.hpp"
#include "AbstractBinaryBlockDisassembler.hpp"

namespace RecursiveTraversal {

	BinaryDataBlock::BinaryDataBlock(const int64_t& address, size_t length)
		 : BinaryBlock(address, length)
	{

	}

	void BinaryDataBlock::getDisassembled(const AbstractBinaryBlockDisassembler& disassembler) const {
		disassembler.disassembleBinaryDataBlock(*this);
	}
	
}