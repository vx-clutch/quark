#define VLIBC_PACKAGE "test-frame"
#define VLIBC_SHORT
#include "vlibc.h"

int main(void) {
  string_t str = new_string("Hello ");
  strcat(str, s("World!"));
  logf(OK "vlibc");
  logf(ERR "vlibc");
  logf(WARN "vlibc");
  logf(INFO "vlibc");
  logf(FATAL "vlibc\n");
  return 0;
}
