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




/* First part of user prologue.  */
#line 1 "src/parser.y"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "analysis.hpp"
#include "ast.hpp"

using namespace std;

int yylex();
void yyerror(const char* s);
extern int yylineno;

static std::vector<std::shared_ptr<ASTNode>>* createNodeList(std::shared_ptr<ASTNode> first) {
    auto* list = new std::vector<std::shared_ptr<ASTNode>>();
    if (first) {
        list->push_back(first);
    }
    return list;
}

#line 98 "build/parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INT_LIT = 4,                    /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 5,                  /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 6,                 /* STRING_LIT  */
  YYSYMBOL_CHAR_LIT = 7,                   /* CHAR_LIT  */
  YYSYMBOL_TRUE = 8,                       /* TRUE  */
  YYSYMBOL_FALSE = 9,                      /* FALSE  */
  YYSYMBOL_FN = 10,                        /* FN  */
  YYSYMBOL_LET = 11,                       /* LET  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_IN = 16,                        /* IN  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_TYPE_I32 = 18,                  /* TYPE_I32  */
  YYSYMBOL_TYPE_F64 = 19,                  /* TYPE_F64  */
  YYSYMBOL_TYPE_BOOL = 20,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_CHAR = 21,                 /* TYPE_CHAR  */
  YYSYMBOL_TYPE_STR = 22,                  /* TYPE_STR  */
  YYSYMBOL_ARROW = 23,                     /* ARROW  */
  YYSYMBOL_ASSIGN = 24,                    /* ASSIGN  */
  YYSYMBOL_COLON = 25,                     /* COLON  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MULT = 28,                      /* MULT  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_LT = 33,                        /* LT  */
  YYSYMBOL_GT = 34,                        /* GT  */
  YYSYMBOL_LE = 35,                        /* LE  */
  YYSYMBOL_GE = 36,                        /* GE  */
  YYSYMBOL_EQ = 37,                        /* EQ  */
  YYSYMBOL_NE = 38,                        /* NE  */
  YYSYMBOL_LBRACE = 39,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 40,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 41,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 42,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 43,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 44,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 46,                 /* SEMICOLON  */
  YYSYMBOL_UMINUS = 47,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_function_list = 50,             /* function_list  */
  YYSYMBOL_function = 51,                  /* function  */
  YYSYMBOL_return_opt = 52,                /* return_opt  */
  YYSYMBOL_opt_params = 53,                /* opt_params  */
  YYSYMBOL_param_list = 54,                /* param_list  */
  YYSYMBOL_parameter = 55,                 /* parameter  */
  YYSYMBOL_type = 56,                      /* type  */
  YYSYMBOL_block = 57,                     /* block  */
  YYSYMBOL_stmt_list_opt = 58,             /* stmt_list_opt  */
  YYSYMBOL_stmt_list = 59,                 /* stmt_list  */
  YYSYMBOL_stmt = 60,                      /* stmt  */
  YYSYMBOL_let_stmt = 61,                  /* let_stmt  */
  YYSYMBOL_return_stmt = 62,               /* return_stmt  */
  YYSYMBOL_if_stmt = 63,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 64,                /* while_stmt  */
  YYSYMBOL_for_stmt = 65,                  /* for_stmt  */
  YYSYMBOL_expr = 66,                      /* expr  */
  YYSYMBOL_primary = 67,                   /* primary  */
  YYSYMBOL_literal = 68,                   /* literal  */
  YYSYMBOL_opt_args = 69,                  /* opt_args  */
  YYSYMBOL_arg_list = 70,                  /* arg_list  */
  YYSYMBOL_argument_item = 71              /* argument_item  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    96,   101,   110,   127,   135,   141,   146,
     152,   157,   166,   178,   180,   182,   184,   186,   191,   199,
     204,   210,   215,   224,   226,   228,   230,   232,   234,   241,
     246,   258,   265,   272,   282,   297,   310,   324,   330,   336,
     342,   348,   354,   360,   366,   372,   378,   384,   390,   396,
     401,   406,   411,   416,   418,   427,   434,   438,   442,   447,
     452,   456,   463,   468,   474,   479,   488
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INT_LIT", "FLOAT_LIT", "STRING_LIT", "CHAR_LIT", "TRUE", "FALSE", "FN",
  "LET", "IF", "ELSE", "WHILE", "FOR", "IN", "RETURN", "TYPE_I32",
  "TYPE_F64", "TYPE_BOOL", "TYPE_CHAR", "TYPE_STR", "ARROW", "ASSIGN",
  "COLON", "PLUS", "MINUS", "MULT", "DIV", "AND", "OR", "NOT", "LT", "GT",
  "LE", "GE", "EQ", "NE", "LBRACE", "RBRACE", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "COMMA", "SEMICOLON", "UMINUS", "$accept",
  "program", "function_list", "function", "return_opt", "opt_params",
  "param_list", "parameter", "type", "block", "stmt_list_opt", "stmt_list",
  "stmt", "let_stmt", "return_stmt", "if_stmt", "while_stmt", "for_stmt",
  "expr", "primary", "literal", "opt_args", "arg_list", "argument_item", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    15,    23,    -3,   -32,    -9,   -32,   -32,    30,    25,
       6,     7,   -32,    39,    28,    30,   -32,   -32,   -32,   -32,
     -32,   -32,    39,    16,   -32,   -32,    81,   -32,    21,   -32,
     -32,   -32,   -32,   -32,   -32,    61,    70,    70,    62,    22,
      70,    70,    70,   -32,    26,    81,   -32,   -32,   -32,   -32,
     -32,   -32,    97,   -32,   -32,    70,    43,   156,   156,    53,
     -32,   111,   -32,   -32,   139,   -32,   -32,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,   -32,
     170,    29,    35,   -32,    70,    57,   -32,    70,   -32,   -32,
     -12,   -12,   -32,   -32,   196,   183,   -25,   -25,   -25,   -25,
     -14,   -14,   -32,    70,   125,    16,   156,   -32,   -32,   -32,
     -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,     9,     0,
       0,     8,    10,     0,     7,     0,    13,    14,    15,    16,
      17,    12,     0,     0,    11,     6,    20,     5,    52,    56,
      57,    58,    59,    60,    61,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,    19,    21,    23,    24,    25,
      26,    27,     0,    51,    53,    63,     0,     0,     0,     0,
      32,     0,    50,    49,     0,    18,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      66,     0,    62,    64,     0,    33,    35,     0,    31,    55,
      45,    46,    47,    48,    38,    37,    41,    43,    42,    44,
      39,    40,    54,     0,     0,     0,     0,    65,    30,    34,
      36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,    78,   -32,   -32,   -32,    76,    72,   -23,
     -32,   -32,    54,   -32,   -32,   -32,   -32,   -32,   -31,   -32,
     -32,   -32,   -32,    -2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    23,    10,    11,    12,    21,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    81,    82,    83
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    67,    68,    69,    70,    57,    58,     1,    61,    62,
      63,    64,    67,    68,    69,    70,    69,    70,     5,    73,
      74,    75,    76,     6,    80,    28,    29,    30,    31,    32,
      33,    34,     8,     9,    85,    86,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    14,    40,
      13,    22,    15,   104,    41,    26,   106,    16,    17,    18,
      19,    20,    55,    42,    56,    59,    65,    84,    60,    87,
     105,   102,    80,    28,    29,    30,    31,    32,    33,    34,
     103,     7,   109,   110,    28,    29,    30,    31,    32,    33,
      34,    24,    35,    36,    25,    37,    38,    40,    39,    66,
       0,   107,    41,     0,     0,     0,     0,     0,    40,     0,
       0,    42,     0,    41,     0,     0,     0,     0,     0,     0,
      26,     0,    42,    67,    68,    69,    70,    71,    72,     0,
      73,    74,    75,    76,    77,    78,     0,    67,    68,    69,
      70,    71,    72,    79,    73,    74,    75,    76,    77,    78,
       0,    67,    68,    69,    70,    71,    72,    88,    73,    74,
      75,    76,    77,    78,     0,    67,    68,    69,    70,    71,
      72,   108,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    89,    67,    68,    69,    70,    71,    72,     0,    73,
      74,    75,    76,    77,    78,    26,    67,    68,    69,    70,
      71,    72,     0,    73,    74,    75,    76,    77,    78,    67,
      68,    69,    70,    71,     0,     0,    73,    74,    75,    76,
      77,    78,    67,    68,    69,    70,     0,     0,     0,    73,
      74,    75,    76,    77,    78
};

static const yytype_int8 yycheck[] =
{
      23,    26,    27,    28,    29,    36,    37,    10,    39,    40,
      41,    42,    26,    27,    28,    29,    28,    29,     3,    33,
      34,    35,    36,     0,    55,     3,     4,     5,     6,     7,
       8,     9,    41,     3,    57,    58,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    42,    27,
      25,    23,    45,    84,    32,    39,    87,    18,    19,    20,
      21,    22,    41,    41,     3,     3,    40,    24,    46,    16,
      13,    42,   103,     3,     4,     5,     6,     7,     8,     9,
      45,     3,   105,   106,     3,     4,     5,     6,     7,     8,
       9,    15,    11,    12,    22,    14,    15,    27,    17,    45,
      -1,   103,    32,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    41,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    41,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    -1,    26,    27,    28,
      29,    30,    31,    46,    33,    34,    35,    36,    37,    38,
      -1,    26,    27,    28,    29,    30,    31,    46,    33,    34,
      35,    36,    37,    38,    -1,    26,    27,    28,    29,    30,
      31,    46,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    42,    26,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    26,
      27,    28,    29,    30,    -1,    -1,    33,    34,    35,    36,
      37,    38,    26,    27,    28,    29,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    49,    50,    51,     3,     0,    51,    41,     3,
      53,    54,    55,    25,    42,    45,    18,    19,    20,    21,
      22,    56,    23,    52,    55,    56,    39,    57,     3,     4,
       5,     6,     7,     8,     9,    11,    12,    14,    15,    17,
      27,    32,    41,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    41,     3,    66,    66,     3,
      46,    66,    66,    66,    66,    40,    60,    26,    27,    28,
      29,    30,    31,    33,    34,    35,    36,    37,    38,    46,
      66,    69,    70,    71,    24,    57,    57,    16,    46,    42,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    42,    45,    66,    13,    66,    71,    46,    57,
      57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    52,    52,    53,    53,
      54,    54,    55,    56,    56,    56,    56,    56,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      61,    62,    62,    63,    63,    64,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    70,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     7,     2,     0,     1,     0,
       1,     3,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     1,     2,     1,     1,     1,     1,     1,     2,     1,
       5,     3,     2,     3,     5,     3,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     1,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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
yyparse (void)
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

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
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
  yychar = YYEMPTY;
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
  case 2: /* program: function_list  */
#line 88 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Program", *(yyvsp[0].nodelist)));
          g_astRoot = *(yyval.node);
          delete (yyvsp[0].nodelist);
      }
#line 1261 "build/parser.tab.c"
    break;

  case 3: /* function_list: function  */
#line 97 "src/parser.y"
      {
          (yyval.nodelist) = createNodeList(*(yyvsp[0].node));
          delete (yyvsp[0].node);
      }
#line 1270 "build/parser.tab.c"
    break;

  case 4: /* function_list: function_list function  */
#line 102 "src/parser.y"
      {
          (yyvsp[-1].nodelist)->push_back(*(yyvsp[0].node));
          (yyval.nodelist) = (yyvsp[-1].nodelist);
          delete (yyvsp[0].node);
      }
#line 1280 "build/parser.tab.c"
    break;

  case 5: /* function: FN IDENTIFIER LPAREN opt_params RPAREN return_opt block  */
#line 111 "src/parser.y"
      {
          auto paramsNode = makeNode("Parameters", *(yyvsp[-3].nodelist));
          auto functionNode = makeNode(std::string("Function: ") + (yyvsp[-5].sval));
          appendChild(functionNode, paramsNode);
          appendChild(functionNode, *(yyvsp[-1].node));
          appendChild(functionNode, *(yyvsp[0].node));
          (yyval.node) = new std::shared_ptr<ASTNode>(functionNode);

          free((yyvsp[-5].sval));
          delete (yyvsp[-3].nodelist);
          delete (yyvsp[-1].node);
          delete (yyvsp[0].node);
      }
#line 1298 "build/parser.tab.c"
    break;

  case 6: /* return_opt: ARROW type  */
#line 128 "src/parser.y"
      {
          auto node = makeNode("ReturnType");
          appendChild(node, *(yyvsp[0].node));
          (yyval.node) = new std::shared_ptr<ASTNode>(node);
          delete (yyvsp[0].node);
      }
#line 1309 "build/parser.tab.c"
    break;

  case 7: /* return_opt: %empty  */
#line 135 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("ReturnType: void"));
      }
#line 1317 "build/parser.tab.c"
    break;

  case 8: /* opt_params: param_list  */
#line 142 "src/parser.y"
      {
          (yyval.nodelist) = (yyvsp[0].nodelist);
      }
#line 1325 "build/parser.tab.c"
    break;

  case 9: /* opt_params: %empty  */
#line 146 "src/parser.y"
      {
          (yyval.nodelist) = new std::vector<std::shared_ptr<ASTNode>>();
      }
#line 1333 "build/parser.tab.c"
    break;

  case 10: /* param_list: parameter  */
#line 153 "src/parser.y"
      {
          (yyval.nodelist) = createNodeList(*(yyvsp[0].node));
          delete (yyvsp[0].node);
      }
#line 1342 "build/parser.tab.c"
    break;

  case 11: /* param_list: param_list COMMA parameter  */
#line 158 "src/parser.y"
      {
          (yyvsp[-2].nodelist)->push_back(*(yyvsp[0].node));
          (yyval.nodelist) = (yyvsp[-2].nodelist);
          delete (yyvsp[0].node);
      }
#line 1352 "build/parser.tab.c"
    break;

  case 12: /* parameter: IDENTIFIER COLON type  */
#line 167 "src/parser.y"
      {
          auto node = makeNode(std::string("Parameter: ") + (yyvsp[-2].sval));
          appendChild(node, *(yyvsp[0].node));
          (yyval.node) = new std::shared_ptr<ASTNode>(node);

          free((yyvsp[-2].sval));
          delete (yyvsp[0].node);
      }
#line 1365 "build/parser.tab.c"
    break;

  case 13: /* type: TYPE_I32  */
#line 179 "src/parser.y"
      { (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Type: i32")); }
#line 1371 "build/parser.tab.c"
    break;

  case 14: /* type: TYPE_F64  */
#line 181 "src/parser.y"
      { (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Type: f64")); }
#line 1377 "build/parser.tab.c"
    break;

  case 15: /* type: TYPE_BOOL  */
#line 183 "src/parser.y"
      { (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Type: bool")); }
#line 1383 "build/parser.tab.c"
    break;

  case 16: /* type: TYPE_CHAR  */
#line 185 "src/parser.y"
      { (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Type: char")); }
#line 1389 "build/parser.tab.c"
    break;

  case 17: /* type: TYPE_STR  */
#line 187 "src/parser.y"
      { (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Type: str")); }
#line 1395 "build/parser.tab.c"
    break;

  case 18: /* block: LBRACE stmt_list_opt RBRACE  */
#line 192 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Block", *(yyvsp[-1].nodelist)));
          delete (yyvsp[-1].nodelist);
      }
#line 1404 "build/parser.tab.c"
    break;

  case 19: /* stmt_list_opt: stmt_list  */
#line 200 "src/parser.y"
      {
          (yyval.nodelist) = (yyvsp[0].nodelist);
      }
#line 1412 "build/parser.tab.c"
    break;

  case 20: /* stmt_list_opt: %empty  */
#line 204 "src/parser.y"
      {
          (yyval.nodelist) = new std::vector<std::shared_ptr<ASTNode>>();
      }
#line 1420 "build/parser.tab.c"
    break;

  case 21: /* stmt_list: stmt  */
#line 211 "src/parser.y"
      {
          (yyval.nodelist) = createNodeList(*(yyvsp[0].node));
          delete (yyvsp[0].node);
      }
#line 1429 "build/parser.tab.c"
    break;

  case 22: /* stmt_list: stmt_list stmt  */
#line 216 "src/parser.y"
      {
          (yyvsp[-1].nodelist)->push_back(*(yyvsp[0].node));
          (yyval.nodelist) = (yyvsp[-1].nodelist);
          delete (yyvsp[0].node);
      }
#line 1439 "build/parser.tab.c"
    break;

  case 23: /* stmt: let_stmt  */
#line 225 "src/parser.y"
      { (yyval.node) = (yyvsp[0].node); }
#line 1445 "build/parser.tab.c"
    break;

  case 24: /* stmt: return_stmt  */
#line 227 "src/parser.y"
      { (yyval.node) = (yyvsp[0].node); }
#line 1451 "build/parser.tab.c"
    break;

  case 25: /* stmt: if_stmt  */
#line 229 "src/parser.y"
      { (yyval.node) = (yyvsp[0].node); }
#line 1457 "build/parser.tab.c"
    break;

  case 26: /* stmt: while_stmt  */
#line 231 "src/parser.y"
      { (yyval.node) = (yyvsp[0].node); }
#line 1463 "build/parser.tab.c"
    break;

  case 27: /* stmt: for_stmt  */
#line 233 "src/parser.y"
      { (yyval.node) = (yyvsp[0].node); }
#line 1469 "build/parser.tab.c"
    break;

  case 28: /* stmt: expr SEMICOLON  */
#line 235 "src/parser.y"
      {
          auto node = makeNode("ExpressionStatement");
          appendChild(node, *(yyvsp[-1].node));
          (yyval.node) = new std::shared_ptr<ASTNode>(node);
          delete (yyvsp[-1].node);
      }
#line 1480 "build/parser.tab.c"
    break;

  case 29: /* stmt: block  */
#line 242 "src/parser.y"
      { (yyval.node) = (yyvsp[0].node); }
#line 1486 "build/parser.tab.c"
    break;

  case 30: /* let_stmt: LET IDENTIFIER ASSIGN expr SEMICOLON  */
#line 247 "src/parser.y"
      {
          auto node = makeNode(std::string("Let: ") + (yyvsp[-3].sval));
          appendChild(node, *(yyvsp[-1].node));
          (yyval.node) = new std::shared_ptr<ASTNode>(node);

          free((yyvsp[-3].sval));
          delete (yyvsp[-1].node);
      }
#line 1499 "build/parser.tab.c"
    break;

  case 31: /* return_stmt: RETURN expr SEMICOLON  */
#line 259 "src/parser.y"
      {
          auto node = makeNode("Return");
          appendChild(node, *(yyvsp[-1].node));
          (yyval.node) = new std::shared_ptr<ASTNode>(node);
          delete (yyvsp[-1].node);
      }
#line 1510 "build/parser.tab.c"
    break;

  case 32: /* return_stmt: RETURN SEMICOLON  */
#line 266 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Return"));
      }
#line 1518 "build/parser.tab.c"
    break;

  case 33: /* if_stmt: IF expr block  */
#line 273 "src/parser.y"
      {
          auto node = makeNode("If");
          appendChild(node, makeNode("Condition", {*(yyvsp[-1].node)}));
          appendChild(node, *(yyvsp[0].node));
          (yyval.node) = new std::shared_ptr<ASTNode>(node);

          delete (yyvsp[-1].node);
          delete (yyvsp[0].node);
      }
#line 1532 "build/parser.tab.c"
    break;

  case 34: /* if_stmt: IF expr block ELSE block  */
#line 283 "src/parser.y"
      {
          auto node = makeNode("IfElse");
          appendChild(node, makeNode("Condition", {*(yyvsp[-3].node)}));
          appendChild(node, makeNode("Then", {*(yyvsp[-2].node)}));
          appendChild(node, makeNode("Else", {*(yyvsp[0].node)}));
          (yyval.node) = new std::shared_ptr<ASTNode>(node);

          delete (yyvsp[-3].node);
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1548 "build/parser.tab.c"
    break;

  case 35: /* while_stmt: WHILE expr block  */
#line 298 "src/parser.y"
      {
          auto node = makeNode("While");
          appendChild(node, makeNode("Condition", {*(yyvsp[-1].node)}));
          appendChild(node, *(yyvsp[0].node));
          (yyval.node) = new std::shared_ptr<ASTNode>(node);

          delete (yyvsp[-1].node);
          delete (yyvsp[0].node);
      }
#line 1562 "build/parser.tab.c"
    break;

  case 36: /* for_stmt: FOR IDENTIFIER IN expr block  */
#line 311 "src/parser.y"
      {
          auto node = makeNode(std::string("For: ") + (yyvsp[-3].sval));
          appendChild(node, makeNode("Iterable", {*(yyvsp[-1].node)}));
          appendChild(node, *(yyvsp[0].node));
          (yyval.node) = new std::shared_ptr<ASTNode>(node);

          free((yyvsp[-3].sval));
          delete (yyvsp[-1].node);
          delete (yyvsp[0].node);
      }
#line 1577 "build/parser.tab.c"
    break;

  case 37: /* expr: expr OR expr  */
#line 325 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: ||", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1587 "build/parser.tab.c"
    break;

  case 38: /* expr: expr AND expr  */
#line 331 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: &&", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1597 "build/parser.tab.c"
    break;

  case 39: /* expr: expr EQ expr  */
#line 337 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: ==", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1607 "build/parser.tab.c"
    break;

  case 40: /* expr: expr NE expr  */
#line 343 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: !=", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1617 "build/parser.tab.c"
    break;

  case 41: /* expr: expr LT expr  */
#line 349 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: <", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1627 "build/parser.tab.c"
    break;

  case 42: /* expr: expr LE expr  */
#line 355 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: <=", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1637 "build/parser.tab.c"
    break;

  case 43: /* expr: expr GT expr  */
#line 361 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: >", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1647 "build/parser.tab.c"
    break;

  case 44: /* expr: expr GE expr  */
#line 367 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: >=", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1657 "build/parser.tab.c"
    break;

  case 45: /* expr: expr PLUS expr  */
#line 373 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: +", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1667 "build/parser.tab.c"
    break;

  case 46: /* expr: expr MINUS expr  */
#line 379 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: -", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1677 "build/parser.tab.c"
    break;

  case 47: /* expr: expr MULT expr  */
#line 385 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: *", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1687 "build/parser.tab.c"
    break;

  case 48: /* expr: expr DIV expr  */
#line 391 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Op: /", {*(yyvsp[-2].node), *(yyvsp[0].node)}));
          delete (yyvsp[-2].node);
          delete (yyvsp[0].node);
      }
#line 1697 "build/parser.tab.c"
    break;

  case 49: /* expr: NOT expr  */
#line 397 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Unary: !", {*(yyvsp[0].node)}));
          delete (yyvsp[0].node);
      }
#line 1706 "build/parser.tab.c"
    break;

  case 50: /* expr: MINUS expr  */
#line 402 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Unary: -", {*(yyvsp[0].node)}));
          delete (yyvsp[0].node);
      }
#line 1715 "build/parser.tab.c"
    break;

  case 51: /* expr: primary  */
#line 407 "src/parser.y"
      { (yyval.node) = (yyvsp[0].node); }
#line 1721 "build/parser.tab.c"
    break;

  case 52: /* primary: IDENTIFIER  */
#line 412 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode(std::string("Identifier: ") + (yyvsp[0].sval)));
          free((yyvsp[0].sval));
      }
#line 1730 "build/parser.tab.c"
    break;

  case 53: /* primary: literal  */
#line 417 "src/parser.y"
      { (yyval.node) = (yyvsp[0].node); }
#line 1736 "build/parser.tab.c"
    break;

  case 54: /* primary: IDENTIFIER LPAREN opt_args RPAREN  */
#line 419 "src/parser.y"
      {
          auto callNode = makeNode(std::string("Call: ") + (yyvsp[-3].sval));
          appendChild(callNode, makeNode("Arguments", *(yyvsp[-1].nodelist)));
          (yyval.node) = new std::shared_ptr<ASTNode>(callNode);

          free((yyvsp[-3].sval));
          delete (yyvsp[-1].nodelist);
      }
#line 1749 "build/parser.tab.c"
    break;

  case 55: /* primary: LPAREN expr RPAREN  */
#line 428 "src/parser.y"
      {
          (yyval.node) = (yyvsp[-1].node);
      }
#line 1757 "build/parser.tab.c"
    break;

  case 56: /* literal: INT_LIT  */
#line 435 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Int: " + std::to_string((yyvsp[0].ival))));
      }
#line 1765 "build/parser.tab.c"
    break;

  case 57: /* literal: FLOAT_LIT  */
#line 439 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Float"));
      }
#line 1773 "build/parser.tab.c"
    break;

  case 58: /* literal: STRING_LIT  */
#line 443 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode(std::string("String: ") + (yyvsp[0].sval)));
          free((yyvsp[0].sval));
      }
#line 1782 "build/parser.tab.c"
    break;

  case 59: /* literal: CHAR_LIT  */
#line 448 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode(std::string("Char: ") + (yyvsp[0].sval)));
          free((yyvsp[0].sval));
      }
#line 1791 "build/parser.tab.c"
    break;

  case 60: /* literal: TRUE  */
#line 453 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Bool: true"));
      }
#line 1799 "build/parser.tab.c"
    break;

  case 61: /* literal: FALSE  */
#line 457 "src/parser.y"
      {
          (yyval.node) = new std::shared_ptr<ASTNode>(makeNode("Bool: false"));
      }
#line 1807 "build/parser.tab.c"
    break;

  case 62: /* opt_args: arg_list  */
#line 464 "src/parser.y"
      {
          (yyval.nodelist) = (yyvsp[0].nodelist);
      }
#line 1815 "build/parser.tab.c"
    break;

  case 63: /* opt_args: %empty  */
#line 468 "src/parser.y"
      {
          (yyval.nodelist) = new std::vector<std::shared_ptr<ASTNode>>();
      }
#line 1823 "build/parser.tab.c"
    break;

  case 64: /* arg_list: argument_item  */
#line 475 "src/parser.y"
      {
          (yyval.nodelist) = createNodeList(*(yyvsp[0].node));
          delete (yyvsp[0].node);
      }
#line 1832 "build/parser.tab.c"
    break;

  case 65: /* arg_list: arg_list COMMA argument_item  */
#line 480 "src/parser.y"
      {
          (yyvsp[-2].nodelist)->push_back(*(yyvsp[0].node));
          (yyval.nodelist) = (yyvsp[-2].nodelist);
          delete (yyvsp[0].node);
      }
#line 1842 "build/parser.tab.c"
    break;

  case 66: /* argument_item: expr  */
#line 489 "src/parser.y"
      { (yyval.node) = (yyvsp[0].node); }
#line 1848 "build/parser.tab.c"
    break;


#line 1852 "build/parser.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 492 "src/parser.y"


void yyerror(const char* s) {
    g_lastError = std::string("Syntax error at line ") + std::to_string(yylineno) + ": " + s;
}
