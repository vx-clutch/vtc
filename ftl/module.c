#include "module.h"
#include <string.h>

module get_module(const char *source) {
  /* ex: a NOP module
   * `input`
   * KWORD::nop;
   *  nop
   *
   * `output`
   * module.KWORD = "nop"
   * module.assembly = "\tnop"
   * module.macro = [...]
   */
  module module;
  memset(&module, 0, sizeof(module));
  const char *start = strstr(source, "KWORD::");
  if (start) {
    start += 7;
    const char *end = strchr(start, ';');
    if ((long unsigned int)(end && (end - start)) < sizeof(module.KWORD)) {
      strncpy(module.KWORD, start, end - start);
      module.KWORD[end - start] = '\0';
    }
  }
  return module;
}
