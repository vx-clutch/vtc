// Copyright (C) 2024 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "config.h"
#include "lexer.h"
#include "output.h"
#include "parse_args.h"
#include "processor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* kill_proc either prints to stdout, or to the set file in the options struct
 * then exits with status code 0 */
void
kill_proc(Options options, char *source)
{
  if (options.output[0] == '\0')
  {
    (void)printf("%s\n", source);
    exit(0);
  }
  FILE *fp;
  fp = fopen(options.output, "w");
  fprintf(fp, "%s", source);
  fclose(fp);
  exit(0);
}

int
toplev(int argc, char **argv)
{
  char *source;
  plog("parsing args", 0);
  parse_args(argc, argv);
  source = options.file;
  source = processor(source);
  if (options.expanded)
  {
    plog("-E was passed.", 1);
    kill_proc(options, source);
  }
  Lexer lexer = {source, 0};
  Token token_buffer[MAXTOKENS];
  int i = 0;

  /* iterate over source and get tokens */
  while (1)
  {
    Token token = next_token(&lexer);

    token_buffer[i] = token;

    if (token.type == EOF)
    {
      free_token(&token);
      break;
    }

    free_token(&token);
    i++;
  }

  Token tokens[i];

  /* takes the first i elemets in token_buffer and place them in the
   * corresponding place in tokens */
  for (int j = 0; j < i; j++)
    tokens[i] = token_buffer[i];

  return 0;
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
