CC = g++ 
INCLUDE_PATH = ./include
COMPILER_FLAGS = -std=c++0x
RELEASE_FLAGS = -O3s

# I r windows guy... :o)
ifeq ($(OS),Windows_NT)
	RM = @del
	COMPILER_FLAGS += -DWIN32
	EXE = rectrav_x86.exe
	TEST_REGSPLIT = regsplit.exe
else
	RM = @rm
	EXE = rectrav_x86
	TEST_REGSPLIT = regsplit
endif

# Main sources
SRC =	src/BinaryBlock.cpp \
		src/BinaryBlockDisassembler.cpp \
		src/BinaryCodeBlock.cpp \
		src/BinaryDataBlock.cpp \
		src/BinaryRegion.cpp \
		src/Instruction.cpp \
		src/ReferencingInstruction.cpp \
		src/FlowInstruction.cpp \
		src/HijackFlowInstruction.cpp \
		
		
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
$(TEST_REGSPLIT): $(OBJ) tests/region_split.o
	$(CC) tests/region_split.o $(OBJ) -o $(TEST_REGSPLIT) 
	s
# Target
tests/region_split.o:
	$(CC) -c tests/region_split.cpp -o tests/region_split.o -I$(INCLUDE_PATH) $(COMPILER_FLAGS)
###################
# UNIT TEST END   #
###################


###################
# MAIN START      #
###################
src/main.o:
	$(CC) -c src/main.cpp -o src/main.o -I$(INCLUDE_PATH) $(COMPILER_FLAGS)

target: $(OBJ) src/main.o
	$(CC) $(OBJ) src/main.o -o $(EXE)
	
%.o: %.cpp
	$(CC) $(COMPILER_FLAGS) -c $< -I$(INCLUDE_PATH) -o $@
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
	