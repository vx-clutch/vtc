#ifndef OPT_H
#define OPT_H

#include "config.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  bool S;
  bool c;
  bool E;
  char o[MAXOUTPUTPATH];
  char F[MAXINPUTBUFFER];
} Options;

Options parse_args(int argc, char **argv);

#endif
