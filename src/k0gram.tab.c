/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         K0_STYPE
/* Substitute the variable and function names.  */
#define yyparse         k0_parse
#define yylex           k0_lex
#define yyerror         k0_error
#define yydebug         k0_debug
#define yynerrs         k0_nerrs
#define yylval          k0_lval
#define yychar          k0_char

/* First part of user prologue.  */
#line 157 "src/k0gram.y"

  #include "parser.h"
  extern const char *filename;
  extern int lineno;
  /* Function prototypes */
  extern void yyerror(ParserContext *pc, const char *msg);
  extern int yylex(ParserContext *pc);
  int k0_debug = 1;

#line 89 "src/k0gram.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "k0gram.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_MULT = 4,                       /* MULT  */
  YYSYMBOL_DIV = 5,                        /* DIV  */
  YYSYMBOL_MOD = 6,                        /* MOD  */
  YYSYMBOL_SUB = 7,                        /* SUB  */
  YYSYMBOL_ASSIGNMENT = 8,                 /* ASSIGNMENT  */
  YYSYMBOL_ADD_ASSIGNMENT = 9,             /* ADD_ASSIGNMENT  */
  YYSYMBOL_SUB_ASSIGNMENT = 10,            /* SUB_ASSIGNMENT  */
  YYSYMBOL_MULT_ASSIGNMENT = 11,           /* MULT_ASSIGNMENT  */
  YYSYMBOL_DIV_ASSIGNMENT = 12,            /* DIV_ASSIGNMENT  */
  YYSYMBOL_MOD_ASSIGNMENT = 13,            /* MOD_ASSIGNMENT  */
  YYSYMBOL_DOT = 14,                       /* DOT  */
  YYSYMBOL_COMMA = 15,                     /* COMMA  */
  YYSYMBOL_INCR = 16,                      /* INCR  */
  YYSYMBOL_DECR = 17,                      /* DECR  */
  YYSYMBOL_CONJ = 18,                      /* CONJ  */
  YYSYMBOL_DISJ = 19,                      /* DISJ  */
  YYSYMBOL_EXCL_WS = 20,                   /* EXCL_WS  */
  YYSYMBOL_EXCL_NO_WS = 21,                /* EXCL_NO_WS  */
  YYSYMBOL_QUEST_WS = 22,                  /* QUEST_WS  */
  YYSYMBOL_QUEST_NO_WS = 23,               /* QUEST_NO_WS  */
  YYSYMBOL_LANGLE = 24,                    /* LANGLE  */
  YYSYMBOL_RANGLE = 25,                    /* RANGLE  */
  YYSYMBOL_LE = 26,                        /* LE  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_EXCL_EQ = 28,                   /* EXCL_EQ  */
  YYSYMBOL_EXCL_EQEQ = 29,                 /* EXCL_EQEQ  */
  YYSYMBOL_EQEQ = 30,                      /* EQEQ  */
  YYSYMBOL_EQEQEQ = 31,                    /* EQEQEQ  */
  YYSYMBOL_FUN = 32,                       /* FUN  */
  YYSYMBOL_VAL = 33,                       /* VAL  */
  YYSYMBOL_VAR = 34,                       /* VAR  */
  YYSYMBOL_IF = 35,                        /* IF  */
  YYSYMBOL_ELSE = 36,                      /* ELSE  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_DO = 38,                        /* DO  */
  YYSYMBOL_WHILE = 39,                     /* WHILE  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 41,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_INTEGERLITERAL = 43,            /* INTEGERLITERAL  */
  YYSYMBOL_BINLITERAL = 44,                /* BINLITERAL  */
  YYSYMBOL_HEXLITERAL = 45,                /* HEXLITERAL  */
  YYSYMBOL_DOUBLELITERAL = 46,             /* DOUBLELITERAL  */
  YYSYMBOL_FLOATLITERAL = 47,              /* FLOATLITERAL  */
  YYSYMBOL_REALLITERAL = 48,               /* REALLITERAL  */
  YYSYMBOL_BOOLEANLITERAL = 49,            /* BOOLEANLITERAL  */
  YYSYMBOL_NULLLITERAL = 50,               /* NULLLITERAL  */
  YYSYMBOL_CHARACTERLITERAL = 51,          /* CHARACTERLITERAL  */
  YYSYMBOL_STRINGLITERAL = 52,             /* STRINGLITERAL  */
  YYSYMBOL_IDENTIFIER = 53,                /* IDENTIFIER  */
  YYSYMBOL_LPAR = 54,                      /* LPAR  */
  YYSYMBOL_RPAR = 55,                      /* RPAR  */
  YYSYMBOL_LSQUARE = 56,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 57,                   /* RSQUARE  */
  YYSYMBOL_COLON = 58,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 59,                 /* SEMICOLON  */
  YYSYMBOL_LCURL = 60,                     /* LCURL  */
  YYSYMBOL_RCURL = 61,                     /* RCURL  */
  YYSYMBOL_EXCL_EXCL = 62,                 /* EXCL_EXCL  */
  YYSYMBOL_RANGE = 63,                     /* RANGE  */
  YYSYMBOL_RANGE_UNTIL = 64,               /* RANGE_UNTIL  */
  YYSYMBOL_CONST = 65,                     /* CONST  */
  YYSYMBOL_IMPORT = 66,                    /* IMPORT  */
  YYSYMBOL_HASH = 67,                      /* HASH  */
  YYSYMBOL_IN = 68,                        /* IN  */
  YYSYMBOL_ERRNO = 69,                     /* ERRNO  */
  YYSYMBOL_EOFNO = 70,                     /* EOFNO  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_program = 72,                   /* program  */
  YYSYMBOL_declr_list = 73,                /* declr_list  */
  YYSYMBOL_func_declr = 74,                /* func_declr  */
  YYSYMBOL_initializer = 75,               /* initializer  */
  YYSYMBOL_gbl_var_declr = 76,             /* gbl_var_declr  */
  YYSYMBOL_declr = 77,                     /* declr  */
  YYSYMBOL_param_list = 78,                /* param_list  */
  YYSYMBOL_param = 79,                     /* param  */
  YYSYMBOL_block = 80,                     /* block  */
  YYSYMBOL_stmt_list = 81,                 /* stmt_list  */
  YYSYMBOL_stmt = 82,                      /* stmt  */
  YYSYMBOL_arg_list = 83,                  /* arg_list  */
  YYSYMBOL_arg = 84,                       /* arg  */
  YYSYMBOL_literal = 85,                   /* literal  */
  YYSYMBOL_expr = 86,                      /* expr  */
  YYSYMBOL_func_call = 87,                 /* func_call  */
  YYSYMBOL_assign_expr = 88,               /* assign_expr  */
  YYSYMBOL_bool_expr = 89,                 /* bool_expr  */
  YYSYMBOL_quest = 90,                     /* quest  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_primary_expr = 92,              /* primary_expr  */
  YYSYMBOL_arith_expr = 93                 /* arith_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined K0_STYPE_IS_TRIVIAL && K0_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  90

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if K0_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   172,   172,   173,   176,   177,   180,   183,   184,   187,
     191,   192,   195,   196,   197,   200,   203,   206,   207,   210,
     214,   215,   216,   219,   220,   223,   224,   225,   226,   229,
     232,   233,   237,   238,   241,   242,   243,   244,   245,   246,
     247,   250,   251,   254,   255,   256,   263,   264,   265,   268,
     269,   270,   271,   272,   273,   274
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if K0_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "MULT", "DIV",
  "MOD", "SUB", "ASSIGNMENT", "ADD_ASSIGNMENT", "SUB_ASSIGNMENT",
  "MULT_ASSIGNMENT", "DIV_ASSIGNMENT", "MOD_ASSIGNMENT", "DOT", "COMMA",
  "INCR", "DECR", "CONJ", "DISJ", "EXCL_WS", "EXCL_NO_WS", "QUEST_WS",
  "QUEST_NO_WS", "LANGLE", "RANGLE", "LE", "GE", "EXCL_EQ", "EXCL_EQEQ",
  "EQEQ", "EQEQEQ", "FUN", "VAL", "VAR", "IF", "ELSE", "FOR", "DO",
  "WHILE", "RETURN", "CONTINUE", "BREAK", "INTEGERLITERAL", "BINLITERAL",
  "HEXLITERAL", "DOUBLELITERAL", "FLOATLITERAL", "REALLITERAL",
  "BOOLEANLITERAL", "NULLLITERAL", "CHARACTERLITERAL", "STRINGLITERAL",
  "IDENTIFIER", "LPAR", "RPAR", "LSQUARE", "RSQUARE", "COLON", "SEMICOLON",
  "LCURL", "RCURL", "EXCL_EXCL", "RANGE", "RANGE_UNTIL", "CONST", "IMPORT",
  "HASH", "IN", "ERRNO", "EOFNO", "$accept", "program", "declr_list",
  "func_declr", "initializer", "gbl_var_declr", "declr", "param_list",
  "param", "block", "stmt_list", "stmt", "arg_list", "arg", "literal",
  "expr", "func_call", "assign_expr", "bool_expr", "quest", "type",
  "primary_expr", "arith_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -22,    -9,   -42,   -42,    21,   -22,   -42,    -6,   -42,   -42,
     -11,   -42,   -42,     3,     1,     9,    22,    26,   -42,    13,
      59,     9,    23,   -42,   -42,   -42,     9,   -42,     5,   -42,
     -42,   -42,    57,   -42,   -42,   -42,   -42,    30,     5,   -42,
      27,   -42,   -42,    14,   -42,    71,   -35,   -42,   -28,    32,
      -3,   -42,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,   -42,   -42,    29,   -42,   -10,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,    45,   -42,   -42,   -42,    45,   -42,   -28,   -42,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     8,     7,     0,     2,    10,     0,    11,     5,
       0,     1,     4,     0,    14,     0,     0,     0,    13,    43,
       0,     0,     0,    12,    42,    41,     0,    44,     0,    15,
      18,     6,     0,    25,    26,    28,    27,    46,     0,    47,
       0,    29,    30,    32,    55,    34,     0,    45,    22,     0,
      34,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     0,    23,     0,    21,
      24,    48,    54,    46,    33,    36,    35,    37,    38,    39,
      40,    49,    51,    52,    53,    50,    19,     0,    31,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,   -42,   -42,   -42,    80,   -42,    72,   -42,
     -42,   -42,   -42,     4,   -41,    -4,   -42,    38,    15,   -42,
     -12,   -42,   -32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,     9,    17,    18,    31,
      46,    65,    68,    69,    39,    40,    41,    42,    43,    27,
      20,    44,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      59,    60,    61,    62,    63,    87,    50,    70,    33,    29,
       1,     2,     3,    34,    32,    33,    35,    36,    37,    38,
      34,    11,    52,    35,    36,    67,    64,    81,    82,    83,
      84,    85,    53,    54,    49,    24,    25,    26,    55,    56,
      57,    58,    66,    14,    10,    88,    70,    13,    33,    60,
      61,    62,    72,    34,    16,    33,    35,    36,    37,    38,
      34,    15,    19,    35,    36,    73,    38,    28,    75,    76,
      77,    78,    79,    80,    59,    60,    61,    62,    63,    16,
      21,    22,    47,    30,    48,    12,    51,    71,    86,    23,
      74,    89
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,     7,    15,    38,    48,    43,    21,
      32,    33,    34,    48,    26,    43,    51,    52,    53,    54,
      48,     0,     8,    51,    52,    53,    61,    59,    60,    61,
      62,    63,    18,    19,    38,    22,    23,    24,    24,    25,
      26,    27,    46,    54,    53,    55,    87,    53,    43,     4,
       5,     6,    55,    48,    53,    43,    51,    52,    53,    54,
      48,    58,    53,    51,    52,    53,    54,     8,    53,    54,
      55,    56,    57,    58,     3,     4,     5,     6,     7,    53,
      58,    55,    25,    60,    54,     5,    59,    55,    59,    17,
      52,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    33,    34,    72,    73,    74,    75,    76,    77,
      53,     0,    77,    53,    54,    58,    53,    78,    79,    53,
      91,    58,    55,    79,    22,    23,    24,    90,     8,    91,
      60,    80,    91,    43,    48,    51,    52,    53,    54,    85,
      86,    87,    88,    89,    92,    93,    81,    25,    54,    86,
      93,    59,     8,    18,    19,    24,    25,    26,    27,     3,
       4,     5,     6,     7,    61,    82,    86,    53,    83,    84,
      85,    55,    55,    53,    88,    89,    89,    89,    89,    89,
      89,    93,    93,    93,    93,    93,    59,    15,    55,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    74,    75,    75,    76,
      77,    77,    78,    78,    78,    79,    80,    81,    81,    82,
      83,    83,    83,    84,    84,    85,    85,    85,    85,    86,
      87,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    91,    91,    92,    92,    92,    93,
      93,    93,    93,    93,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     6,     1,     1,     7,
       1,     1,     2,     1,     0,     3,     3,     2,     0,     2,
       3,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     2,     4,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = K0_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == K0_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (pc, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use K0_error or K0_UNDEF. */
#define YYERRCODE K0_UNDEF


/* Enable debugging if requested.  */
#if K0_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, pc); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ParserContext *pc)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (pc);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ParserContext *pc)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, pc);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, ParserContext *pc)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], pc);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, pc); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !K0_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !K0_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, ParserContext *pc)
{
  YY_USE (yyvaluep);
  YY_USE (pc);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (ParserContext *pc)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = K0_EMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == K0_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (pc);
    }

  if (yychar <= K0_EOF)
    {
      yychar = K0_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == K0_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = K0_UNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = K0_EMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declr_list  */
#line 172 "src/k0gram.y"
                    { pc->pt.root = yyval = create_nterm(yyn, "program", 1, yyvsp[0]); }
#line 1239 "src/k0gram.tab.c"
    break;

  case 3: /* program: %empty  */
#line 173 "src/k0gram.y"
                { printf("[WARN]: Empty program\n"); pc->pt.root = yyval; }
#line 1245 "src/k0gram.tab.c"
    break;

  case 4: /* declr_list: declr_list declr  */
#line 176 "src/k0gram.y"
                             { yyval = create_nterm(yyn, "declr_list", 2, yyvsp[-1], yyvsp[0]);  }
#line 1251 "src/k0gram.tab.c"
    break;

  case 5: /* declr_list: declr  */
#line 177 "src/k0gram.y"
                 { yyval = create_nterm(yyn, "declr_list", 1, yyvsp[0]);  }
#line 1257 "src/k0gram.tab.c"
    break;

  case 6: /* func_declr: FUN IDENTIFIER LPAR param_list RPAR block  */
#line 180 "src/k0gram.y"
                                                      { yyval = create_nterm(yyn, "func_declr", 6, yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1263 "src/k0gram.tab.c"
    break;

  case 7: /* initializer: VAR  */
#line 183 "src/k0gram.y"
                 { yyval = yyvsp[0]; }
#line 1269 "src/k0gram.tab.c"
    break;

  case 8: /* initializer: VAL  */
#line 184 "src/k0gram.y"
                 { yyval = yyvsp[0]; }
#line 1275 "src/k0gram.tab.c"
    break;

  case 9: /* gbl_var_declr: initializer IDENTIFIER COLON type ASSIGNMENT expr SEMICOLON  */
#line 188 "src/k0gram.y"
             { yyval = create_nterm(yyn,  "gbl_var_declr", 6, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1]); }
#line 1281 "src/k0gram.tab.c"
    break;

  case 10: /* declr: func_declr  */
#line 191 "src/k0gram.y"
                  {yyval = yyvsp[0]; }
#line 1287 "src/k0gram.tab.c"
    break;

  case 11: /* declr: gbl_var_declr  */
#line 192 "src/k0gram.y"
                      {yyval = yyvsp[0]; }
#line 1293 "src/k0gram.tab.c"
    break;

  case 12: /* param_list: param_list param  */
#line 195 "src/k0gram.y"
                             { yyval = create_nterm(yyn, "param_list", 2, yyvsp[-1], yyvsp[0]); }
#line 1299 "src/k0gram.tab.c"
    break;

  case 13: /* param_list: param  */
#line 196 "src/k0gram.y"
                {yyval = create_nterm(yyn, "param_list", 1, yyvsp[0]);  }
#line 1305 "src/k0gram.tab.c"
    break;

  case 14: /* param_list: %empty  */
#line 197 "src/k0gram.y"
                 { yyval = NULL; }
#line 1311 "src/k0gram.tab.c"
    break;

  case 15: /* param: IDENTIFIER COLON type  */
#line 200 "src/k0gram.y"
                             { yyval = create_nterm(yyn, "param", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1317 "src/k0gram.tab.c"
    break;

  case 16: /* block: LCURL stmt_list RCURL  */
#line 203 "src/k0gram.y"
                             { yyval = create_nterm(yyn, "block", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1323 "src/k0gram.tab.c"
    break;

  case 17: /* stmt_list: stmt_list stmt  */
#line 206 "src/k0gram.y"
                          { yyval = create_nterm(yyn, "stmt_list", 2, yyvsp[-1], yyvsp[0]); }
#line 1329 "src/k0gram.tab.c"
    break;

  case 18: /* stmt_list: %empty  */
#line 207 "src/k0gram.y"
                  { yyval = NULL; }
#line 1335 "src/k0gram.tab.c"
    break;

  case 19: /* stmt: expr SEMICOLON  */
#line 210 "src/k0gram.y"
                     {yyval = create_nterm(yyn, "stmt", 2, yyvsp[-1], yyvsp[0]); }
#line 1341 "src/k0gram.tab.c"
    break;

  case 20: /* arg_list: arg_list COMMA arg  */
#line 214 "src/k0gram.y"
                         {yyval = create_nterm(yyn, "arg_list", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1347 "src/k0gram.tab.c"
    break;

  case 21: /* arg_list: arg  */
#line 215 "src/k0gram.y"
            {yyval = create_nterm(yyn, "arg_list", 1, yyvsp[0]); }
#line 1353 "src/k0gram.tab.c"
    break;

  case 22: /* arg_list: %empty  */
#line 216 "src/k0gram.y"
               { yyval = NULL; }
#line 1359 "src/k0gram.tab.c"
    break;

  case 23: /* arg: IDENTIFIER  */
#line 219 "src/k0gram.y"
                { yyval = create_nterm(yyn, "param", 1, yyvsp[0]); }
#line 1365 "src/k0gram.tab.c"
    break;

  case 24: /* arg: literal  */
#line 220 "src/k0gram.y"
               { yyval = create_nterm(yyn, "arg", 1, yyvsp[0]); }
#line 1371 "src/k0gram.tab.c"
    break;

  case 25: /* literal: INTEGERLITERAL  */
#line 223 "src/k0gram.y"
                           { yyval = create_nterm(yyn, "literal", 1, yyvsp[0]); }
#line 1377 "src/k0gram.tab.c"
    break;

  case 26: /* literal: REALLITERAL  */
#line 224 "src/k0gram.y"
                           { yyval = create_nterm(yyn, "literal", 1, yyvsp[0]); }
#line 1383 "src/k0gram.tab.c"
    break;

  case 27: /* literal: STRINGLITERAL  */
#line 225 "src/k0gram.y"
                           { yyval = create_nterm(yyn, "literal", 1, yyvsp[0]); }
#line 1389 "src/k0gram.tab.c"
    break;

  case 28: /* literal: CHARACTERLITERAL  */
#line 226 "src/k0gram.y"
                           { yyval = create_nterm(yyn, "literal", 1, yyvsp[0]); }
#line 1395 "src/k0gram.tab.c"
    break;

  case 29: /* expr: func_call  */
#line 229 "src/k0gram.y"
                 {yyval = yyvsp[0]; }
#line 1401 "src/k0gram.tab.c"
    break;

  case 30: /* func_call: assign_expr  */
#line 232 "src/k0gram.y"
                       { yyval = yyvsp[0]; }
#line 1407 "src/k0gram.tab.c"
    break;

  case 31: /* func_call: IDENTIFIER LPAR arg_list RPAR  */
#line 234 "src/k0gram.y"
         {yyval = create_nterm(yyn, "func_call", 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1413 "src/k0gram.tab.c"
    break;

  case 32: /* assign_expr: bool_expr  */
#line 237 "src/k0gram.y"
                       { yyval = yyvsp[0]; }
#line 1419 "src/k0gram.tab.c"
    break;

  case 33: /* assign_expr: bool_expr ASSIGNMENT assign_expr  */
#line 238 "src/k0gram.y"
                                              {yyval = create_nterm(yyn, "assign_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1425 "src/k0gram.tab.c"
    break;

  case 34: /* bool_expr: arith_expr  */
#line 241 "src/k0gram.y"
                      { yyval = yyvsp[0];}
#line 1431 "src/k0gram.tab.c"
    break;

  case 35: /* bool_expr: bool_expr DISJ bool_expr  */
#line 242 "src/k0gram.y"
                                     { yyval = create_nterm(yyn, "bool_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1437 "src/k0gram.tab.c"
    break;

  case 36: /* bool_expr: bool_expr CONJ bool_expr  */
#line 243 "src/k0gram.y"
                                    { yyval = create_nterm(yyn, "bool_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1443 "src/k0gram.tab.c"
    break;

  case 37: /* bool_expr: bool_expr LANGLE bool_expr  */
#line 244 "src/k0gram.y"
                                      { yyval = create_nterm(yyn, "bool_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1449 "src/k0gram.tab.c"
    break;

  case 38: /* bool_expr: bool_expr RANGLE bool_expr  */
#line 245 "src/k0gram.y"
                                      { yyval = create_nterm(yyn, "bool_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1455 "src/k0gram.tab.c"
    break;

  case 39: /* bool_expr: bool_expr LE bool_expr  */
#line 246 "src/k0gram.y"
                                  { yyval = create_nterm(yyn, "bool_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1461 "src/k0gram.tab.c"
    break;

  case 40: /* bool_expr: bool_expr GE bool_expr  */
#line 247 "src/k0gram.y"
                                  { yyval = create_nterm(yyn, "bool_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1467 "src/k0gram.tab.c"
    break;

  case 41: /* quest: QUEST_NO_WS  */
#line 250 "src/k0gram.y"
                   { yyval = create_nterm(yyn, "quest", 1, yyvsp[0]);  }
#line 1473 "src/k0gram.tab.c"
    break;

  case 42: /* quest: QUEST_WS  */
#line 251 "src/k0gram.y"
                {  yyval = create_nterm(yyn, "quest", 1, yyvsp[0]);  }
#line 1479 "src/k0gram.tab.c"
    break;

  case 43: /* type: IDENTIFIER  */
#line 254 "src/k0gram.y"
                 { yyval = create_nterm(yyn, "type", 1, yyvsp[0]);  }
#line 1485 "src/k0gram.tab.c"
    break;

  case 44: /* type: IDENTIFIER quest  */
#line 255 "src/k0gram.y"
                       {yyval = create_nterm(yyn, "type", 2, yyvsp[-1], yyvsp[0]);   }
#line 1491 "src/k0gram.tab.c"
    break;

  case 45: /* type: IDENTIFIER LANGLE type RANGLE  */
#line 256 "src/k0gram.y"
                                    {yyval = create_nterm(yyn, "type", 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1497 "src/k0gram.tab.c"
    break;

  case 46: /* primary_expr: IDENTIFIER  */
#line 263 "src/k0gram.y"
                          { yyval = create_nterm(yyn, "primary_expr", 1, yyvsp[0]); }
#line 1503 "src/k0gram.tab.c"
    break;

  case 47: /* primary_expr: literal  */
#line 264 "src/k0gram.y"
                       { yyval = create_nterm(yyn, "primary_expr", 1, yyvsp[0]); }
#line 1509 "src/k0gram.tab.c"
    break;

  case 48: /* primary_expr: LPAR expr RPAR  */
#line 265 "src/k0gram.y"
                              { yyval = create_nterm(yyn, "primary_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1515 "src/k0gram.tab.c"
    break;

  case 49: /* arith_expr: arith_expr ADD arith_expr  */
#line 268 "src/k0gram.y"
                                      { yyval = create_nterm(yyn, "arith_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1521 "src/k0gram.tab.c"
    break;

  case 50: /* arith_expr: arith_expr SUB arith_expr  */
#line 269 "src/k0gram.y"
                                { yyval = create_nterm(yyn, "arith_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1527 "src/k0gram.tab.c"
    break;

  case 51: /* arith_expr: arith_expr MULT arith_expr  */
#line 270 "src/k0gram.y"
                                 { yyval = create_nterm(yyn, "arith_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1533 "src/k0gram.tab.c"
    break;

  case 52: /* arith_expr: arith_expr DIV arith_expr  */
#line 271 "src/k0gram.y"
                                { yyval = create_nterm(yyn, "arith_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1539 "src/k0gram.tab.c"
    break;

  case 53: /* arith_expr: arith_expr MOD arith_expr  */
#line 272 "src/k0gram.y"
                                { yyval = create_nterm(yyn, "arith_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1545 "src/k0gram.tab.c"
    break;

  case 54: /* arith_expr: LPAR arith_expr RPAR  */
#line 273 "src/k0gram.y"
                           { yyval = create_nterm(yyn, "arith_expr", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 1551 "src/k0gram.tab.c"
    break;

  case 55: /* arith_expr: primary_expr  */
#line 274 "src/k0gram.y"
                   { yyval = yyvsp[0]; }
#line 1557 "src/k0gram.tab.c"
    break;


#line 1561 "src/k0gram.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == K0_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (pc, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= K0_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == K0_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, pc);
          yychar = K0_EMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, pc);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (pc, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != K0_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, pc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, pc);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 276 "src/k0gram.y"

