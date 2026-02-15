#include "strb.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
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
  char *str = (char *)malloc((sb->size + 1) * sizeof(char));
  strncpy(str, sb->items, sb->size);
  str[sb->size] = '\0';
  if (opt == MOVE)
    alist_free(sb);
  return str;
}

void sb_chop_by_delim(StringBuilder *sb, const char *delim) {
  size_t window = strnlen(delim, sb->size);
  size_t s = 0;
  while (s < sb->size) {
    if (strncmp(sb->items + s, delim, window) == 0) {
      for (size_t i = 0; i < window; i += 1) {
        alist_delete_at(sb, s);
      }
    } else {
      s += 1;
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
    size_t *items;
    size_t size;
    size_t capacity;
  } SubIndex;
  SubIndex si = {0};
  size_t saved_size = sb->size;
  size_t window = strnlen(delim, saved_size);
  size_t slen = strlen(substr);
  size_t s = 0;
  while (s < sb->size) {
    if (strncmp(sb->items + s, delim, window) == 0) {
      alist_append(&si, s);
      for (size_t i = 0; i < window; i += 1) {
        alist_delete_at(sb, s);
      }
    } else {
      s += 1;
    }
  }
  // Replay the captured inserted indices, use them to insert substr
  for (size_t i = 0; i < si.size; i += 1) {
    size_t iindex = si.items[i];
    // Calculate offset based on written chars in prev itrs
    size_t index = iindex + (slen * i);
    if (sb->size == 0) { // CASE 1: string is empty
      alist_append_many(sb, substr, slen);
    } else if (sb->size <= index) { // CASE 2: index points to last
      alist_append_many(sb, substr, slen);
    } else { // CASE 3: index points somewhere in middle
      for (int j = slen - 1; j >= 0; j -= 1) {
        alist_insert_at(sb, substr[j], index);
      }
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

int sb_has_substr(StringBuilder *sb, const char *str) {
  size_t window = strnlen(str, sb->size);
  for (size_t s = 0; s < sb->size; s += 1) {
    if (strncmp(sb->items + s, str, window) == 0) {
      return 1;
    }
  }
  return 0;
}
