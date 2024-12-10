ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=c11 -I./ftl -D COMPILER_PLATFORM="\"$(shell uname -o) $(shell uname -r)\""
LDFLAGS := 
SRC := $(wildcard ftl/*.c) $(wildcard ftl/options/*.c)
OBJ := $(SRC:.c=.o)
BIN_DIR := bin
EXEC := $(BIN_DIR)/ftl
MAN_DIR := $(PREFIX)/share/man
MAN_SRC := man/ftl.1
MAN_DEST := $(MAN_DIR)/man1/ftl.1

.PHONY: all clean install uninstall

all: $(EXEC)

$(EXEC): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) $(LDFLAGS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

cftl/%.o: cftl/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(EXEC)

install: $(EXEC)
	install -d $(PREFIX)/bin
	install $(EXEC) $(PREFIX)/bin/
	install -d $(MAN_DIR)/man1
	install -m 644 $(MAN_SRC) $(MAN_DEST)

uninstall:
	$(RM) $(PREFIX)/bin/ftl
	$(RM_ $(MAN_DEST)
