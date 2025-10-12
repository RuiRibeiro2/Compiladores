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
#line 1 "gocompiler.y"

    /*
    Projeto de Compiladores 2023/2024~yaacv2
    Meta 2
    2021189478 - Rui Ribeiro
    2021221169 - Francisco Rodrigues
    */
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "y.tab.h"

extern int yylex(void);
extern void yyerror(char *);
extern char *yytext;

node* program_root = NULL;
node* aux;
node* varspec_aux;
node* varspec_aux1 = NULL;
node* aux2 = NULL;


#line 95 "gocompiler.tab.c"

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

#include "gocompiler.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_COMMA = 5,                      /* COMMA  */
  YYSYMBOL_BLANKID = 6,                    /* BLANKID  */
  YYSYMBOL_ASSIGN = 7,                     /* ASSIGN  */
  YYSYMBOL_STAR = 8,                       /* STAR  */
  YYSYMBOL_DIV = 9,                        /* DIV  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_PLUS = 11,                      /* PLUS  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_GE = 13,                        /* GE  */
  YYSYMBOL_GT = 14,                        /* GT  */
  YYSYMBOL_LE = 15,                        /* LE  */
  YYSYMBOL_LT = 16,                        /* LT  */
  YYSYMBOL_MOD = 17,                       /* MOD  */
  YYSYMBOL_NE = 18,                        /* NE  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_LBRACE = 22,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 23,                    /* RBRACE  */
  YYSYMBOL_LPAR = 24,                      /* LPAR  */
  YYSYMBOL_RPAR = 25,                      /* RPAR  */
  YYSYMBOL_LSQ = 26,                       /* LSQ  */
  YYSYMBOL_RSQ = 27,                       /* RSQ  */
  YYSYMBOL_PACKAGE = 28,                   /* PACKAGE  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_PRINT = 30,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 31,                  /* PARSEINT  */
  YYSYMBOL_FUNC = 32,                      /* FUNC  */
  YYSYMBOL_CMDARGS = 33,                   /* CMDARGS  */
  YYSYMBOL_VAR = 34,                       /* VAR  */
  YYSYMBOL_IF = 35,                        /* IF  */
  YYSYMBOL_ELSE = 36,                      /* ELSE  */
  YYSYMBOL_FOR = 37,                       /* FOR  */
  YYSYMBOL_INT = 38,                       /* INT  */
  YYSYMBOL_FLOAT32 = 39,                   /* FLOAT32  */
  YYSYMBOL_BOOL = 40,                      /* BOOL  */
  YYSYMBOL_IDENTIFIER = 41,                /* IDENTIFIER  */
  YYSYMBOL_NATURAL = 42,                   /* NATURAL  */
  YYSYMBOL_DECIMAL = 43,                   /* DECIMAL  */
  YYSYMBOL_STRLIT = 44,                    /* STRLIT  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_Program = 46,                   /* Program  */
  YYSYMBOL_Declarations = 47,              /* Declarations  */
  YYSYMBOL_Declarations2 = 48,             /* Declarations2  */
  YYSYMBOL_VarDeclaration = 49,            /* VarDeclaration  */
  YYSYMBOL_VarSpec = 50,                   /* VarSpec  */
  YYSYMBOL_VarSpecList = 51,               /* VarSpecList  */
  YYSYMBOL_Type = 52,                      /* Type  */
  YYSYMBOL_FuncDeclaration = 53,           /* FuncDeclaration  */
  YYSYMBOL_Parameters = 54,                /* Parameters  */
  YYSYMBOL_ParametersList = 55,            /* ParametersList  */
  YYSYMBOL_FuncBody = 56,                  /* FuncBody  */
  YYSYMBOL_VarsAndStatements = 57,         /* VarsAndStatements  */
  YYSYMBOL_Statement = 58,                 /* Statement  */
  YYSYMBOL_StatementList = 59,             /* StatementList  */
  YYSYMBOL_ParseArgs = 60,                 /* ParseArgs  */
  YYSYMBOL_FuncID = 61,                    /* FuncID  */
  YYSYMBOL_FuncInvocation = 62,            /* FuncInvocation  */
  YYSYMBOL_CommaExpressionList = 63,       /* CommaExpressionList  */
  YYSYMBOL_Expr = 64                       /* Expr  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   485

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    76,    77,    79,    83,    84,    88,    91,
      92,    95,   100,   115,   122,   130,   131,   132,   133,   136,
     146,   155,   165,   176,   184,   193,   199,   206,   211,   215,
     219,   220,   222,   229,   232,   246,   253,   261,   268,   276,
     285,   295,   299,   305,   310,   317,   320,   324,   328,   331,
     335,   340,   346,   350,   355,   361,   370,   374,   375,   379,
     384,   391,   395,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "STRING",
  "COMMA", "BLANKID", "ASSIGN", "STAR", "DIV", "MINUS", "PLUS", "EQ", "GE",
  "GT", "LE", "LT", "MOD", "NE", "NOT", "AND", "OR", "LBRACE", "RBRACE",
  "LPAR", "RPAR", "LSQ", "RSQ", "PACKAGE", "RETURN", "PRINT", "PARSEINT",
  "FUNC", "CMDARGS", "VAR", "IF", "ELSE", "FOR", "INT", "FLOAT32", "BOOL",
  "IDENTIFIER", "NATURAL", "DECIMAL", "STRLIT", "$accept", "Program",
  "Declarations", "Declarations2", "VarDeclaration", "VarSpec",
  "VarSpecList", "Type", "FuncDeclaration", "Parameters", "ParametersList",
  "FuncBody", "VarsAndStatements", "Statement", "StatementList",
  "ParseArgs", "FuncID", "FuncInvocation", "CommaExpressionList", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,   -28,    28,    15,   -72,    29,    -4,   -10,   -72,    29,
      38,    41,    25,    14,    18,   -72,    47,    57,   -72,   -72,
     -22,    65,   -72,    48,   -72,   -72,   -72,    26,   -72,   -72,
     -72,   102,    26,    67,    69,    90,   -72,   -72,    78,   -72,
      99,   102,   -72,   -72,   125,   -72,    64,   -72,    78,   -72,
     -72,   -72,   109,   -72,   297,    83,   297,   291,    81,   105,
     106,   -72,    89,   -72,    26,   -72,   -72,   111,   135,   297,
     297,   297,    92,    91,   -72,   -72,   -72,   440,   276,   410,
     151,   425,   114,   297,   -72,   -72,    10,    99,   -72,   -72,
     118,   -72,   -72,   -72,   104,   374,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   112,
     392,   160,   -72,   176,   186,   120,   440,   124,   -72,   336,
     -72,   -72,   -72,   -72,   -72,   -72,     8,     8,   314,   314,
     314,   314,   314,   -72,   314,   467,   454,   -72,   -72,   107,
     202,   -72,   -72,   211,   122,   -72,   297,   -72,     2,   129,
     127,   -72,   132,   440,   297,   -72,   227,   145,     9,   440,
     -72,   237,   253,   143,   149,   -72,   -72,   262,   -72,   297,
     -72,   354,   144,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     9,     0,     0,     6,     8,
       0,     0,    18,     0,    15,    16,    17,     0,    11,     5,
       7,     0,     0,     0,     0,    14,    12,    31,     0,    22,
      24,     0,    10,    13,     0,    21,     0,    23,     0,    20,
      51,    30,     0,    27,    45,     0,     0,     0,    56,     0,
       0,    48,     0,    47,     0,    19,    33,     0,     0,     0,
       0,     0,     0,    81,    79,    80,    82,    46,     0,     0,
       0,     0,     0,     0,    28,    29,     0,    26,    53,    34,
       0,    77,    78,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    32,     0,    57,     0,
      25,    52,    84,    83,    73,    74,    72,    71,    67,    70,
      66,    69,    65,    75,    68,    64,    63,    50,    49,    35,
       0,    42,    43,     0,     0,    60,     0,    58,     0,     0,
      36,    44,     0,    62,     0,    59,     0,     0,     0,    61,
      37,     0,     0,     0,     0,    39,    38,     0,    55,     0,
      40,     0,     0,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   -72,    -5,   158,   150,   -26,   169,   -72,
      97,    49,   -72,   -42,   -71,   -72,   -72,   -44,   -72,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,     9,    10,    15,    27,    28,    11,    33,
      47,    39,    44,    67,    68,    61,    62,    76,   148,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    36,    60,    31,    16,    38,    40,   154,    63,   113,
     163,   117,     1,     3,    13,    48,    96,    97,     5,    32,
      69,    70,    22,    23,    63,   105,    90,   155,     4,    71,
      22,    14,    79,    81,    72,   118,    63,    12,    87,    59,
     140,    18,   164,   143,    19,    91,    92,    93,    95,    20,
      29,    73,    74,    75,   110,    14,    24,    25,    26,   116,
      30,     6,   119,     7,    24,    25,    26,    63,    34,    63,
      63,    90,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   161,    82,    45,    83,    35,
      49,   167,    41,    94,    42,    23,    63,    65,    90,    63,
      37,    90,    69,    70,    46,    64,    22,    78,    84,    85,
      50,    71,    63,    86,    88,   -56,    72,    63,    63,    90,
     115,   121,   153,    63,    37,    90,    50,   144,    51,   122,
     159,    52,    66,    73,    74,    75,    50,   137,    54,    55,
      24,    25,    26,   149,    56,   171,    57,    52,    53,   145,
      58,   156,    50,   152,    54,    55,   158,    52,    89,     7,
      56,    50,    57,   157,    54,    55,    58,   162,   168,   173,
      56,    21,    57,    52,   112,   169,    58,    50,    17,     0,
      54,    55,    52,   139,   120,    43,    56,    50,    57,    54,
      55,     0,    58,     0,     0,    56,     0,    57,    52,   141,
       0,    58,     0,    50,     0,    54,    55,     0,    52,   142,
       0,    56,    50,    57,     0,    54,    55,    58,     0,     0,
       0,    56,     0,    57,    52,   150,     0,    58,    50,     0,
       0,    54,    55,    52,   151,     0,     0,    56,    50,    57,
      54,    55,     0,    58,     0,     0,    56,     0,    57,    52,
     160,     0,    58,     0,    50,     0,    54,    55,     0,    52,
     165,     0,    56,    50,    57,     0,    54,    55,    58,     0,
       0,     0,    56,     0,    57,    52,   166,     0,    58,     0,
       0,     0,    54,    55,    52,   170,    69,    70,    56,     0,
      57,    54,    55,     0,    58,    71,     0,    56,     0,    57,
      72,    69,    70,    58,     0,     0,     0,    69,    70,     0,
      71,     0,     0,    80,     0,    72,    71,    73,    74,    75,
     109,    72,    96,    97,    98,    99,     0,     0,     0,     0,
       0,   105,    73,    74,    75,     0,     0,     0,    73,    74,
      75,   146,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,     0,     0,
       0,   147,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,     0,     0,     0,     0,
       0,   172,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,     0,     0,     0,   123,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,     0,     0,     0,   138,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,   111,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,   114,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106
};

static const yytype_int16 yycheck[] =
{
      44,    27,    44,    25,     9,    31,    32,     5,    52,    80,
       1,     1,    28,    41,    24,    41,     8,     9,     3,    41,
      10,    11,     4,     5,    68,    17,    68,    25,     0,    19,
       4,    41,    56,    57,    24,    25,    80,    41,    64,    44,
     111,     3,    33,   114,     3,    69,    70,    71,    72,    24,
       3,    41,    42,    43,    78,    41,    38,    39,    40,    83,
       3,    32,    86,    34,    38,    39,    40,   111,     3,   113,
     114,   113,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   156,     5,    38,     7,    41,
      41,   162,    25,     1,    25,     5,   140,    48,   140,   143,
      22,   143,    10,    11,     5,    41,     4,    24,     3,     3,
       1,    19,   156,    24,     3,    24,    24,   161,   162,   161,
       6,     3,   146,   167,    22,   167,     1,     7,     3,    25,
     154,    22,    23,    41,    42,    43,     1,    25,    29,    30,
      38,    39,    40,    36,    35,   169,    37,    22,    23,    25,
      41,    22,     1,    31,    29,    30,    24,    22,    23,    34,
      35,     1,    37,    36,    29,    30,    41,    22,    25,    25,
      35,    13,    37,    22,    23,    26,    41,     1,     9,    -1,
      29,    30,    22,    23,    87,    35,    35,     1,    37,    29,
      30,    -1,    41,    -1,    -1,    35,    -1,    37,    22,    23,
      -1,    41,    -1,     1,    -1,    29,    30,    -1,    22,    23,
      -1,    35,     1,    37,    -1,    29,    30,    41,    -1,    -1,
      -1,    35,    -1,    37,    22,    23,    -1,    41,     1,    -1,
      -1,    29,    30,    22,    23,    -1,    -1,    35,     1,    37,
      29,    30,    -1,    41,    -1,    -1,    35,    -1,    37,    22,
      23,    -1,    41,    -1,     1,    -1,    29,    30,    -1,    22,
      23,    -1,    35,     1,    37,    -1,    29,    30,    41,    -1,
      -1,    -1,    35,    -1,    37,    22,    23,    -1,    41,    -1,
      -1,    -1,    29,    30,    22,    23,    10,    11,    35,    -1,
      37,    29,    30,    -1,    41,    19,    -1,    35,    -1,    37,
      24,    10,    11,    41,    -1,    -1,    -1,    10,    11,    -1,
      19,    -1,    -1,    22,    -1,    24,    19,    41,    42,    43,
      44,    24,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    41,    42,    43,    -1,    -1,    -1,    41,    42,
      43,     5,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    22,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    21,    22,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    46,    41,     0,     3,    32,    34,    47,    48,
      49,    53,    41,    24,    41,    50,    49,    53,     3,     3,
      24,    50,     4,     5,    38,    39,    40,    51,    52,     3,
       3,    25,    41,    54,     3,    41,    52,    22,    52,    56,
      52,    25,    25,    51,    57,    56,     5,    55,    52,    56,
       1,     3,    22,    23,    29,    30,    35,    37,    41,    49,
      58,    60,    61,    62,    41,    56,    23,    58,    59,    10,
      11,    19,    24,    41,    42,    43,    62,    64,    24,    64,
      22,    64,     5,     7,     3,     3,    24,    52,     3,    23,
      58,    64,    64,    64,     1,    64,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    20,    21,    44,
      64,    22,    23,    59,    22,     6,    64,     1,    25,    64,
      55,     3,    25,    25,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    25,    25,    23,
      59,    23,    23,    59,     7,    25,     5,    25,    63,    36,
      23,    23,    31,    64,     5,    25,    22,    36,    24,    64,
      23,    59,    22,     1,    33,    23,    23,    59,    25,    26,
      23,    64,    27,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    49,
      49,    50,    50,    51,    51,    52,    52,    52,    52,    53,
      53,    53,    53,    54,    54,    55,    55,    56,    57,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    62,    62,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     0,     3,     2,     3,     2,     2,
       5,     2,     3,     3,     2,     1,     1,     1,     1,     7,
       6,     6,     5,     3,     2,     4,     3,     3,     3,     3,
       2,     0,     3,     2,     3,     4,     5,     7,     8,     8,
       9,     3,     4,     4,     5,     1,     2,     1,     1,     4,
       4,     1,     3,     2,    11,     8,     1,     3,     4,     5,
       4,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     1,
       1,     1,     1,     3,     3
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
  case 2: /* Program: PACKAGE IDENTIFIER SEMICOLON Declarations  */
#line 70 "gocompiler.y"
                                                   {
    program_root = newNode("Program", NULL);
    addchild(program_root, (yyvsp[0].node));
}
#line 1320 "gocompiler.tab.c"
    break;

  case 3: /* Declarations: Declarations2  */
#line 76 "gocompiler.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1326 "gocompiler.tab.c"
    break;

  case 4: /* Declarations: %empty  */
#line 77 "gocompiler.y"
                            { (yyval.node) = NULL; }
#line 1332 "gocompiler.tab.c"
    break;

  case 5: /* Declarations2: Declarations2 VarDeclaration SEMICOLON  */
#line 79 "gocompiler.y"
                                                      {
    (yyval.node) = (yyvsp[-2].node);
    addsiblings((yyvsp[-2].node), (yyvsp[-1].node));
}
#line 1341 "gocompiler.tab.c"
    break;

  case 6: /* Declarations2: VarDeclaration SEMICOLON  */
#line 83 "gocompiler.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1347 "gocompiler.tab.c"
    break;

  case 7: /* Declarations2: Declarations2 FuncDeclaration SEMICOLON  */
#line 84 "gocompiler.y"
                                          {
    (yyval.node) = (yyvsp[-2].node);
    addsiblings((yyvsp[-2].node), (yyvsp[-1].node));
}
#line 1356 "gocompiler.tab.c"
    break;

  case 8: /* Declarations2: FuncDeclaration SEMICOLON  */
#line 88 "gocompiler.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1362 "gocompiler.tab.c"
    break;

  case 9: /* VarDeclaration: VAR VarSpec  */
#line 91 "gocompiler.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1368 "gocompiler.tab.c"
    break;

  case 10: /* VarDeclaration: VAR LPAR VarSpec SEMICOLON RPAR  */
#line 92 "gocompiler.y"
                                                { (yyval.node) = (yyvsp[-2].node); }
#line 1374 "gocompiler.tab.c"
    break;

  case 11: /* VarSpec: IDENTIFIER Type  */
#line 95 "gocompiler.y"
                         {
    (yyval.node) = newNode("VarDecl", NULL);
    addchild((yyval.node), (yyvsp[0].node));
    addsiblings((yyvsp[0].node), newNode("IDENTIFIER", (yyvsp[-1].value)));
}
#line 1384 "gocompiler.tab.c"
    break;

  case 12: /* VarSpec: IDENTIFIER VarSpecList Type  */
#line 100 "gocompiler.y"
                              {
    (yyval.node) = newNode("VarDecl", NULL);
    aux = newNode("IDENTIFIER", (yyvsp[-2].value));
    addchild((yyval.node), (yyvsp[0].node));
    addsiblings((yyvsp[0].node), aux);
    addsiblings((yyval.node), (yyvsp[-1].node));

    varspec_aux = (yyval.node)->sibling;
    while (varspec_aux != NULL && strcmp(varspec_aux->children->node->token, "notype") == 0) {
        strcpy(varspec_aux->children->node->token, (yyvsp[0].node)->token);
        varspec_aux = varspec_aux->sibling;
    }
}
#line 1402 "gocompiler.tab.c"
    break;

  case 13: /* VarSpecList: COMMA IDENTIFIER VarSpecList  */
#line 115 "gocompiler.y"
                                          {
    (yyval.node) = newNode("VarDecl", NULL);
    varspec_aux1 = newNode("notype", NULL);
    addsiblings((yyval.node), (yyvsp[0].node));
    addchild((yyval.node), varspec_aux1);
    addsiblings(varspec_aux1, newNode("IDENTIFIER", (yyvsp[-1].value)));
}
#line 1414 "gocompiler.tab.c"
    break;

  case 14: /* VarSpecList: COMMA IDENTIFIER  */
#line 122 "gocompiler.y"
                   {
    (yyval.node) = newNode("VarDecl", NULL);
    aux = newNode("notype", NULL);
    addchild((yyval.node), aux);
    addsiblings(aux, newNode("IDENTIFIER", (yyvsp[0].value)));
}
#line 1425 "gocompiler.tab.c"
    break;

  case 15: /* Type: INT  */
#line 130 "gocompiler.y"
          { (yyval.node) = newNode("Int", NULL); }
#line 1431 "gocompiler.tab.c"
    break;

  case 16: /* Type: FLOAT32  */
#line 131 "gocompiler.y"
              { (yyval.node) = newNode("Float32", NULL); }
#line 1437 "gocompiler.tab.c"
    break;

  case 17: /* Type: BOOL  */
#line 132 "gocompiler.y"
           { (yyval.node) = newNode("Bool", NULL); }
#line 1443 "gocompiler.tab.c"
    break;

  case 18: /* Type: STRING  */
#line 133 "gocompiler.y"
             { (yyval.node) = newNode("String", NULL); }
#line 1449 "gocompiler.tab.c"
    break;

  case 19: /* FuncDeclaration: FUNC IDENTIFIER LPAR Parameters RPAR Type FuncBody  */
#line 136 "gocompiler.y"
                                                                    {
    (yyval.node) = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", (yyvsp[-5].value));
    addchild((yyval.node), aux);
    addsiblings(aux, (yyvsp[0].node));
    addchild(aux, aux2);
    addsiblings((yyvsp[-1].node), (yyvsp[-3].node));
    addsiblings(aux2, (yyvsp[-1].node));
}
#line 1464 "gocompiler.tab.c"
    break;

  case 20: /* FuncDeclaration: FUNC IDENTIFIER LPAR Parameters RPAR FuncBody  */
#line 146 "gocompiler.y"
                                                {
    (yyval.node) = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", (yyvsp[-4].value));
    addchild((yyval.node), aux);
    addsiblings(aux, (yyvsp[0].node));
    addchild(aux, aux2);
    addsiblings(aux2, (yyvsp[-2].node));
}
#line 1478 "gocompiler.tab.c"
    break;

  case 21: /* FuncDeclaration: FUNC IDENTIFIER LPAR RPAR Type FuncBody  */
#line 155 "gocompiler.y"
                                          {
    (yyval.node) = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", (yyvsp[-4].value));
    addchild((yyval.node), aux);
    addsiblings(aux, (yyvsp[0].node));
    addchild(aux, aux2);
    addsiblings(aux2, (yyvsp[-1].node));
    addsiblings((yyvsp[-1].node), newNode("FuncParams", NULL));
}
#line 1493 "gocompiler.tab.c"
    break;

  case 22: /* FuncDeclaration: FUNC IDENTIFIER LPAR RPAR FuncBody  */
#line 165 "gocompiler.y"
                                     {
    (yyval.node) = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", (yyvsp[-3].value));
    addchild((yyval.node), aux);
    addchild(aux, aux2);
    addsiblings(aux2, newNode("FuncParams", NULL));
    addsiblings(aux, (yyvsp[0].node));
}
#line 1507 "gocompiler.tab.c"
    break;

  case 23: /* Parameters: IDENTIFIER Type ParametersList  */
#line 176 "gocompiler.y"
                                           {
    (yyval.node) = newNode("FuncParams", NULL);
    aux = newNode("ParamDecl", NULL);
    addchild((yyval.node), aux);
    addsiblings(aux, (yyvsp[0].node));
    addchild(aux, (yyvsp[-1].node));
    addsiblings((yyvsp[-1].node), newNode("IDENTIFIER", (yyvsp[-2].value)));
}
#line 1520 "gocompiler.tab.c"
    break;

  case 24: /* Parameters: IDENTIFIER Type  */
#line 184 "gocompiler.y"
                  {
    (yyval.node) = newNode("FuncParams", NULL);
    aux = newNode("ParamDecl", NULL);
    addchild((yyval.node), aux);
    addchild(aux, (yyvsp[0].node));
    addsiblings((yyvsp[0].node), newNode("IDENTIFIER", (yyvsp[-1].value)));
}
#line 1532 "gocompiler.tab.c"
    break;

  case 25: /* ParametersList: COMMA IDENTIFIER Type ParametersList  */
#line 193 "gocompiler.y"
                                                     {
    (yyval.node) = newNode("ParamDecl", NULL);
    addchild((yyval.node), (yyvsp[-1].node));
    addsiblings((yyvsp[-1].node), newNode("IDENTIFIER", (yyvsp[-2].value)));
    addsiblings((yyval.node), (yyvsp[0].node));
}
#line 1543 "gocompiler.tab.c"
    break;

  case 26: /* ParametersList: COMMA IDENTIFIER Type  */
#line 199 "gocompiler.y"
                        {
    (yyval.node) = newNode("ParamDecl", NULL);
    addchild((yyval.node), (yyvsp[0].node));
    addsiblings((yyvsp[0].node), newNode("IDENTIFIER", (yyvsp[-1].value)));
}
#line 1553 "gocompiler.tab.c"
    break;

  case 27: /* FuncBody: LBRACE VarsAndStatements RBRACE  */
#line 206 "gocompiler.y"
                                          {
    (yyval.node) = newNode("FuncBody", NULL);
    addchild((yyval.node), (yyvsp[-1].node));
}
#line 1562 "gocompiler.tab.c"
    break;

  case 28: /* VarsAndStatements: VarsAndStatements VarDeclaration SEMICOLON  */
#line 211 "gocompiler.y"
                                                              {
    (yyval.node) = (yyvsp[-2].node);
    addsiblings((yyvsp[-2].node), (yyvsp[-1].node));
}
#line 1571 "gocompiler.tab.c"
    break;

  case 29: /* VarsAndStatements: VarsAndStatements Statement SEMICOLON  */
#line 215 "gocompiler.y"
                                        {
    (yyval.node) = (yyvsp[-2].node);
    addsiblings((yyvsp[-2].node), (yyvsp[-1].node));
}
#line 1580 "gocompiler.tab.c"
    break;

  case 30: /* VarsAndStatements: VarsAndStatements SEMICOLON  */
#line 219 "gocompiler.y"
                              { (yyvsp[-1].node) = (yyvsp[-1].node); }
#line 1586 "gocompiler.tab.c"
    break;

  case 31: /* VarsAndStatements: %empty  */
#line 220 "gocompiler.y"
                { (yyval.node) = newNode("NULL", NULL); }
#line 1592 "gocompiler.tab.c"
    break;

  case 32: /* Statement: IDENTIFIER ASSIGN Expr  */
#line 222 "gocompiler.y"
                                  {
    (yyval.node) = newNode("Assign", NULL);
    aux = newNode("IDENTIFIER", (yyvsp[-2].value));
    addchild((yyval.node), aux);
    addsiblings(aux, (yyvsp[0].node));
}
#line 1603 "gocompiler.tab.c"
    break;

  case 33: /* Statement: LBRACE RBRACE  */
#line 229 "gocompiler.y"
                {
    (yyval.node) = newNode("NULL", NULL);
}
#line 1611 "gocompiler.tab.c"
    break;

  case 34: /* Statement: LBRACE StatementList RBRACE  */
#line 232 "gocompiler.y"
                              {
    aux = (yyvsp[-1].node);
    int n = 0;
    while (aux != NULL) {
        if (strcmp(aux->token, "NULL") != 0) n++;
        aux = aux->sibling;
    }
    if (n >= 2) {
        (yyval.node) = newNode("Block", NULL);
        addchild((yyval.node), (yyvsp[-1].node));
    } else {
        (yyval.node) = (yyvsp[-1].node);
    }
}
#line 1630 "gocompiler.tab.c"
    break;

  case 35: /* Statement: IF Expr LBRACE RBRACE  */
#line 246 "gocompiler.y"
                        {
    (yyval.node) = newNode("If", NULL);
    addchild((yyval.node), (yyvsp[-2].node));
    aux = newNode("Block", NULL);
    addsiblings((yyvsp[-2].node), aux);
    addsiblings(aux, newNode("Block", NULL));
}
#line 1642 "gocompiler.tab.c"
    break;

  case 36: /* Statement: IF Expr LBRACE StatementList RBRACE  */
#line 253 "gocompiler.y"
                                      {
    (yyval.node) = newNode("If", NULL);
    addchild((yyval.node), (yyvsp[-3].node));
    aux = newNode("Block", NULL);
    addsiblings((yyvsp[-3].node), aux);
    addchild(aux, (yyvsp[-1].node));
    addsiblings(aux, newNode("Block", NULL));
}
#line 1655 "gocompiler.tab.c"
    break;

  case 37: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE RBRACE  */
#line 261 "gocompiler.y"
                                           {
    (yyval.node) = newNode("If", NULL);
    addchild((yyval.node), (yyvsp[-5].node));
    aux = newNode("Block", NULL);
    addsiblings((yyvsp[-5].node), aux);
    addsiblings(aux, newNode("Block", NULL));
}
#line 1667 "gocompiler.tab.c"
    break;

  case 38: /* Statement: IF Expr LBRACE StatementList RBRACE ELSE LBRACE RBRACE  */
#line 268 "gocompiler.y"
                                                         {
    (yyval.node) = newNode("If", NULL);
    addchild((yyval.node), (yyvsp[-6].node));
    aux = newNode("Block", NULL);
    addsiblings((yyvsp[-6].node), aux);
    addchild(aux, (yyvsp[-4].node));
    addsiblings(aux, newNode("Block", NULL));
}
#line 1680 "gocompiler.tab.c"
    break;

  case 39: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE StatementList RBRACE  */
#line 276 "gocompiler.y"
                                                         {
    (yyval.node) = newNode("If", NULL);
    addchild((yyval.node), (yyvsp[-6].node));
    aux = newNode("Block", NULL);
    aux2 = newNode("Block", NULL);
    addsiblings((yyvsp[-6].node), aux);
    addsiblings(aux, aux2);
    addchild(aux2, (yyvsp[-1].node));
}
#line 1694 "gocompiler.tab.c"
    break;

  case 40: /* Statement: IF Expr LBRACE StatementList RBRACE ELSE LBRACE StatementList RBRACE  */
#line 285 "gocompiler.y"
                                                                       {
    (yyval.node) = newNode("If", NULL);
    addchild((yyval.node), (yyvsp[-7].node));
    aux = newNode("Block", NULL);
    aux2 = newNode("Block", NULL);
    addsiblings((yyvsp[-7].node), aux);
    addchild(aux, (yyvsp[-5].node));
    addsiblings(aux, aux2);
    addchild(aux2, (yyvsp[-1].node));
}
#line 1709 "gocompiler.tab.c"
    break;

  case 41: /* Statement: FOR LBRACE RBRACE  */
#line 295 "gocompiler.y"
                    {
    (yyval.node) = newNode("For", NULL);
    addchild((yyval.node), newNode("Block", NULL));
}
#line 1718 "gocompiler.tab.c"
    break;

  case 42: /* Statement: FOR LBRACE StatementList RBRACE  */
#line 299 "gocompiler.y"
                                  {
    (yyval.node) = newNode("For", NULL);
    aux = newNode("Block", NULL);
    addchild((yyval.node), aux);
    addchild(aux, (yyvsp[-1].node));
}
#line 1729 "gocompiler.tab.c"
    break;

  case 43: /* Statement: FOR Expr LBRACE RBRACE  */
#line 305 "gocompiler.y"
                         {
    (yyval.node) = newNode("For", NULL);
    addchild((yyval.node), (yyvsp[-2].node));
    addsiblings((yyvsp[-2].node), newNode("Block", NULL));
}
#line 1739 "gocompiler.tab.c"
    break;

  case 44: /* Statement: FOR Expr LBRACE StatementList RBRACE  */
#line 310 "gocompiler.y"
                                       {
    (yyval.node) = newNode("For", NULL);
    addchild((yyval.node), (yyvsp[-3].node));
    aux = newNode("Block", NULL);
    addsiblings((yyvsp[-3].node), aux);
    addchild(aux, (yyvsp[-1].node));
}
#line 1751 "gocompiler.tab.c"
    break;

  case 45: /* Statement: RETURN  */
#line 317 "gocompiler.y"
         {
    (yyval.node) = newNode("Return", NULL);
}
#line 1759 "gocompiler.tab.c"
    break;

  case 46: /* Statement: RETURN Expr  */
#line 320 "gocompiler.y"
              {
    (yyval.node) = newNode("Return", NULL);
    addchild((yyval.node), (yyvsp[0].node));
}
#line 1768 "gocompiler.tab.c"
    break;

  case 47: /* Statement: FuncInvocation  */
#line 324 "gocompiler.y"
                 {
    (yyval.node) = newNode("Call", NULL);
    addchild((yyval.node), (yyvsp[0].node));
}
#line 1777 "gocompiler.tab.c"
    break;

  case 48: /* Statement: ParseArgs  */
#line 328 "gocompiler.y"
            {
    (yyval.node) = (yyvsp[0].node);
}
#line 1785 "gocompiler.tab.c"
    break;

  case 49: /* Statement: PRINT LPAR Expr RPAR  */
#line 331 "gocompiler.y"
                       {
    (yyval.node) = newNode("Print", NULL);
    addchild((yyval.node), (yyvsp[-1].node));
}
#line 1794 "gocompiler.tab.c"
    break;

  case 50: /* Statement: PRINT LPAR STRLIT RPAR  */
#line 335 "gocompiler.y"
                         { 
    (yyval.node) = newNode("Print", NULL); 
    aux = newNode("StrLit", (yyvsp[-1].value)); 
    addchild((yyval.node), aux);}
#line 1803 "gocompiler.tab.c"
    break;

  case 51: /* Statement: error  */
#line 340 "gocompiler.y"
        {
    (yyval.node) = newNode("Error", NULL);
    freetree(program_root);         //ALTERACAO
}
#line 1812 "gocompiler.tab.c"
    break;

  case 52: /* StatementList: StatementList Statement SEMICOLON  */
#line 346 "gocompiler.y"
                                                 {
    (yyval.node) = (yyvsp[-2].node);
    addsiblings((yyvsp[-2].node), (yyvsp[-1].node));
}
#line 1821 "gocompiler.tab.c"
    break;

  case 53: /* StatementList: Statement SEMICOLON  */
#line 350 "gocompiler.y"
                      {
    (yyval.node) = (yyvsp[-1].node);
}
#line 1829 "gocompiler.tab.c"
    break;

  case 54: /* ParseArgs: IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR  */
#line 355 "gocompiler.y"
                                                                                   {
    (yyval.node) = newNode("ParseArgs", NULL);
    aux = newNode("IDENTIFIER", (yyvsp[-10].value));
    addchild((yyval.node), aux);
    addsiblings(aux, (yyvsp[-2].node));
}
#line 1840 "gocompiler.tab.c"
    break;

  case 55: /* ParseArgs: IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR  */
#line 361 "gocompiler.y"
                                                           {
    (yyval.node) = newNode("ParseArgs", NULL);
    aux = newNode("IDENTIFIER", (yyvsp[-7].value));
    addchild((yyval.node), aux);
    addsiblings(aux, newNode("Error", NULL));
    freetree(program_root);         //ALTERACAO
}
#line 1852 "gocompiler.tab.c"
    break;

  case 56: /* FuncID: IDENTIFIER  */
#line 372 "gocompiler.y"
    {(yyval.node) = newNode("IDENTIFIER", (yyvsp[0].value));}
#line 1858 "gocompiler.tab.c"
    break;

  case 57: /* FuncInvocation: FuncID LPAR RPAR  */
#line 374 "gocompiler.y"
                                 { (yyval.node) = (yyvsp[-2].node); }
#line 1864 "gocompiler.tab.c"
    break;

  case 58: /* FuncInvocation: FuncID LPAR Expr RPAR  */
#line 375 "gocompiler.y"
                        {
    (yyval.node) = (yyvsp[-3].node);
    addsiblings((yyvsp[-3].node), (yyvsp[-1].node));
}
#line 1873 "gocompiler.tab.c"
    break;

  case 59: /* FuncInvocation: FuncID LPAR Expr CommaExpressionList RPAR  */
#line 379 "gocompiler.y"
                                            {
    (yyval.node) = (yyvsp[-4].node);
    addsiblings((yyvsp[-4].node), (yyvsp[-2].node));
    addsiblings((yyvsp[-2].node), (yyvsp[-1].node));
}
#line 1883 "gocompiler.tab.c"
    break;

  case 60: /* FuncInvocation: FuncID LPAR error RPAR  */
#line 384 "gocompiler.y"
                         {
    (yyval.node) = (yyvsp[-3].node);
    addsiblings((yyvsp[-3].node), newNode("Error", NULL));
    freetree(program_root);         //ALTERACAO
}
#line 1893 "gocompiler.tab.c"
    break;

  case 61: /* CommaExpressionList: CommaExpressionList COMMA Expr  */
#line 391 "gocompiler.y"
                                                    {
    (yyval.node) = (yyvsp[-2].node);
    addsiblings((yyvsp[-2].node), (yyvsp[0].node));
}
#line 1902 "gocompiler.tab.c"
    break;

  case 62: /* CommaExpressionList: COMMA Expr  */
#line 395 "gocompiler.y"
             {
    (yyval.node) = (yyvsp[0].node);
}
#line 1910 "gocompiler.tab.c"
    break;

  case 63: /* Expr: Expr OR Expr  */
#line 400 "gocompiler.y"
                     {(yyval.node) = newNode("Or", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1916 "gocompiler.tab.c"
    break;

  case 64: /* Expr: Expr AND Expr  */
#line 401 "gocompiler.y"
                {(yyval.node) = newNode("And", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1922 "gocompiler.tab.c"
    break;

  case 65: /* Expr: Expr LT Expr  */
#line 402 "gocompiler.y"
               {(yyval.node) = newNode("Lt", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1928 "gocompiler.tab.c"
    break;

  case 66: /* Expr: Expr GT Expr  */
#line 403 "gocompiler.y"
               {(yyval.node) = newNode("Gt", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1934 "gocompiler.tab.c"
    break;

  case 67: /* Expr: Expr EQ Expr  */
#line 404 "gocompiler.y"
               {(yyval.node) = newNode("Eq", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1940 "gocompiler.tab.c"
    break;

  case 68: /* Expr: Expr NE Expr  */
#line 405 "gocompiler.y"
               {(yyval.node) = newNode("Ne", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1946 "gocompiler.tab.c"
    break;

  case 69: /* Expr: Expr LE Expr  */
#line 406 "gocompiler.y"
               {(yyval.node) = newNode("Le", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1952 "gocompiler.tab.c"
    break;

  case 70: /* Expr: Expr GE Expr  */
#line 407 "gocompiler.y"
               {(yyval.node) = newNode("Ge", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1958 "gocompiler.tab.c"
    break;

  case 71: /* Expr: Expr PLUS Expr  */
#line 408 "gocompiler.y"
                 {(yyval.node) = newNode("Add", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1964 "gocompiler.tab.c"
    break;

  case 72: /* Expr: Expr MINUS Expr  */
#line 409 "gocompiler.y"
                  {(yyval.node) = newNode("Sub", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1970 "gocompiler.tab.c"
    break;

  case 73: /* Expr: Expr STAR Expr  */
#line 410 "gocompiler.y"
                 {(yyval.node) = newNode("Mul", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1976 "gocompiler.tab.c"
    break;

  case 74: /* Expr: Expr DIV Expr  */
#line 411 "gocompiler.y"
                {(yyval.node) = newNode("Div", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1982 "gocompiler.tab.c"
    break;

  case 75: /* Expr: Expr MOD Expr  */
#line 412 "gocompiler.y"
                {(yyval.node) = newNode("Mod", NULL); addchild((yyval.node), (yyvsp[-2].node)); addsiblings((yyvsp[-2].node), (yyvsp[0].node));}
#line 1988 "gocompiler.tab.c"
    break;

  case 76: /* Expr: NOT Expr  */
#line 413 "gocompiler.y"
           {(yyval.node) = newNode("Not", NULL); addchild((yyval.node), (yyvsp[0].node));}
#line 1994 "gocompiler.tab.c"
    break;

  case 77: /* Expr: MINUS Expr  */
#line 414 "gocompiler.y"
                       {(yyval.node) = newNode("Minus", NULL); addchild((yyval.node), (yyvsp[0].node));}
#line 2000 "gocompiler.tab.c"
    break;

  case 78: /* Expr: PLUS Expr  */
#line 415 "gocompiler.y"
                      {(yyval.node) = newNode("Plus", NULL); addchild((yyval.node), (yyvsp[0].node));}
#line 2006 "gocompiler.tab.c"
    break;

  case 79: /* Expr: NATURAL  */
#line 416 "gocompiler.y"
          {(yyval.node) = newNode("NATURAL", (yyvsp[0].value));}
#line 2012 "gocompiler.tab.c"
    break;

  case 80: /* Expr: DECIMAL  */
#line 417 "gocompiler.y"
          {(yyval.node) = newNode("DECIMAL", (yyvsp[0].value));}
#line 2018 "gocompiler.tab.c"
    break;

  case 81: /* Expr: IDENTIFIER  */
#line 418 "gocompiler.y"
             {(yyval.node) = newNode("IDENTIFIER", (yyvsp[0].value));}
#line 2024 "gocompiler.tab.c"
    break;

  case 82: /* Expr: FuncInvocation  */
#line 419 "gocompiler.y"
                 {(yyval.node) = newNode("Call", NULL); addchild((yyval.node), (yyvsp[0].node));}
#line 2030 "gocompiler.tab.c"
    break;

  case 83: /* Expr: LPAR Expr RPAR  */
#line 420 "gocompiler.y"
                 {(yyval.node) = (yyvsp[-1].node);}
#line 2036 "gocompiler.tab.c"
    break;

  case 84: /* Expr: LPAR error RPAR  */
#line 421 "gocompiler.y"
                  {(yyval.node) = newNode("Error", NULL);freetree(program_root);}
#line 2042 "gocompiler.tab.c"
    break;


#line 2046 "gocompiler.tab.c"

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

#line 423 "gocompiler.y"
 
