#include "token.h"
#include "common.h"
#include "k0gram.tab.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Helper function to chop away double quotes from lexeme to create sval */
static char *chop_dquote(const char *str) {
  int nlen = strlen(str) - 2;
  char *chopped_str = (char *)malloc((nlen + 1) * sizeof(char));
  strncpy(chopped_str, str + 1, nlen);
  chopped_str[nlen] = '\0';
  return chopped_str;
}

/** Helper fucntion to chop away any triple double quote strings
 *  and then retrieve their enclosed content
 */
static char *chop_trip_dquote(const char *str) {
  int nlen = strlen(str) - 6;
  char *chopped_str = (char *)malloc((nlen + 1) * sizeof(char));
  strncpy(chopped_str, str + 3, nlen);
  chopped_str[nlen] = '\0';
  return chopped_str;
}

/* Helper function to strip off some arbitrary char to create a new string */
static char *str_remove_char(char *str, char c) {
  int len = strlen(str);
  char *nstr = (char *)malloc((len + 1) * sizeof(char));
  nstr[len] = '\0';
  char *pw = nstr;
  for (int idx = 0; str[idx] != '\0'; idx += 1) {
    if (str[idx] != c) {
      *pw = str[idx];
      pw += 1;
    }
  }
  *pw = '\0';
  return nstr;
}

/** Helper function to strip off escape sequences
 * EXAMPLE f: "aba\n" => "aba<NL>" or "abs\"" => "abs""
 */
static char *strip_esc_chars(char *str) {
  // REFERENCE: https://www.cs.nmt.edu/~jeffery/courses/423/k0.html
  int len = strlen(str);
  char *nstr = (char *)malloc((len + 1) * sizeof(char));
  nstr[len] = '\0';
  char *pw = nstr;
  for (int idx = 0; str[idx] != '\0'; idx += 1) {
    if (str[idx] == '\\') {
      char c = str[++idx];
      switch (c) {
      case '\n':
      case '\\':
      case '\"':
      case '\'':
      case '$':
        *pw = str[idx];
        pw += 1;
        break;
      // Use of control char, prefixed by escape
      case 'n':
        *pw = '\n'; // newline escape
        pw += 1;
        break;
      case 't':
        *pw = '\t'; // tab escape
        pw += 1;
        break;
      case 'r':
        *pw = '\r';
        pw += 1;
        break;
      case 'b':
        *pw = '\b';
        pw += 1;
        break;
      default:
        // NOTE: just error for now if escape doesn't make sense
        eprintf("Unsupported escape sequence: '\\%c' in %s:%d\n", c, filename,
                lineno);
        exit(EXIT_FAILURE);
        break;
      }
    } else {
      *pw = str[idx];
      pw += 1;
    }
  }
  *pw = '\0';
  return nstr;
}

/* Simple function to determine if a character is inside the str */
static bool str_has(char *str, char c) {
  for (int idx = 0; str[idx] != '\0'; idx += 1) {
    if (str[idx] == c)
      return true;
  }
  return false;
}

/* Helper function to strip directory info from files*/
static char *strip_file_dirs(char *fname) {
  int idx = 0;
  int last_dir_idx = 0;
  while (fname[idx] != '\0') {
    // NOTE: Not platform independent, won't work on non-unix platforms
    if (fname[idx] == '/') {
      last_dir_idx = idx;
    }
    idx += 1;
  }
  int size = (idx - 1) - last_dir_idx;
  char *filename = (char *)malloc((size + 1) * sizeof(char));
  filename[size] = '\0';
  strncpy(filename, fname + last_dir_idx + 1, size);
  free(fname);
  return filename;
}

/* Helper to check if string is triple enclosed in double-quotes */
static bool is_triple_enc_dquote(char *str) {
  int len = strlen(str);
  if (len >= 6) {
    bool start_trip = (str[0] == '\"' && str[1] == '\"' && str[2] == '\"');
    bool end_trip =
        (str[len - 3] == '\"' && str[len - 2] == '\"' && str[len - 1] == '\"');
    return start_trip && end_trip;
  } else {
    return false;
  }
}

/* Function that helps in token creation */
Token new_token(int category, const char *lexeme, const char *filename,
                const int lineno) {
  Token t = {.category = category, .lineno = lineno};

  // copy over lexeme via strncpy
  int llen = strlen(lexeme);
  t.lexeme = (char *)malloc((llen + 1) * sizeof(char));
  t.lexeme[llen] = '\0';
  strncpy(t.lexeme, lexeme, llen);
  // copy over filename via strncpy
  int flen = strlen(filename);
  t.filename = (char *)malloc((flen + 1) * sizeof(char));
  t.filename[flen] = '\0';
  strncpy(t.filename, filename, flen);
  t.filename = strip_file_dirs(t.filename);
  switch (t.category) {
  case INTEGERLITERAL:
    if (str_has(t.lexeme, '_')) { // check for separators
      char *lexeme_no_sep = str_remove_char(t.lexeme, '_');
      t.val.ival = atoi(lexeme_no_sep);
      free(lexeme_no_sep); // destroy sanitized string
    } else {
      t.val.ival = atoi(t.lexeme);
    }
    break;
  case HEXLITERAL:
    t.category = INTEGERLITERAL;  // collapse to int
    if (str_has(t.lexeme, '_')) { // check for separators
      char *lexeme_no_sep = str_remove_char(t.lexeme, '_');
      t.val.ival = atoi(lexeme_no_sep);
      free(lexeme_no_sep); // destroy sanitized string
    } else {
      t.val.ival = (int)strtol(t.lexeme, NULL, 16);
    }
    break;
  case BINLITERAL:
    t.category = INTEGERLITERAL;  // collapse to int
    if (str_has(t.lexeme, '_')) { // check for separators
      char *lexeme_no_sep = str_remove_char(t.lexeme + 2, '_');
      t.val.ival = (int)strtol(lexeme_no_sep, NULL, 2);
      free(lexeme_no_sep); // destroy sanitized string
    } else {
      // NOTE strtol doesn't support 0b prefix, so we skip over it
      t.val.ival = (int)strtol(t.lexeme + 2, NULL, 2);
    }
    break;
  case DOUBLELITERAL:
  case FLOATLITERAL:          // FALL THROUGH: all floats are treated as double
    t.category = REALLITERAL; // collapse to real
    if (str_has(t.lexeme, '_')) { // check for seperators
      char *lexeme_no_sep = str_remove_char(t.lexeme, '_');
      t.val.dval = atof(lexeme_no_sep);
      free(lexeme_no_sep); // destroy process string
    } else {
      t.val.dval = atof(t.lexeme);
    }
    break;
  case STRINGLITERAL:
    if (is_triple_enc_dquote(t.lexeme)) {
      char *chopped_str = chop_trip_dquote(t.lexeme);
      t.val.sval = strip_esc_chars(chopped_str);
      free(chopped_str);
    } else {
      char *chopped_str = chop_dquote(t.lexeme);
      t.val.sval = strip_esc_chars(chopped_str);
      free(chopped_str);
    }
    break;
  case CHARACTERLITERAL:
    if (strlen(t.lexeme) == 3) {
      t.val.cval = t.lexeme[1]; // 'x'
    } else {
      // NOTE: this should be handled with `err_char` regex
      eprintf("Error in character literal\n");
      exit(EXIT_FAILURE);
    }
  }
  return t;
}

/* Function to print out the tokens in a table of values  */
void print_tokens(const TokenList *tl) {
  // print out the header of the table
  const char *const header[] = {"Type", "Lexeme", "Lineno", "File",
                                "Sval/Ival/Dval"};
  const int DIV_LENGTH = 105;
  char *div = (char *)malloc(DIV_LENGTH * sizeof(char));
  for (int i = 0; i < DIV_LENGTH; i++) {
    div[i] = '-';
  }
  printf("%-25s%-30s%-10s%-15s%-30s\n", header[0], header[1], header[2],
         header[3], header[4]);
  printf("%.*s\n", DIV_LENGTH, div);
  for (size_t ts = 0; ts < tl->size; ts += 1) {
    Token token = tl->items[ts];
    // NOTE: make a better guess at the padding required for each row!
    printf("%-3d:%-21s%-30s%-10d%-15s", token.category,
           ytab_ltable[token.category - 258], token.lexeme, token.lineno,
           token.filename);
    switch (token.category) {
    case CHARACTERLITERAL:
      printf("%-30c\n", token.val.cval);
      break;
    case STRINGLITERAL:
      printf("%-30s\n", token.val.sval);
      break;
    case INTEGERLITERAL: // FALL THROUGH: all stored as ints
    case HEXLITERAL:
    case BINLITERAL:
      printf("%-30d\n", token.val.ival);
      break;
    case REALLITERAL: // FALL THROUGH: all stored as "reals"/double
    case FLOATLITERAL:
    case DOUBLELITERAL:
      printf("%-30.2f\n", token.val.dval);
      break;
    default:
      printf("\n");
      break;
    }
  }
  free(div);
}

/* Delete tokenlist by freeing all heap allocs owned by struct members */
void delete_tokens(TokenList *tl) {
  for (size_t ls = 0; ls < tl->size; ls += 1) {
    Token t = tl->items[ls];
    free(t.filename);
    free(t.lexeme);
    if (t.category == STRINGLITERAL)
      free(t.val.sval);
  }
  alist_free(tl);
}

/* Helper function to merge two different token lists */
void merge_tokens(TokenList *dest, TokenList *src) {
  alist_append_many(dest, src->items, src->size); // WARN: shallow copy
  free(src->items);
}

/* TAKEN FROM: https://www.cs.nmt.edu/~jeffery/courses/423/k0lex.l
 * Determines where to insert semi-colon: ... + semi-colon + ender
 */
int is_ender(int category) {
  switch (category) {
  case IDENTIFIER:
  case RPAR:
  case RSQUARE:
  case REALLITERAL:
  case NULLLITERAL:
  case BOOLEANLITERAL:
  case CHARACTERLITERAL:
  case STRINGLITERAL:
  case INTEGERLITERAL:
    return 1;
    break;
  default:
    return 0;
    break;
  }
}

/* TAKEN FROM: https://www.cs.nmt.edu/~jeffery/courses/423/k0lex.l
 * Determines where to insert semi-colon: beginner + semi-colon + ...
 */
int is_beginner(int category) {
  switch (category) {
  case RCURL:
  case VAL:
  case VAR:
  case IDENTIFIER:
  case WHILE:
  case IF:
    return 1;
    break;
  case INTEGERLITERAL:
    return 1;
    break;
  default:
    return 0;
    break;
  }
}
