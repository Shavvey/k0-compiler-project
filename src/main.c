#include "lexer.h"
#include "parser.h"

int main(int argc, char **argv) {
  TokenList tl = lex_files(argc, argv);
  ParseTree pt = parse(&tl);
  pt_print_tokens(&pt);
  return EXIT_SUCCESS;
}
