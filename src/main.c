#include "strb.h"

int main() {
  StringBuilder sb = sb_from_cstring("What", COPY);
  sb_sub_by_delim(&sb, "Hello", "S");
  sb_print(&sb);
  sb_print(&sb);
  return 0;
}
