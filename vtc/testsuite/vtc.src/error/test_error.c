#include "../../../error.h"
#include "../../../parse_args.h"

Options options = {
    .verbose = 1,
    .__parsed = 1,
};

int
main(void)
{
  plog(INFO "info");
  plog(OK "ok");
  plog(WARNING "warning");
  plog(FAILURE "failure");
  plogf(OK "format %s", "foo");
  pdebug("pdebug", "pdebug");
  pdebugf("pdebugf", "pdebug%s", "f");
  pwarning("pwarning");
  pwarningf("pwarning%s", "f");
  perror("perror");
  perrorf("perror%s", "f");
  pfatal("pfatal");
}
