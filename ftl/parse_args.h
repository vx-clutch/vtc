#ifndef OPT_H
#define OPT_H

#include "config.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  bool S; /* assembly */
  bool c; /* object */
  bool E; /* expand */
  char o[MAXOUTPUTPATH]; /* outfile */
  char F[MAXINPUTBUFFER]; /* input file */
} Options;

Options parse_args(int argc, char **argv);

#endif
