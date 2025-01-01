// Copyright (C) 2024 vx-clutch
// See end of file for extended copyright information.

#include "lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char peek(Lexer *lexer) { return lexer->input[lexer->pos]; }
void advance(Lexer *lexer) { lexer->pos++; }

Token tokenize_number(Lexer *lexer) {
  size_t start = lexer->pos;
  while (isdigit(peek(lexer)))
    advance(lexer);
  size_t length = lexer->pos - start;
  char *num = malloc(length + 1);
  strncpy(num, lexer->input + start, length);
  num[length] = '\0';
  Token token = {TOKEN_NUMBER, num};
  return token;
}

Token tokenize_alpha(Lexer *lexer) {
  size_t start = lexer->pos;

  while ((peek(lexer) != '\0' && isalpha(peek(lexer))) || peek(lexer) == '_')
    advance(lexer);

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

Token next_token(Lexer *lexer) {
  while (peek(lexer) != '\0') {
    char c = peek(lexer);

    if (isspace(c)) {
      advance(lexer);
      continue;
    }

    if (isdigit(c))
      return tokenize_number(lexer);

    if (isalpha(c))
      return tokenize_alpha(lexer);

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

void free_token(Token *token) {
  if (token->type == TOKEN_NUMBER)
    free(token->value);
}

/* ftl is a simple and extensible compiler.
 * Copyright (C) 2024 vx-clutch
 *
 * The file is part of ftl.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions, and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions, and the following disclaimer in the documentation or
 * other materials provided with the distribution.
 * 3. Neither the name of vx-clutch nor the names of its contributors may be
 * used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
