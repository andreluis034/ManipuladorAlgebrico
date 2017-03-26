CC = gcc
C_FILES = $(wildcard src/*.c)
OBJ_DIR = obj
OBJ_FILES = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(C_FILES))
CC_FLAGS =  -Wall
BINARY = algebra.out


$(BINARY): $(OBJ_FILES) 
	$(CC) -o $@ $^

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -c -o $@ $<

all: clean $(BINARY)

clean:
	rm -rf $(BINARY) $(OBJ_DIR)