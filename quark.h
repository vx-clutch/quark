#ifndef QUARK_H
#define QUARK_H

#ifndef QUARK_SHORT
#define _mixin_concat(a, b) a##b
#define mixin(name) _mixin_concat(q_, name)
#else
#define mixin(name) name
#endif

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
}

#ifndef QUARK_SHORT
quark_string_t;
#else
string_t;
#endif

#ifndef QUARK_SHORT
#define _quark_string_t quark_string_t
#define s(s) quark_new_string(s)
#else
#define _quark_string_t string_t
#define s(s) new_string(s)
#endif

static _quark_string_t mixin(new_string)(char *src) {
  int length = 0;
  for (;;) {
    if (src[length] != '\0') {
      length++;
      continue;
    }
    break;
  }
  _quark_string_t buf;
  buf.to_str = src;
  buf.len = length;
  return buf;
}

#ifndef QUARK_SHORT
#define _strcpy(d, s) quark_strcpy(d, s)
#else
#define _strcpy(d, s) strcpy(d, s)
#endif

static _quark_string_t mixin(strcpy)(_quark_string_t dest,
                                     _quark_string_t src) {
  dest.to_str = src.to_str;
  dest.len = src.len;
  return dest;
}

#ifndef QUARK_SHORT
#define _strcat(d, s) quark_strcat(d, s)
#else
#define _strcat(d, s) strcat(d, s)
#endif

/*static _quark_string_t mixin(strcat)(_quark_string_t dest,*/
/*                                     _quark_string_t src) {}*/

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

#ifndef QUARK_SHORT
#define _logf(l, s, ...) quark_logf(l, s, __VA_ARGS__)
#else
#define _logf(l, s, ...) logf(l, s, __VA_ARGS__)
#endif

static int mixin(logf)(__level_t level, _quark_string_t src, ...) {
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

#ifndef QUARK_SHORT
#undef s
#endif

#undef mixin
#undef _mixin_concat
#undef _quark_case
#endif
