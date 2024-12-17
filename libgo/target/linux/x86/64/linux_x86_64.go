package linux_x86_64

import (
  _ "embed"
)

//go:embed header.asm
var H_linux_x86_64 string
