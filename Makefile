CC = g++ 
INCLUDE_PATH = ./include
COMPILER_FLAGS = -std=c++0x
RELEASE_FLAGS = -O3s
# I r windows guy... :o)
ifeq ($(OS),Windows_NT)
	RM = @del
	CC += -DWIN32
	EXE = rectrav_x86.exe
else
	RM = @rm
	EXE = rectrav_x86
endif

SRC = 	src/BinaryBlock.cpp \
		src/BinaryCodeBlock.cpp \
		src/BinaryDataBlock.cpp \
		src/Instruction.cpp \
		src/ReferencingInstruction.cpp \
		src/FlowInstruction.cpp \
		src/HijackFlowInstruction.cpp \
		src/main.cpp

OBJ = $(SRC:.cpp=.o)




all: $(EXE)

$(EXE): target
	
# CodeBlocks
Debug: COMPILER_FLAGS += -Wall -ggdb
Debug: target


Release: COMPILER_FLAGS += -O3
Release: target
	
target: $(OBJ)
	$(CC) $(OBJ) -o $(EXE)
	
%.o: %.cpp
	$(CC) $(COMPILER_FLAGS) -c $< -I$(INCLUDE_PATH) -o $@
	
cleanDebug: clean

clean:
ifeq ($(OS),Windows_NT)
	$(RM) src\*.o
else
	$(RM) src/*.o
endif
	