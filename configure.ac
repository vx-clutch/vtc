AC_INIT([vtc], [0.1], [owen@gmail.com])
AM_INIT_AUTOMAKE([foreign -Wall])

AC_PROG_CC
AC_PROG_LIBTOOL

AC_CHECK_LIB([go-linuxx64], [get_header_for], [], [AC_MSG_ERROR([Function get_header_for() not found in libgo-linuxx64.a])])
AC_CHECK_LIB([go-linuxx64], [populate], [], [AC_MSG_ERROR([Function populate() not found in libgo-linuxx64.a])])

CPPFLAGS="-I${srcdir}/static"

LDFLAGS="-L${srcdir}/static"

AC_CHECK_HEADERS([libgo-linuxx64.h], [], [AC_MSG_ERROR([Header file libgo-linuxx64.h not found])])

AC_CONFIG_FILES([
    Makefile
    libgo/Makefile
    vtc/Makefile
    man/Makefile
])
AC_OUTPUT
