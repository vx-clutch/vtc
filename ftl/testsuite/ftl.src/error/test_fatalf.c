#include "../../../error.h"
#include "../../../parse_args.h"

Options options = {
    .verbose = 1,
    .__parsed = 1,
};

int
main(void)
{
  pfatalf("pfatal%s", "f");
}
