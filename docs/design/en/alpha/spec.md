# FTL Alpha Specification

## Stack Machine
FTL uses a stack machine for all its mathmatical calculations.

## Reverse Polish Notation
FTL uses Reverse Polish notation for math syntax.
For example:
  3 4 *
This would compute to 12 and place it on the stack.

See Stack Machine.

## Comments
Coments are defined with two semi-colons.
```
;; This is a comment
````

## Variables
### General
All variables are global scope.

### Define
#### Integers
```
x;
int x;
```
#### String
```
string x;
```
## Assign
You can asign to a variable with the assignment operator
```
3 4 * -> $x;
```
This sets `x` to 12.
## Using
To use a variable you place a `$` infront of it, i.e. `$x`
