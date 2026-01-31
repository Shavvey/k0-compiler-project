#ifndef INCLUDE_SRC_TOKEN_H_
#define INCLUDE_SRC_TOKEN_H_
#include <stdlib.h>

// Token definition (pulled from class notes)
typedef struct {
   int category;           /* the integer code returned by yylex */
   char *lexeme;           /* the actual string (lexeme) matched */
   char *filename;         /* the source file in which the token occurs */
   int lineno;             /* the line number on which the token occurs */
   int ival;               /* for integer constants, store binary value here */
   double dval;	           /* for real constants, store binary value here */
   char *sval;             /* for string constants, malloc space, de-escape, store */
} Token;

// TokenList is a dynamic array/arraylist of tokens
typedef struct {
  Token *items;
  size_t capacity;
  size_t size;
} TokenList;

// NOTE: error and control symbols are always negative
#define ERRNO -1 // emits this value if content cannot be matched
#define EOFNO -2 // end of file value
// TOKEN TYPES
#define ADD 0
#define MULT 1
#define DIV 2
#define REMAINDER 3
#define SUB 4
#define ASSIGNMENT 5 
#define ADD_ASSIGNMENT 6 
#define SUB_ASSIGNMENT 7 
#define MULT_ASSIGNMENT 8
#define DIV_ASSIGNMENT 9
#define INCR 10
#define DECR 11
#define CONJ 12
#define DISJ 13
#define EXCL_WS 14
#define EXCL_NO_WS 15
#define QUEST_WS 16
#define QUEST_NO_WS 17
#define LANGLE 18
#define RANGLE 29
#define LE 20
#define GE 21
#define EXCL_EQ 22
#define EXCL_EQEQ 23
#define AS_SAFE 24
#define EQEQ 25
#define EQEQEQ 26
#define RETURN_AT 29
#define CONTINUE_AT 30
#define BREAK_AT 31
#define IMPORT 32
#define FUN 33
#define OBJECT 34
#define VAL 35
#define VAR 36
#define TYPE_ALIAS 37
#define BY 38
#define INIT 39
#define TYPEOF 40
#define WHERE 41
#define IF 42
#define ELSE 43
#define WHEN 44
#define TRY 45
#define CATCH 46
#define FINALLY 47
#define FOR 48
#define DO 49
#define WHILE 50
#define THROW 51
#define RETURN 52
#define CONTINUE 53
#define BREAK 54
#define DECDIGIT 55
#define INTEGERLITERAL 60
#define FLOATLITERAL 61
#define DOUBLELITERAL 62
#define HEXLITERAL 66
#define BINLITERAL 69
#define BOOLEANLITERAL 72
#define NULLLITERAL 73
#define CHARACTERLITERAL 74
#define IDENTIFIER 75
#define LPAR 76
#define RPAR 77
#define LSQUARE 78
#define RSQUARE 79
#define COLON 80
#define SEMICOLON 81
#define LCURL 82
#define RCURL 83
#define EXCL_EXCL 84
#define RESERVED 85
#define RANGE 86
#define RANGE_UNTIL 87 // NOTE: Kotlin spec doesn't include this? Figure out why
#define HASH 88

// API
Token new_token(int category, const char *lexeme, 
                const char *filename, const int lineno);
void print_tokens(TokenList *tl);
void delete_tokens(TokenList *tl);
TokenList merge_tokens(TokenList *rhs, TokenList *lhs);
#endif  // INCLUDE_SRC_TOKEN_H_
