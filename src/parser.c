#include "parser.h"
#include "k0gram.tab.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

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
  K0_STYPE peek = create_term(token_stream.items + cursor);
  Token token = peek->value.term;
  printf("Peeking token value! %d:%s\n", token.category,
         ytab_ltable[token.category - YTABLE_START]);
  k0_lval = peek;
  cursor += 1;
  return token.category;
}

/* This is a tricky function. Right now, I am trying to use
 * a variatic array of arguments to produce node with an arbitrary
 * ammount of children */
Node *create_nterm(const int prod_rule, char *symbol_name,
                   const int num_children, ...) {
  Node *nterm_parent = malloc(sizeof(Node) * 1);
  nterm_parent->value.nonterm =
      (NonTerminal){.children = (Node **)malloc(sizeof(Node *) * num_children),
                    .num_children = num_children,
                    .prod_rule = prod_rule};
  nterm_parent->is_term = false;
  va_list args;
  va_start(args, num_children);
  for (int i = 0; i < num_children; i += 1) {
    Node *node = va_arg(args, Node *);
    nterm_parent->value.nonterm.children[i] = node;
  }
  va_end(args);
  return nterm_parent;
}

/* If we are tasked to construct a terminal just create a
 * very simple node with a fixed reference to a token (leaf in AST)
 * NOTE: We may want to copy the entire value of the Token,
 * I haven't quite decided yet which is best*/
Node *create_term(Token *token) {
  Node *n = malloc(sizeof(Node) * 1);
  n->value.term = *token;
  n->is_term = true;
  return n;
}
