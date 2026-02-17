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

  #include "token.h"
  #include "parser.h"
}

%define api.value.type { Node *}
%define api.prefix {k0_}
%define parse.trace

%defines "src/k0gram.tab.h"
%lex-param { ParserContext *pc }
%parse-param { ParserContext *pc }
%{
  #include "parser.h"
  extern const char *filename;
  extern int lineno;
  /* Function prototypes */
  extern void yyerror(ParserContext *pc, const char *msg);
  extern int yylex(ParserContext *pc);
  int k0_debug = 1;
%}
%start program
%%
program: func_list { $$ = create_nterm(yyn, "program", 1, $1); pc->pt.root = $$; }
       | %empty { printf("[WARN]: Empty program\n"); pc->pt.root = $$; }; 

func_list: func_list func { $$ = create_nterm(yyn, "func_list", 2, $1, $2); pc->pt.root = $$; }
         | func { $$ = create_nterm(yyn, "func_list", 1, $1); pc->pt.root = $$; };

func: FUN IDENTIFIER LPAR arg_list RPAR block { $$ = create_nterm(yyn, "func", 6, $1, $2, $3, $4, $5, $6); pc->pt.root = $$; };

arg_list: arg_list arg { $$ = create_nterm(yyn, "arg_list", 2, $1, $2); pc->pt.root = $$; }
        | arg {$$ = create_nterm(yyn, "arg_list", 1, $1); pc->pt.root = $$; } ;
        
arg: IDENTIFIER COLON type { $$ = create_nterm(yyn, "arg", 3, $1, $2, $3); pc->pt.root = $$; };

block: LCURL stmt_list RCURL { $$ = create_nterm(yyn, "block", 3, $1, $2, $3); pc->pt.root = $$; };

stmt_list: stmt_list stmt { $$ = create_nterm(yyn, "stmt_list", 2, $1, $2); pc->pt.root = $$; }
         | stmt { $$ = create_nterm(yyn, "stmt_list", 1, $1); pc->pt.root = $$; };

stmt: primary_expr {$$ = create_nterm(yyn, "stmt", 1, $1); pc->pt.root = $$; };
    
params: params COMMA param {$$ = create_nterm(yyn, "params", 3, $1, $2, $3); pc->pt.root = $$; }
      | param {$$ = create_nterm(yyn, "params", 1, $1); pc->pt.root = $$; };

param: IDENTIFIER { $$ = create_nterm(yyn, "param", 1, $1); pc->pt.root = $$; }
     | literal { $$ = create_nterm(yyn, "param", 1, $1); pc->pt.root = $$; };

literal: INTEGERLITERAL    { $$ = create_nterm(yyn, "literal", 1, $1); pc->pt.root = $$; }
       | REALLITERAL       { $$ = create_nterm(yyn, "literal", 1, $1); pc->pt.root = $$; }
       | STRINGLITERAL     { $$ = create_nterm(yyn, "literal", 1, $1); pc->pt.root = $$; }
       | CHARACTERLITERAL  { $$ = create_nterm(yyn, "literal", 1, $1); pc->pt.root = $$; }

primary_expr: IDENTIFIER LPAR params RPAR SEMICOLON
            {$$ = create_nterm(yyn, "primary_expr", 5, $1, $2, $3, $4, $5); pc->pt.root = $$;  };

quest: QUEST_NO_WS { $$ = create_nterm(yyn, "quest", 1, $1); pc->pt.root = $$; }
     | QUEST_WS {  $$ = create_nterm(yyn, "quest", 1, $1); pc->pt.root = $$; };

type: IDENTIFIER { $$ = create_nterm(yyn, "type", 1, $1); pc->pt.root = $$; }
    | IDENTIFIER quest {$$ = create_nterm(yyn, "type", 2, $1, $2); pc->pt.root = $$;  };
