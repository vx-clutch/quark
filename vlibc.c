#define VLIBC_PACKAGE "test-frame"
#include "vlibc.h"

int main(void) {
  string_t str = new_string("Hello ");
  strcat(str, s("World!"));
  vlibc_logf(OK "vlibc");
  vlibc_logf(ERR "vlibc");
  vlibc_logf(WARN "vlibc");
  vlibc_logf(INFO "vlibc");
  vlibc_logf(FATAL "vlibc");
  return 0;
}
