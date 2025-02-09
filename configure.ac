AC_INIT([vtc], [0.1], [owen@gmail.com])
AM_INIT_AUTOMAKE([subdir-objects foreign -Wall])

AC_PROG_CC

# Set the CFLAGS and LDFLAGS variables (no direct assignment in configure.ac)
AC_SUBST([CFLAGS], "-I/static")
AC_SUBST([LDFLAGS], "-L/static/libgo-linuxx64.a")

AC_CHECK_HEADERS([libgo-linuxx64.h], [], [AC_MSG_ERROR([Header file libgo-linuxx64.h not found])])

AC_CONFIG_FILES([
    Makefile
    vtc/Makefile
    man/Makefile
])
AC_OUTPUT
