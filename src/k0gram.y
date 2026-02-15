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

%{
  #include <stdio.h>
  /* Function prototypes */
  extern int yylex(void);
  extern void yyerror(const char* s);
%}
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
