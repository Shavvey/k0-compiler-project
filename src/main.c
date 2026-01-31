#include "strb.h"

int main() {
  StringBuilder sb = sb_from_cstring("MovelHHHHHHHH", COPY);
  sb_print(&sb);
  sb_sub_by_delim(&sb, "HHHH", "S");
  sb_print(&sb);
  return 0;
}
