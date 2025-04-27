#include "quarks.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void test_strings() {
  printf("%s[STRING TESTS]%s\n", QUARK_PURPLE, QUARK_RESET);

  q_string_t hello = q_new_string("Hello");
  q_string_t world = q_new_string("World");

  printf("hello: %s (len %d)\n", hello.as_str, hello.len);
  printf("world: %s (len %d)\n", world.as_str, world.len);

  q_string_t copy = q_strcpy(hello, world);
  printf("copy: %s\n", copy.as_str);

  q_string_t combined = q_strcat(hello, world);
  printf("combined: %s\n", combined.as_str);

  q_string_t cmp_result = q_strcmp(hello, world);
  printf("comparison result: %d\n", *(int *)(&cmp_result));

  free(hello.as_str);
  free(world.as_str);
  free(copy.as_str);
  free(combined.as_str);
  free(cmp_result.as_str);
}

void test_logging() {
  printf("%s[LOGGING TESTS]%s\n", QUARK_PURPLE, QUARK_RESET);

  q_string_t msg = q_new_string("This is a q_string_t log message.");

  q_logf(OK msg);
  q_logf(ERR "This is an error log.");
  q_logf(WARN "This is a warning log.");
  q_logf(INFO "This is an info log.");
  q_logf(FATAL "This is a fatal log.");

  free(msg.as_str);
}

void test_files() {
  printf("%s[FILE TESTS]%s\n", QUARK_PURPLE, QUARK_RESET);

  q_string_t filename = q_new_string("test_output.txt");
  q_string_t content = q_new_string("Hello from Quarks!");

  if (q_write_string(filename, content) != 0) {
    printf("%sFailed to write string to file%s\n", QUARK_RED, QUARK_RESET);
  }

  if (q_write_char("test_output2.txt", "Another hello!") != 0) {
    printf("%sFailed to write char to file%s\n", QUARK_RED, QUARK_RESET);
  }

  if (q_mkdir_char("test_dir") != 0) {
    printf("%sFailed to create directory%s\n", QUARK_RED, QUARK_RESET);
  }

  q_string_t dir_name = q_new_string("test_dir2");
  if (q_mkdir_string(dir_name) != 0) {
    printf("%sFailed to create directory%s\n", QUARK_RED, QUARK_RESET);
  }

  free(filename.as_str);
  free(content.as_str);
  free(dir_name.as_str);
}

int main() {
  test_strings();
  test_logging();
  test_files();
  printf("%sAll tests completed.%s\n", QUARK_GREEN, QUARK_RESET);
  return 0;
}
