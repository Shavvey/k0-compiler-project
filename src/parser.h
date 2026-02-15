#ifndef INCLUDE_SRC_PARSER_H_
#define INCLUDE_SRC_PARSER_H_
#include "lexer.h"

// DECLARATIONS
typedef struct _Node {
  int prod_rule;
  char *symbol_name;
  bool is_leaf; // NOTE: redundant can always check num_children == 0?
  int num_children;
  struct _Node **children; // NOTE: [0, num_children - 1] array of refs
  Token leaf;
} Node;

typedef struct {
  Node const *root;
} ParseTree;

typedef struct {
  Token *items;
  size_t size;
  size_t cursor;
} TokenStream;


// API
ParseTree parse(TokenList tl);
int k0_lex();
#endif  // INCLUDE_SRC_PARSER_H_
