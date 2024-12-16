package embed_linuxx32

import _ "embed"

//go:embed /linux/x86/32/main.s
var main string

//go:embed /linux/x86/32/exit.s
var exit string
