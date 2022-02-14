CC := gcc
SRC := core/Src
BUILD := build

# -g = debug, -Wall = warning
FLAGS  := -I -g -Wall -std=c++2a
TARGET := $(BUILD)/unrolledLL
OBJ    := $(BUILD)/*.o

RM := rm -f

all: clearsrc clean main.o node.o output run

output: main.o node.o
	$(CC) $(FLAGS) $(OBJ) -o $(TARGET)

# start c file #
# -c = compile only
main.o: $(SRC)/main.c
	$(CC) -c $< -o $(BUILD)/$@ 

node.o: $(SRC)/node.c
	$(CC) -c $< -o $(BUILD)/$@
# end c file #

run: $(TARGET)
	./$<

# -f = force
clean: 
	$(RM) build/*.o $(TARGET)

clearsrc:
	clear
