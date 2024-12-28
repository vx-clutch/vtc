#include "module.h"

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
  module.KWORD = "nop";
  module.assembly = "nop";
  return module;
}
