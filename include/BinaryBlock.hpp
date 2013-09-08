#ifndef _BINARYBLOCK_HPP_
#define _BINARYBLOCK_HPP_

#include <cstdio>
#include <cstdint>

class BinaryBlockDisassembler;

class BinaryBlock {
public:
	BinaryBlock(const int64_t& address = 0, size_t length = 0);
	BinaryBlock(const BinaryBlock&); // Copy constructor
	
	bool operator==(const BinaryBlock&) const;
	
	inline const int64_t& address() const {
		return m_address;
	}
	
	inline size_t length() const {
		return m_length;
	}
	
	virtual void getDisassembled(const BinaryBlockDisassembler&) = 0;
	
	void setAddress(const int64_t& address);
	void setLength(size_t length);
	
protected:
	int64_t m_address;
	size_t m_length;
};

#endif /* _BINARYBLOCK_HPP_ */
