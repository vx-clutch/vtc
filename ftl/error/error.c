#include "../error.h"

int
perror(const char *message)
{
  fprintf(stderr, "%s%s%s: %serror%s: %s\n", WHITE, COMPILER_NAME, RESET, RED,
          RESET, message);
  return 0;
}

void
perrorf(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  fprintf(stderr, "%s%s%s: %serror%s: ", WHITE, COMPILER_NAME, RESET, RED,
          RESET);
  vfprintf(stderr, format, args);
  fprintf(stderr, "\n");
  va_end(args);
}
