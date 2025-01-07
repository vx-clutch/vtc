CC=gcc

error_impl=../../../error/log.c
error_impl+=../../../error/colors.c
error_impl+=../../../error/debug.c
error_impl+=../../../error/error.c
error_impl+=../../../error/fatal.c
error_impl+=../../../error/warning.c

all: test_error.c | test_fatalf.c
	$(CC) -o test_error test_error.c $(error_impl)
	$(CC) -o test_fatalf test_fatalf.c $(error_impl)

clean:
	-rm test_error
	-rm test_fatalf
