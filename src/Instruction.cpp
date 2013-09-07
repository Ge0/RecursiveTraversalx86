#include "Instruction.hpp"

Instruction::Instruction(size_t length)
	: m_length(length)
{

}

void Instruction::setLength(size_t length) {
	m_length = length;
}