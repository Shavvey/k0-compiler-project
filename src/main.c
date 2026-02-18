#include "lexer.h"
#include "parser.h"
#include <stdio.h>

int main(int argc, char **argv) {
  TokenList tl = lex_files(argc, argv);
  ParseTree pt = parse(&tl);
  printf("%s\n", pt.root->value.nonterm.symbol_name);
  pt_pretty_print(&pt);
  pt_delete(&pt);
  return EXIT_SUCCESS;
}
