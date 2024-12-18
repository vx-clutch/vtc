section .text
global _start

_start:
  call main
  jmp main_exit_

main_exit_:
  mov eax, 60
  xor edi, edi
  syscall

main:
