#include "BinaryDataBlock.hpp"
#include "BinaryBlockDisassembler.hpp"

BinaryDataBlock::BinaryDataBlock(const int64_t& address, size_t length)
	 : BinaryBlock(address, length)
{

}

void BinaryDataBlock::getDisassembled(const BinaryBlockDisassembler& disassembler) const {
	disassembler.disassembleBinaryDataBlock(*this);
}