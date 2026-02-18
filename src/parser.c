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
  // TODO: implement a proper cleanup routine here!
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

typedef struct {
  bool *items;
  size_t size;
  size_t capacity;
} TreeStatus;

static void root_syntax_tree(const Node *root, StringBuilder *sb, bool is_end,
                             TreeStatus *ts) {
  // first account for depth
  for (size_t s = 1; s < ts->size; s += 1) {
    bool is_ongoing = ts->items[s];
    (is_ongoing) ? sb_append(sb, "│   ") : sb_append(sb, "    ");
  }

  if (ts->size > 0)
    (is_end) ? sb_append(sb, "└── ") : sb_append(sb, "├── ");

  bool is_term = root->is_term;
  if (is_term) {
    Terminal term = root->value.term;
    sb_append(sb, ytab_ltable[term.category - YTABLE_START]);
    // NOTE: print out integer code for debugging purposes
    // char *str = (char *)malloc(sizeof(char) * 5);
    // snprintf(str, 5, ":%d", term.category);
    // sb_append(sb, str);
    // free(str);
    sb_append(sb, "\n");
  } else {
    NonTerminal nterm = root->value.nonterm;
    alist_append(ts, true);
    if (is_end) {
      alist_delete_last(ts);
      alist_append(ts, false);
    }
    sb_append(sb, nterm.symbol_name);
    sb_append(sb, "\n");
    for (int i = 0; i < nterm.num_children - 1; i += 1) {
      Node *child = nterm.children[i];
      root_syntax_tree(child, sb, false, ts);
    }
    if (nterm.num_children > 0) {
      root_syntax_tree(nterm.children[nterm.num_children - 1], sb, true, ts);
    }
    alist_delete_last(ts);
  }
}

void pt_pretty_print(const ParseTree *pt) {
  if (pt == NULL) {
    wprintf("Given tree with nil root!\n");
  } else {
    StringBuilder sb = {0};
    TreeStatus ts = {0};
    root_syntax_tree(pt->root, &sb, false, &ts);
    char *syntax_tree = sb_to_cstring(&sb, MOVE);
    puts(syntax_tree);
    alist_free(&ts);
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
    if (nt.category == STRINGLITERAL)
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

/* This is called from `k0_parse` during shift actions */
int k0_lex(ParserContext *pc) {
  if (pc->cursor == pc->tl->size)
    return K0_EOF; // emit EOF symbol if tl tokens are exhausted
  // Peek token from tl based on cursor position
  Token *peek = pc->tl->items + pc->cursor;
  // Construct terminal (token) from peeked value
  // NOTE: shallow copy is happening here, be wary of this during cleanup if
  // parsing fails
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
                    .prod_rule = prod_rule,
                    .symbol_name = symbol_name};
  nterm_parent->is_term = false;
  // first determine all children passed that are not null
  size_t non_null_idx = 0;
  va_list args;
  va_start(args, num_children);
  for (int i = 0; i < num_children; i += 1) {
    Node *node = va_arg(args, Node *);
    if (node != NULL) {
      nterm_parent->value.nonterm.children[non_null_idx] = node;
      non_null_idx += 1;
    }
  }
  // NOTE: Maybe we should also resize children alloc?
  nterm_parent->value.nonterm.num_children = non_null_idx;
  va_end(args);
  return nterm_parent;
}

/* If we are tasked to construct a terminal just create a
 * very simple node with a fixed reference to a token (leaf in AST)
 * NOTE: We may want to copy the entire value of the Token,
 * I haven't quite decided yet which is best*/
Node *create_term(Token *token) {
  Node *n = malloc(sizeof(Node) * 1);
  n->value.term = *token; // WARN: shallow copy
  n->is_term = true;
  return n;
}
