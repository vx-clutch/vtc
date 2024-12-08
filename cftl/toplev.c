#include "processor.h"
#include "parse_args.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int toplev(int argc, char **argv) {
  Options options = parse_args(argc, argv);
  char *source;
  source = processor(source);
  if (options.E) {
    (void)printf("%s\n", source);
    exit(0);
  }
  return 0;
}
