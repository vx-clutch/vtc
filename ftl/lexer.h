#ifndef LEXER_H
#define LEXER_H

#include "ctype.h"
#include "string.h"

typedef enum {
  TOKEN_NUMBER,
  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_STAR,
  TOKEN_SLASH,
  TOKEN_LPAREN,
  TOKEN_RPAREN,
  TOKEN_EOF,
  TOKEN_UNKNOWN,
} TokenType;

typedef struct {
  TokenType type;
  char *value;
} Token;

typedef struct {
  const char *input;
  size_t pos;
} Lexer;

void print_token(const Token *token);
void free_token(Token *token);

#endif
