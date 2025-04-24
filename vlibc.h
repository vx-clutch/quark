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

// Strings
typedef struct {
  char *value;
  int length;
}
#ifndef VLIBC_SHORT
vlibc_string_t;
#else
string_t;
#endif

#ifndef VLIBC_SHORT
#define _vlibc_string_t vlibc_string_t
#else
#define _vlibc_string_t string_t
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
  buf.value = src;
  buf.length = length;
  return buf;
}

static _vlibc_string_t mixin(strcat)(_vlibc_string_t dest, _vlibc_string_t src) {
  char *d = dest.value;
  while (*d)
    d++;
  while ((*d++ = *src.value++))
    ;
  return (_vlibc_string_t){
      .value = dest.value,
      .length = dest.length + src.length,
  };
}

// Logging
static const char *VLIBC_RESET = "[0m";
static const char *VLIBC_RED = "[1;91m";
static const char *VLIBC_YELLOW = "[0;33m";
static const char *VLIBC_GREEN = "[1;32m";
static const char *VLIBC_PURPLE = "[0;95m";
static const char *VLIBC_WHITE = "[0;97m";

typedef enum {
  ok,
  error,
  warn,
  info,
  fatal,
} __level_t;

#define vlibc_case(message, level_color)                                       \
  case message:                                                                \
    printf("%s%s%s: %s" #message "%s: ", VLIBC_WHITE, VLIBC_PACKAGE,           \
           VLIBC_RESET, level_color, VLIBC_RESET);                             \
    break;

static int mixin(logf)(__level_t level, char *src, ...) {
  va_list args;
  va_start(args, src);
  switch (level) {
    vlibc_case(ok, VLIBC_GREEN);
    vlibc_case(error, VLIBC_RED);
    vlibc_case(warn, VLIBC_YELLOW);
    vlibc_case(info, VLIBC_PURPLE);
    vlibc_case(fatal, VLIBC_RED);
  }
  vprintf(src, args);
  printf("\n");
  va_end(args);
  return 0;
}

#undef mixin
#endif
