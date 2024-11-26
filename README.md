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

  starting state

  | Index | Value |
  | - | - |
  | 0 | 0 |

  input program
  ```
  3 4 *
  ```

  push 3

  | Index | Value |
  | - | - |
  | 0 | 3 |

  push 4

  | Index | Value |
  | - | - |
  | 0 | 3 |
  | 0 | 4 |

  multiplication 

  | Index | Value |
  | - | - |
  | 0 | 12 |
