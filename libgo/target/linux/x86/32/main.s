%include exit.inc

section .text
global _start

_start:
  call main
  jmp main_exit

main_exit:
  mov eax, 60
  xor edi, edi
  syscall

main:
