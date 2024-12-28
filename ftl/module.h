#ifndef MODULE_H
#define MODULE_H

#include "config.h"

typedef struct {
  char KWORD[MAXKWORDLEN];
  char assembly[MAXASM];
} module;

module get_module(const char *source);

#endif
