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
  print_tokens(&token_stream);
  int res = k0_parse();
  if (res == 0) {
    printf("Somehow parsing worked!\n");
  }
  delete_tokens(&tl);
  return (ParseTree){0};
}

/* I can't believe this works, kind of */
int k0_lex() {
  if (cursor == token_stream.size) {
    return K0_EMPTY;
  }
  K0_STYPE peek = token_stream.items[cursor];
  printf("Peeking token value! %d:%s\n", peek.category,
         ytab_ltable[peek.category - YTABLE_START]);
  k0_lval = peek;
  cursor += 1;
  return peek.category;
}
