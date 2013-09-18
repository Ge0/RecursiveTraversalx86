#include <cstdlib>
#include <set>
#include <stack>

#include <iostream>

#include "Instruction.hpp"
#include "BinaryBlock.hpp"
#include "BinaryRegion.hpp"
#include "RecursiveTraversalInstructionProcessor.hpp"

//#include <libdasm.h>
namespace RT = RecursiveTraversal;

RT::Instruction* my_disass_function(const RT::BinaryRegion& binaryRegion, const int64_t& address);

bool is_address_within_blocks(const int64_t& address, std::set<RT::BinaryBlock*>& binaryBlocks);

bool is_address_within_binary_region(const RT::BinaryRegion& binaryRegion, const int64_t& address);

void analyze_binary_region(const RT::BinaryRegion& binaryRegion, std::set<RT::BinaryBlock*>& binaryBlocks);

int main(int argc, char** argv) {
	RT::BinaryRegion binaryRegion(
		0x00400000,	/* Base address */
		0,			/* Entry point offset */
		"\x50\x8B\xD9\xEB\x01\xDE\x83\xF2\x43",
		9
	);
	
	my_disass_function(binaryRegion, 0);
	
	return EXIT_SUCCESS;
	
}

void analyze_binary_region(const RT::BinaryRegion& binaryRegion, std::set<RT::BinaryBlock*>& binaryBlocks) {
	RT::RecursiveTraversalInstructionProcessor processor(
		&binaryRegion, binaryRegion.baseAddress() + binaryRegion.entryPointOffset());
	
	// The current_memory_address should not be into any pre-existing binary block
	if(is_address_within_blocks(processor.currentAddress(), binaryBlocks)) {
		return;
	}
	
	processor.pushAddressToDisassemble(processor.currentAddress());
	
	while(1) {
		// Empty stack? End.
		if(processor.addressesToDisassemble().empty()) {
			break;
		}
		
		// Get last address to disassemble
		processor.setCurrentAddressToDisassemble(processor.popLastAddressToDisassemble());
		
		// if our address doesn't overlays any block and is within the binary region, keep disassembling
		while(!is_address_within_blocks(processor.currentAddress(), binaryBlocks) && 
			is_address_within_binary_region(binaryRegion,processor.currentAddress()))
		{
			RT::Instruction* inst = my_disass_function(binaryRegion, processor.currentAddress());
			
			// According to the instruction type, need to do something
			
			processor.incrementCurrentAddress(inst->length());
			
			delete inst;
			
			
		
		}
	}
	
}



bool is_address_within_binary_region(const RT::BinaryRegion& binaryRegion, const int64_t& address) {
	return address >= binaryRegion.baseAddress() && address <= binaryRegion.baseAddress() + binaryRegion.contentSize();
}

bool is_address_within_blocks(const int64_t& address, std::set<RT::BinaryBlock*>& binaryBlocks) {
	std::set<RT::BinaryBlock*>::const_iterator it = binaryBlocks.begin();
	bool match = false;
	
	while(!match && it != binaryBlocks.end()) {
		if(address >= (*it)->address() && address <= (*it)->address() + (*it)->length()) {
			match = !match;
		}
		++it;
	}
}