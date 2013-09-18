#ifndef _DISASSX86_HPP_
#define _DISASSX86_HPP_

#include "BinaryRegion.hpp"
#include "Instruction.hpp"
#include <libdasm.h>

namespace RT = RecursiveTraversal;

RT::Instruction* my_disass_function(const RT::BinaryRegion& binaryRegion, const int64_t& address);


#endif /* _DISASSX86_HPP_ */