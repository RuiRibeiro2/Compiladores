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

// Estrutura para tracking de posição no código fonte
#define TRACK_POSITION(node, l, c) do { \
    if (node) { \
        node->line = l; \
        node->col = c; \
    } \
} while(0)

node* program_root = NULL;
node* aux;
node* varspec_aux;
node* varspec_aux1 = NULL;
node* aux2 = NULL;


#line 103 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    NATURAL = 259,                 /* NATURAL  */
    DECIMAL = 260,                 /* DECIMAL  */
    STRLIT = 261,                  /* STRLIT  */
    SEMICOLON = 262,               /* SEMICOLON  */
    COMMA = 263,                   /* COMMA  */
    BLANKID = 264,                 /* BLANKID  */
    PACKAGE = 265,                 /* PACKAGE  */
    FUNC = 266,                    /* FUNC  */
    VAR = 267,                     /* VAR  */
    INT = 268,                     /* INT  */
    FLOAT32 = 269,                 /* FLOAT32  */
    BOOL = 270,                    /* BOOL  */
    STRING = 271,                  /* STRING  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    FOR = 274,                     /* FOR  */
    RETURN = 275,                  /* RETURN  */
    PRINT = 276,                   /* PRINT  */
    PARSEINT = 277,                /* PARSEINT  */
    CMDARGS = 278,                 /* CMDARGS  */
    ASSIGN = 279,                  /* ASSIGN  */
    OR = 280,                      /* OR  */
    AND = 281,                     /* AND  */
    EQ = 282,                      /* EQ  */
    NE = 283,                      /* NE  */
    LT = 284,                      /* LT  */
    LE = 285,                      /* LE  */
    GT = 286,                      /* GT  */
    GE = 287,                      /* GE  */
    PLUS = 288,                    /* PLUS  */
    MINUS = 289,                   /* MINUS  */
    STAR = 290,                    /* STAR  */
    DIV = 291,                     /* DIV  */
    MOD = 292,                     /* MOD  */
    NOT = 293,                     /* NOT  */
    LBRACE = 294,                  /* LBRACE  */
    RBRACE = 295,                  /* RBRACE  */
    LPAR = 296,                    /* LPAR  */
    RPAR = 297,                    /* RPAR  */
    LSQ = 298,                     /* LSQ  */
    RSQ = 299                      /* RSQ  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define NATURAL 259
#define DECIMAL 260
#define STRLIT 261
#define SEMICOLON 262
#define COMMA 263
#define BLANKID 264
#define PACKAGE 265
#define FUNC 266
#define VAR 267
#define INT 268
#define FLOAT32 269
#define BOOL 270
#define STRING 271
#define IF 272
#define ELSE 273
#define FOR 274
#define RETURN 275
#define PRINT 276
#define PARSEINT 277
#define CMDARGS 278
#define ASSIGN 279
#define OR 280
#define AND 281
#define EQ 282
#define NE 283
#define LT 284
#define LE 285
#define GT 286
#define GE 287
#define PLUS 288
#define MINUS 289
#define STAR 290
#define DIV 291
#define MOD 292
#define NOT 293
#define LBRACE 294
#define RBRACE 295
#define LPAR 296
#define RPAR 297
#define LSQ 298
#define RSQ 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "gocompiler.y"

    char* token_value;      // Valores de tokens (identificadores, literais, etc)
    struct node* ast_node;  // Nós da árvore sintática abstrata

#line 249 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_NATURAL = 4,                    /* NATURAL  */
  YYSYMBOL_DECIMAL = 5,                    /* DECIMAL  */
  YYSYMBOL_STRLIT = 6,                     /* STRLIT  */
  YYSYMBOL_SEMICOLON = 7,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 8,                      /* COMMA  */
  YYSYMBOL_BLANKID = 9,                    /* BLANKID  */
  YYSYMBOL_PACKAGE = 10,                   /* PACKAGE  */
  YYSYMBOL_FUNC = 11,                      /* FUNC  */
  YYSYMBOL_VAR = 12,                       /* VAR  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_FLOAT32 = 14,                   /* FLOAT32  */
  YYSYMBOL_BOOL = 15,                      /* BOOL  */
  YYSYMBOL_STRING = 16,                    /* STRING  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_PRINT = 21,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 22,                  /* PARSEINT  */
  YYSYMBOL_CMDARGS = 23,                   /* CMDARGS  */
  YYSYMBOL_ASSIGN = 24,                    /* ASSIGN  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_EQ = 27,                        /* EQ  */
  YYSYMBOL_NE = 28,                        /* NE  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_LE = 30,                        /* LE  */
  YYSYMBOL_GT = 31,                        /* GT  */
  YYSYMBOL_GE = 32,                        /* GE  */
  YYSYMBOL_PLUS = 33,                      /* PLUS  */
  YYSYMBOL_MINUS = 34,                     /* MINUS  */
  YYSYMBOL_STAR = 35,                      /* STAR  */
  YYSYMBOL_DIV = 36,                       /* DIV  */
  YYSYMBOL_MOD = 37,                       /* MOD  */
  YYSYMBOL_NOT = 38,                       /* NOT  */
  YYSYMBOL_LBRACE = 39,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 40,                    /* RBRACE  */
  YYSYMBOL_LPAR = 41,                      /* LPAR  */
  YYSYMBOL_RPAR = 42,                      /* RPAR  */
  YYSYMBOL_LSQ = 43,                       /* LSQ  */
  YYSYMBOL_RSQ = 44,                       /* RSQ  */
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
#define YYLAST   463

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
       0,    89,    89,    95,    96,    98,   102,   103,   107,   110,
     111,   114,   119,   134,   141,   149,   150,   151,   152,   155,
     165,   174,   184,   195,   203,   212,   218,   225,   230,   234,
     238,   239,   241,   248,   251,   265,   272,   280,   287,   295,
     304,   314,   318,   324,   329,   336,   339,   343,   347,   350,
     354,   359,   365,   369,   374,   380,   389,   393,   394,   398,
     403,   410,   414,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440
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
  "NATURAL", "DECIMAL", "STRLIT", "SEMICOLON", "COMMA", "BLANKID",
  "PACKAGE", "FUNC", "VAR", "INT", "FLOAT32", "BOOL", "STRING", "IF",
  "ELSE", "FOR", "RETURN", "PRINT", "PARSEINT", "CMDARGS", "ASSIGN", "OR",
  "AND", "EQ", "NE", "LT", "LE", "GT", "GE", "PLUS", "MINUS", "STAR",
  "DIV", "MOD", "NOT", "LBRACE", "RBRACE", "LPAR", "RPAR", "LSQ", "RSQ",
  "$accept", "Program", "Declarations", "Declarations2", "VarDeclaration",
  "VarSpec", "VarSpecList", "Type", "FuncDeclaration", "Parameters",
  "ParametersList", "FuncBody", "VarsAndStatements", "Statement",
  "StatementList", "ParseArgs", "FuncID", "FuncInvocation",
  "CommaExpressionList", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,     7,    11,    10,   -51,    49,    17,    -2,   -51,    49,
      23,    37,   -14,   275,    59,   -51,    57,    62,   -51,   -51,
       0,    68,   -51,   -51,   -51,   -51,   290,   -51,    66,   -51,
     -51,   290,    20,    34,    69,   -51,    36,    72,   -51,    42,
     -51,    20,   -51,   -51,    79,   -51,    67,   -51,    42,   -51,
     290,   -51,     5,   -51,   282,   261,   282,    44,   143,   -51,
      76,    82,   -51,    50,   -51,   -51,    72,    81,   282,    52,
     -51,   -51,   282,   282,   282,   109,   -51,   373,   148,   388,
     403,   276,   -51,    92,   153,   -51,   -51,    97,   -51,    84,
     403,   -51,   -51,   -51,    61,   337,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   158,
     -51,   183,   188,    63,   355,   -51,   -51,   102,    73,   -51,
     299,    99,   -51,   -51,   415,   426,   322,   322,   322,   322,
     322,   322,   -21,   -21,   -51,   -51,   -51,   104,   193,   -51,
     -51,   198,   -51,   -51,   -51,   -51,   282,   -51,     1,    83,
      87,   110,   -51,   403,   282,   -51,     3,   223,    90,   403,
      91,    89,   -51,   228,   233,   -51,   282,   -51,   -51,   238,
     317,   -51,    94,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     9,     0,     0,     6,     8,
       0,     0,    15,    16,    17,    18,     0,    11,     0,     5,
       7,     0,     0,     0,    14,    12,     0,    24,    31,     0,
      22,     0,    13,    10,     0,    23,     0,    21,     0,    20,
       0,    51,    56,    30,     0,     0,    45,     0,     0,    27,
       0,     0,    48,     0,    47,    19,    26,     0,     0,    81,
      79,    80,     0,     0,     0,     0,    82,     0,     0,     0,
      46,     0,    33,     0,     0,    28,    29,     0,    25,     0,
      32,    78,    77,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,     0,    53,    34,     0,     0,    57,
       0,     0,    84,    83,    63,    64,    67,    68,    65,    69,
      66,    70,    71,    72,    73,    74,    75,    35,     0,    42,
      43,     0,    50,    49,    52,    60,     0,    58,     0,     0,
       0,    36,    44,    62,     0,    59,     0,     0,     0,    61,
       0,     0,    37,     0,     0,    55,     0,    39,    38,     0,
       0,    40,     0,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,   -51,   -51,    -1,   120,   103,   243,   131,   -51,
      75,   -20,   -51,   -44,   -37,   -51,   -51,   -46,   -51,   -50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,     9,    10,    15,    26,    27,    11,    33,
      45,    40,    46,    83,    84,    62,    63,    76,   148,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    13,    61,    31,   160,    79,    80,     1,    16,   154,
       3,     4,    64,    67,   106,   107,   108,     5,    90,    47,
      12,    49,    91,    92,    93,    95,   161,    20,    65,    68,
      18,   114,    64,    22,    23,    24,    25,   120,    64,    14,
     117,   111,    32,   155,    19,    60,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,    38,
       6,     7,    13,    64,    29,    64,    64,   117,    51,    30,
      52,    34,   138,    36,    53,   141,    41,    21,    43,     7,
      44,    38,    50,    85,    54,    81,    55,    56,    57,    86,
      89,    87,    64,   -56,   117,    64,   153,   117,   118,   115,
      69,    70,    71,   122,   159,   142,    58,    59,   121,   144,
      94,    64,    69,    70,    71,   145,   170,    64,    64,   117,
     163,   149,   150,    64,   156,   117,   157,   169,   158,   164,
      72,    73,   166,   165,    28,    74,   173,    42,    75,   119,
      17,    88,    72,    73,    51,     0,    52,    74,     0,    51,
      75,    52,     0,     0,    51,     0,    52,     0,     0,    51,
      54,    52,    55,    56,    57,    54,     0,    55,    56,    57,
      54,     0,    55,    56,    57,    54,     0,    55,    56,    57,
       0,     0,    58,    82,    51,     0,    52,    58,   110,    51,
       0,    52,    58,   116,    51,     0,    52,    58,   137,    51,
      54,    52,    55,    56,    57,    54,     0,    55,    56,    57,
      54,     0,    55,    56,    57,    54,     0,    55,    56,    57,
       0,     0,    58,   139,    51,     0,    52,    58,   140,    51,
       0,    52,    58,   151,    51,     0,    52,    58,   152,    51,
      54,    52,    55,    56,    57,    54,     0,    55,    56,    57,
      54,     0,    55,    56,    57,    54,     0,    55,    56,    57,
       0,     0,    58,   162,    69,    70,    71,    58,   167,    35,
       0,     0,    58,   168,    37,    39,     0,    58,   171,    69,
      70,    71,   113,    21,    48,    69,    70,    71,    22,    23,
      24,    25,     0,    66,    72,    73,     0,     0,     0,    74,
      78,     0,    75,    22,    23,    24,    25,   146,     0,    72,
      73,     0,     0,     0,    74,    72,    73,    75,     0,     0,
      74,     0,     0,    75,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
       0,   147,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   104,   105,   106,   107,   108,
       0,   172,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,     0,   123,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,   143,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,   109,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,     0,   112,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108
};

static const yytype_int16 yycheck[] =
{
      46,     3,    46,     3,     1,    55,    56,    10,     9,     8,
       3,     0,    58,     8,    35,    36,    37,     7,    68,    39,
       3,    41,    72,    73,    74,    75,    23,    41,    48,    24,
       7,    81,    78,    13,    14,    15,    16,    87,    84,    41,
      84,    78,    42,    42,     7,    46,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    39,
      11,    12,     3,   109,     7,   111,   112,   111,     1,     7,
       3,     3,   109,     7,     7,   112,    42,     8,    42,    12,
       8,    39,     3,     7,    17,    41,    19,    20,    21,     7,
       9,    41,   138,    41,   138,   141,   146,   141,     1,     7,
       3,     4,     5,    42,   154,    42,    39,    40,    24,     7,
       1,   157,     3,     4,     5,    42,   166,   163,   164,   163,
     157,    22,    18,   169,    41,   169,    39,   164,    18,    39,
      33,    34,    43,    42,    14,    38,    42,    34,    41,    42,
       9,    66,    33,    34,     1,    -1,     3,    38,    -1,     1,
      41,     3,    -1,    -1,     1,    -1,     3,    -1,    -1,     1,
      17,     3,    19,    20,    21,    17,    -1,    19,    20,    21,
      17,    -1,    19,    20,    21,    17,    -1,    19,    20,    21,
      -1,    -1,    39,    40,     1,    -1,     3,    39,    40,     1,
      -1,     3,    39,    40,     1,    -1,     3,    39,    40,     1,
      17,     3,    19,    20,    21,    17,    -1,    19,    20,    21,
      17,    -1,    19,    20,    21,    17,    -1,    19,    20,    21,
      -1,    -1,    39,    40,     1,    -1,     3,    39,    40,     1,
      -1,     3,    39,    40,     1,    -1,     3,    39,    40,     1,
      17,     3,    19,    20,    21,    17,    -1,    19,    20,    21,
      17,    -1,    19,    20,    21,    17,    -1,    19,    20,    21,
      -1,    -1,    39,    40,     3,     4,     5,    39,    40,    26,
      -1,    -1,    39,    40,    31,    32,    -1,    39,    40,     3,
       4,     5,     6,     8,    41,     3,     4,     5,    13,    14,
      15,    16,    -1,    50,    33,    34,    -1,    -1,    -1,    38,
      39,    -1,    41,    13,    14,    15,    16,     8,    -1,    33,
      34,    -1,    -1,    -1,    38,    33,    34,    41,    -1,    -1,
      38,    -1,    -1,    41,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    33,    34,    35,    36,    37,
      -1,    44,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    46,     3,     0,     7,    11,    12,    47,    48,
      49,    53,     3,     3,    41,    50,    49,    53,     7,     7,
      41,     8,    13,    14,    15,    16,    51,    52,    50,     7,
       7,     3,    42,    54,     3,    52,     7,    52,    39,    52,
      56,    42,    51,    42,     8,    55,    57,    56,    52,    56,
       3,     1,     3,     7,    17,    19,    20,    21,    39,    40,
      49,    58,    60,    61,    62,    56,    52,     8,    24,     3,
       4,     5,    33,    34,    38,    41,    62,    64,    39,    64,
      64,    41,    40,    58,    59,     7,     7,    41,    55,     9,
      64,    64,    64,    64,     1,    64,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    39,
      40,    59,    39,     6,    64,     7,    40,    58,     1,    42,
      64,    24,    42,    42,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    40,    59,    40,
      40,    59,    42,    42,     7,    42,     8,    42,    63,    22,
      18,    40,    40,    64,     8,    42,    41,    39,    18,    64,
       1,    23,    40,    59,    39,    42,    43,    40,    40,    59,
      64,    40,    44,    42
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
#line 89 "gocompiler.y"
                                                   {
    program_root = newNode("Program", NULL);
    addchild(program_root, (yyvsp[0].ast_node));
}
#line 1463 "y.tab.c"
    break;

  case 3: /* Declarations: Declarations2  */
#line 95 "gocompiler.y"
                            { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1469 "y.tab.c"
    break;

  case 4: /* Declarations: %empty  */
#line 96 "gocompiler.y"
                            { (yyval.ast_node) = NULL; }
#line 1475 "y.tab.c"
    break;

  case 5: /* Declarations2: Declarations2 VarDeclaration SEMICOLON  */
#line 98 "gocompiler.y"
                                                      {
    (yyval.ast_node) = (yyvsp[-2].ast_node);
    addsiblings((yyvsp[-2].ast_node), (yyvsp[-1].ast_node));
}
#line 1484 "y.tab.c"
    break;

  case 6: /* Declarations2: VarDeclaration SEMICOLON  */
#line 102 "gocompiler.y"
                           { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1490 "y.tab.c"
    break;

  case 7: /* Declarations2: Declarations2 FuncDeclaration SEMICOLON  */
#line 103 "gocompiler.y"
                                          {
    (yyval.ast_node) = (yyvsp[-2].ast_node);
    addsiblings((yyvsp[-2].ast_node), (yyvsp[-1].ast_node));
}
#line 1499 "y.tab.c"
    break;

  case 8: /* Declarations2: FuncDeclaration SEMICOLON  */
#line 107 "gocompiler.y"
                            { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1505 "y.tab.c"
    break;

  case 9: /* VarDeclaration: VAR VarSpec  */
#line 110 "gocompiler.y"
                            { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1511 "y.tab.c"
    break;

  case 10: /* VarDeclaration: VAR LPAR VarSpec SEMICOLON RPAR  */
#line 111 "gocompiler.y"
                                                { (yyval.ast_node) = (yyvsp[-2].ast_node); }
#line 1517 "y.tab.c"
    break;

  case 11: /* VarSpec: IDENTIFIER Type  */
#line 114 "gocompiler.y"
                         {
    (yyval.ast_node) = newNode("VarDecl", NULL);
    addchild((yyval.ast_node), (yyvsp[0].ast_node));
    addsiblings((yyvsp[0].ast_node), newNode("IDENTIFIER", (yyvsp[-1].token_value)));
}
#line 1527 "y.tab.c"
    break;

  case 12: /* VarSpec: IDENTIFIER VarSpecList Type  */
#line 119 "gocompiler.y"
                              {
    (yyval.ast_node) = newNode("VarDecl", NULL);
    aux = newNode("IDENTIFIER", (yyvsp[-2].token_value));
    addchild((yyval.ast_node), (yyvsp[0].ast_node));
    addsiblings((yyvsp[0].ast_node), aux);
    addsiblings((yyval.ast_node), (yyvsp[-1].ast_node));

    varspec_aux = (yyval.ast_node)->sibling;
    while (varspec_aux != NULL && strcmp(varspec_aux->children->node->token, "notype") == 0) {
        strcpy(varspec_aux->children->node->token, (yyvsp[0].ast_node)->token);
        varspec_aux = varspec_aux->sibling;
    }
}
#line 1545 "y.tab.c"
    break;

  case 13: /* VarSpecList: COMMA IDENTIFIER VarSpecList  */
#line 134 "gocompiler.y"
                                          {
    (yyval.ast_node) = newNode("VarDecl", NULL);
    varspec_aux1 = newNode("notype", NULL);
    addsiblings((yyval.ast_node), (yyvsp[0].ast_node));
    addchild((yyval.ast_node), varspec_aux1);
    addsiblings(varspec_aux1, newNode("IDENTIFIER", (yyvsp[-1].token_value)));
}
#line 1557 "y.tab.c"
    break;

  case 14: /* VarSpecList: COMMA IDENTIFIER  */
#line 141 "gocompiler.y"
                   {
    (yyval.ast_node) = newNode("VarDecl", NULL);
    aux = newNode("notype", NULL);
    addchild((yyval.ast_node), aux);
    addsiblings(aux, newNode("IDENTIFIER", (yyvsp[0].token_value)));
}
#line 1568 "y.tab.c"
    break;

  case 15: /* Type: INT  */
#line 149 "gocompiler.y"
          { (yyval.ast_node) = newNode("Int", NULL); }
#line 1574 "y.tab.c"
    break;

  case 16: /* Type: FLOAT32  */
#line 150 "gocompiler.y"
              { (yyval.ast_node) = newNode("Float32", NULL); }
#line 1580 "y.tab.c"
    break;

  case 17: /* Type: BOOL  */
#line 151 "gocompiler.y"
           { (yyval.ast_node) = newNode("Bool", NULL); }
#line 1586 "y.tab.c"
    break;

  case 18: /* Type: STRING  */
#line 152 "gocompiler.y"
             { (yyval.ast_node) = newNode("String", NULL); }
#line 1592 "y.tab.c"
    break;

  case 19: /* FuncDeclaration: FUNC IDENTIFIER LPAR Parameters RPAR Type FuncBody  */
#line 155 "gocompiler.y"
                                                                    {
    (yyval.ast_node) = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", (yyvsp[-5].token_value));
    addchild((yyval.ast_node), aux);
    addsiblings(aux, (yyvsp[0].ast_node));
    addchild(aux, aux2);
    addsiblings((yyvsp[-1].ast_node), (yyvsp[-3].ast_node));
    addsiblings(aux2, (yyvsp[-1].ast_node));
}
#line 1607 "y.tab.c"
    break;

  case 20: /* FuncDeclaration: FUNC IDENTIFIER LPAR Parameters RPAR FuncBody  */
#line 165 "gocompiler.y"
                                                {
    (yyval.ast_node) = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", (yyvsp[-4].token_value));
    addchild((yyval.ast_node), aux);
    addsiblings(aux, (yyvsp[0].ast_node));
    addchild(aux, aux2);
    addsiblings(aux2, (yyvsp[-2].ast_node));
}
#line 1621 "y.tab.c"
    break;

  case 21: /* FuncDeclaration: FUNC IDENTIFIER LPAR RPAR Type FuncBody  */
#line 174 "gocompiler.y"
                                          {
    (yyval.ast_node) = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", (yyvsp[-4].token_value));
    addchild((yyval.ast_node), aux);
    addsiblings(aux, (yyvsp[0].ast_node));
    addchild(aux, aux2);
    addsiblings(aux2, (yyvsp[-1].ast_node));
    addsiblings((yyvsp[-1].ast_node), newNode("FuncParams", NULL));
}
#line 1636 "y.tab.c"
    break;

  case 22: /* FuncDeclaration: FUNC IDENTIFIER LPAR RPAR FuncBody  */
#line 184 "gocompiler.y"
                                     {
    (yyval.ast_node) = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", (yyvsp[-3].token_value));
    addchild((yyval.ast_node), aux);
    addchild(aux, aux2);
    addsiblings(aux2, newNode("FuncParams", NULL));
    addsiblings(aux, (yyvsp[0].ast_node));
}
#line 1650 "y.tab.c"
    break;

  case 23: /* Parameters: IDENTIFIER Type ParametersList  */
#line 195 "gocompiler.y"
                                           {
    (yyval.ast_node) = newNode("FuncParams", NULL);
    aux = newNode("ParamDecl", NULL);
    addchild((yyval.ast_node), aux);
    addsiblings(aux, (yyvsp[0].ast_node));
    addchild(aux, (yyvsp[-1].ast_node));
    addsiblings((yyvsp[-1].ast_node), newNode("IDENTIFIER", (yyvsp[-2].token_value)));
}
#line 1663 "y.tab.c"
    break;

  case 24: /* Parameters: IDENTIFIER Type  */
#line 203 "gocompiler.y"
                  {
    (yyval.ast_node) = newNode("FuncParams", NULL);
    aux = newNode("ParamDecl", NULL);
    addchild((yyval.ast_node), aux);
    addchild(aux, (yyvsp[0].ast_node));
    addsiblings((yyvsp[0].ast_node), newNode("IDENTIFIER", (yyvsp[-1].token_value)));
}
#line 1675 "y.tab.c"
    break;

  case 25: /* ParametersList: COMMA IDENTIFIER Type ParametersList  */
#line 212 "gocompiler.y"
                                                     {
    (yyval.ast_node) = newNode("ParamDecl", NULL);
    addchild((yyval.ast_node), (yyvsp[-1].ast_node));
    addsiblings((yyvsp[-1].ast_node), newNode("IDENTIFIER", (yyvsp[-2].token_value)));
    addsiblings((yyval.ast_node), (yyvsp[0].ast_node));
}
#line 1686 "y.tab.c"
    break;

  case 26: /* ParametersList: COMMA IDENTIFIER Type  */
#line 218 "gocompiler.y"
                        {
    (yyval.ast_node) = newNode("ParamDecl", NULL);
    addchild((yyval.ast_node), (yyvsp[0].ast_node));
    addsiblings((yyvsp[0].ast_node), newNode("IDENTIFIER", (yyvsp[-1].token_value)));
}
#line 1696 "y.tab.c"
    break;

  case 27: /* FuncBody: LBRACE VarsAndStatements RBRACE  */
#line 225 "gocompiler.y"
                                          {
    (yyval.ast_node) = newNode("FuncBody", NULL);
    addchild((yyval.ast_node), (yyvsp[-1].ast_node));
}
#line 1705 "y.tab.c"
    break;

  case 28: /* VarsAndStatements: VarsAndStatements VarDeclaration SEMICOLON  */
#line 230 "gocompiler.y"
                                                              {
    (yyval.ast_node) = (yyvsp[-2].ast_node);
    addsiblings((yyvsp[-2].ast_node), (yyvsp[-1].ast_node));
}
#line 1714 "y.tab.c"
    break;

  case 29: /* VarsAndStatements: VarsAndStatements Statement SEMICOLON  */
#line 234 "gocompiler.y"
                                        {
    (yyval.ast_node) = (yyvsp[-2].ast_node);
    addsiblings((yyvsp[-2].ast_node), (yyvsp[-1].ast_node));
}
#line 1723 "y.tab.c"
    break;

  case 30: /* VarsAndStatements: VarsAndStatements SEMICOLON  */
#line 238 "gocompiler.y"
                              { (yyvsp[-1].ast_node) = (yyvsp[-1].ast_node); }
#line 1729 "y.tab.c"
    break;

  case 31: /* VarsAndStatements: %empty  */
#line 239 "gocompiler.y"
                { (yyval.ast_node) = newNode("NULL", NULL); }
#line 1735 "y.tab.c"
    break;

  case 32: /* Statement: IDENTIFIER ASSIGN Expr  */
#line 241 "gocompiler.y"
                                  {
    (yyval.ast_node) = newNode("Assign", NULL);
    aux = newNode("IDENTIFIER", (yyvsp[-2].token_value));
    addchild((yyval.ast_node), aux);
    addsiblings(aux, (yyvsp[0].ast_node));
}
#line 1746 "y.tab.c"
    break;

  case 33: /* Statement: LBRACE RBRACE  */
#line 248 "gocompiler.y"
                {
    (yyval.ast_node) = newNode("NULL", NULL);
}
#line 1754 "y.tab.c"
    break;

  case 34: /* Statement: LBRACE StatementList RBRACE  */
#line 251 "gocompiler.y"
                              {
    aux = (yyvsp[-1].ast_node);
    int n = 0;
    while (aux != NULL) {
        if (strcmp(aux->token, "NULL") != 0) n++;
        aux = aux->sibling;
    }
    if (n >= 2) {
        (yyval.ast_node) = newNode("Block", NULL);
        addchild((yyval.ast_node), (yyvsp[-1].ast_node));
    } else {
        (yyval.ast_node) = (yyvsp[-1].ast_node);
    }
}
#line 1773 "y.tab.c"
    break;

  case 35: /* Statement: IF Expr LBRACE RBRACE  */
#line 265 "gocompiler.y"
                        {
    (yyval.ast_node) = newNode("If", NULL);
    addchild((yyval.ast_node), (yyvsp[-2].ast_node));
    aux = newNode("Block", NULL);
    addsiblings((yyvsp[-2].ast_node), aux);
    addsiblings(aux, newNode("Block", NULL));
}
#line 1785 "y.tab.c"
    break;

  case 36: /* Statement: IF Expr LBRACE StatementList RBRACE  */
#line 272 "gocompiler.y"
                                      {
    (yyval.ast_node) = newNode("If", NULL);
    addchild((yyval.ast_node), (yyvsp[-3].ast_node));
    aux = newNode("Block", NULL);
    addsiblings((yyvsp[-3].ast_node), aux);
    addchild(aux, (yyvsp[-1].ast_node));
    addsiblings(aux, newNode("Block", NULL));
}
#line 1798 "y.tab.c"
    break;

  case 37: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE RBRACE  */
#line 280 "gocompiler.y"
                                           {
    (yyval.ast_node) = newNode("If", NULL);
    addchild((yyval.ast_node), (yyvsp[-5].ast_node));
    aux = newNode("Block", NULL);
    addsiblings((yyvsp[-5].ast_node), aux);
    addsiblings(aux, newNode("Block", NULL));
}
#line 1810 "y.tab.c"
    break;

  case 38: /* Statement: IF Expr LBRACE StatementList RBRACE ELSE LBRACE RBRACE  */
#line 287 "gocompiler.y"
                                                         {
    (yyval.ast_node) = newNode("If", NULL);
    addchild((yyval.ast_node), (yyvsp[-6].ast_node));
    aux = newNode("Block", NULL);
    addsiblings((yyvsp[-6].ast_node), aux);
    addchild(aux, (yyvsp[-4].ast_node));
    addsiblings(aux, newNode("Block", NULL));
}
#line 1823 "y.tab.c"
    break;

  case 39: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE StatementList RBRACE  */
#line 295 "gocompiler.y"
                                                         {
    (yyval.ast_node) = newNode("If", NULL);
    addchild((yyval.ast_node), (yyvsp[-6].ast_node));
    aux = newNode("Block", NULL);
    aux2 = newNode("Block", NULL);
    addsiblings((yyvsp[-6].ast_node), aux);
    addsiblings(aux, aux2);
    addchild(aux2, (yyvsp[-1].ast_node));
}
#line 1837 "y.tab.c"
    break;

  case 40: /* Statement: IF Expr LBRACE StatementList RBRACE ELSE LBRACE StatementList RBRACE  */
#line 304 "gocompiler.y"
                                                                       {
    (yyval.ast_node) = newNode("If", NULL);
    addchild((yyval.ast_node), (yyvsp[-7].ast_node));
    aux = newNode("Block", NULL);
    aux2 = newNode("Block", NULL);
    addsiblings((yyvsp[-7].ast_node), aux);
    addchild(aux, (yyvsp[-5].ast_node));
    addsiblings(aux, aux2);
    addchild(aux2, (yyvsp[-1].ast_node));
}
#line 1852 "y.tab.c"
    break;

  case 41: /* Statement: FOR LBRACE RBRACE  */
#line 314 "gocompiler.y"
                    {
    (yyval.ast_node) = newNode("For", NULL);
    addchild((yyval.ast_node), newNode("Block", NULL));
}
#line 1861 "y.tab.c"
    break;

  case 42: /* Statement: FOR LBRACE StatementList RBRACE  */
#line 318 "gocompiler.y"
                                  {
    (yyval.ast_node) = newNode("For", NULL);
    aux = newNode("Block", NULL);
    addchild((yyval.ast_node), aux);
    addchild(aux, (yyvsp[-1].ast_node));
}
#line 1872 "y.tab.c"
    break;

  case 43: /* Statement: FOR Expr LBRACE RBRACE  */
#line 324 "gocompiler.y"
                         {
    (yyval.ast_node) = newNode("For", NULL);
    addchild((yyval.ast_node), (yyvsp[-2].ast_node));
    addsiblings((yyvsp[-2].ast_node), newNode("Block", NULL));
}
#line 1882 "y.tab.c"
    break;

  case 44: /* Statement: FOR Expr LBRACE StatementList RBRACE  */
#line 329 "gocompiler.y"
                                       {
    (yyval.ast_node) = newNode("For", NULL);
    addchild((yyval.ast_node), (yyvsp[-3].ast_node));
    aux = newNode("Block", NULL);
    addsiblings((yyvsp[-3].ast_node), aux);
    addchild(aux, (yyvsp[-1].ast_node));
}
#line 1894 "y.tab.c"
    break;

  case 45: /* Statement: RETURN  */
#line 336 "gocompiler.y"
         {
    (yyval.ast_node) = newNode("Return", NULL);
}
#line 1902 "y.tab.c"
    break;

  case 46: /* Statement: RETURN Expr  */
#line 339 "gocompiler.y"
              {
    (yyval.ast_node) = newNode("Return", NULL);
    addchild((yyval.ast_node), (yyvsp[0].ast_node));
}
#line 1911 "y.tab.c"
    break;

  case 47: /* Statement: FuncInvocation  */
#line 343 "gocompiler.y"
                 {
    (yyval.ast_node) = newNode("Call", NULL);
    addchild((yyval.ast_node), (yyvsp[0].ast_node));
}
#line 1920 "y.tab.c"
    break;

  case 48: /* Statement: ParseArgs  */
#line 347 "gocompiler.y"
            {
    (yyval.ast_node) = (yyvsp[0].ast_node);
}
#line 1928 "y.tab.c"
    break;

  case 49: /* Statement: PRINT LPAR Expr RPAR  */
#line 350 "gocompiler.y"
                       {
    (yyval.ast_node) = newNode("Print", NULL);
    addchild((yyval.ast_node), (yyvsp[-1].ast_node));
}
#line 1937 "y.tab.c"
    break;

  case 50: /* Statement: PRINT LPAR STRLIT RPAR  */
#line 354 "gocompiler.y"
                         { 
    (yyval.ast_node) = newNode("Print", NULL); 
    aux = newNode("StrLit", (yyvsp[-1].token_value)); 
    addchild((yyval.ast_node), aux);}
#line 1946 "y.tab.c"
    break;

  case 51: /* Statement: error  */
#line 359 "gocompiler.y"
        {
    (yyval.ast_node) = newNode("Error", NULL);
    freetree(program_root);         //ALTERACAO
}
#line 1955 "y.tab.c"
    break;

  case 52: /* StatementList: StatementList Statement SEMICOLON  */
#line 365 "gocompiler.y"
                                                 {
    (yyval.ast_node) = (yyvsp[-2].ast_node);
    addsiblings((yyvsp[-2].ast_node), (yyvsp[-1].ast_node));
}
#line 1964 "y.tab.c"
    break;

  case 53: /* StatementList: Statement SEMICOLON  */
#line 369 "gocompiler.y"
                      {
    (yyval.ast_node) = (yyvsp[-1].ast_node);
}
#line 1972 "y.tab.c"
    break;

  case 54: /* ParseArgs: IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR  */
#line 374 "gocompiler.y"
                                                                                   {
    (yyval.ast_node) = newNode("ParseArgs", NULL);
    aux = newNode("IDENTIFIER", (yyvsp[-10].token_value));
    addchild((yyval.ast_node), aux);
    addsiblings(aux, (yyvsp[-2].ast_node));
}
#line 1983 "y.tab.c"
    break;

  case 55: /* ParseArgs: IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR  */
#line 380 "gocompiler.y"
                                                           {
    (yyval.ast_node) = newNode("ParseArgs", NULL);
    aux = newNode("IDENTIFIER", (yyvsp[-7].token_value));
    addchild((yyval.ast_node), aux);
    addsiblings(aux, newNode("Error", NULL));
    freetree(program_root);         //ALTERACAO
}
#line 1995 "y.tab.c"
    break;

  case 56: /* FuncID: IDENTIFIER  */
#line 391 "gocompiler.y"
    {(yyval.ast_node) = newNode("IDENTIFIER", (yyvsp[0].token_value));}
#line 2001 "y.tab.c"
    break;

  case 57: /* FuncInvocation: FuncID LPAR RPAR  */
#line 393 "gocompiler.y"
                                 { (yyval.ast_node) = (yyvsp[-2].ast_node); }
#line 2007 "y.tab.c"
    break;

  case 58: /* FuncInvocation: FuncID LPAR Expr RPAR  */
#line 394 "gocompiler.y"
                        {
    (yyval.ast_node) = (yyvsp[-3].ast_node);
    addsiblings((yyvsp[-3].ast_node), (yyvsp[-1].ast_node));
}
#line 2016 "y.tab.c"
    break;

  case 59: /* FuncInvocation: FuncID LPAR Expr CommaExpressionList RPAR  */
#line 398 "gocompiler.y"
                                            {
    (yyval.ast_node) = (yyvsp[-4].ast_node);
    addsiblings((yyvsp[-4].ast_node), (yyvsp[-2].ast_node));
    addsiblings((yyvsp[-2].ast_node), (yyvsp[-1].ast_node));
}
#line 2026 "y.tab.c"
    break;

  case 60: /* FuncInvocation: FuncID LPAR error RPAR  */
#line 403 "gocompiler.y"
                         {
    (yyval.ast_node) = (yyvsp[-3].ast_node);
    addsiblings((yyvsp[-3].ast_node), newNode("Error", NULL));
    freetree(program_root);         //ALTERACAO
}
#line 2036 "y.tab.c"
    break;

  case 61: /* CommaExpressionList: CommaExpressionList COMMA Expr  */
#line 410 "gocompiler.y"
                                                    {
    (yyval.ast_node) = (yyvsp[-2].ast_node);
    addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));
}
#line 2045 "y.tab.c"
    break;

  case 62: /* CommaExpressionList: COMMA Expr  */
#line 414 "gocompiler.y"
             {
    (yyval.ast_node) = (yyvsp[0].ast_node);
}
#line 2053 "y.tab.c"
    break;

  case 63: /* Expr: Expr OR Expr  */
#line 419 "gocompiler.y"
                     {(yyval.ast_node) = newNode("Or", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2059 "y.tab.c"
    break;

  case 64: /* Expr: Expr AND Expr  */
#line 420 "gocompiler.y"
                {(yyval.ast_node) = newNode("And", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2065 "y.tab.c"
    break;

  case 65: /* Expr: Expr LT Expr  */
#line 421 "gocompiler.y"
               {(yyval.ast_node) = newNode("Lt", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2071 "y.tab.c"
    break;

  case 66: /* Expr: Expr GT Expr  */
#line 422 "gocompiler.y"
               {(yyval.ast_node) = newNode("Gt", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2077 "y.tab.c"
    break;

  case 67: /* Expr: Expr EQ Expr  */
#line 423 "gocompiler.y"
               {(yyval.ast_node) = newNode("Eq", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2083 "y.tab.c"
    break;

  case 68: /* Expr: Expr NE Expr  */
#line 424 "gocompiler.y"
               {(yyval.ast_node) = newNode("Ne", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2089 "y.tab.c"
    break;

  case 69: /* Expr: Expr LE Expr  */
#line 425 "gocompiler.y"
               {(yyval.ast_node) = newNode("Le", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2095 "y.tab.c"
    break;

  case 70: /* Expr: Expr GE Expr  */
#line 426 "gocompiler.y"
               {(yyval.ast_node) = newNode("Ge", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2101 "y.tab.c"
    break;

  case 71: /* Expr: Expr PLUS Expr  */
#line 427 "gocompiler.y"
                 {(yyval.ast_node) = newNode("Add", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2107 "y.tab.c"
    break;

  case 72: /* Expr: Expr MINUS Expr  */
#line 428 "gocompiler.y"
                  {(yyval.ast_node) = newNode("Sub", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2113 "y.tab.c"
    break;

  case 73: /* Expr: Expr STAR Expr  */
#line 429 "gocompiler.y"
                 {(yyval.ast_node) = newNode("Mul", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2119 "y.tab.c"
    break;

  case 74: /* Expr: Expr DIV Expr  */
#line 430 "gocompiler.y"
                {(yyval.ast_node) = newNode("Div", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2125 "y.tab.c"
    break;

  case 75: /* Expr: Expr MOD Expr  */
#line 431 "gocompiler.y"
                {(yyval.ast_node) = newNode("Mod", NULL); addchild((yyval.ast_node), (yyvsp[-2].ast_node)); addsiblings((yyvsp[-2].ast_node), (yyvsp[0].ast_node));}
#line 2131 "y.tab.c"
    break;

  case 76: /* Expr: NOT Expr  */
#line 432 "gocompiler.y"
           {(yyval.ast_node) = newNode("Not", NULL); addchild((yyval.ast_node), (yyvsp[0].ast_node));}
#line 2137 "y.tab.c"
    break;

  case 77: /* Expr: MINUS Expr  */
#line 433 "gocompiler.y"
                       {(yyval.ast_node) = newNode("Minus", NULL); addchild((yyval.ast_node), (yyvsp[0].ast_node));}
#line 2143 "y.tab.c"
    break;

  case 78: /* Expr: PLUS Expr  */
#line 434 "gocompiler.y"
                      {(yyval.ast_node) = newNode("Plus", NULL); addchild((yyval.ast_node), (yyvsp[0].ast_node));}
#line 2149 "y.tab.c"
    break;

  case 79: /* Expr: NATURAL  */
#line 435 "gocompiler.y"
          {(yyval.ast_node) = newNode("NATURAL", (yyvsp[0].token_value));}
#line 2155 "y.tab.c"
    break;

  case 80: /* Expr: DECIMAL  */
#line 436 "gocompiler.y"
          {(yyval.ast_node) = newNode("DECIMAL", (yyvsp[0].token_value));}
#line 2161 "y.tab.c"
    break;

  case 81: /* Expr: IDENTIFIER  */
#line 437 "gocompiler.y"
             {(yyval.ast_node) = newNode("IDENTIFIER", (yyvsp[0].token_value));}
#line 2167 "y.tab.c"
    break;

  case 82: /* Expr: FuncInvocation  */
#line 438 "gocompiler.y"
                 {(yyval.ast_node) = newNode("Call", NULL); addchild((yyval.ast_node), (yyvsp[0].ast_node));}
#line 2173 "y.tab.c"
    break;

  case 83: /* Expr: LPAR Expr RPAR  */
#line 439 "gocompiler.y"
                 {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2179 "y.tab.c"
    break;

  case 84: /* Expr: LPAR error RPAR  */
#line 440 "gocompiler.y"
                  {(yyval.ast_node) = newNode("Error", NULL);freetree(program_root);}
#line 2185 "y.tab.c"
    break;


#line 2189 "y.tab.c"

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

#line 442 "gocompiler.y"
 
