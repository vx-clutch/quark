#include "../../include/lib.h"
#include <stdarg.h>
#include <stdio.h>

#define quark_case(message, level_color)                                       \
  case message:                                                                \
    fprintf(stderr, "%s%s%s: %s" #message "%s: ", QUARK_WHITE, QUARK_PACKAGE,  \
            QUARK_RESET, level_color, QUARK_RESET);                            \
    break;

int
q_logf(q_level_t level, char *src, ...)
{
  va_list args;
  va_start(args, src);
  switch (level)
  {
    quark_case(ok, QUARK_GREEN);
    quark_case(error, QUARK_RED);
    quark_case(warn, QUARK_YELLOW);
    quark_case(info, QUARK_PURPLE);
    quark_case(fatal, QUARK_RED);
  case NIL:
    struct q_err errval = {
        .code = 1,
        .level = 1,
        .log = 1,
        .msg = q_new_string("Cannot call q_logf with NIL level")};
    q_abortf(errval);
    break;
  }
  vfprintf(stderr, src, args);
  printf("\n");
  va_end(args);
  return 0;
}

#undef quark_case
