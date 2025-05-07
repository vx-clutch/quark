#ifndef Q_ERR_H
#define Q_ERR_H

#include "log.h"
#include "strings.h"

struct q_err {
    int code;
    int log;
    int level;
    q_string_t msg;
};

void q_abortf(struct q_err, ...);

#define q_assert(x) if (!(x)) q_abortf(q_err{.code = 1, .log = 1, .level = 1, .msg = q_string(#x)}, "Assertion failed: %s", #x)

#endif // Q_ERR_H