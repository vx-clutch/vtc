#include "lexer.h"
#include "parse_args.h"
#include "processor.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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
  printf("Lexing source: %s\n", source);

  while (1) {
    Token token = next_token(&lexer);
    print_token(&token);

    if (token.type == TOKEN_EOF) {
      free_token(&token);
      break;
    }

    free_token(&token);
  }
  return 0;
}
