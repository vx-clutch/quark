#define QUARK_PACKAGE "test-frame"
#include "quarks.h"

int main(void) {
  q_string_t str = q_new_string("Hello ");
  q_logf_char(OK "quark");
  q_logf_char(ERR "quark");
  q_logf_char(WARN "quark");
  q_logf_char(INFO "quark");
  q_logf_char(FATAL "quark");
  return 0;
}
