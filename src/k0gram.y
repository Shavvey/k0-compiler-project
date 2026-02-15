%token ADD
%token MULT
%token DIV
%token MOD
%token SUB
%token ASSIGNMENT
%token ADD_ASSIGNMENT
%token SUB_ASSIGNMENT
%token MULT_ASSIGNMENT
%token DIV_ASSIGNMENT
%token MOD_ASSIGNMENT
%token DOT
%token COMMA
%token INCR
%token DECR
%token CONJ
%token DISJ
%token EXCL_WS
%token EXCL_NO_WS
%token QUEST_WS
%token QUEST_NO_WS
%token LANGLE
%token RANGLE
%token LE
%token GE
%token EXCL_EQ
%token EXCL_EQEQ
%token EQEQ
%token EQEQEQ
%token FUN
%token VAL
%token VAR
%token IF
%token ELSE
%token FOR
%token DO
%token WHILE
%token RETURN
%token CONTINUE
%token BREAK
%token INTEGERLITERAL
%token BINLITERAL
%token HEXLITERAL
%token DOUBLELITERAL
%token FLOATLITERAL
%token REALLITERAL
%token BOOLEANLITERAL
%token NULLLITERAL
%token CHARACTERLITERAL
%token STRINGLITERAL
%token IDENTIFIER
%token LPAR
%token RPAR
%token LSQUARE
%token RSQUARE
%token COLON
%token SEMICOLON
%token LCURL
%token RCURL
%token EXCL_EXCL
%token RANGE
%token RANGE_UNTIL
%token CONST
%token IMPORT
%token HASH
%token IN
%token ERRNO
%token EOFNO

%code requires {

  extern const char *filename;
  extern int lineno;

  #define TABLE_SIZE 66
  #define MAX_LENGTH 17
  #define YTABLE_START 258
  static const char ytab_ltable[TABLE_SIZE][MAX_LENGTH] = {
    "ADD",
    "MULT",
    "DIV",
    "MOD",
    "SUB",
    "ASSIGNMENT",
    "ADD_ASSIGNMENT",
    "SUB_ASSIGNMENT",
    "MULT_ASSIGNMENT",
    "DIV_ASSIGNMENT",
    "MOD_ASSIGNMENT",
    "DOT",
    "COMMA",
    "INCR",
    "DECR",
    "CONJ",
    "DISJ",
    "EXCL_WS",
    "EXCL_NO_WS",
    "QUEST_WS",
    "QUEST_NO_WS",
    "LANGLE",
    "RANGLE",
    "LE",
    "GE",
    "EXCL_EQ",
    "EXCL_EQEQ",
    "EQEQ",
    "EQEQEQ",
    "FUN",
    "VAL",
    "VAR",
    "IF",
    "ELSE",
    "FOR",
    "DO",
    "WHILE",
    "RETURN",
    "CONTINUE",
    "BREAK",
    "INTEGERLITERAL",
    "BINLITERAL",
    "HEXLITERAL",
    "DOUBLELITERAL",
    "FLOATLITERAL",
    "REALLITERAL",
    "BOOLEANLITERAL",
    "NULLLITERAL",
    "CHARACTERLITERAL",
    "STRINGLITERAL",
    "IDENTIFIER",
    "LPAR",
    "RPAR",
    "LSQUARE",
    "RSQUARE",
    "COLON",
    "SEMICOLON",
    "LCURL",
    "RCURL",
    "EXCL_EXCL",
    "RANGE",
    "RANGE_UNTIL",
    "CONST",
    "IMPORT",
    "HASH",
    "IN"
  };
}

%{
  #include <stdio.h>
  extern const char *filename;
  extern int lineno;
  /* Function prototypes */
  extern int yylex(void);
  extern void yyerror(const char* s);
%}
%defines "src/k0gram.tab.h"
%start program
%%
program: func_list | ;
func_list: func_list func | func;
func: FUN IDENTIFIER LPAR arg_list 
      RPAR COLON IDENTIFIER block ;
arg_list: arg_list arg | arg ;
arg: IDENTIFIER COLON type ;
block: LCURL stmt_list RCURL ;
stmt_list: stmt_list stmt | stmt;
stmt: primary_expr ;
params: params COMMA param | param;
param: IDENTIFIER ;
primary_expr: IDENTIFIER LPAR params RPAR SEMICOLON ;
quest: QUEST_NO_WS | QUEST_WS ;
type: IDENTIFIER |
      IDENTIFIER quest ;
