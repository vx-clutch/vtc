# Copyright (C) 2024 vx-clutch ( owestness@gmail.com )
# See end of file for extended copyright information.

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

CC := gcc
CFLAGS := -Wall -Wextra -O2 -pedantic -static -std=c11 -Ivtc/syslog -Ivtc -D COMPILER_PLATFORM="\"$(shell uname -o) $(shell uname -r)\""
LDFLAGS :=
SRC := $(wildcard vtc/*.c) $(wildcard vtc/syslog/*.c)
BIN_DIR := build
OBJ_DIR := $(BIN_DIR)/obj
OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
EXEC := $(BIN_DIR)/bin/vtc
MAN_DIR := $(PREFIX)/share/man
MAN_SRC := man/vtc.1
MAN_DEST := $(MAN_DIR)/man1/vtc.1
GC := go build
GOFLAGS := -buildmode=c-archive
GOSRC := libgo/go/main.go
LIBGO_DIR := libgo
LIBGO_A := $(OBJ_DIR)/libgo/libgo.a

.PHONY: all clean install uninstall

all: $(EXEC)

$(EXEC): $(OBJ) $(LIBGO_A) | $(BIN_DIR)/bin
	@echo -n "  CALL  "
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

$(LIBGO_A): $(GOSRC) | $(LIBGO_DIR) $(BIN_DIR)/obj/libgo
	@echo -n "  CALL  "
	cd $(LIBGO_DIR) && $(GC) $(GOFLAGS) -o ../$(LIBGO_A) go/main.go

$(OBJ_DIR)/%.o: %.c $(LIBGO_A) | $(OBJ_DIR)
	@echo -n "  CALL  "
	mkdir -p $(dir $@)
	@echo -n "  CALL  "
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/bin $(OBJ_DIR) $(BIN_DIR)/obj/libgo:
	@echo -n "  CALL  "
	mkdir -p $@

clean:
	@echo -n "  CALL  "
	$(RM) -r $(BIN_DIR)

install: $(EXEC) $(LIBGO_A)
	install -d $(PREFIX)/bin
	install $(EXEC) $(PREFIX)/bin/
	install -d $(MAN_DIR)/man1
	install -m 644 $(MAN_SRC) $(MAN_DEST)

uninstall:
	$(RM) $(PREFIX)/bin/vtc
	$(RM) $(MAN_DEST)

# vtc is a simple and extensible compiler.
# Copyright (C) 2024 vx-clutch
#
# The file is part of vtc.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 1. Redistributions of source code must retain the above copyright notice,
# this list of conditions, and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions, and the following disclaimer in the documentation or
# other materials provided with the distribution.
# 3. Neither the name of vx-clutch nor the names of its contributors may be
# used to endorse or promote products derived from this software without
# specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
