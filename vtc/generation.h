#ifndef GEN_H
#define GEN_H

typedef enum
{
  LEA,
  MOV,
  INT,
  XOR,
  PUSH,
  POP,
  ADD,
  SUB,
  IMUL,
  IDIV,
  CMP,
  JE,
  JNE,
  JL,
  JMP,
  CALL,
  RET,
} optcode;

#endif
