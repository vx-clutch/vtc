#include "../../../lexer.h"
#include "../../../config.h"
#include <stdlib.h>

int
main(void)
{
  char *source = "123 IDENT + - * / ( ) , : ; # % !";
  Lexer lexer = {source, 0};
  Token token_buffer[MAXTOKENS];
  int i = 0;

  while (1)
  {
    Token token = next_token(&lexer);
    token_buffer[i] = token;
    if (token.type == EOF)
    {
      free_token(&token);
      break;
    }
    free_token(&token);
    i++;
  }
  return EXIT_SUCCESS;
}
