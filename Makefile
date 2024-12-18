ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

CC := $(shell ./configure -from-make)
CFLAGS := -Wall -Wextra -Werror -O2 -pedantic -std=c11 -I./ftl -D COMPILER_PLATFORM="\"$(shell uname -o) $(shell uname -r)\"" -ggdb
GOC := go build 
GOFLAGS := -buildmmode=c-shared
LDFLAGS :=
SRC := $(wildcard ftl/*.c) $(wildcard ftl/options/*.c)
BIN_DIR := build
OBJ_DIR := $(BIN_DIR)/obj
OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
EXEC := $(BIN_DIR)/bin/ftl
MAN_DIR := $(PREFIX)/share/man
MAN_SRC := man/ftl.1
MAN_DEST := $(MAN_DIR)/man1/ftl.1

.PHONY: all clean install uninstall

all: $(EXEC)

$(EXEC): $(OBJ) | $(BIN_DIR)/bin
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

$(BIN_DIR)/bin $(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BIN_DIR)

install: $(EXEC)
	install -d $(PREFIX)/bin
	install $(EXEC) $(PREFIX)/bin/
	install -d $(MAN_DIR)/man1
	install -m 644 $(MAN_SRC) $(MAN_DEST)

uninstall:
	$(RM) $(PREFIX)/bin/ftl
	$(RM) $(MAN_DEST)
