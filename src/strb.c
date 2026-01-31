#include "strb.h"
#include "common.h"
#include <stdio.h>
#include <string.h>

StringBuilder sb_from_cstring(char *str, CopyOrMove opt) {
  StringBuilder sb = {0};
  size_t len = strlen(str);
  alist_append_many(&sb, str, len);
  if (opt == MOVE)
    free(str);
  return sb;
}

void sb_append(StringBuilder *sb, const char *str) {
  alist_append_many(sb, str, strlen(str));
}

char *sb_to_cstring(StringBuilder *sb, CopyOrMove opt) {
  char *str = (char *)malloc(sb->size * sizeof(char));
  strncpy(str, sb->items, sb->size);
  str[sb->size] = '\0';
  if (opt == MOVE)
    alist_free(sb);
  return str;
}

void sb_chop_by_delim(StringBuilder *sb, const char *delim) {
  size_t window = strnlen(delim, sb->size);
  for (size_t s = 0; s < sb->size; s += 1) {
    if (strncmp(sb->items + s, delim, window) == 0) {
      for (size_t i = 0; i < window; i += 1) {
        alist_delete_at(sb, s);
      }
    }
  }
}

void sb_print(StringBuilder *sb) {
  // TOOD: Add a way to modify the print format of this function
  printf("%.*s\n", (int)sb->size, sb->items);
}

void sb_sub_by_delim(StringBuilder *sb, const char *delim, const char *substr) {
  // Helper arraylist that records indexes
  typedef struct {
    int *items;
    size_t size;
    size_t capacity;
  } SubIndex;
  SubIndex si = {0};
  int window = strnlen(delim, sb->size);
  size_t slen = strlen(substr);
  for (size_t cursor = 0; cursor < sb->size; cursor += 1) {
    if (strncmp(sb->items + cursor, delim, window) == 0) {
      // Keep track starting indexes of delims
      alist_append(&si, cursor);
      for (int i = 0; i < window; i += 1) {
        alist_delete_at(sb, cursor);
      }
    }
  }
  // Replay cursor captures of starting chopped indexes
  for (size_t ssi = 0; ssi < si.size; ssi += 1) {
    for (int j = slen - 1; j >= 0; j -= 1) {
      // Offset based on what was written by prev iterations
      alist_insert_at(sb, substr[j], si.items[ssi] + (slen - 1) * ssi);
    }
  }
  alist_free(&si);
}

char *sb_to_string(StringBuilder *sb, CopyOrMove opt) {
  char *str = (char *)malloc(sb->size * sizeof(char));
  strncpy(str, sb->items, sb->size);
  if (opt == MOVE)
    alist_free(sb);
  return str;
}

void sb_delete(StringBuilder *sb) { alist_free(sb); }
