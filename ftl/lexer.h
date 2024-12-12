#ifndef LEXER_H
#define LEXER_H

#include "config.h"

typedef struct {
    char *type;
    char *value;
} Token;

typedef struct {
    Token tokens[MAXTOKENS];
} TokenArray;

TokenArray lexer(const char* source);

#endif
