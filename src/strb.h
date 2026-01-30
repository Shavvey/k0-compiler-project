#ifndef INCLUDE_SRC_STR_H_
#define INCLUDE_SRC_STR_H_
#include <stdlib.h>

// StringBuilder is just a arraylist of chars, uses `common.h`
typedef struct {
  char* items;
  size_t capacity;
  size_t size;
} StringBuilder;

typedef enum {
  COPY,
  MOVE
} CopyOrMove;

// API
StringBuilder sb_from_cstring(char *str, CopyOrMove opt);
void sb_chop_by_delim(StringBuilder *sb, const char *delim);
void sb_sub_by_delim(StringBuilder *sb, const char *delim, const char *sub);
char *sb_to_string(StringBuilder *sb, CopyOrMove opt);
void sb_delete(StringBuilder *sb);
#endif  // INCLUDE_SRC_STR_H_
