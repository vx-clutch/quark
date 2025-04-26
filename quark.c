#define QUARK_PACKAGE "test-frame"
#include "quark.h"

int main(void) {
  quark_string_t str = quark_new_string("Hello ");
  /*quark_strcat(str, s("World!"));*/
  quark_logf(OK s("quark"));
  quark_logf(ERR s("quark"));
  quark_logf(WARN s("quark"));
  quark_logf(INFO s("quark"));
  quark_logf(FATAL s("quark"));
  return 0;
}
