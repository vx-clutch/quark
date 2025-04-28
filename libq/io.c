#include "../quarks.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>

int q_write_string(q_string_t path, q_string_t format, ...) {
  va_list args;
  va_start(args, format);
  FILE *fp;
  fp = fopen(path.as_str, "w");
  if (!fp)
    q_logf_char(FATAL "failed to open %s.", path.as_str);
  vfprintf(fp, format.as_str, args);
  fclose(fp);
  va_end(args);
  return 0;
}

int q_write_char(char *path, char *format, ...) {
  va_list args;
  va_start(args, format);
  FILE *fp;
  fp = fopen(path, "w");
  if (!fp)
    q_logf_char(FATAL "failed to open %s.", path);
  vfprintf(fp, format, args);
  fclose(fp);
  va_end(args);
  return 0;
}

struct stat st = {0};

int q_mkdir_string(q_string_t path) {
  if (stat(path.as_str, &st) != -1) {
    q_logf_char(WARN "directory %s already exists", path.as_str);
    return 17; // TODO: use EEXIST
  }
  int err = mkdir(path.as_str, 0700);
  if (err) {
    q_logf_char(FATAL "failed to make directory at %s", path.as_str);
  }
  return 0;
}

int q_mkdir_char(char *path) {
  if (stat(path, &st) != -1) {
    q_logf_char(WARN "directory %s already exists", path);
    return 17; // TODO: use EEXIST
  }
  int err = mkdir(path, 0700);
  if (err) {
    q_logf_char(FATAL "failed to make directory at %s", path);
  }
  return 0;
}
