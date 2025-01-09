CC=gcc

error_impl=../../../syslog/log.c
error_impl+=../../../syslog/colors.c
error_impl+=../../../syslog/debug.c
error_impl+=../../../syslog/error.c
error_impl+=../../../syslog/fatal.c
error_impl+=../../../syslog/warning.c

all: test_error test_fatalf

test_error: test_error.c 
	$(CC) -o test_error test_error.c $(error_impl)

test_fatalf: test_fatalf.c
	$(CC) -o test_fatalf test_fatalf.c $(error_impl)

clean:
	-rm test_error
	-rm test_fatalf
