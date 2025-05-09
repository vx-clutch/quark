#include "../../include/lib.h"
#include <stdlib.h>
#include <stdarg.h>

void q_exitf(struct q_err err, ...) {
  va_list args;
  va_start(args, err);
  if (err.log) q_logf(FATAL err.msg.as_str, args);
  va_end(args);
  exit(err.code);
}

int q_log(struct q_err err) {
  q_logf(err.level, err.msg.as_str);
  if (err.code) exit(err.code);
  return 0;
}