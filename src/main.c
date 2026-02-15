#include "lexer.h"
#include "parser.h"
#include <stdio.h>

int main(int argc, char **argv) {
  ParseTree ps = parse(lex_files(argc, argv));
  printf("Should be false! %d\n", ps.root->is_term);
  printf("Root token name: %s\n", ps.root->value.nonterm.symbol_name);
  return EXIT_SUCCESS;
}
