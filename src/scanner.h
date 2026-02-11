#ifndef INCLUDE_SRC_SCANNER_H_
#define INCLUDE_SRC_SCANNER_H_

#include "token.h"
#include <stdbool.h>

TokenList scan_files(int argc, char **argv);
#endif  // INCLUDE_SRC_SCANNER_H_
