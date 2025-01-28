; Output file: ELF 64-bit executable
; Compiler: $@
; Source: $$

section .text
global _start

_start:
  call .main
  jmp .exit

.exit:
  mov rax, 60
  xor rdi, rdi
  syscall

.main:
