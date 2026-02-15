/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_K0_SRC_K0GRAM_TAB_H_INCLUDED
# define YY_K0_SRC_K0GRAM_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef K0_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define K0_DEBUG 1
#  else
#   define K0_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define K0_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined K0_DEBUG */
#if K0_DEBUG
extern int k0_debug;
#endif
/* "%code requires" blocks.  */
#line 70 "src/k0gram.y"


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

#line 138 "src/k0gram.tab.h"

/* Token kinds.  */
#ifndef K0_TOKENTYPE
# define K0_TOKENTYPE
  enum k0_tokentype
  {
    K0_EMPTY = -2,
    K0_EOF = 0,                    /* "end of file"  */
    K0_error = 256,                /* error  */
    K0_UNDEF = 257,                /* "invalid token"  */
    ADD = 258,                     /* ADD  */
    MULT = 259,                    /* MULT  */
    DIV = 260,                     /* DIV  */
    MOD = 261,                     /* MOD  */
    SUB = 262,                     /* SUB  */
    ASSIGNMENT = 263,              /* ASSIGNMENT  */
    ADD_ASSIGNMENT = 264,          /* ADD_ASSIGNMENT  */
    SUB_ASSIGNMENT = 265,          /* SUB_ASSIGNMENT  */
    MULT_ASSIGNMENT = 266,         /* MULT_ASSIGNMENT  */
    DIV_ASSIGNMENT = 267,          /* DIV_ASSIGNMENT  */
    MOD_ASSIGNMENT = 268,          /* MOD_ASSIGNMENT  */
    DOT = 269,                     /* DOT  */
    COMMA = 270,                   /* COMMA  */
    INCR = 271,                    /* INCR  */
    DECR = 272,                    /* DECR  */
    CONJ = 273,                    /* CONJ  */
    DISJ = 274,                    /* DISJ  */
    EXCL_WS = 275,                 /* EXCL_WS  */
    EXCL_NO_WS = 276,              /* EXCL_NO_WS  */
    QUEST_WS = 277,                /* QUEST_WS  */
    QUEST_NO_WS = 278,             /* QUEST_NO_WS  */
    LANGLE = 279,                  /* LANGLE  */
    RANGLE = 280,                  /* RANGLE  */
    LE = 281,                      /* LE  */
    GE = 282,                      /* GE  */
    EXCL_EQ = 283,                 /* EXCL_EQ  */
    EXCL_EQEQ = 284,               /* EXCL_EQEQ  */
    EQEQ = 285,                    /* EQEQ  */
    EQEQEQ = 286,                  /* EQEQEQ  */
    FUN = 287,                     /* FUN  */
    VAL = 288,                     /* VAL  */
    VAR = 289,                     /* VAR  */
    IF = 290,                      /* IF  */
    ELSE = 291,                    /* ELSE  */
    FOR = 292,                     /* FOR  */
    DO = 293,                      /* DO  */
    WHILE = 294,                   /* WHILE  */
    RETURN = 295,                  /* RETURN  */
    CONTINUE = 296,                /* CONTINUE  */
    BREAK = 297,                   /* BREAK  */
    INTEGERLITERAL = 298,          /* INTEGERLITERAL  */
    BINLITERAL = 299,              /* BINLITERAL  */
    HEXLITERAL = 300,              /* HEXLITERAL  */
    DOUBLELITERAL = 301,           /* DOUBLELITERAL  */
    FLOATLITERAL = 302,            /* FLOATLITERAL  */
    REALLITERAL = 303,             /* REALLITERAL  */
    BOOLEANLITERAL = 304,          /* BOOLEANLITERAL  */
    NULLLITERAL = 305,             /* NULLLITERAL  */
    CHARACTERLITERAL = 306,        /* CHARACTERLITERAL  */
    STRINGLITERAL = 307,           /* STRINGLITERAL  */
    IDENTIFIER = 308,              /* IDENTIFIER  */
    LPAR = 309,                    /* LPAR  */
    RPAR = 310,                    /* RPAR  */
    LSQUARE = 311,                 /* LSQUARE  */
    RSQUARE = 312,                 /* RSQUARE  */
    COLON = 313,                   /* COLON  */
    SEMICOLON = 314,               /* SEMICOLON  */
    LCURL = 315,                   /* LCURL  */
    RCURL = 316,                   /* RCURL  */
    EXCL_EXCL = 317,               /* EXCL_EXCL  */
    RANGE = 318,                   /* RANGE  */
    RANGE_UNTIL = 319,             /* RANGE_UNTIL  */
    CONST = 320,                   /* CONST  */
    IMPORT = 321,                  /* IMPORT  */
    HASH = 322,                    /* HASH  */
    IN = 323,                      /* IN  */
    ERRNO = 324,                   /* ERRNO  */
    EOFNO = 325                    /* EOFNO  */
  };
  typedef enum k0_tokentype k0_token_kind_t;
#endif

/* Value type.  */
#if ! defined K0_STYPE && ! defined K0_STYPE_IS_DECLARED
typedef  Token  K0_STYPE;
# define K0_STYPE_IS_TRIVIAL 1
# define K0_STYPE_IS_DECLARED 1
#endif


extern K0_STYPE k0_lval;


int k0_parse (void);


#endif /* !YY_K0_SRC_K0GRAM_TAB_H_INCLUDED  */
