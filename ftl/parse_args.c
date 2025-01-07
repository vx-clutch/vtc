// Copyright (C) 2024 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "parse_args.h"
#include "config.h"
#include "error.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_help(void);
void print_version(void);

void
print_help()
{
  printf("Usage: ftl [options] file...\n\n");
  printf("Options:\n");
  printf("  --help\tPrints out the help and exit.\n");
  printf("  --version\tPrints out the version number and exit.\n");
  printf("  -o <file>\tPlace the output into <file>.\n");
  printf("  -S\t\tCompile only; do not assembly or link.\n");
  printf("  -c\t\tCompile and assemble, but do not link.\n");
  printf("  -M\t\tSets the module directory\n");
  printf("  -v\t\tEnables verbose output\n");
}

Options options = {
    .assembly = 0,
    .object = 0,
    .expanded = 0,
    .verbose = 0,
    .output = "",
    .file = "",
};

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
void
print_version()
{
  printf(
      "ftl (FTL) %s %s (%s)\nCopyright (C) %s vx-clutch\nThis is free "
      "software; see the source for copying conditions. There is NO\nwarranty; "
      "not even for MERCHANTABLITY or FITNESS FOR A PARTICULAR PURPOSE\n",
      COMPILER_VERSION, COMPILER_YEAR, COMPILER_PLATFORM, COMPILER_YEAR);
}

Options
parse_args(int argc, char **argv)
{
  int opt;
  int option_index = 0;

  /* define long options */
  struct option long_options[] = {{"version", no_argument, 0, 1},
                                  {"help", no_argument, 0, 2},
                                  {0, 0, 0, 0}};
  opterr = 0;
  while ((opt = getopt_long(argc, argv, "SEco:hvM:", long_options,
                            &option_index)) != -1)
  {
    switch (opt)
    {
    case 'S':
      options.assembly = 1;
      break;
    case 'c':
      options.object = 1;
      break;
    case 'o':
      if (optarg == NULL || optarg[0] == '-')
      {
        perror("missing filename after '-o'");
        break;
      }
      else
      {
        /* this is intended behavior */
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wstringop-truncation"
        strncpy(options.output, optarg, MAXINPUTBUFFER);
        #pragma GCC diagnostic pop
        break;
      }
    case 'E':
      options.expanded = 1;
      break;
    case 'v':
      options.verbose = 1;
      break;
    case 2:
      print_help();
      exit(EXIT_SUCCESS);
    case 1:
      print_version();
      exit(EXIT_SUCCESS);
    case '?':
      perrorf("unreconized command-line argument '%s'", argv[optind - 1]);
      break;
    default:
      perrorf("unreconized command-line argument '%s'", argv[optind - 1]);
      break;
    }
    options.__parsed = 1;
  }

  plog(INFO "Looking for input files.");
  if (optind >= argc)
    pfatal("no input files.");

  /* file processing */
  /* read file, and set options.F to the char[] of the contents */
  for (int i = optind; i < argc; i++)
  {
    FILE *fp;
    char *buffer;
    long file_size;
    char *path = argv[i];

    /* file pointer */
    fp = fopen(path, "r");

    if (fp == NULL)
      pfatalf("no such file or directory '%s'", path);

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    /* is file small enough (you can increase this limit in config.h) */
    if (file_size >= MAXINPUTBUFFER)
    {
      fclose(fp);
      pfatalf("input buffer exceeds buffer capacity (%d bytes).",
              MAXINPUTBUFFER);
    }
    else if (file_size == 0)
    {
    }

    buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL)
    {
      fclose(fp);
      pfatal("error allocating memory.");
    }

    int elem = fread(buffer, 1, file_size, fp);
    if (elem != file_size)
      pfatalf("error reading file. Expected %d bytes, got %d bytes.", file_size, elem);
    buffer[file_size] = '\0';

    strncpy(options.file, buffer, MAXINPUTBUFFER - 1);
    options.file[MAXINPUTBUFFER - 1] = '\0';

    fclose(fp);
    free(buffer);
  }
  return options;
}

/* ftl is a simple and extensible compiler.
 * Copyright (C) 2024 vx-clutch
 *
 * The file is part of ftl.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions, and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions, and the following disclaimer in the documentation or
 * other materials provided with the distribution.
 * 3. Neither the name of vx-clutch nor the names of its contributors may be
 * used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
