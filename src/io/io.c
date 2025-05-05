#include "../../include/log.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>

int q_write(char *path, char *format, ...) {
  va_list args;
  va_start(args, format);
  FILE *fp;
  fp = fopen(path, "w");
  if (!fp)
    q_logf(FATAL "failed to open %s.", path);
  vfprintf(fp, format, args);
  fclose(fp);
  va_end(args);
  return 0;
}

struct stat st = {0};

int q_mkdir(char *path) {
  if (stat(path, &st) != -1) {
    q_logf(WARN "directory %s already exists", path);
    return 17; // TODO: use EEXIST
  }
  int err = mkdir(path, 0700);
  if (err) {
    q_logf(FATAL "failed to make directory at %s", path);
  }
  return 0;
}
