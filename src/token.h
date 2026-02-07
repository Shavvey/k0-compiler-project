#ifndef INCLUDE_SRC_TOKEN_H_
#define INCLUDE_SRC_TOKEN_H_
#include <stdlib.h>

typedef union {
   int ival;         /* for integer constants, store binary value here */
   double dval;	     /* for real constants, store binary value here */
   char *sval;       /* for string constants, malloc space, de-escape, store */
   char cval;        /* for char constants */ 
} Value;

// Token definition
typedef struct {
   int category;     /* the integer code returned by yylex */
   char *lexeme;     /* the actual string (lexeme) matched */
   char *filename;   /* the source file in which the token occurs */
   int lineno;       /* the line number on which the token occurs */
   Value val;        /* stored value of the token */
} Token;

// TokenList is a dynamic array/arraylist of tokens
typedef struct {
  Token *items;
  size_t capacity;
  size_t size;
} TokenList;

// API
Token new_token(int category, const char *lexeme, 
                const char *filename, const int lineno);
void print_tokens(TokenList *tl);
void delete_tokens(TokenList *tl);
void merge_tokens(TokenList *dest, TokenList *src);
int is_ender(int category);
int is_beginner(int category);
#endif  // INCLUDE_SRC_TOKEN_H_
