#include "../error.h"

int
pdebug(const char *desc, const char *message)
{
  printf("debug: %s: %s", desc, message);
  return 0;
}

int
pdebugf(const char *desc, const char *format, ...)
{
  va_list args;
  va_start(args, format);
  fprintf(stdout, "%s%s%s: ", WHITE, desc, RESET);
  vfprintf(stdout, format, args);
  printf("\n");
  va_end(args);
  return 0;
}
