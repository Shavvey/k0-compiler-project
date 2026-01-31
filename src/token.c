#include "token.h"
#include "common.h"
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

/* Helper function to strip off escape sequences
 * EXAMPLE f: "aba\n" => "aba"
 */
static char *strip_esc_chars(char *str) {
  // TODO: implement windows/http style newline: \r\n
  int len = strlen(str);
  char *nstr = (char *)malloc((len + 1) * sizeof(char));
  nstr[len] = '\0';
  char *pw = nstr;
  for (int idx = 0; str[idx] != '\0'; idx += 1) {
    if (str[idx] == '\\') {
      char c = str[++idx];
      switch (c) {
      case '\n': // NOTE: may need to revise this
      case '\\':
      case '\"':
        *pw = str[idx];
        pw += 1;
        break;
      // Use of control char, prefixed by escape
      case 'n':
        *pw = '\n';
        pw += 1;
        break;
      case 't':
        *pw = '\t';
        pw += 1;
        break;
      case 'v':
        *pw = '\v';
        pw += 1;
        break;
      default:
        // NOTE: just error for now if escape doesn't make sense
        eprintf("Unsupported escape sequence: ");
        printf("\\%c\n", c);
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

/* Helper to check if string is triple escaped */
static bool is_triple_quoted(char *str) {
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
      t.ival = atoi(lexeme_no_sep);
      free(lexeme_no_sep); // destroy sanitized string
    } else {
      t.ival = atoi(t.lexeme);
    }
    break;
  case HEXLITERAL:
    if (str_has(t.lexeme, '_')) { // check for separators
      char *lexeme_no_sep = str_remove_char(t.lexeme, '_');
      t.ival = atoi(lexeme_no_sep);
      free(lexeme_no_sep); // destroy sanitized string
    } else {
      t.ival = (int)strtol(t.lexeme, NULL, 16);
    }
    break;
  case BINLITERAL:
    if (str_has(t.lexeme, '_')) { // check for separators
      char *lexeme_no_sep = str_remove_char(t.lexeme + 2, '_');
      t.ival = (int)strtol(lexeme_no_sep, NULL, 2);
      free(lexeme_no_sep); // destroy sanitized string
    } else {
      t.ival = (int)strtol(t.lexeme + 2, NULL, 2);
    }
    break;
  case DOUBLELITERAL:
  case FLOATLITERAL: // FALL THROUGH: all floats are treated as double
    if (str_has(t.lexeme, '_')) { // check for seperators
      char *lexeme_no_sep = str_remove_char(t.lexeme, '_');
      t.dval = atof(lexeme_no_sep);
      free(lexeme_no_sep); // destroy process string
    } else {
      t.dval = atof(t.lexeme);
    }
    break;
  case CHARACTERLITERAL:
    if (is_triple_quoted(t.lexeme)) {
      char *chopped_str = chop_trip_dquote(t.lexeme);
      t.sval = strip_esc_chars(chopped_str);
      free(chopped_str);
    } else {
      char *chopped_str = chop_dquote(t.lexeme);
      t.sval = strip_esc_chars(chopped_str);
      free(chopped_str);
    }
    break;
  }
  return t;
}

/* Function to print out the tokens in a table of values  */
void print_tokens(TokenList *tl) {
  // print out the header of the table
  const char *const header[] = {"Type", "Lexeme", "Lineno", "File",
                                "Sval/Ival/Dval"};
  const int DIV_LENGTH = 90;
  char *div = (char *)malloc(DIV_LENGTH * sizeof(char));
  for (int i = 0; i < DIV_LENGTH; i++) {
    div[i] = '-';
  }
  printf("%-5s%-30s%-10s%-15s%-30s\n", header[0], header[1], header[2],
         header[3], header[4]);
  printf("%.*s\n", DIV_LENGTH, div);
  for (size_t ts = 0; ts < tl->size; ts += 1) {
    Token token = tl->items[ts];
    // NOTE: make a better guess at the padding required for each row!
    printf("%-5d%-30s%-10d%-15s", token.category, token.lexeme, token.lineno,
           token.filename);
    switch (token.category) {
    case CHARACTERLITERAL:
      printf("%-30s\n", token.sval);
      break;
    case INTEGERLITERAL: // FALL THROUGH: all stored as ints
    case HEXLITERAL:
    case BINLITERAL:
      printf("%-30d\n", token.ival);
      break;
    case FLOATLITERAL: // FALL THROUGH: floats are promoted to double
    case DOUBLELITERAL:
      printf("%-30.2f\n", token.dval);
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
    free(t.sval);
  }
  alist_free(tl);
}

/* Helper function to merge two different token lists */
TokenList merge_tokens(TokenList *rhs, TokenList *lhs) {
  TokenList tl = {0};
  // NOTE: maybe we should just insert into either rhs or lhs, not another tl
  alist_append_many(&tl, rhs->items, rhs->size); // WARN: shallow copy
  alist_append_many(&tl, lhs->items, lhs->size); // WARN: shallow copy
  free(rhs->items);
  free(lhs->items);
  return tl;
}
