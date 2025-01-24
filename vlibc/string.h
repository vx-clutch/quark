#ifndef VLIBC_STRING_H
#define VLIBC_STRING_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char *value;
  int length;
} string;

static string
newString(char *src)
{
  int length = 0;
  for (;;)
  {
    if (src[length] != '\0')
    {
      length++;
      continue;
    }
    break;
  }
  string buf;
  buf.value = src;
  buf.length = length;
  return buf;
}

static string
strcat(string dest, string src)
{
  char *d = dest.value;
  while (*d) d++;
  while ((*d++ = *src.value++));
  return (string){
      .value = dest.value,
      .length = dest.length + src.length,
  };
}

#endif
