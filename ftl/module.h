#ifndef MODULE_H
#define MODULE_H

#include "config.h"

typedef struct {
  char *KWORD;
  char *assembly;
  char macros[MAXMACROS];
} module;

module get_module(const char *source);

#endif
