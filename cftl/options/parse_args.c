#include "options.h"
#include "stdlib.h"
#include <bits/getopt_core.h>
#include <stdio.h>
#include <getopt.h>

void print_help() {
  printf("Usage: ftl [options] file...\n\n");
  printf("Options:\n");
  printf("  --help\tPrints out the help and exit.\n");
  printf("  --version\tPrints out the version number and exit.\n");
  printf("  -o <file>\tPlace the output into <file>.\n");
  printf("  -S\tCompile only; do not assembly or link.\n");
  printf("  -c\tComppile and assemble, but do not link.\n");
}

#ifndef VERSION
#define VERSION "unknown"
#endif
#ifndef YEAR
#define YEAR "unknown"
#endif

void print_version() {
  printf("ftl (FTL) %s 2024-%s (vx-clutch)\nCopyright (C) 2024-%s vx-clutch\nThis is free software; see the source for copying conditions.   There is NO\nwarranty; not even for MERCHANTABLITY or FITNESS FOR A PARTICULAR PURPOSE", VERSION, YEAR, YEAR);
}

int parseArgs(int argc, char **argv) {
  int c;
  int option_index = 0;
  struct option long_options[] = {
    {"version", no_argument, 0, 'v'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
  };
  while ((c = getopt_long(argc, argv, "hv", long_options, &option_index)) != -1) {
    switch (c) {
      case 'h':
        print_help();
        return 0;
      case 'v':
        print_version();
        return 0;
      case '?':
        return 1;
      default:
        abort();
    }
  }
  return 0;
}
