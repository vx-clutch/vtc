#include "../../../processor.h"
#include <assert.h>
#include <stdio.h>

int
main(void)
{
  char source[MAXINPUTBUFFER] = "KEYWORD; ;; comment";
  processor(source);
  printf("%s\n", source);
  return 0;
}
