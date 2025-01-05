#include "../error.h"

void
pfatal(const char *message)
{
  fprintf(stderr, "%s%s%s: %sfatal error%s: %s\ncompilation terminated.\n",
          WHITE, COMPILER_NAME, RESET, RED, RESET, message);
  exit(EXIT_FAILURE);
}

void
pfatalf(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  fprintf(stderr, "%s%s%s: %sfatal error%s: ", WHITE, COMPILER_NAME, RESET, RED,
          RESET);
  vfprintf(stderr, format, args);
  fprintf(stderr, "\ncompilation terminated.\n");
  va_end(args);
  exit(EXIT_FAILURE);
}
