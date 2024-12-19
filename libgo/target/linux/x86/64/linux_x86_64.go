package linux_x86_64

import (
  "C"
  _ "embed"
)

//go:embed header.asm
var H_linux_x86_64 string

func Get() *C.char {
  return C.CString(H_linux_x86_64)
}