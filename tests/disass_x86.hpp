#ifndef _DISASSX86_HPP_
#define _DISASSX86_HPP_

#include "BinaryRegion.hpp"
#include "Instruction.hpp"


Instruction* my_disass_function(const BinaryRegion& binaryRegion, const int64_t& address);


#endif /* _DISASSX86_HPP_ */