#ifndef VLIBC_STRING_H
#define VLIBC_STRING_H

#include <stdio.h>
typedef struct
{
  char *value;
  int length;
} string;

static string
newString(char *str)
{
  int length = 0;
  for (;;) {
    if (str[length] != '\0') {
      length++;
      continue;
    }
    break;
  }
  string buf;
  buf.value = str;
  buf.length = length;
  return buf;
}

#endif
