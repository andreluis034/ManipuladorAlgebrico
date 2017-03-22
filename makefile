CC = gcc
C_FILES = $(wildcard src/*.c)
CC_FLAGS =  -Wall
BINARY = bin/algebra.out

all: 
	$(CC) $(C_FILES) $(CC_FLAGS) -o $(BINARY)