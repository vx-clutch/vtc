#include "processor.h"
#include "config.h"
#include <string.h>

void remove_comments(char *source) {
    for (unsigned long int i = 0; i < strlen(source); i++) {
        if (source[i] == ';' && source[i + 1] == ';') {
            // Loop until a newline is encountered or the end of the string
            while (source[i] != '\n' && source[i] != '\0') {
                source[i] = ' ';  // Replace character with space
                i++;  // Increment i to move to the next character
            }
        }
    }
}

char *processor(char source[MAXINPUTBUFFER]) {
  /* TODO:
   *  + preprocessor macros
   *  + cut comments
   */
  remove_comments(source);
  return source;
}
