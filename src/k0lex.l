/* -*-bison-*- */
/* Simple wc implementation in Flex */
%option noyywrap
%option noinput
%option nounput
%{
      #include "y.tab.h"
      #define UNSUPPORTED() do {\
        fprintf(stderr, "[TOKENIZER ERROR]: %s:%d => Kotlin token '%s' is recognized but unsupported in k0.\n", \
        filename, lineno, yytext);\
        exit(1); \
      }while(0)

      #define SYNTAX_ERROR(msg, ...) do {\
        fprintf(stderr,  "[SYNTAX ERROR]: %s:%d => " msg, filename, lineno, ##__VA_ARGS__);\
        exit(1); \
      }while(0)
      int newline = 0;
%}
whitespace [ \t\f\v\r]+
/* FOR DECIMAL/FLOAT/HEX/BINARY LITERALS */
dec_digit [0-9]
hex_digit [A-Fa-f0-9]
bin_digit [0-1]
hex_header "0x"|"0X"
bin_header "0b"|"0B"

hexlit {hex_header}({hex_digit}("_"*{hex_digit})*)
binlit {bin_header}({bin_digit}("_"*{bin_digit})*)
intlit {dec_digit}("_"*{dec_digit})*
floatlit {intlit}("F"|"f")

doublelit {intlit}?"."{intlit}
exp_doublelit ({doublelit}|{intlit})("e"|"E")("-"|"+")?({intlit})

escaped_str "\""([^\r\"\n]|\\[\r\"\n])*"\""
trip_enc_str "\"\"\""(.|[\r\n])*"\"\"\""
unpair_single_str "\""([^\r\"\n]|\\[\r\"\n])*
unpair_triple_str "\"\"\""([^\r\"\n]|\\[\r\"\n])*
str {escaped_str}|{trip_enc_str}
char "'"[^\']"'"
err_char "'"[^\']*"'"
/* FOR IDENTIFIERS */
letter [a-zA-Z]
id (({letter}|"_")({letter}|"_"|{dec_digit})*)|("`"[^`\r\n]+"`")
newline (\n|\r\n)
comment "//"[^\r\n]*
block_comment "/*"(.|[\r\n])*"*/"$
unpair_block_comment "/*"[^\r\n]*
%%
\n                            { lineno += 1; newline = 1; }
{whitespace}                  { /* ignore whitespace */ }
{comment}                     { /* ignore comments */ }
{block_comment}               { /* ignore multi-line comments */ }
{unpair_block_comment}        { SYNTAX_ERROR("Must close block comment with '*/': %s\n", yytext); }
<<EOF>>                       { return EOFNO; }
"return@"                     { UNSUPPORTED(); }
"continue@"                   { UNSUPPORTED(); }
"break@"                      { UNSUPPORTED(); }
"enum"                        { UNSUPPORTED(); } 
"object"                      { UNSUPPORTED(); }
"typeof"                      { UNSUPPORTED(); }
"typealias"                   { UNSUPPORTED(); }
"init"                        { UNSUPPORTED(); }
"where"                       { UNSUPPORTED(); }
"is"                          { UNSUPPORTED(); }
"!is"                         { UNSUPPORTED(); }
"!in"                         { UNSUPPORTED(); }
"try"                         { UNSUPPORTED(); }
"catch"                       { UNSUPPORTED(); }
"finally"                     { UNSUPPORTED(); }
"public"                      { UNSUPPORTED(); }
"private"                     { UNSUPPORTED(); }
"protected"                   { UNSUPPORTED(); }
"this"                        { UNSUPPORTED(); }
"super"                       { UNSUPPORTED(); }
"as"                          { UNSUPPORTED(); }
"as?"                         { UNSUPPORTED(); }
"..."                         { UNSUPPORTED(); }
"throw"                       { UNSUPPORTED(); }
"package"                     { UNSUPPORTED(); }
"delegate"                    { UNSUPPORTED(); }
"contructor"                  { UNSUPPORTED(); }
"dynamic"                     { UNSUPPORTED(); }
"field"                       { UNSUPPORTED(); }
"file"                        { UNSUPPORTED(); }
"get"                         { UNSUPPORTED(); }
"param"                       { UNSUPPORTED(); }
"property"                    { UNSUPPORTED(); }
"receiver"                    { UNSUPPORTED(); }
"set"                         { UNSUPPORTED(); }
"setparam"                    { UNSUPPORTED(); }
"infix"                       { UNSUPPORTED(); }
"inline"                      { UNSUPPORTED(); }
"override"                    { UNSUPPORTED(); }
"final"                       { UNSUPPORTED(); }
"open"                        { UNSUPPORTED(); }
"->"                          { UNSUPPORTED(); }
"=>"                          { UNSUPPORTED(); }
"vararg"                      { UNSUPPORTED(); }
"noinline"                    { UNSUPPORTED(); }
"lateinit"                    { UNSUPPORTED(); }
"reified"                     { UNSUPPORTED(); }
"expect"                      { UNSUPPORTED(); }
"actual"                      { UNSUPPORTED(); }
"companion"                   { UNSUPPORTED(); }
"sealed"                      { UNSUPPORTED(); }
"suspend"                     { UNSUPPORTED(); }
"by"                          { UNSUPPORTED(); }
"#"                           { UNSUPPORTED(); }
"it"                          { UNSUPPORTED(); }
"when"                        { UNSUPPORTED(); }
"&"                           { UNSUPPORTED(); }
"^"                           { UNSUPPORTED(); }
"~"                           { UNSUPPORTED(); }
"|"                           { UNSUPPORTED(); }
">>"                          { UNSUPPORTED(); }
"<<"                          { UNSUPPORTED(); }
"|="                          { UNSUPPORTED(); }
"^="                          { UNSUPPORTED(); }
"&="                          { UNSUPPORTED(); }
"~="                          { UNSUPPORTED(); }
"<<="                         { UNSUPPORTED(); }
">>="                         { UNSUPPORTED(); }
"import"                      { return IMPORT; }
^"#"([^\r\n]|"\\"[\r\n])*     { return HASH; }
"in"                          { return IN; }
"const"                       { return CONST; }
"fun"                         { return FUN; }
"val"                         { return VAL; }
"var"                         { return VAR; }
"if"                          { return IF; }
"else"                        { return ELSE; }
"for"                         { return FOR; }
"do"                          { return DO; }
"while"                       { return WHILE; }
"return"                      { return RETURN; }
"continue"                    { return CONTINUE; }
"break"                       { return BREAK; }
"null"                        { return NULLLITERAL; }
"+"                           { return ADD; }
"*"                           { return MULT; }
"/"                           { return DIV; }
"%"                           { return MOD; }
"-"                           { return SUB; }
"="                           { return ASSIGNMENT; }
"+="                          { return ADD_ASSIGNMENT; }
"-="                          { return SUB_ASSIGNMENT; }
"*="                          { return MULT_ASSIGNMENT; }
"/="                          { return DIV_ASSIGNMENT; }
"%="                          { return MOD_ASSIGNMENT; }
"++"                          { return INCR; }
"--"                          { return DECR; }
"&&"                          { return CONJ; }
"||"                          { return DISJ; }
"!!"                          { return EXCL_EXCL; }
"!"                           { return EXCL_NO_WS; }
"!"{whitespace}               { return EXCL_WS; }
"?"                           { return QUEST_NO_WS; }
"?"{whitespace}               { return QUEST_WS; }
"=="                          { return EQEQ; }
"==="                         { return EQEQEQ; }
"!="                          { return EXCL_EQ; }
"!=="                         { return EXCL_EQEQ; }
"<"                           { return LANGLE; }
">"                           { return RANGLE; }
"<="                          { return LE; }
">="                          { return GE; }
"("                           { return LPAR; }
")"                           { return RPAR; }
"["                           { return LSQUARE; }
"]"                           { return RSQUARE; }
"{"                           { return LCURL; }
"}"                           { return RCURL; }
":"                           { return COLON; }
";"                           { return SEMICOLON; }
"..<"                         { return RANGE_UNTIL; }
".."                          { return RANGE; }
"."                           { return DOT; }
","                           { return COMMA; }
{intlit}"L"?                  { return INTEGERLITERAL; }
{hexlit}                      { return HEXLITERAL; }
{binlit}                      { return BINLITERAL; }
({doublelit}|{exp_doublelit}) { return DOUBLELITERAL; }
{floatlit}                    { return FLOATLITERAL; }
"true"|"false"                { return BOOLEANLITERAL; }
{unpair_single_str}           { SYNTAX_ERROR("Must end string with \": %s\n", yytext); }
{unpair_triple_str}           { SYNTAX_ERROR("Must end string with \"\"\": %s\n", yytext); }
{str}                         { return STRINGLITERAL; } 
{char}                        { return CHARACTERLITERAL; }
{err_char}                    { SYNTAX_ERROR("Must declare exactly one character: %s\n", yytext); }
{id}                          { return IDENTIFIER; }
.                             { return ERRNO; }
%%
