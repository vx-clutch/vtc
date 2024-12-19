#include "lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* see next token */
char peek(Lexer *lexer) { return lexer->input[lexer->pos]; }

/* get next token */
void advance(Lexer *lexer) { lexer->pos++; }

/* get number and turn it into a token */
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

/* turn A-Za-z into single token */
Token tokenize_alpha(Lexer *lexer) {
  size_t start = lexer->pos;

  while ((peek(lexer) != '\0' && isalpha(peek(lexer))) || peek(lexer) == '_') {
    advance(lexer);
  }

  size_t length = lexer->pos - start;

  char *id = malloc(length + 1);
  if (!id) {
    fprintf(stderr, "Error: Memory allocation failed in tokenize_alpha.\n");
    exit(EXIT_FAILURE);
  }
  strncpy(id, lexer->input + start, length);
  id[length] = '\0';

  Token token = {TOKEN_IDENT, id};
  return token;
}

/* for external use
 * get the next token in *lexer */
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

    if (isalpha(c)) {
      return tokenize_alpha(lexer);
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
    case ',':
      return (Token){TOKEN_COMMA, NULL};
    case ':':
      return (Token){TOKEN_COLON, NULL};
    case ';':
      return (Token){TOKEN_SEMICOLON, NULL};
    default:
      return (Token){TOKEN_UNKNOWN, NULL};
    }
  }
  return (Token){TOKEN_EOF, NULL};
}

/* print token type and value if it has one */
void print_token(const Token *token) {
  switch (token->type) {
  case TOKEN_NUMBER:
    printf("NUMBER(%s)\n", token->value);
    break;
  case TOKEN_IDENT:
    printf("IDENT(%s)\n", token->value);
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
  case TOKEN_COMMA:
    printf("COMMA\n");
    break;
  case TOKEN_COLON:
    printf("COLON\n");
    break;
  case TOKEN_SEMICOLON:
    printf("SEMICOLON\n");
    break;
  case TOKEN_EOF:
    printf("EOF\n");
    break;
  default:
    printf("UNKNOWN\n");
    break;
  }
}

/* free token memory */
void free_token(Token *token) {
  if (token->type == TOKEN_NUMBER) {
    free(token->value);
  }
}
