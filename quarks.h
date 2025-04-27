#ifndef QUARK_H
#define QUARK_H

#ifndef QUARK_PACKAGE
#error "macro `QUARK_PACKAGE` not defined. Store the name of the package here."
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// Strings
typedef struct {
  char *to_str;
  int len;
} q_string_t;

static q_string_t new_string(char *src) {
  int length = 0;
  for (;;) {
    if (src[length] != '\0') {
      length++;
      continue;
    }
    break;
  }
  q_string_t buf;
  buf.to_str = src;
  buf.len = length;
  return buf;
}

static q_string_t strcpy(q_string_t dest, q_string_t src) {
  dest.to_str = src.to_str;
  dest.len = src.len;
  return dest;
}

/*static q_string_t strcat)(q_string_t dest,*/
/*                                     q_string_t src) {}*/

// Logging
static const char *QUARK_RESET = "[0m";
static const char *QUARK_RED = "[1;91m";
static const char *QUARK_YELLOW = "[0;33m";
static const char *QUARK_GREEN = "[1;32m";
static const char *QUARK_PURPLE = "[0;95m";
static const char *QUARK_WHITE = "[0;97m";

// __level_t mappings
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
} __level_t;

#define _quark_case(message, level_color)                                      \
  case message:                                                                \
    fprintf(stderr, "%s%s%s: %s" #message "%s: ", QUARK_WHITE, QUARK_PACKAGE,  \
            QUARK_RESET, level_color, QUARK_RESET);                            \
    break;

static int logf(__level_t level, q_string_t src, ...) {
  va_list args;
  va_start(args, src.to_str);
  switch (level) {
    _quark_case(ok, QUARK_GREEN);
    _quark_case(error, QUARK_RED);
    _quark_case(warn, QUARK_YELLOW);
    _quark_case(info, QUARK_PURPLE);
    _quark_case(fatal, QUARK_RED);
  }
  vfprintf(stderr, src.to_str, args);
  printf("\n");
  va_end(args);
  return 0;
}

#undef mixin
#undef _mixin_concat
#undef _quark_case
#endif
