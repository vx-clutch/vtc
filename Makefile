ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

CC := $(shell ./configure -from-make)
CFLAGS := -Wall -Wextra -O2 -pedantic -std=c11 -I./ftl -D COMPILER_PLATFORM="\"$(shell uname -o) $(shell uname -r)\""
LDFLAGS :=
SRC := $(wildcard ftl/*.c) $(wildcard ftl/options/*.c)
BIN_DIR := build
OBJ_DIR := $(BIN_DIR)/obj
OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
EXEC := $(BIN_DIR)/bin/ftl
MAN_DIR := $(PREFIX)/share/man
MAN_SRC := man/ftl.1
MAN_DEST := $(MAN_DIR)/man1/ftl.1
GC := go build
GOFLAGS := -buildmode=c-shared
GOSRC := libgo/go/main.go
LIBGO_DIR := libgo
LIBGO_SO := $(OBJ_DIR)/libgo/libgo.so

.PHONY: all clean install uninstall

all: $(EXEC) $(LIBGO_SO)

$(EXEC): $(OBJ) | $(BIN_DIR)/bin
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

debug: $(OBJ) | $(BIN_DIR)/bin
	$(CC) $(CFLAGS) -ggdb $(OBJ) -o $@ $(LDFLAGS)

$(LIBGO_SO): $(GOSRC) | $(LIBGO_DIR) $(BIN_DIR)/obj/libgo
	cd $(LIBGO_DIR) && $(GC) $(GOFLAGS) -o ../$(LIBGO_SO) go/main.go

$(BIN_DIR)/bin $(OBJ_DIR) $(BIN_DIR)/obj/libgo:
	mkdir -p $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BIN_DIR)

install: $(EXEC) $(LIBGO_SO)
	install -d $(PREFIX)/bin
	install $(EXEC) $(PREFIX)/bin/
	install -d $(MAN_DIR)/man1
	install -m 644 $(MAN_SRC) $(MAN_DEST)

uninstall:
	$(RM) $(PREFIX)/bin/ftl
	$(RM) $(MAN_DEST)
run:
	export LD_LIBRARY_PATH=.
	./build/bin/ftl
