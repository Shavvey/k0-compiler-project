#include "strb.h"
#include <stdio.h>

int main() {
  printf("Hello\n");
  StringBuilder sb = sb_from_cstring("Hello, World\n Hello", COPY);
  sb_print(&sb);
  sb_sub_by_delim(&sb, "Hello", "Hell");
  sb_append(&sb, "Append all of this at the end!");
  sb_print(&sb);
  return 0;
}
