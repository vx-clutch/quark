#include "vlibc/syslog/log.h"
#include "vlibc/syslog/debug.h"
#include "vlibc/syslog/fatal.h"
#include "vlibc/syslog/error.h"
#include "vlibc/syslog/warning.h"

int
main(void)
{
  
  log(INFO "info");
  log(OK "ok");
  log(WARN "warning");
  log(FAIL "failure");
  debug("debug", "debug");
  warning("warning");
  error("error");
  fatal("fatal");
}
