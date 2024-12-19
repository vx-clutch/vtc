#include "parse_args.h"
#include "config.h"
#include "error.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_help() {
  printf("Usage: ftl [options] file...\n\n");
  printf("Options:\n");
  printf("  --help\tPrints out the help and exit.\n");
  printf("  --version\tPrints out the version number and exit.\n");
  printf("  -o <file>\tPlace the output into <file>.\n");
  printf("  -S\t\tCompile only; do not assembly or link.\n");
  printf("  -c\t\tCompile and assemble, but do not link.\n");
}

/* see config.h */
#ifndef COMPILER_VERSION
#define COMPILER_VERSION "unknown"
#endif
#ifndef COMPILER_YEAR
#define COMPILER_YEAR "unknown"
#endif
#ifndef COMPILER_PLATFORM
#define COMPILER_PLATFORM "unknown unix system"
#endif

/* print versioning information */
void print_version() {
  printf(
      "ftl (FTL) %s %s (%s)\nCopyright (C) %s vx-clutch\nThis is free "
      "software; see the source for copying conditions. There is NO\nwarranty; "
      "not even for MERCHANTABLITY or FITNESS FOR A PARTICULAR PURPOSE\n",
      COMPILER_VERSION, COMPILER_YEAR, COMPILER_PLATFORM, COMPILER_YEAR);
}

Options parse_args(int argc, char **argv) {
  int c;
  int option_index = 0;

  /* init options struct */
  Options options;
  options.E = false;
  options.c = false;
  options.S = false;

  /* define long options */
  struct option long_options[] = {{"version", no_argument, 0, 'v'},
                                  {"help", no_argument, 0, 'h'},
                                  {0, 0, 0, 0}};
  while ((c = getopt_long(argc, argv, "SEco:hv", long_options,
                          &option_index)) != -1) {
    switch (c) {
    /* assembly */
    case 'S':
      options.S = true;
      break;
    /* object */
    case 'c':
      options.c = true;
      break;
    /* output */
    case 'o':
      strncpy(options.o, optarg, MAXINPUTBUFFER);
      break;
    /* preproccsor */
    case 'E':
      options.E = true;
      break;
    /* help */
    case 'h':
      print_help();
      exit(EXIT_SUCCESS);
    /* version */
    case 'v':
      print_version();
      exit(EXIT_SUCCESS);
    case '?':
      exit(EXIT_FAILURE);
    default:
      abort();
    }
  }

  if (optind >= argc) {
    fatal_error("no input files.");
  }

  /* file processing */
  /* read file, and set options.F to the char[] of the contents */
  for (int i = optind; i < argc; i++) {
    FILE *fp;
    char *buffer;
    long file_size;
    char *path = argv[i];

    /* file pointer */
    fp = fopen(path, "r");

    if (fp == NULL) {
      fatal_error("cannot open file.");
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    /* is file small enough (you can increase this limit in config.h) */
    if (file_size >= MAXINPUTBUFFER) {
      fclose(fp);
      fatal_errorf("input buffer exceeds buffer capacity (%d bytes).",
                   MAXINPUTBUFFER);
    } else if (file_size == 0) {
    }

    buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL) {
      fclose(fp);
      fatal_error("error allocating memory.");
    }

    (void)fread(buffer, 1, file_size, fp);
    buffer[file_size] = '\0';

    strncpy(options.F, buffer, MAXINPUTBUFFER - 1);
    options.F[MAXINPUTBUFFER - 1] = '\0';

    fclose(fp);
    free(buffer);
  }
  return options;
}
