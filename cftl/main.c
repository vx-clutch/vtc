#include "error.h"
#include "toplev.h"
#include <assert.h>

#ifndef __linux__
#error "the ftl software at its current stage of development only features unix support. If you do not like this feel free to make a pull request."
#endif

int main(int argc, char **argv) {
  (void)toplev(argc, argv);
  return 0;
}
