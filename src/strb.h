#ifndef INCLUDE_SRC_STR_H_
#define INCLUDE_SRC_STR_H_
#include <stdlib.h>

// StringBuilder is just a arraylist of chars, uses `common.h`
typedef struct {
  char* items;
  int capacity;
  int size;
} StringBuilder;

typedef enum {
  COPY,
  MOVE
} CopyOrMove;

// API
StringBuilder sb_from_cstring(char *str, CopyOrMove opt);
void sb_chop_by_delim(StringBuilder *sb, const char *delim);
void sb_sub_by_delim(StringBuilder *sb, const char *delim,
                     const char *substr);
char *sb_to_cstring(StringBuilder *sb, CopyOrMove opt);
void sb_delete(StringBuilder *sb);
void sb_print(StringBuilder *sb);
#endif  // INCLUDE_SRC_STR_H_
