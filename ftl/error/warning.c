#include "../error.h"

int
pwarning(const char *message)
{
  fprintf(stderr, "%s%s%s: %swarning%s: %s\n", WHITE, COMPILER_NAME, RESET,
          PURPLE, RESET, message);
  return 0;
}

void
pwarningf(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  fprintf(stderr, "%s%s%s: %swarning%s: ", WHITE, COMPILER_NAME, RESET, PURPLE,
          RESET);
  vfprintf(stderr, format, args);
  fprintf(stderr, "\n");
  va_end(args);
}
