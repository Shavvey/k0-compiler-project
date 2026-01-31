#include "strb.h"
#include <stdio.h>

int main() {
  StringBuilder sb = sb_from_cstring("Hello, World\n Hello", COPY);
  sb_sub_by_delim(&sb, "Hello", "Hell");
  char *str = sb_to_cstring(&sb, MOVE);
  printf("%s\n", str);
  return 0;
}
