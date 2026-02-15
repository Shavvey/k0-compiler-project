#include "lexer.h"
#include "parser.h"

int main(int argc, char **argv) {
  parse(lex_files(argc, argv));
  return EXIT_SUCCESS;
}
