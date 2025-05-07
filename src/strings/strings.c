#include "../../include/strings.h"

#define Q_NULL ((void *) 0)

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

q_string_t q_strcat(q_string_t *dest, q_string_t *src) {
  q_strcpy(q_string_t.as_str + q_string_t.len, src);
  dest->len += src->len;
  return *dest;
}

int q_strcmp(q_string_t *a, q_string_t *b) {
  if (a->len != b->len) {
    return 1;
  }
  for (int i = 0; i < a->len; i++) {
    if (a->as_str[i] != b->as_str[i]) {
      return 1;
    }
  }
  return 0;
}