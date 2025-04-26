#ifndef VLIBC_H
#define VLIBC_H

#ifndef VLIBC_SHORT
#define _mixin_concat(a, b) a##b
#define mixin(name) _mixin_concat(vlibc_, name)
#else
#define mixin(name) name
#endif

#ifndef VLIBC_PACKAGE
#error "macro `VLIBC_PACKAGE` not defined. Store the name of the package here."
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

#ifndef VLIBC_SHORT
vlibc_string_t;
#else
string_t;
#endif

#ifndef VLIBC_SHORT
#define _vlibc_string_t vlibc_string_t
#define s(s) vlibc_new_string(s)
#else
#define _vlibc_string_t string_t
#define s(s) new_string(s)
#endif

static _vlibc_string_t mixin(new_string)(char *src) {
  int length = 0;
  for (;;) {
    if (src[length] != '\0') {
      length++;
      continue;
    }
    break;
  }
  _vlibc_string_t buf;
  buf.to_str = src;
  buf.len = length;
  return buf;
}

#ifndef VLIBC_SHORT
#define _strcpy(d, s) vlibc_strcpy(d, s)
#else
#define _strcpy(d, s) strcpy(d, s)
#endif

static _vlibc_string_t mixin(strcpy)(_vlibc_string_t dest,
                                     _vlibc_string_t src) {
  dest.to_str = src.to_str;
  dest.len = src.len;
  return dest;
}

#ifndef VLIBC_SHORT
#define _strcat(d, s) vlibc_strcat(d, s)
#else
#define _strcat(d, s) strcat(d, s)
#endif

/*static _vlibc_string_t mixin(strcat)(_vlibc_string_t dest,*/
/*                                     _vlibc_string_t src) {}*/

// Logging
static const char *VLIBC_RESET = "[0m";
static const char *VLIBC_RED = "[1;91m";
static const char *VLIBC_YELLOW = "[0;33m";
static const char *VLIBC_GREEN = "[1;32m";
static const char *VLIBC_PURPLE = "[0;95m";
static const char *VLIBC_WHITE = "[0;97m";

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

#define _vlibc_case(message, level_color)                                      \
  case message:                                                                \
    fprintf(stderr, "%s%s%s: %s" #message "%s: ", VLIBC_WHITE, VLIBC_PACKAGE,  \
            VLIBC_RESET, level_color, VLIBC_RESET);                            \
    break;

#ifndef VLIBC_SHORT
#define _logf(l, s, ...) vlibc_logf(l, s, __VA_ARGS__)
#else
#define _logf(l, s, ...) logf(l, s, __VA_ARGS__)
#endif

static int mixin(logf)(__level_t level, _vlibc_string_t src, ...) {
  va_list args;
  va_start(args, src.to_str);
  switch (level) {
    _vlibc_case(ok, VLIBC_GREEN);
    _vlibc_case(error, VLIBC_RED);
    _vlibc_case(warn, VLIBC_YELLOW);
    _vlibc_case(info, VLIBC_PURPLE);
    _vlibc_case(fatal, VLIBC_RED);
  }
  vfprintf(stderr, src.to_str, args);
  printf("\n");
  va_end(args);
  return 0;
}

#ifndef VLIBC_SHORT
#undef s
#endif

#undef mixin
#undef _mixin_concat
#undef _vlibc_case
#endif
