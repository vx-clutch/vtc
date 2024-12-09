#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* ANSI color codes */
static const char *RESET = "\033[0m";
static const char *RED = "\033[1;91m";
static const char *PURPLE = "\033[0;95m";


/* fatal */
static inline void fatal_error(const char *message) {
    (void)fprintf(stderr, "ftl: %sfatal error%s: %s\ncompilation terminated.\n", RED, RESET, message);
    exit(EXIT_FAILURE);
}

static inline void fatal_errorf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    (void)fprintf(stderr, "ftl: %sfatal error%s: ", RED, RESET);
    (void)vfprintf(stderr, format, args);
    (void)fprintf(stderr, "\ncompilation terminated.\n");
    va_end(args);
    exit(EXIT_FAILURE);
}

/* error */
static inline int error(const char *message) {
    (void)fprintf(stderr, "ftl: %serror%s: %s\n", RED, RESET, message);
    return 0;
}

static inline void errorf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    (void)fprintf(stderr, "ftl: %serror%s: ", RED, RESET);
    (void)vfprintf(stderr, format, args);
    va_end(args);
}

/* warning */
static inline int warning(const char *message) {
    (void)fprintf(stderr, "ftl: %swarning%s: %s\n", PURPLE, RESET, message);
    return 0;
}

static inline void warningf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    (void)fprintf(stderr, "ftl: %warning%s: ", PURPLE, RESET);
    (void)vfprintf(stderr, format, args);
    va_end(args);
}

static inline int debug(const char *tag, const char *message) {
    (void)printf("debug: %s:\n%s", tag, message);
    return 0;
}

#endif
