// Copyright (C) 2024 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "processor.h"
#include "config.h"
#include <ctype.h>
#include <string.h>

void
remove_comments(char *source)
{
  for (unsigned long int current_char = 0; current_char < strlen(source);
       current_char++)
  {
    /* look for a ';;' symbol */
    if (source[current_char] == ';' && source[current_char + 1] == ';')
    {
      /* if ';;' found set all chars after to '\0' until newline */
      while (source[current_char] != '\n' && source[current_char] != '\0')
      {
        /* set char to space */
        source[current_char] = ' ';
        current_char++;
      }
    }
  }
}

void
colapse_whitespace(char *source)
{
  int i = 0, j = 0;
  int len = strlen(source);
  int space_found = 0;

  while (i < len)
  {
    if (!isspace(source[i]))
    {
      source[j++] = source[i++];
      space_found = 0;
    }
    else
    {
      if (!space_found)
      {
        source[j++] = ' ';
        space_found = 1;
      }
      i++;
    }
  }

  // Remove trailing space if present
  if (j > 0 && source[j - 1] == ' ')
    j--;

  source[j] = '\0'; // Null-terminate the cleaned string
}

char *
processor(char source[MAXINPUTBUFFER])
{
  remove_comments(source);
  colapse_whitespace(source);
  return source;
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
