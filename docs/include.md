# Include
In FTL you can include other ftl code with a `.fd` file.
## Example
`foo.fd`
```
fn exit(int status) {
    SYSCALL(60, status);
}
```
