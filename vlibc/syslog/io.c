#include "io.h"
#include <stdarg.h>
#include <stdio.h>

int
printfn(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
  putchar('\n');
  return 0;
}
