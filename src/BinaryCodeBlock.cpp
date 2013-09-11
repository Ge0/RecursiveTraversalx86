#include "BinaryCodeBlock.hpp"
#include "AbstractBinaryBlockDisassembler.hpp"

BinaryCodeBlock::BinaryCodeBlock(const int64_t& address, size_t length)
	 : BinaryBlock(address, length)
{

}

void BinaryCodeBlock::addSymbol(long symbol) {
	m_symbols.insert(symbol);
}

void BinaryCodeBlock::getDisassembled(const AbstractBinaryBlockDisassembler& disassembler) const {
	disassembler.disassembleBinaryCodeBlock(*this);
}