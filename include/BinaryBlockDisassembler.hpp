#ifndef _BINARY_BLOC_DISASSEMBLER_HPP_
#define _BINARY_BLOC_DISASSEMBLER_HPP_

class BinaryCodeBlock;
class BinaryDataBlock;

class BinaryBlockDisassembler {
public:
	void disassembleBinaryCodeBlock(const BinaryCodeBlock& binaryCodeBlock);
	void disassembleBinaryDataBlock(const BinaryDataBlock& binaryDataBlock);
private:

};

#endif /* _BINARY_BLOC_DISASSEMBLER_HPP_ */