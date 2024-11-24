#include <stdio.h>
#include <stdlib.h>
#include "error.h"


const char *RESET = "\033[0m";
const char *RED = "\033[1;91m";
const char *PURPLE = "\033[0;95m";

void fatal_error(const char *message) {
  (void)fprintf(stderr, "ftl: %sfatal error%s: %s\ncompilation terminated.\n", RED, RESET, message);
  exit(EXIT_FAILURE);
}

int error(const char *message) {
  (void)fprintf(stderr, "ftl: %serror%s: %s\n", RED, RESET, message);
  return 0;
}

int warning(const char *message) {
  (void)fprintf(stderr, "ftl: %swarning%s: %s\n", PURPLE, RESET, message);
  return 0;
}

int debug(const char *tag, const char*message) {
  (void)printf("debug: %s:\n%s", tag, message);
  return 0;
}
