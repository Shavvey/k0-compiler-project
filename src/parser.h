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
  Node *root;
} ParseTree;

typedef struct {
  ParseTree pt; // NOTE: Okay to pass by ref, only contains pointer
  TokenList *tl;
  size_t cursor;
} ParserContext;

// API
ParseTree parse(TokenList *tl);
int k0_lex(ParserContext *pc);
Node *create_nterm(const int prod_rule, char *symbol_name,
                  const int num_children, ...);
Node *create_term(Token *token);
void pt_print_tokens(const ParseTree *pt);
void pt_delete(ParseTree *pt);
void pt_pretty_print(const ParseTree *pt);
#endif  // INCLUDE_SRC_PARSER_H_
