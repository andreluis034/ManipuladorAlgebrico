CC = gcc
C_FILES = $(wildcard src/*.c)
OBJ_FILES = $(patsubst src/%.c,obj/%.o,$(C_FILES))
CC_FLAGS =  -Wall
BINARY = algebra.out


$(BINARY): $(OBJ_FILES)
	$(CC) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CC_FLAGS) -c -o $@ $<

all: clean $(BINARY)

clean:
	rm -f $(BINARY) $(OBJ_FILES)

