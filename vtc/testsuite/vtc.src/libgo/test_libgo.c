#include "../../../../build/obj/libgo/libgo.h"
#include "../../../config.h"
#include <stdio.h>

int
main(void)
{
  char *header = get_header_for("linuxx64");
  char *populated = populate(header, COMPILER_NAME, "foo.vl");
  printf("Base Header:\n%s\n\n", header);
  printf("Populated Header:\n%s\n", populated);
  return 0;
}
