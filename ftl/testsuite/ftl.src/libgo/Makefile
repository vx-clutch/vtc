CC=gcc

all: test_libgo

test_libgo: test_libgo.o
	$(CC) -o test_libgo test_libgo.o ../../../../build/obj/libgo/libgo.a

test_libgo.o: test_libgo.c
	$(CC) -c -o test_libgo.o test_libgo.c

clean:
	-rm test_libgo
