CC = g++ -std=c++0x
INCLUDE_PATH = ./include

# I r windows guy... :o)
ifeq ($(OS),Windows_NT)
	RM = @del
	CC += -DWIN32
else
	RM = @rm
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

EXE = rectrav_x86.exe


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

%.o: %.cpp
	$(CC) -c $< -I$(INCLUDE_PATH) -o $@
	
clean:
ifeq ($(OS),Windows_NT)
	$(RM) src\*.o
else
	$(RM) src/*.o
endif
	