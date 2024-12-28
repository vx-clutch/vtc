#include "processor.h"
#include "config.h"
#include <ctype.h>
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

void colapse_whitespace(char *source) {
  int i = 0, j = 0;
  int len = strlen(source);
  int space_found = 0;

  while (i < len) {
    if (!isspace(source[i])) {
      source[j++] = source[i++];
      space_found = 0;
    } else {
      if (!space_found) {
        source[j++] = ' ';
        space_found = 1;
      }
      i++;
    }
  }

  // Remove trailing space if present
  if (j > 0 && source[j - 1] == ' ') {
    j--;
  }

  source[j] = '\0'; // Null-terminate the cleaned string
}

char *processor(char source[MAXINPUTBUFFER]) {
  remove_comments(source);
  colapse_whitespace(source);
  return source;
}
