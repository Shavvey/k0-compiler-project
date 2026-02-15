#ifndef INCLUDE_SRC_PARSER_H_
#define INCLUDE_SRC_PARSER_H_
#include "lexer.h"


// DECLARATIONS
typedef struct _Token Terminal;

typedef struct {
  struct _Node **children; // NOTE: [0, num_children - 1] array of refs
  int prod_rule;
  int num_children;
  char *symbol_name;
} NonTerminal;

typedef struct _Node {
  union {
    Terminal term;
    NonTerminal nonterm;
  } value;
  bool is_term;
} Node;

typedef struct {
  Node const *root;
} ParseTree;

typedef struct _ParserStatus {
  ParseTree parse_tree;
  int ko_nerrs;
} ParserStatus;

// API
ParseTree parse(TokenList tl);
int k0_lex();
Node *create_nterm(const int prod_rule, char *symbol_name,
                  const int num_children, ...);
Node *create_term(Token *token);
#endif  // INCLUDE_SRC_PARSER_H_
