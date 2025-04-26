#define VLIBC_PACKAGE "test-frame"
#include "vlibc.h"

int main(void) {
  vlibc_string_t str = vlibc_new_string("Hello ");
  /*vlibc_strcat(str, s("World!"));*/
  vlibc_logf(OK s("vlibc"));
  vlibc_logf(ERR s("vlibc"));
  vlibc_logf(WARN s("vlibc"));
  vlibc_logf(INFO s("vlibc"));
  vlibc_logf(FATAL s("vlibc"));
  return 0;
}
