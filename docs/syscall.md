# Syscall
In ftl you can make a system call with the `SYSCALL(rdx, rdi, ...)` systax
## Example
```
SYSCALL(60, 0); ;; Exits with status 0.
```
