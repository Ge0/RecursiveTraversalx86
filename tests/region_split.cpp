#include <cstdlib>
#include <set>
#include <stack>
#include <libdasm.h>
#include <iostream>

#include "BinaryBlock.hpp"
#include "BinaryRegion.hpp"

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
	
}