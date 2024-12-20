package main

import "C"

import (
	"libgo/target/linux/x86/32"
	"libgo/target/linux/x86/64"
)

func main() {}

//export get_header_for
func get_header_for(__which *C.char) *C.char {
	which := C.GoString(__which)
	switch which {
	case "linux_x86_64":
		return (*C.char)(linux_x86_64.Get())
	case "linux_x86_32":
		return (*C.char)(linux_x86_32.Get())
	default:
		return C.CString("")
	}
}
