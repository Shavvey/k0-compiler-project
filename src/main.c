#include "strb.h"

int main() {
  StringBuilder sb = sb_from_cstring("Hello, World\n Hello", COPY);
  sb_sub_by_delim(&sb, "Hello", "Hell");
  sb_print(&sb);
  StringBuilder sb1 = sb_from_cstring("Hello, World\n Hello", COPY);
  sb_chop_by_delim(&sb1, "Hello");
  return 0;
}
