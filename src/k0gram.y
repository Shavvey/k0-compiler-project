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
%right ASSIGNMENT ADD_ASSIGNMENT SUB_ASSIGNMENT
%right MULT_ASSIGNMENT DIV_ASSIGNMENT MOD_ASSIGNMENT
%left GE LE LANGLE RANGLE DISJ CONJ
%left EXCL_EQ EQEQ
%left ADD SUB
%left MULT DIV MOD
%%
program: declr_list { pc->pt.root = $$ = create_nterm(yyn, "program", 1, $1); }
       | %empty { printf("[WARN]: Empty program\n"); pc->pt.root = $$; }
       ; 

declr_list: declr_list declr { $$ = create_nterm(yyn, "declr_list", 2, $1, $2);  }
         | declr { $$ = create_nterm(yyn, "declr_list", 1, $1);  }
         ;

func_declr: FUN IDENTIFIER LPAR param_list RPAR block { $$ = create_nterm(yyn, "func_declr", 6, $1, $2, $3, $4, $5, $6); }
          ;

init_prefix: VAR { $$ = $1; }
           | VAL { $$ = $1; }
           ;

intializer_list: intializer_list COMMA intializer {$$ = create_nterm(yyn, "intializer_list", 2, $1, $2); }
               | intializer {$$ = $1; }
               | %empty {$$ = NULL; }
               ;

array_intializer: RCURL intializer_list LCURL {$$ = create_nterm(yyn, "array_intializer", 2, $1, $2); }
                ;

intializer: expr {$$ = create_nterm(yyn, "initializer", 1, $1); }
          | array_intializer {$$ = create_nterm(yyn, "intializer", 1, $1); }
          ;

gbl_var_declr:  init_prefix IDENTIFIER COLON type ASSIGNMENT intializer_list SEMICOLON
             { $$ = create_nterm(yyn,  "gbl_var_declr", 6, $1, $2, $3, $4, $5, $6); }
             ;

declr: func_declr {$$ = $1; } // FALL THROUGH
     |  gbl_var_declr {$$ = $1; }
     ;

param_list: param_list COLON param { $$ = create_nterm(yyn, "param_list", 3, $1, $2, $3); }
        | param {$$ = $1;  } 
        | %empty { $$ = NULL; }
        ;
        
param: IDENTIFIER COLON type { $$ = create_nterm(yyn, "param", 3, $1, $2, $3); }
     ;

block: LCURL stmt_list RCURL { $$ = create_nterm(yyn, "block", 3, $1, $2, $3); }
     ;

stmt_list: stmt_list stmt { $$ = create_nterm(yyn, "stmt_list", 2, $1, $2); } // Allows expansion of collection of statements
         | %empty { $$ = NULL; }
         ;

stmt: expr SEMICOLON {$$ = create_nterm(yyn, "stmt", 2, $1, $2); } // TODO: expand this please!
    | if_stmt {$$ = create_nterm(yyn, "if_stmt", 1, $1); }
    ;

if_stmt: IF LPAR bool_expr RPAR block else_if_list else_stmt
      { $$ = create_nterm(yyn, "if_stmt", 6, $1, $2, $3, $4, $5, $6); }
      ;

else_if_list: else_if_list else_if_stmt 
            { $$ = create_nterm(yyn, "if_else_list", 2, $1, $2); }
            | %empty { $$ = NULL; }
            ;

else_if_stmt: ELSE IF LPAR bool_expr RPAR block 
       { $$ = create_nterm(yyn, "if_else", 6, $1, $2, $3, $4, $5, $6); }
       ;

else_stmt: ELSE block 
         { $$ = create_nterm(yyn, "else_stmt", 2, $1, $2); }
        | %empty { $$ = NULL; }
        ;
    
arg_list: 
      arg_list COMMA arg {$$ = create_nterm(yyn, "arg_list", 3, $1, $2, $3); }
      | arg {$$ = $1; }
      | %empty { $$ = NULL; }
      ;

arg: IDENTIFIER { $$ = create_nterm(yyn, "param", 1, $1); }
     | literal { $$ = create_nterm(yyn, "arg", 1, $1); }
     ;

literal: INTEGERLITERAL    { $$ = create_nterm(yyn, "literal", 1, $1); }
       | REALLITERAL       { $$ = create_nterm(yyn, "literal", 1, $1); }
       | STRINGLITERAL     { $$ = create_nterm(yyn, "literal", 1, $1); }
       | CHARACTERLITERAL  { $$ = create_nterm(yyn, "literal", 1, $1); }
       ;

expr:  assign_expr {$$ = $1; } // has highest precedence
       ;

assign_expr: bool_expr { $$ = $1; }
           | assign_expr ASSIGNMENT assign_expr { $$ = create_nterm(yyn, "assign_expr", 3, $1, $2, $3); } // NOTE: maybe we should have a special unary on lhs?
           | assign_expr ADD_ASSIGNMENT assign_expr { $$ = create_nterm(yyn, "assign_expr", 3, $1, $2, $3); }
           | assign_expr MULT_ASSIGNMENT assign_expr { $$ = create_nterm(yyn, "assign_expr", 3, $1, $2, $3); }
           | assign_expr SUB_ASSIGNMENT assign_expr { $$ = create_nterm(yyn, "assign_expr", 3, $1, $2, $3); }
           | assign_expr DIV_ASSIGNMENT assign_expr { $$ = create_nterm(yyn, "assign_expr", 3, $1, $2, $3); }
           | assign_expr MOD_ASSIGNMENT assign_expr { $$ = create_nterm(yyn, "assign_expr", 3, $1, $2, $3); }
           ;

func_call: IDENTIFIER LPAR arg_list RPAR
         {$$ = create_nterm(yyn, "func_call", 4, $1, $2, $3, $4); }
         ;

bool_expr: arith_expr { $$ = $1;} // FALL THROUGH
         | bool_expr DISJ bool_expr  { $$ = create_nterm(yyn, "bool_expr", 3, $1, $2, $3); }
         | bool_expr CONJ bool_expr { $$ = create_nterm(yyn, "bool_expr", 3, $1, $2, $3); }
         | bool_expr LANGLE bool_expr { $$ = create_nterm(yyn, "bool_expr", 3, $1, $2, $3); }
         | bool_expr RANGLE bool_expr { $$ = create_nterm(yyn, "bool_expr", 3, $1, $2, $3); }
         | bool_expr LE bool_expr { $$ = create_nterm(yyn, "bool_expr", 3, $1, $2, $3); }
         | bool_expr GE bool_expr { $$ = create_nterm(yyn, "bool_expr", 3, $1, $2, $3); }
         | bool_expr EQEQ bool_expr { $$ = create_nterm(yyn, "bool_expr", 3, $1, $2, $3); }
         | bool_expr EXCL_EQ bool_expr { $$ = create_nterm(yyn, "bool_expr", 3, $1, $2, $3); }
         ;

quest: QUEST_NO_WS { $$ = create_nterm(yyn, "quest", 1, $1);  } // production rule when whitespace doesn't have semantic meaning
     | QUEST_WS {  $$ = create_nterm(yyn, "quest", 1, $1);  }
     ;

type: IDENTIFIER { $$ = create_nterm(yyn, "type", 1, $1);  } // simple type (e.g. x: Int)
    | IDENTIFIER quest {$$ = create_nterm(yyn, "type", 2, $1, $2);   } // nullable type (e.g. x: Int?)
    | IDENTIFIER LANGLE type RANGLE {$$ = create_nterm(yyn, "type", 4, $1, $2, $3, $4); }  // array declaration (e.g. x: ArrayList<String>)
    ;

// term: IDENTIFIER { $$ = create_nterm(yyn, "term", 1, $1); }
//     | literal { $$ = create_nterm(yyn, "term", 1, $1); }
//     ;

// NOTE: maybe we should just carry these through
primary_expr : IDENTIFIER { $$ = create_nterm(yyn, "primary_expr", 1, $1); }
             | literal { $$ = create_nterm(yyn, "primary_expr", 1, $1); }
             | func_call {$$ = create_nterm(yyn, "primary_expr", 1, $1); }
             | LPAR expr RPAR { $$ = create_nterm(yyn, "primary_expr", 3, $1, $2, $3); }
             ;

arith_expr: primary_expr { $$ = $1; } // FALL THROUGH
    | arith_expr ADD arith_expr { $$ = create_nterm(yyn, "arith_expr", 3, $1, $2, $3); }
    | arith_expr SUB arith_expr { $$ = create_nterm(yyn, "arith_expr", 3, $1, $2, $3); }
    | arith_expr MULT arith_expr { $$ = create_nterm(yyn, "arith_expr", 3, $1, $2, $3); }
    | arith_expr DIV arith_expr { $$ = create_nterm(yyn, "arith_expr", 3, $1, $2, $3); }
    | arith_expr MOD arith_expr { $$ = create_nterm(yyn, "arith_expr", 3, $1, $2, $3); }
    ;
%%
