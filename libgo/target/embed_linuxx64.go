package embed_linuxx64

import (
  _ "embed"
)

//go:embed linux/x86/64/main.s
var main string
