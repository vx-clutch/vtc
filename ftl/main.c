#include "toplev.h"
#include "error.h"

#ifndef __linux__
#error                                                                         \
    "the ftl software at its current stage of development only features unix support. If you do not like this feel free to make a pull request."
#endif

int main(int argc, char **argv) {
  fatal_errorf("%s", 123);
  /* call toplev which is where all of the main logic is held */
  (void)toplev(argc, argv);
  return 0;
}
