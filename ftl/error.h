#ifndef EREROR_H
#define EREROR_H

#include "config.h"
#include "parse_args.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// ANSI color codes
extern const char *RESET;
extern const char *RED;
extern const char *PURPLE;
extern const char *WHITE;
extern const char *GREEN;
extern const char *YELLOW;

void
pfatal(const char *message);

void
pfatalf(const char *format, ...);

#define perror __perror
int
__perror(const char *message);

void
perrorf(const char *format, ...);

int
pwarning(const char *message);

void
pwarningf(const char *format, ...);

int
pdebug(const char *desc, const char *message);

int
pdebugf(const char *desc, const char *format, ...);

void
plog(int status, const char *message);

#define INFO 0,
#define OK 1,
#define WARNING 2,
#define FAILURE 3,

#endif
