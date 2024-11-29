#ifndef OPT_H
#define OPT_H

#include <stdbool.h>

typedef struct {
    bool S;
    bool c;
    char *o;

} Options;

int parse_args_long(int argc, char **argv);
Options parse_args_short(int argc, char **argv);

#endif
