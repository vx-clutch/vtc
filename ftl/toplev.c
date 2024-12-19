#include "config.h"
#include "lexer.h"
#include "parse_args.h"
#include "processor.h"
#include <stdlib.h>

/* kill_proc either prints to stdout, or to the set file in the options struct
 * then exits with status code 0 */
void kill_proc(Options options, char *source) {
  if (options.o[0] == '\0') {
    (void)printf("%s", source);
    exit(0);
  }
  FILE *fp;
  fp = fopen(options.o, "w");
  fprintf(fp, "%s", source);
  fclose(fp);
  exit(0);
}

int toplev(int argc, char **argv) {
  char *source;
  Options options = parse_args(argc, argv);
  source = options.F;
  source = processor(source);
  if (options.E) {
    kill_proc(options, source);
  }

  Lexer lexer = {source, 0};
  Token token_buffer[MAXTOKENS];
  int i;

  /* iterate over source and get tokens */
  while (1) {
    Token token = next_token(&lexer);

    token_buffer[i] = token;

    if (token.type == TOKEN_EOF) {
      free_token(&token);
      break;
    }

    free_token(&token);
    i++;
  }

  Token tokens[i];

  /* takes the first i elemets in token_buffer and place them in the
   * corresponding place in tokens */
  for (int j = 0; j < i; j++) {
    tokens[i] = token_buffer[i];
  }

  return 0;
}
