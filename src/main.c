#include "lexer.h"
#include "parser.h"

int main(int argc, char **argv) {
  ParseTree pt = parse(lex_files(argc, argv));
  pt_print_tokens(&pt);
  return EXIT_SUCCESS;
}
