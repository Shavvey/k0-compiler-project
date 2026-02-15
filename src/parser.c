#include "parser.h"
#include "k0gram.tab.h"
#include "token.h"
#include <stdio.h>

int k0_error(char *s) {
  fprintf(stderr, "[PARSE ERROR]: %s\n", s);
  exit(EXIT_FAILURE);
}

TokenList token_stream = {0}; // EVIL
size_t cursor = 0;

ParseTree parse(TokenList tl) {
  token_stream = tl;
  int res = k0_lex();
  if (res) {
    printf("Parsing was successful!\n");
  } else {
    printf("[ERROR]: Something went wrong!\n");
  }
  delete_tokens(&tl);
  return (ParseTree){0};
}

/* I can't believe this works */
int k0_lex() {
  if (cursor == token_stream.size) {
    return K0_EMPTY;
  }
  K0_STYPE peek = token_stream.items[cursor];
  cursor += 1;
  return peek.category;
}
