CC=gcc

all: test_generation

test_generation: test_generation.c
	$(CC) -o test_generation test_generation.c ../../../generation.c -I../../../ -I../../../../build/obj/libgo


clean:
	-rm test_generation
