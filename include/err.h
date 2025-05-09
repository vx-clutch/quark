#ifndef Q_ERR_H
#define Q_ERR_H

#include "log.h"
#include "strings.h"

struct q_err {
    int code;
    int log;
    int errno;
    int line;
    q_level_t level;
    q_string_t msg;
    q_string_t source;
    q_string_t context;
    q_string_t func;
    void *metadata;
};

void q_exitf(struct q_err, ...);
int q_log(struct q_err);

#endif // Q_ERR_H