#include "common.h"
#include "strb.h"
#include <string.h>

StringBuilder sb_from_cstring(char *str, CopyOrMove opt) {
  StringBuilder sv = {0};
  int len = strlen(str);
  alist_append_many(&sv, str, len);
  if (opt == MOVE) free(str);
  return sv;
}

void sb_chop_by_delim(StringBuilder *sb, const char *delim);
void sb_sub_by_delim(StringBuilder *sb, const char *delim, const char *substr);
char *sb_to_string(StringBuilder *sb, CopyOrMove opt);
void sb_delete(StringBuilder *sb);
