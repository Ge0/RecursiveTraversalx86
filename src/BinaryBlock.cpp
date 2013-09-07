#include "BinaryBlock.hpp"

BinaryBlock::BinaryBlock(const int64_t& address, size_t length)
	: m_address(address), m_length(length)
{

}

void BinaryBlock::setAddress(const int64_t& address) {
	m_address = address;
}

void BinaryBlock::setLength(size_t length) {
	m_length = length;
}