# Output file: ELF 64-bit executable
# Compiler: $@
# Source: $$

.text
.global main

main:
  call .prog
  jmp .exit

.exit:
  movq $60, %rax
  xorq %rdi, %rdi
  syscall

.prog:
