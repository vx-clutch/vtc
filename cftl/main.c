#include "error.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    fatal_error("no input files.");
  }
  return 0;
}
