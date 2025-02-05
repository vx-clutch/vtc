AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = libgo
libgo_SOURCES = $(GO_SRCS)
libgo_CFLAGS = $(GO_CFLAGS)

# Build static library
if GO_BUILD_STATIC_LIB = true; then
  lib_LIBRARIES = $(STATIC_LIB_DIR)/libgo.a
  libgo_a_SOURCES = $(GO_SRCS)
  libgo_a_CFLAGS = $(GO_CFLAGS)
  libgo_a_LDFLAGS = -static
else
  lib_LIBRARIES = $(STATIC_LIB_DIR)/libgo.so
  libgo_so_SOURCES = $(GO_SRCS)
  libgo_so_CFLAGS = $(GO_CFLAGS)
  libgo_so_LDFLAGS = -shared
endif

# Install the header file in the ../static directory
include_HEADERS = $(STATIC_LIB_DIR)/libgo.h
