#include <bits/getopt_ext.h>
#include <getopt.h>

option[] parseArgs(int argc, char **argv) {
  int c;
  int opti = 0;
  struct option long_options[] = {
    {"verbose", no_argument, 0, 'v'},
    {"output", required_argument, 0, 'o'},
    {0, 0, 0, 0}
  };

  return long_options;
}
