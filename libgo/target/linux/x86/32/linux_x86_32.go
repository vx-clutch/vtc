package linux_x86_32

import (
  _ "embed"
)

//go:embed header.asm
var H_linux_x86_32 string
