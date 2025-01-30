# Output file: ELF 64-bit executable
# Compiler: $@
# Source: $$

.text
.global _start

_start:
  call .prog
  jmp .exit

.exit:
  movq $60, %rax
  xorq %rdi, %rdi
  syscall

.prog:
