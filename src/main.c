#include "strb.h"
#include <stdio.h>

int main() {
  StringBuilder sb = sb_from_cstring("MovelHHHHHHHH", COPY);
  sb_print(&sb);
  sb_sub_by_delim(&sb, "HHHH", "S");
  sb_print(&sb);
  if (sb_has_substr(&sb, "SS")) {
    printf("Snake Eyes\n");
  }
  sb_chop_by_delim(&sb, "SS");
  char *cstr = sb_to_cstring(&sb, MOVE);
  puts(cstr);
  free(cstr);
  return 0;
}
