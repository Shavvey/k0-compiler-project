#include "strb.h"
#include "common.h"
#include <stdio.h>
#include <string.h>

StringBuilder sb_from_cstring(char *str, CopyOrMove opt) {
  StringBuilder sb = {0};
  int len = strlen(str);
  alist_append_many(&sb, str, len);
  if (opt == MOVE)
    free(str);
  return sb;
}

char *sb_to_cstring(StringBuilder *sb, CopyOrMove opt) {
  char *str = (char *)malloc(sb->size * sizeof(char));
  strncpy(str, sb->items, sb->size);
  str[sb->size] = '\0';
  if (opt == MOVE)
    free(sb->items);
  return str;
}

void sb_chop_by_delim(StringBuilder *sb, const char *delim) {
  int window = strnlen(delim, sb->size);
  for (int s = 0; s < sb->size; s += 1) {
    if (strncmp(sb->items + s, delim, window) == 0) {
      for (int i = 0; i < window; i += 1) {
        alist_delete_at(sb, s);
      }
    }
  }
}

void sb_sub_by_delim(StringBuilder *sb, const char *delim, const char *substr) {
  typedef struct {
    int *items;
    size_t size;
    size_t capacity;
  } SubIndex;
  SubIndex si = {0};
  int window = strnlen(delim, sb->size);
  int slen = strlen(substr);
  for (int cursor = 0; cursor < sb->size; cursor += 1) {
    if (strncmp(sb->items + cursor, delim, window) == 0) {
      alist_append(&si, cursor); // keep track of delim deletions
      for (int i = 0; i < window; i += 1) {
        alist_delete_at(sb, cursor);
      }
    }
  }
  // replay cursor captures of starting chopped indexes
  for (int ssi = si.size - 1; ssi <= 0; ssi -= 1) {
    printf("Help\n");
    for (int j = 0; j < slen; j += 1) {
      alist_insert_at(sb, substr[j], si.items[ssi]);
    }
  }
}

char *sb_to_string(StringBuilder *sb, CopyOrMove opt);
void sb_delete(StringBuilder *sb);
