#include "../include/strings.h"

q_string_t q_new_string(char *src) {
  int length = 0;
  for (;;) {
    if (src[length] != '\0') {
      length++;
      continue;
    }
    break;
  }
  q_string_t buf;
  buf.as_str = src;
  buf.len = length;
  return buf;
}

q_string_t q_strcpy(q_string_t *dest, q_string_t *src) {
  dest->as_str = src->as_str;
  dest->len = src->len;
  return *dest;
}
