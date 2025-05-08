#ifndef Q_ERR_H
#define Q_ERR_H

#include "log.h"
#include "strings.h"

#define EPERM 1
#define ENOENT 2
#define EIO 5
#define EACCES 13
#define EFAULT 14
#define EEXIST 17
#define EISDIR 21
#define ENOTDIR 20
#define ENOSYS 38
#define EROFS 30
#define ENETDOWN 100
#define ENETUNREACH 101
#define ETIMEDOUT 110
#define EHOSTUNREACH 113

struct q_err {
    int code;
    int log;
    int level;
    int errno;
    q_string_t msg;
};

void q_abortf(struct q_err, ...);

#define q_assert(x) if (!(x)) q_abortf(q_err{.code = 1, .log = 1, .level = 1, .msg = q_string(#x)}, "Assertion failed: %s", #x)

#endif // Q_ERR_H