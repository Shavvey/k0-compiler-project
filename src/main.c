#include "lexer.h"
#include "token.h"

int main(int argc, char **argv) {
  TokenList tl = lex_files(argc, argv);
  print_tokens(&tl);
  delete_tokens(&tl);
  return EXIT_SUCCESS;
}
