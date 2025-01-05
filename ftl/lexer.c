// Copyright (C) 2024 vx-clutch ( owestness@gmail.com )
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
  Token token = {INT, num};
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

  Token token = {IDENT, id};
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
      return (Token){PLUS, NULL};
    case '-':
      return (Token){MINUS, NULL};
    case '*':
      return (Token){STAR, NULL};
    case '/':
      return (Token){SLASH, NULL};
    case '(':
      return (Token){LPAREN, NULL};
    case ')':
      return (Token){RPAREN, NULL};
    case ',':
      return (Token){COMMA, NULL};
    case ':':
      return (Token){COLON, NULL};
    case ';':
      return (Token){SEMICOLON, NULL};
    case '#':
      return (Token){POUND, NULL};
    case '%':
      return (Token){PERCENT, NULL};
    case '!':
      return (Token){BANG, NULL};
    default:
      return (Token){UNKNOWN, NULL};
    }
  }
  return (Token){EOF, NULL};
}

void free_token(Token *token) {
  if (token->type == INT)
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
