#ifndef _BINARY_CODE_BLOCK_HPP_
#define _BINARY_CODE_BLOCK_HPP_

#include <cstdio>
#include <set>
#include "BinaryBlock.hpp"

class BinaryCodeBlock : public BinaryBlock {
public:
	BinaryCodeBlock(const int64_t& address = 0, size_t length = 0);

	inline const std::set<long> symbols() const {
		return m_symbols;
	}
	
	void addSymbol(long symbol);
	
	virtual void getDisassembled(const AbstractBinaryBlockDisassembler&) const;
	
private:
	std::set<long> m_symbols;
};

#endif /* _BINARY_CODE_BLOCK_HPP_ */