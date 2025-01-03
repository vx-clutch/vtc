// Copyright (C) 2024 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#ifndef OUTPUT_H
#define OUTPUT_H

#include "config.h"
#include "parse_args.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define perror __perror

/* ANSI color codes */
static const char *RESET = "\033[0m";
static const char *RED = "\033[1;91m";
static const char *PURPLE = "\033[0;95m";
static const char *WHITE = "\033[0;97m";
static const char *GREEN = "\033[1;32m";
static const char *YELLOW = "\033[0;33m";

/* fatal */
static inline void pfatal(const char *message) {
  (void)fprintf(stderr,
                "%s%s%s: %sfatal error%s: %s\ncompilation terminated.\n", WHITE,
                COMPILER_NAME, RESET, RED, RESET, message);
  exit(EXIT_FAILURE);
}

static inline void pfatalf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  (void)fprintf(stderr, "%s%s%s: %sfatal error%s: ", WHITE, COMPILER_NAME,
                RESET, RED, RESET);
  (void)vfprintf(stderr, format, args);
  (void)fprintf(stderr, "\ncompilation terminated.\n");
  va_end(args);
  exit(EXIT_FAILURE);
}

/* error */
static inline int __perror(const char *message) {
  (void)fprintf(stderr, "%s%s%s: %serror%s: %s\n", WHITE, COMPILER_NAME, RESET,
                RED, RESET, message);
  return 0;
}

static inline void perrorf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  (void)fprintf(stderr, "%s%s%s: %serror%s: ", WHITE, COMPILER_NAME, RESET, RED,
                RESET);
  (void)vfprintf(stderr, format, args);
  (void)printf("\n");
  va_end(args);
}

/* warning */
static inline int pwarning(const char *message) {
  (void)fprintf(stderr, "%s%s%s: %swarning%s: %s\n", WHITE, COMPILER_NAME,
                RESET, PURPLE, RESET, message);
  return 0;
}

static inline void pwarningf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  (void)fprintf(stderr, "%s%s%s: %swarning%s: ", WHITE, COMPILER_NAME, RESET,
                PURPLE, RESET);
  (void)vfprintf(stderr, format, args);
  (void)printf("\n");
  va_end(args);
}

/* debug */
static inline int pdebug(const char *tag, const char *message) {
  (void)printf("debug: %s: %s", tag, message);
  return 0;
}

static inline int pdebugf(const char *tag, const char *format, ...) {
  va_list args;
  va_start(args, format);
  (void)fprintf(stdout, "%s%s%s: ", WHITE, tag, RESET);
  (void)vfprintf(stdout, format, args);
  (void)printf("\n");
  va_end(args);
  return 0;
}

static inline void plog(const char *message, int level) {
  /* levels:
   * 0 - all good
   * 1 - warning
   * 2+ - error
   */
  if (level == 0)
    (void)printf("[ %sOK%s ] %s", GREEN, RESET, message);
  else if (level == 1)
    (void)printf("[ %sWARNING%s ] %s", YELLOW, RESET, message);
  else
    (void)printf("[ %sFAILURE%s ] %s", RED, RESET, message);
}

#endif

/* ftl is a simple and extensible compiler.
 * Copyright (C) 2024 vx-clutch
 *
 * The file is part of ftl.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions, and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions, and the following disclaimer in the documentation or
 * other materials provided with the distribution.
 * 3. Neither the name of vx-clutch nor the names of its contributors may be
 * used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
