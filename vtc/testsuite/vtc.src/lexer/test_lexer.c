#include "../../../lexer.h"
#include "../../../config.h"
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
      fprintf(stderr, "Error: Too many tokens.\n");
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

  printf("Tokens:\n");
  for (int j = 0; j < i; j++)
  {
    printf("Type: %d", token_buffer[j].type);
    if (token_buffer[j].value)
      printf(", Value: %s", token_buffer[j].value);
    printf("\n");

    // Free dynamically allocated memory for the token's value
    free_token(&token_buffer[j]);
  }

  return 0;
}
