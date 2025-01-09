// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "error.h"
#include <stdio.h>

int
__pdebug(int line, const char *file, const char *desc, const char *message)
{
  if (!options.debug)
    return 0;
  printf("%s%s%s: %sdebug: %s:%d%s: %s: %s\n", WHITE, COMPILER_NAME, RESET,
         WHITE, file, line, RESET, desc, message);
  return 0;
}

int
__pdebugf(int line, const char *file, const char *desc, const char *format, ...)
{
  if (!options.debug)
    return 0;
  va_list args;
  va_start(args, format);
  printf("%s%s%s: %sdebug: %s:%d%s: ", WHITE, COMPILER_NAME, RESET, WHITE, file,
         line, RESET);
  fprintf(stdout, "%s: ", desc);
  vfprintf(stdout, format, args);
  putchar('\n');
  va_end(args);
  return 0;
}

/* vtc is a simple and extensible compiler.
 * Copyright (C) 2024 vx-clutch
 *
 * The file is part of vtc.
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
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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
