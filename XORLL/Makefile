CC := gcc
SRC := core/Src
BUILD := build

# -g = debug, -Wall = warning
FLAGS  := -I -g -Wall
TARGET := $(BUILD)/XORLL
OBJ    := $(BUILD)/*.o

RM := rm -f

all: clearsrc clean main.o XORLL.o output run

output: main.o XORLL.o
	$(CC) $(FLAGS) $(OBJ) -o $(TARGET)

main.o: $(SRC)/main.c
	$(CC) -c $< -o $(BUILD)/$@

XORLL.o: $(SRC)/XORLL.c # -c = compile only
	$(CC) -c $< -o $(BUILD)/$@

run: $(TARGET)
	./$<

clean: # -f = force
	$(RM) build/*.o $(TARGET)

clearsrc:
	clear
