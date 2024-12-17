#include "lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char peek(Lexer *lexer) { return lexer->input[lexer->pos]; }

void advance(Lexer *lexer) { lexer->pos++; }

Token tokenize_number(Lexer *lexer) {
  size_t start = lexer->pos;
  while (isdigit(peek(lexer))) {
    advance(lexer);
  }
  size_t length = lexer->pos - start;
  char *num = malloc(length + 1);
  strncpy(num, lexer->input + start, length);
  num[length] = '\0';
  Token token = {TOKEN_NUMBER, num};
  return token;
}

Token next_token(Lexer *lexer) {
  while (peek(lexer) != '\0') {
    char c = peek(lexer);

    if (isspace(c)) {
      advance(lexer);
      continue;
    }

    if (isdigit(c)) {
      return tokenize_number(lexer);
    }

    advance(lexer);

    switch (c) {
    case '+':
      return (Token){TOKEN_PLUS, NULL};
    case '-':
      return (Token){TOKEN_MINUS, NULL};
    case '*':
      return (Token){TOKEN_STAR, NULL};
    case '/':
      return (Token){TOKEN_SLASH, NULL};
    case '(':
      return (Token){TOKEN_LPAREN, NULL};
    case ')':
      return (Token){TOKEN_RPAREN, NULL};
    default:
      return (Token){TOKEN_UNKNOWN, NULL};
    }
  }
  return (Token){TOKEN_EOF, NULL};
}

void print_token(const Token *token) {
  switch (token->type) {
  case TOKEN_NUMBER:
    printf("NUMBER(%s)\n", token->value);
    break;
  case TOKEN_PLUS:
    printf("PLUS\n");
    break;
  case TOKEN_MINUS:
    printf("MINUS\n");
    break;
  case TOKEN_STAR:
    printf("STAR\n");
    break;
  case TOKEN_SLASH:
    printf("SLASH\n");
    break;
  case TOKEN_LPAREN:
    printf("LPAREN\n");
    break;
  case TOKEN_RPAREN:
    printf("RPAREN\n");
    break;
  case TOKEN_EOF:
    printf("EOF\n");
    break;
  default:
    printf("UNKNOWN\n");
    break;
  }
}

void free_token(Token *token) {
  if (token->type == TOKEN_NUMBER) {
    free(token->value);
  }
}
