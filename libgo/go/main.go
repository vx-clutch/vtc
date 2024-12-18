package main

import (
	"libgo/target/linux/x86/64"
)

func main() {}

/* get linux x86 64 header */
func Get(__which string) string {
	switch __which {
	case "linuxx64":
		return linux_x86_64.H_linux_x86_64
	}
	return ""
}

