#include <cstdlib>
#include <set>
#include <stack>

#include <iostream>

#include "Instruction.hpp"
#include "BinaryBlock.hpp"
#include "BinaryRegion.hpp"

//#include <libdasm.h>

Instruction* my_disass_function(const BinaryRegion& binaryRegion, const int64_t& address);

bool is_address_within_blocks(const int64_t& address, std::set<BinaryBlock*>& binaryBlocks);

bool is_address_within_binary_region(const BinaryRegion& binaryRegion, const int64_t& address);

void analyze_binary_region(const BinaryRegion& binaryRegion, std::set<BinaryBlock*>& binaryBlocks);

int main(int argc, char** argv) {
	BinaryRegion binaryRegion(
		0x00400000,	/* Base address */
		0,			/* Entry point offset */
		"\x50\x8B\xD9\xEB\x01\xDE\x83\xF2\x43",
		9
	);
	
	return EXIT_SUCCESS;
	
}

void analyze_binary_region(const BinaryRegion& binaryRegion, std::set<BinaryBlock*>& binaryBlocks) {
	int64_t current_memory_address = binaryRegion.baseAddress() + binaryRegion.entryPointOffset();
	
	// The current_memory_address should not be into any pre-existing binary block
	if(is_address_within_blocks(current_memory_address, binaryBlocks)) {
		return;
	}
	
	std::stack<int64_t> stack_disass_addresses;
	stack_disass_addresses.push(current_memory_address);
	
	while(1) {
		// Empty stack? End.
		if(stack_disass_addresses.empty()) {
			break;
		}
		
		// if our address doesn't overlays any block and is within the binary region, keep disassembling
		while(!is_address_within_blocks(current_memory_address, binaryBlocks) && 
			is_address_within_binary_region(binaryRegion,current_memory_address))
		{
			Instruction* inst = my_disass_function(binaryRegion, current_memory_address);
			
			// According to the instruction type, need to do something
			
			current_memory_address += inst->length();
			
			delete inst;
			
			
		
		}
	}
	
}

Instruction* my_disass_function(const BinaryRegion& binaryRegion, const int64_t& address) {
	// ...
	return new Instruction;
}

bool is_address_within_binary_region(const BinaryRegion& binaryRegion, const int64_t& address) {
	return address >= binaryRegion.baseAddress() && address <= binaryRegion.baseAddress() + binaryRegion.contentSize();
}

bool is_address_within_blocks(const int64_t& address, std::set<BinaryBlock*>& binaryBlocks) {
	std::set<BinaryBlock*>::const_iterator it = binaryBlocks.begin();
	bool match = false;
	
	while(!match && it != binaryBlocks.end()) {
		if(address >= (*it)->address() && address <= (*it)->address() + (*it)->length()) {
			match = !match;
		}
		++it;
	}
}