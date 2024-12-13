section .text
global _start

_start:
  call main
  jmp main_exit

main_exit:
  mov rax, 60
  xor rdi, rdi
  syscall

main:
