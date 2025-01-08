# Specification

> [!WARNING]  
> vx turning language is currently in its **alpha** stages of development. Most of this specification document will not be implemented yet, and will be subject to change.

## File
The vx turning language uses the `.vl` file extention

## Types
void
int
string

### Extended Types
#### Array
void[]
int[]
string[]

#### Pointers
void *
int *
string *

## Functions
fn {RETURN TYPE} {IDENT}({PARAMETERS})
{
    ;; code...
}

## Comments
;; comment

## Control Logic
### If
if {COND} {
    ;; code...
} else if {COND} {
    ;; code...
} else {
    ;; code ...
}
### Loop
while {COND} {
    ;; code...
}

## Assembly
asm {
    ;; assembly...
}

## Include
#include <{CORE LIB}>
#include "{RELATIVE}"

## Arthimetic
\+
-
*
/

## Comparison
==
<
>
<=
>=

## Variables
{TYPE} {IDENT}
{TYPE} mut {IDENT}

### Assign
{IDNET} = {EXPR}

## Return
return {INT}
