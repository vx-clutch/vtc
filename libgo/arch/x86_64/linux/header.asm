; Output file: ELF 64-bit executable
; Compiler: $@
; Source: $@1

section .text
global _start

_start:
  call main
  jmp main_exit_

main_exit_:
  mov rax, 60
  xor rdi, rdi
  syscall

main:
