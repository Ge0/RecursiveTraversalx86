#include "BinaryCodeBlock.hpp"

BinaryCodeBlock::BinaryCodeBlock(const int64_t& address, size_t length)
	 : BinaryBlock(address, length)
{

}

void BinaryCodeBlock::addSymbol(long symbol) {
	m_symbols.insert(symbol);
}

void BinaryCodeBlock::getDisassembled(const BinaryBlockDisassembler& disassembler) {

}