CPP := g++
SRC := core/Src
BUILD := build

# -g = debug, -Wall = warning
FLAGS  := -I -g -Wall -std=c++2a
TARGET := $(BUILD)/binaryTree
OBJ    := $(BUILD)/*.o

RM := rm -f

all: clearsrc clean main.o binaryTree.o output run

output: main.o binaryTree.o
	$(CPP) $(FLAGS) $(OBJ) -o $(TARGET)

main.o: $(SRC)/main.cpp
	$(CPP) -c $< -o $(BUILD)/$@

binaryTree.o: $(SRC)/binaryTree.cpp # -c = compile only
	$(CPP) -c $< -o $(BUILD)/$@

run: $(TARGET)
	./$<

clean: # -f = force
	$(RM) build/*.o $(TARGET)

clearsrc:
	clear
