#include "disass_x86.hpp"
#include <iostream>
#include "HijackFlowInstruction.hpp"

namespace RT = RecursiveTraversal;

void compute_referenced_address(const INSTRUCTION& inst, RT::ReferencingInstruction* instruction);

RT::Instruction* my_disass_function(const RT::BinaryRegion& binaryRegion, const int64_t& address) {
	// ... Test
	
	RT::Instruction* ret_instruction = NULL;
	INSTRUCTION inst;
	char localbuf[128] = {'\0'};

	size_t size = get_instruction(&inst, (BYTE*)binaryRegion.content() + address - binaryRegion.baseAddress(), MODE_32);
	
	switch(inst.type) {
	
	// Hijack flow instruction
	case INSTRUCTION_TYPE_JMP:
	case INSTRUCTION_TYPE_RET:
		ret_instruction = new RT::HijackFlowInstruction(size);
		//RT::ReferencingInstruction* referencing_instruction = static_cast<RT::HijackFlowInstruction*>(ret_instruction);
		compute_referenced_address(inst, static_cast<RT::HijackFlowInstruction*>(ret_instruction));
		
		//std::cout << "Referenced address: " << static_cast<RT::HijackFlowInstruction*>(ret_instruction)->referencedAddress() << std::endl;
		break;
		
	case INSTRUCTION_TYPE_JMPC: // Conditional jump
	case INSTRUCTION_TYPE_CALL:
		ret_instruction = new RT::FlowInstruction(size);
		
		compute_referenced_address(inst, static_cast<RT::HijackFlowInstruction*>(ret_instruction));
		break;
	
	// TODO: cases for ReferencingInstruction
		
	default:
		ret_instruction = new RT::Instruction(size);
	}
	
	/*
	get_instruction_string(&inst, FORMAT_INTEL, 0, localbuf, 127);
	
	std::cout << localbuf << std::endl;
	*/
	
	return ret_instruction;
}

void compute_referenced_address(const INSTRUCTION& inst, RT::ReferencingInstruction* instruction) {
	if(inst.op1.type == OPERAND_TYPE_IMMEDIATE) {
		instruction->setReferencedAddress(inst.op1.immediate);
	}
}