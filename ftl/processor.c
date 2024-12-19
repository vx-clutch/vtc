#include "processor.h"
#include "config.h"
#include <string.h>

void remove_comments(char *source) {
  for (unsigned long int current_char = 0; current_char < strlen(source);
       current_char++) {
    /* look for a ';;' symbol */
    if (source[current_char] == ';' && source[current_char + 1] == ';') {
      /* if ';;' found set all chars after to '\0' until newline */
      while (source[current_char] != '\n' && source[current_char] != '\0') {
        /* set char to space */
        source[current_char] = ' ';
        current_char++;
      }
    }
  }
}

char *processor(char source[MAXINPUTBUFFER]) {
  /* TODO:
   *  + preprocessor macros
   */

  remove_comments(source);

  return source;
}
