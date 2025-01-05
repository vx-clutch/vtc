#include "../error.h"

void
plog(int status, const char *message)
{
  if (!options.verbose)
    return;

  switch (status)
  {
  case 0:
    printf("[ %sINFO%s ] %s\n", PURPLE, RESET, message);
    break;
  case 1:
    printf("[ %sOKAY%s ] %s\n", GREEN, RESET, message);
    break;
  case 2:
    printf("[ %sWARN%s ] %s\n", YELLOW, RESET, message);
    break;
  case 3:
    printf("[ %sFAIL%s ] %s\n", RED, RESET, message);
    break;
  }
}
