#include "parser.h"
#include "common.h"
#include "k0gram.tab.h"
#include "strb.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int k0_error(ParserContext *pc, const char *msg) {
  printf("Tree root address: %p\n", pc->pt.root);
  fprintf(stderr, "[PARSE ERROR] => Occured during parsing: %s\n", msg);
  exit(EXIT_FAILURE);
}

ParseTree parse(TokenList *tl) {
  /* Once we begin parsing, we have an auxillary struct
   that helps manage the current state of the tree
   and the next token that will be placed inside it */
  ParserContext pc = {.tl = tl, .pt = {0}, .cursor = 0};
  print_tokens(tl);
  int res = k0_parse(&pc);
  if (res == 0) {
    printf("Somehow parsing worked!\n");
  }
  // NOTE: TokenList will be "consumed", into ParseTree
  // So, we should free any references it holds
  free(tl->items); // mem "owned" by AST now
  return pc.pt;
}

/* Recursive traversal of AST root that will visit
 * all the terminals/tokens and print them out */
static void root_print_tokens(const Node *root) {
  bool is_term = root->is_term;
  /* NOTE: root value either stores term or nonterm
   * `is_term` acts as flag to access the union properly (see parser.h)
   **/
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
static void root_syntax_tree(const Node *root, StringBuilder *sb, int depth) {

  // first account for depth
  for (int i = 0; i < depth - 1; i += 1) {
    sb_append(sb, "    ");
  }
  if (depth > 0) sb_append(sb, "├── ");
  bool is_term = root->is_term;
  if (is_term) {
    Terminal term = root->value.term;
    sb_append(sb, ytab_ltable[term.category - YTABLE_START]);
    sb_append(sb, "\n");
  } else {
    NonTerminal nterm = root->value.nonterm;
    sb_append(sb, nterm.symbol_name);
    sb_append(sb, "\n");
    for (int i = 0; i < nterm.num_children; i += 1) {
      Node *child = nterm.children[i];
      root_syntax_tree(child, sb, depth+1);
    }
  }
}

void pt_pretty_print(const ParseTree *pt) {
  if (pt == NULL) {
    wprintf("Given tree with nil root!\n");
  } else {
    StringBuilder sb = {0};
    root_syntax_tree(pt->root, &sb, 0);
    char *syntax_tree = sb_to_cstring(&sb, MOVE);
    puts(syntax_tree);
    free(syntax_tree);
  }
}

void pt_print_tokens(const ParseTree *pt) {
  if (pt == NULL) {
    wprintf("Given tree with nil root!\n");
  } else {
    root_print_tokens(pt->root);
  }
}

static void root_delete(Node *root) {
  bool is_term = root->is_term;
  if (!is_term) {
    NonTerminal nterm = root->value.nonterm;
    for (int i = 0; i < nterm.num_children; i += 1) {
      // destroy all children first
      root_delete(nterm.children[i]);
    }
    free(nterm.children);
    free(root);
  } else {
    // destroy terminal
    Terminal nt = root->value.term;
    free(nt.lexeme);
    free(nt.filename);
    free(nt.val.sval);
    free(root);
  }
}

void pt_delete(ParseTree *pt) {
  if (pt == NULL) {
    wprintf("Given tree with nil root!\n");
  } else {
    root_delete(pt->root);
  }
}

/* I can't believe this works, kind of */
int k0_lex(ParserContext *pc) {
  if (pc->cursor == pc->tl->size)
    return K0_EOF; // emit EOF symbol if tl tokens are exhausted
  // peek token from tl based on cursor position
  Token *peek = pc->tl->items + pc->cursor;
  printf("Peeking token value! %d:%s\n", peek->category,
         ytab_ltable[peek->category - YTABLE_START]);
  k0_lval = create_term(peek);
  pc->cursor += 1;
  return peek->category;
}

/* This is a tricky function. Right now, I am trying to use
 * a variatic array of arguments to produce an AST node with an arbitrary
 * ammount of children */
Node *create_nterm(const int prod_rule, char *symbol_name,
                   const int num_children, ...) {
  Node *nterm_parent = malloc(sizeof(Node) * 1);
  nterm_parent->value.nonterm =
      (NonTerminal){.children = (Node **)malloc(sizeof(Node *) * num_children),
                    .num_children = num_children,
                    .prod_rule = prod_rule,
                    .symbol_name = symbol_name};
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
  printf("Creating new term for %d!\n", token->category);
  Node *n = malloc(sizeof(Node) * 1);
  n->value.term = *token; // WARN: shallow copy
  n->is_term = true;
  return n;
}
