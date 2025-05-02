#ifndef QUARK_H
#define QUARK_H

// Strings
typedef struct {
  char *as_str;
  int len;
} q_string_t;

q_string_t q_new_string(char *);
q_string_t q_strcpy(q_string_t *, q_string_t *);
/*q_string_t q_strcat(q_string_t, q_string_t);*/
/*q_string_t q_strcmp(q_string_t, q_string_t);*/

#define qstr(x) q_new_string(x)

// Logging
#ifndef QUARK_PACKAGE
#define QUARK_PACKAGE "quarks"
#endif

static const char *QUARK_RESET = "[0m";
static const char *QUARK_RED = "[1;91m";
static const char *QUARK_YELLOW = "[0;33m";
static const char *QUARK_GREEN = "[1;32m";
static const char *QUARK_PURPLE = "[0;95m";
static const char *QUARK_WHITE = "[0;97m";

#define OK ok,
#define ERR error,
#define WARN warn,
#define INFO info,
#define FATAL fatal,

typedef enum {
  ok,
  error,
  warn,
  info,
  fatal,
} q_level_t;

int q_logf_string(q_level_t, q_string_t, ...);
int q_logf_char(q_level_t, char *, ...);

#define q_logf(X, K, ...) _Generic((K), \
  q_string_t : q_logf_string,           \
  char *     : q_logf_char              \
)(X, K, ##__VA_ARGS__)

// Files
int q_write_string(q_string_t, q_string_t, ...);
int q_write(char *, char *, ...);
int q_mkdir_string(q_string_t);
int q_mkdir(char *);

#endif // QUARKS_H

