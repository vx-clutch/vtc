#include "parse_args.h"
#include <string.h>
#include <getopt.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

void print_help() {
  printf("Usage: ftl [options] file...\n\n");
  printf("Options:\n");
  printf("  --help\tPrints out the help and exit.\n");
  printf("  --version\tPrints out the version number and exit.\n");
  printf("  -o <file>\tPlace the output into <file>.\n");
  printf("  -S\t\tCompile only; do not assembly or link.\n");
  printf("  -c\t\tComppile and assemble, but do not link.\n");
}

#ifndef VERSION
#define VERSION "unknown"
#endif
#ifndef YEAR
#define YEAR "unknown"
#endif

void print_version() {
  printf("ftl (FTL) %s 2024-%s (vx-clutch)\nCopyright (C) 2024-%s vx-clutch\nThis is free software; see the source for copying conditions. There is NO\nwarranty; not even for MERCHANTABLITY or FITNESS FOR A PARTICULAR PURPOSE\n", VERSION, YEAR, YEAR);
}

Options parse_args(int argc, char **argv) {
  int c;
  int option_index = 0;
  Options options;
  options.c = false;
  options.S = false;
  options.o = NULL;
  struct option long_options[] = {
    {"version", no_argument, 0, 'v'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
  };
  while ((c = getopt_long(argc, argv, "Sco:hv", long_options, &option_index)) != -1) {
    switch (c) {
      case 'S':
        options.S = true;
        break;
      case 'c':
        options.c = true;
        break;
      case 'o':
        options.o = optarg;
        break;
      case 'h':
        print_help();
        exit(EXIT_SUCCESS);
      case 'v':
        print_version();
        exit(EXIT_SUCCESS);
      case '?':
        exit(EXIT_FAILURE);
      default:
        abort();
    }
  }
  return options;
}
