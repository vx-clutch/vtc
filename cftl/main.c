#include "error.h"
#include "toplev.h"
#include <assert.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fatal_error("no input files.");
  }
  int err = toplev();
  assert(err != 0);
  return 0;
}
