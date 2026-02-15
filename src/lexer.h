#ifndef INCLUDE_SRC_SCANNER_H_
#define INCLUDE_SRC_SCANNER_H_

#include "token.h"
#include <stdbool.h>

TokenList lex_files(int argc, char **argv);
Token get_next_token();
#endif  // INCLUDE_SRC_SCANNER_H_
