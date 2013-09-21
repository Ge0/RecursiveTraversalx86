#include "BinaryBlock.hpp"
#include <iostream>

namespace RecursiveTraversal {

	BinaryBlock::BinaryBlock(const int64_t& address, size_t length)
		: m_address(address), m_length(length)
	{

	}

	BinaryBlock::BinaryBlock(const BinaryBlock& binaryBlock) 
		: m_address(binaryBlock.m_address), m_length(binaryBlock.m_length) {
		
	}

	bool BinaryBlock::operator==(const BinaryBlock& binaryBlock) const {
		return m_address == binaryBlock.m_address && m_length == binaryBlock.m_length;
	}
<<<<<<< HEAD
=======
	
	bool BinaryBlock::operator<(const BinaryBlock& binaryBlock) const {
		return m_address < binaryBlock.m_address;
	}
>>>>>>> origin/Ge0

	void BinaryBlock::setAddress(const int64_t& address) {
		m_address = address;
	}

	void BinaryBlock::setLength(size_t length) {
		m_length = length;
	}
	
<<<<<<< HEAD
=======
	void BinaryBlock::incrementLength(size_t offset) {
		m_length += offset;
	}
	
>>>>>>> origin/Ge0
}