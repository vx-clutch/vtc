# Define libgo.la for Go files
libgo_la_SOURCES = \
  libgo/go/main.go \
  libgo/go/arch/x86_64/linux/header.go \
  # Add more Go files here if needed

# Tell automake to treat the Go files as part of the library
libgo_la_SCRIPTS = $(libgo_la_SOURCES)

# If libgo is a static library, we want to use 'libgo.la' (not 'libgo.a')
lib_LIBRARIES = libgo.la

# Link dependencies (if any other libraries are needed)
libgo_la_LIBADD =

# Specify compilation flags for Go (if any)
GOFLAGS = -v

# Define additional tools or flags required for Go compilation (if needed)
# Example: if you want to specify a Go toolchain
GO_TOOLCHAIN = go

# We may need to add steps to make sure the Go files are compiled:
# These will be called in the build process

# To avoid direct shell commands in Makefile.am, handle them via rules
# Here's an example rule for compiling Go files:
go_build:
	$(GO_TOOLCHAIN) build -o build/libgo.so libgo/go/*.go

# If your Go files need to be installed, you can do it as follows:
install-go:
	$(GO_TOOLCHAIN) install libgo/go/*.go

# Add these to your targets
ALL_LOCAL_TARGETS = go_build
