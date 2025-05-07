#ifndef Q_STRINGS_H
#define Q_STRINGS_H

typedef struct {
  char *as_str;
  int len;
} q_string_t;

q_string_t q_new_string(char *);
q_string_t q_strcpy(q_string_t *, q_string_t *);
q_string_t q_strcat(q_string_t *, q_string_t *);
q_string_t q_strcmp(q_string_t *, q_string_t *);

#endif // Q_STRINGS_H
