package main

import (
	"libgo/target/linux/x86/64"
	"libgo/target/linux/x86/32"
)

func main() {}

/* get linux x86 64 header */
func Get(__which string) string {
	switch __which {
	case "linuxx64":
		return linux_x86_64.H_linux_x86_64
	case "linuxx32":
		return linux_x86_32.H_linux_x86_32
	}
	return ""
}

