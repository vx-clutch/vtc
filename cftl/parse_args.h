#ifndef OPT_H
#define OPT_H

#include <stdbool.h>

typedef struct {
    bool S;
    bool c;
    char *o;
} Options;

Options parse_args(int argc, char **argv);

#endif
