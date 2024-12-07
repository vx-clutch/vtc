#include "error.h"
#include "toplev.h"
#include <assert.h>

#ifndef __linux__
#error "the ftl software at its current staage of development only features unix support. If you do not like this feel free to make a pull request."
#endif

int main(int argc, char **argv) {
  if (argc < 2) {
    fatal_error("no input files.");
  }
  (void)toplev(argc, argv);
  return 0;
}
