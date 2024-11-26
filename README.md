# ftl
Faster-than-Light

### Reverse Polish Notation
Reverse polish notation, also know as postfix, is a mathmatical notation system that places the operator after the operands. See Figure 1. as an example.

Figure 1.
```
3 4 *
```
This places a twelve at the top of the stack

### Stack Machine
FTL is based on a stack machine, which is a computation model that performs all operations on a stack. See Figures 2-X

Figure 2.
start
| Index | Value |
| - | - |
| 0 | 0 |

prog: 3 4 *

first operand

| Index | Value |
| - | - |
| 0 | 3 |

second operand

| Index | Value |
| - | - |
| 0 | 3 |
| 0 | 4 |

operation

| Index | Value |
| - | - |
| 0 | 12 |
