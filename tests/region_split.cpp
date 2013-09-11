#include <cstdlib>
#include <set>
#include "BinaryRegion.hpp"

int main(int argc, char** argv) {
	BinaryRegion binaryRegion(
		0x00400000,	/* Base address */
		0,			/* Entry point offset */
		"\x50\x8B\xD9\xEB\x01\xDE\x83\xF2\x43",
		9
	);
	
	return EXIT_SUCCESS;
	
}