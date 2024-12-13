%macro exit 1
  mov eax, 60
  mov edi, %1
  syscall
%endmacro
