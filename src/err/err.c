#include "../../include/lib.h"
#include <stdlib.h>
#include <stdarg.h>

void q_abortf(struct q_err err, ...) {
  va_list args;
  va_start(args, err);
  if (err.log) q_logf(FATAL err.msg.as_str, args);
  va_end(args);
  exit(err.code);
}