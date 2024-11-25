#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

// ANSI color codes
static const char *RESET = "\033[0m";
static const char *RED = "\033[1;91m";
static const char *PURPLE = "\033[0;95m";

// Function prototypes
static inline void fatal_error(const char *message) {
    (void)fprintf(stderr, "ftl: %sfatal error%s: %s\ncompilation terminated.\n", RED, RESET, message);
    exit(EXIT_FAILURE);
}

static inline int error(const char *message) {
    (void)fprintf(stderr, "ftl: %serror%s: %s\n", RED, RESET, message);
    return 0;
}

static inline int warning(const char *message) {
    (void)fprintf(stderr, "ftl: %swarning%s: %s\n", PURPLE, RESET, message);
    return 0;
}

static inline int debug(const char *tag, const char *message) {
    (void)printf("debug: %s:\n%s", tag, message);
    return 0;
}

#endif // ERROR_H
