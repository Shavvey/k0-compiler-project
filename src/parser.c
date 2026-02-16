#include "parser.h"
#include "k0gram.tab.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k0_error(ParseTree *pt, const char *msg) {
  fprintf(stderr, "[PARSE ERROR]: Occured when parsing %s\n:", msg);
  exit(EXIT_FAILURE);
}

TokenList token_stream = {0}; // EVIL
size_t cursor = 0;

ParseTree parse(TokenList tl) {
  token_stream = tl;
  print_tokens(&token_stream);
  // create helper parser status, which will allow us to dummp
  // the in progress tree if needed
  ParseTree pt = {0};
  int res = k0_parse(&pt);
  if (res == 0) {
    printf("Somehow parsing worked!\n");
  }
  return pt;
}

static void root_print_tokens(const Node *root) {
  bool is_term = root->is_term;
  if (is_term) {
    Terminal term = root->value.term;
    printf("Found token: %d\n", term.category);
    return;
  } else {
    NonTerminal nterm = root->value.nonterm;
    for (int i = 0; i < nterm.num_children; i += 1) {
      root_print_tokens(nterm.children[i]);
    }
  }
}

void pt_print_tokens(const ParseTree *pt) { root_print_tokens(pt->root); }


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
 * a variatic array of arguments to produce an AST node with an arbitrary
 * ammount of children */
Node *create_nterm(const int prod_rule, char *symbol_name,
                   const int num_children, ...) {
  Node *nterm_parent = malloc(sizeof(Node) * 1);
  int len = strlen(symbol_name);
  char *copy_symbol_name = (char *)malloc(sizeof(char) * (len + 1));
  copy_symbol_name[len] = '\0';
  strcpy(copy_symbol_name, symbol_name);
  nterm_parent->value.nonterm =
      (NonTerminal){.children = (Node **)malloc(sizeof(Node *) * num_children),
                    .num_children = num_children,
                    .prod_rule = prod_rule,
                    .symbol_name = copy_symbol_name};
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
