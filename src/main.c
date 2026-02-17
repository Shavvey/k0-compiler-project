#include "lexer.h"
#include "parser.h"

int main(int argc, char **argv) {
  TokenList tl = lex_files(argc, argv);
  ParseTree pt = parse(&tl);
  pt_pretty_print(&pt);
  pt_delete(&pt);
  return EXIT_SUCCESS;
}
