CC = g++ 
INCLUDE_PATH        = ./include
COMPILER_FLAGS      = -std=c++0x
RELEASE_FLAGS       = -O3s

LIBASM_INCLUDE_PATH = ./lib/libdasm/inc

# I r windows guy... :o)
ifeq ($(OS),Windows_NT)
	RM = @del
	COMPILER_FLAGS += -DWIN32
	EXE = rectrav_x86.exe
	TEST_REGSPLIT = regsplit.exe
	LIBASM_PATH   = ./lib/libdasm/bin/win32
else
	RM = @rm
	EXE = rectrav_x86
	TEST_REGSPLIT = regsplit
	LIBASM_PATH   = ./lib/libdasm/bin/linux
endif

# Main sources
SRC =	src/BinaryBlock.cpp \
		src/BinaryBlockDisassembler.cpp \
		src/BinaryCodeBlock.cpp \
		src/BinaryDataBlock.cpp \
		src/BinaryRegion.cpp \
		src/FlowInstruction.cpp \
		src/HijackFlowInstruction.cpp \
		src/Instruction.cpp \
		src/RecursiveTraversalInstructionProcessor.cpp \
		src/ReferencingInstruction.cpp
		
OBJ = $(SRC:.cpp=.o)




all: $(EXE) $(TEST_REGSPLIT)

$(EXE): target
tests: $(TEST_REGSPLIT)
	
# CodeBlocks
Debug: COMPILER_FLAGS += -Wall -ggdb
Debug: target


Release: COMPILER_FLAGS += -O3
Release: target

###################
# UNIT TEST START #
###################
$(TEST_REGSPLIT): $(OBJ) tests/region_split.o tests/disass_x86.o
	$(CC) tests/region_split.o tests/disass_x86.o $(OBJ) -o $(TEST_REGSPLIT) -L$(LIBASM_PATH) -ldasm
	
# Target
tests/region_split.o: 
	$(CC) -c tests/region_split.cpp -o tests/region_split.o -I$(INCLUDE_PATH) -I$(LIBASM_INCLUDE_PATH) $(COMPILER_FLAGS)
tests/disass_x86.o:
	$(CC) -c tests/disass_x86.cpp -o tests/disass_x86.o -I$(INCLUDE_PATH) -I$(LIBASM_INCLUDE_PATH) $(COMPILER_FLAGS)
###################
# UNIT TEST END   #
###################


###################
# MAIN START      #
###################
src/main.o:
	$(CC) -c src/main.cpp -o src/main.o -I$(INCLUDE_PATH) -I$(LIBASM_INCLUDE_PATH) $(COMPILER_FLAGS)

target: $(OBJ) src/main.o
	$(CC) $(OBJ) src/main.o -o $(EXE) -L$(LIBASM_PATH) -ldasm
	
%.o: %.cpp
	$(CC) $(COMPILER_FLAGS) -c $< -I$(INCLUDE_PATH) -I$(LIBASM_INCLUDE_PATH) -o $@
###################
# MAIN END        #
###################
	
cleanDebug: clean

clean:
ifeq ($(OS),Windows_NT)
	$(RM) src\*.o
	$(RM) tests\*.o
else
	$(RM) src/*.o
	$(RM) tests/*.o
endif
	