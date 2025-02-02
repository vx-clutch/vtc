bin_PROGRAMS = vtc
vtc_SOURCES = $(wildcard ../vtc/*.c) $(wildcard ../vtc/syslog/*.c)
vtc_CFLAGS = -I../vtc/syslog -I../vtc -D COMPILER_PLATFORM="\"$(shell uname -o) $(shell uname -r)\""

# libgo
lib_LTLIBRARIES = libgo.a
libgo_a_SOURCES = ../libgo/go/main.go
GOFLAGS = -buildmode=c-archive

all-local:
    cd ../libgo && go build $(GOFLAGS) -o ../autoconf/libgo.a go/main.go

CLEANFILES = libgo.a
