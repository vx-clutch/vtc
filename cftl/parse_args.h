#ifndef OPT_H
#define OPT_H

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    bool S;
    bool c;
    bool E;
    char *o;
    FILE *F;
} Options;

Options parse_args(int argc, char **argv);

#endif
