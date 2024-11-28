CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=c11 -I./cftl
LDFLAGS := 
SRC := $(wildcard cftl/*.c) $(wildcard cftl/options/*.c)
OBJ := $(SRC:.c=.o)
BIN_DIR := bin
EXEC := $(BIN_DIR)/ftl

.PHONY: all clean run ftl-check

all: $(EXEC)

$(EXEC): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) $(LDFLAGS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

cftl/%.o: cftl/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(EXEC)

run: all
	./$(EXEC)
