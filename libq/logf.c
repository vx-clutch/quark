#include "../quarks.h"

#include <stdarg.h>
#include <stdio.h>

#define quark_case(message, level_color)                                      \
  case message:                                                                \
    fprintf(stderr, "%s%s%s: %s" #message "%s: ", QUARK_WHITE, QUARK_PACKAGE,  \
            QUARK_RESET, level_color, QUARK_RESET);                            \
    break;

int q_logf_string(q_level_t level, q_string_t src, ...) {
  va_list args;
  va_start(args, src.as_str);
  switch (level) {
    quark_case(ok, QUARK_GREEN);
    quark_case(error, QUARK_RED);
    quark_case(warn, QUARK_YELLOW);
    quark_case(info, QUARK_PURPLE);
    quark_case(fatal, QUARK_RED);
  }
  vfprintf(stderr, src.as_str, args);
  printf("\n");
  va_end(args);
  return 0;
}

int q_logf(q_level_t level, char *src, ...) {
  va_list args;
  va_start(args, src);
  switch (level) {
    quark_case(ok, QUARK_GREEN);
    quark_case(error, QUARK_RED);
    quark_case(warn, QUARK_YELLOW);
    quark_case(info, QUARK_PURPLE);
    quark_case(fatal, QUARK_RED);
  }
  vfprintf(stderr, src, args);
  printf("\n");
  va_end(args);
  return 0;
}


#undef quark_case
