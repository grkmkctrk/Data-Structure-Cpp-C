CPP := g++
SRC := core/Src
BUILD := build

# -g = debug, -Wall = warning
FLAGS  := -I -g -Wall -std=c++2a
TARGET := $(BUILD)/Graph
OBJ    := $(BUILD)/*.o

RM := rm -f

all: clearsrc clean main.o output run

output: main.o
	$(CPP) $(FLAGS) $(OBJ) -o $(TARGET)

main.o: $(SRC)/main.cpp
	$(CPP) -c $< -o $(BUILD)/$@

run: $(TARGET)
	./$<

clean: # -f = force
	$(RM) build/*.o $(TARGET)

clearsrc:
	clear
