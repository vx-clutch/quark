#include <stdarg.h>
#include <stdio.h>
#include "../../include/log.h"

#ifndef QUARK_PACKAGE
#define QUARK_PACKAGE "quarks"
#endif

static const char *QUARK_RESET = "[0m";
static const char *QUARK_RED = "[1;91m";
static const char *QUARK_YELLOW = "[0;33m";
static const char *QUARK_GREEN = "[1;32m";
static const char *QUARK_PURPLE = "[0;95m";
static const char *QUARK_WHITE = "[0;97m";

#define OK ok,
#define ERR error,
#define WARN warn,
#define INFO info,
#define FATAL fatal,

typedef enum {
  ok,
  error,
  warn,
  info,
  fatal,
} q_level_t;

#define quark_case(message, level_color)                                       \
  case message:                                                                \
    fprintf(stderr, "%s%s%s: %s" #message "%s: ", QUARK_WHITE, QUARK_PACKAGE,  \
            QUARK_RESET, level_color, QUARK_RESET);                            \
    break;

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
