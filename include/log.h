#ifndef Q_LOG_H
#define Q_LOG_H

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
  NIL,
} q_level_t;

int q_logf(q_level_t, char *, ...); // q_logf(OK Hello, World!);

#endif // Q_LOG_H
