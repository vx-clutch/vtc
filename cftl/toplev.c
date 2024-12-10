#include "config.h"
#include "processor.h"
#include "parse_args.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int toplev(int argc, char **argv) {
  char *source;
  Options options = parse_args(argc, argv);
  source = options.F;
  source = processor(source);
  if (options.E) {
    char default_val[MAXOUTPUTPATH];
    if (options.o[0] == '\0') {
      (void)printf("%s\n", source);
      exit(0);
    }
    FILE *fp;
    fp = fopen(options.o, "w");
    fprintf(fp, "%s\n", source);
    fclose(fp);
    exit(0);
  }
  return 0;
}
