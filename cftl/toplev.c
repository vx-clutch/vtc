#include "processor.h"
#include "parse_args.h"
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
  return 0;
}
