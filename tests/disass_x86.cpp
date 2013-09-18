#include "disass_x86.hpp"
#include <iostream>

namespace RT = RecursiveTraversal;

RT::Instruction* my_disass_function(const RT::BinaryRegion& binaryRegion, const int64_t& address) {
	// ... Test
	INSTRUCTION inst;
	char localbuf[128] = {'\0'};
	const char* buf = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
	get_instruction(&inst, (BYTE*)buf, MODE_32);
	
	get_instruction_string(&inst, FORMAT_INTEL, 0, localbuf, 127);
	
	std::cout << localbuf << std::endl;
	
	return new RT::Instruction;
}