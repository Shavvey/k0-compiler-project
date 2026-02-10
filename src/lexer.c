#include "lexer.h"
#include "common.h"
#include "token.h"
#include "y.tab.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern int yylex_destroy(void);
extern int yylex(void);
extern char *yytext;
extern int newline;

const char *filename; // tracked filename of current tokenizing file
int lineno = 1;       // linenumber of current tokenizing file

static void append_token(TokenList *tl, Token t, const bool ins_semicolon) {
  if (ins_semicolon && is_beginner(t.category) &&
      is_ender(alist_last(tl).category) && newline) {
    alist_append(tl, new_token(SEMICOLON, "AUTO INSERTED SEMICOLON", filename,
                               lineno - 1));
  }
  alist_append(tl, t);
}

static Token get_next_token() {
  // lex the file is yylex
  int tok_int = yylex();
  if (tok_int == ERRNO) {
    eprintf("Could not lex line content => %s at %s:%d\n", yytext, filename,
            lineno);
    exit(EXIT_FAILURE);
  }
  Token token = new_token(tok_int, yytext, filename, lineno);
  return token;
}

static TokenList lex_file(const char *fname) {
  filename = fname; // set filename
  lineno = 1;       // rest linenumber
  TokenList tl = {0};
  yyin = fopen(fname, "r"); // open file for flex
  if (yyin == NULL) {
    eprintf("Could not open file: %s\n", fname);
    exit(EXIT_FAILURE);
  }
  Token token = get_next_token();
  while(token.category != EOFNO) {
    append_token(&tl, token, 1);
    newline = 0;
    token = get_next_token();
  } 
  fclose(yyin);
  return tl;
}

static Token get_and_expect(int expected_category) {
  // first return the next token
  Token t = get_next_token();
  if (t.category != expected_category) {
    int category = t.category;
    eprintf("Expected %d:%s got %d:%s!\n", expected_category,
            ytab_ltable[expected_category - 258], category,
            ytab_ltable[category - 258]);
    exit(EXIT_FAILURE);
  }
  return t;
}

/** NOTE: this should be the only public facing component of the lexer,
 * since the entire point of the lexer is gather all the text input and emit
 * a series of tokens
 */
TokenList lex_files(int argc, char **argv) {
  TokenList tl = {0};
  if (argc > 1) {
    // NOTE: assumes passed files are all the args we are given
    for (int i = 1; i < argc; i += 1) {
      filename = argv[i]; // decode file args
      TokenList next = lex_file(filename);
      merge_tokens(&tl, &next);
      lineno = 1; // reset lineno
    }
  } else {
    eprintf("No file passed!\n");
    exit(EXIT_FAILURE);
  }
  print_tokens(&tl);
  yylex_destroy();
  return tl;
}
