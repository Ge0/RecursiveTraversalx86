#ifndef _BINARY_BLOC_DISASSEMBLER_HPP_
#define _BINARY_BLOC_DISASSEMBLER_HPP_

class BinaryCodeBlock;
class BinaryDataBlock;

class BinaryBlockDisassembler {
public:
	BinaryBlockDisassembler();
	void disassembleBinaryCodeBlock(const BinaryCodeBlock& binaryCodeBlock) const;
	void disassembleBinaryDataBlock(const BinaryDataBlock& binaryDataBlock) const;
private:

};

#endif /* _BINARY_BLOC_DISASSEMBLER_HPP_ */