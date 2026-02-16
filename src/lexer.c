#include "lexer.h"
#include "common.h"
#include "k0gram.tab.h"
#include "token.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INS_SEMICOLON

extern FILE *yyin;
extern int yylex_destroy(void);
extern int yylex(void);
extern char *yytext;
extern int newline;

const char *filename; // tracked filename of current tokenizing file
int lineno = 1;       // linenumber of current tokenizing file

static void append_token(TokenList *tl, Token t) {
#ifdef INS_SEMICOLON // NOTE: undef or comment out INS_SEMICOLON to disable this
  if (is_beginner(t.category) && is_ender(alist_last(tl).category) && newline) {
    alist_append(tl, new_token(SEMICOLON, "AUTO INSERTED SEMICOLON", filename,
                               lineno - 1));
  }
#endif
  alist_append(tl, t);
  // consume newline flag after append is successful
  newline = 0;
}

Token get_next_token() {
  // Use yylex to return token category, construct token based on this
  int tok_int = yylex();
  if (tok_int == ERRNO) {
    eprintf("Could not lex line content => %s at %s:%d\n", yytext, filename,
            lineno);
    exit(EXIT_FAILURE);
  }
  Token token = new_token(tok_int, yytext, filename, lineno);
  return token;
}

static Token get_and_expect(int expected_category) {
  // First return the next token
  Token t = get_next_token();
  if (t.category != expected_category) {
    int category = t.category;
    SYNTAX_ERROR("Expected %d:%s got %d:%s!\n", expected_category,
                 ytab_ltable[expected_category - YTABLE_START], category,
                 ytab_ltable[category - YTABLE_START]);
    exit(EXIT_FAILURE);
  }
  // If we get what we expected, just return it. Insertion will happen later
  return t;
}

TokenList lex_file(const char *fname) {
  filename = fname; // set filename
  lineno = 1;       // reset linenumber
  TokenList tl = {0};
  yyin = fopen(fname, "r"); // open file for flex
  if (yyin == NULL) {
    eprintf("Could not open file: %s\n", fname);
    exit(EXIT_FAILURE);
  }
  Token token = get_next_token();
  while (token.category != EOFNO) {

    append_token(&tl, token);
    token = get_next_token();

    if (token.category == VAR || token.category == VAL) {
      // speculatively get next token and check its category
      Token next_token = get_and_expect(IDENTIFIER);
      append_token(&tl, token);
      // if assertion succeeds, run main loop but with this new speculatively
      // returned token
      token = next_token;
    }
  }
  /** NOTE: this token is the "endfile" token.
   *  We don't need to merge and append this one.
   *  Just delete it and ignore it for now */
  free(token.filename);
  free(token.lexeme);
  // NOTE: fix this so that allocation doesn't happen in the first place
  fclose(yyin);
  return tl;
}

/** NOTE: this should be the only public facing component of the scanner,
 * since the entire point of the scanner is to gather all the text input and
 * emit a series of tokens
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
  yylex_destroy();
  return tl;
}
