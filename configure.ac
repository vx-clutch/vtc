AC_INIT([vtc], [1.0], [owestness@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Wextra foreign])
AC_CONFIG_SRCDIR([vtc])
AC_CONFIG_AUX_DIR([build-aux])
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_AWK
AC_CHECK_PROG([GOC], [go], [yes], [no])

CFLAGS="-Wall -Wextra -O2 -pedantic -static -std=c99"
AC_SUBST(CFLAGS)
AC_SUBST(LDFLAGS)

if test "x$GOC" = "xno"; then
  AC_MSG_ERROR([Go compiler (go) is required to build the Go library])
fi

AC_CONFIG_FILES([Makefile autoconf/Makefile man/Makefile])
AC_OUTPUT
