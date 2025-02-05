AC_INIT([libgo], [1.0], [owestness@gmail.com])
AM_INIT_AUTOMAKE([foreign])
AC_PROG_CC

# Check for Go
AC_PATH_PROG([GO], [go], [no])

if test "$GO" = "no"; then
  AC_MSG_ERROR([Go not found. Please install Go.])
fi

# Set the Go source files
GO_SRCS="go/main.go arch/x86_64/linux/linuxx64.go"

# Check for Go build command
AC_CHECK_PROG([GOBUILD], [go], [no])

if test "$GOBUILD" = "no"; then
  AC_MSG_ERROR([Go build not found. Please ensure Go is properly installed.])
fi

# Produce the library
AC_ARG_ENABLE([static-lib],
              [AS_HELP_STRING([--enable-static-lib], [Build static library])],
              [],
              [enable_static_lib=yes])

if test "x$enable_static_lib" = "xyes"; then
  AC_MSG_NOTICE([Building static library...])
  GO_BUILD_STATIC_LIB="true"
else
  GO_BUILD_STATIC_LIB="false"
fi

# Set the custom directory for output files
AC_SUBST([STATIC_LIB_DIR], [../static])

AC_OUTPUT
