// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "../../../config.h"
#include "../../../lexer.h"
#include <stdio.h>
#include <stdlib.h>

int
main()
{
  Lexer lexer = {0};
  lexer.input = "123 IDENT + - * / ( ) , : ; # % !";
  lexer.pos = 0;

  Token token_buffer[MAXTOKENS];
  int i = 0;

  while (1)
  {
    if (i >= MAXTOKENS)
    {
      fprintf(stderr, "Error: Too many tokens.");
      exit(EXIT_FAILURE);
    }

    Token token = next_token(&lexer);

    // Store a copy of the token in the buffer
    if (token.type == INT || token.type == IDENT)
    {
      token_buffer[i].type = token.type;
      token_buffer[i].value = token.value; // Take ownership of the memory
    }
    else
    {
      token_buffer[i] = token;
    }

    if (token.type == EOF)
      break;

    i++;
  }

  printf("Tokens:");
  for (int j = 0; j < i; j++)
  {
    printf("Type: %d", token_buffer[j].type);
    if (token_buffer[j].value)
      printf(", Value: %s", token_buffer[j].value);
    printf("");

    // Free dynamically allocated memory for the token's value
    free_token(&token_buffer[j]);
  }

  return 0;
}

/* vtc is a simple and extensible compiler.
 * Copyright (C) 2024 vx-clutch
 *
 * The file is part of vtc.
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
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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
