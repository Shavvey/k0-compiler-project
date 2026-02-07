#ifndef INCLUDE_SRC_LEXER_H_
#define INCLUDE_SRC_LEXER_H_

#include "token.h"
#include <stdbool.h>

TokenList lex_files(int argc, char **argv);
#endif  // INCLUDE_SRC_LEXER_H_
