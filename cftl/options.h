#ifndef OPT_H
#define OPT_H

#include <stdbool.h>

typedef struct {
    bool S;
    bool c;
    char o;
    bool help;
    bool version;

} Options;

int parse_args(int argc, char **argv);

#endif
