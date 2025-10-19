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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylex(void);
extern int yylineno;
extern char *yytext;
extern int line;
extern int col;
int yyparse(void);
void yyerror(const char *s);


struct node *root = NULL;
extern char flag;

#line 90 "y.tab.c"

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
    PACKAGE = 258,                 /* PACKAGE  */
    RETURN = 259,                  /* RETURN  */
    ELSE = 260,                    /* ELSE  */
    FOR = 261,                     /* FOR  */
    IF = 262,                      /* IF  */
    VAR = 263,                     /* VAR  */
    INT = 264,                     /* INT  */
    FLOAT32 = 265,                 /* FLOAT32  */
    BOOL = 266,                    /* BOOL  */
    STRING = 267,                  /* STRING  */
    FUNC = 268,                    /* FUNC  */
    CMDARGS = 269,                 /* CMDARGS  */
    PRINT = 270,                   /* PRINT  */
    PARSEINT = 271,                /* PARSEINT  */
    SEMICOLON = 272,               /* SEMICOLON  */
    COMMA = 273,                   /* COMMA  */
    BLANKID = 274,                 /* BLANKID  */
    ASSIGN = 275,                  /* ASSIGN  */
    STAR = 276,                    /* STAR  */
    DIV = 277,                     /* DIV  */
    MINUS = 278,                   /* MINUS  */
    PLUS = 279,                    /* PLUS  */
    EQ = 280,                      /* EQ  */
    GE = 281,                      /* GE  */
    GT = 282,                      /* GT  */
    LE = 283,                      /* LE  */
    LPAR = 284,                    /* LPAR  */
    LSQ = 285,                     /* LSQ  */
    LT = 286,                      /* LT  */
    MOD = 287,                     /* MOD  */
    NE = 288,                      /* NE  */
    NOT = 289,                     /* NOT  */
    AND = 290,                     /* AND  */
    OR = 291,                      /* OR  */
    RBRACE = 292,                  /* RBRACE  */
    RPAR = 293,                    /* RPAR  */
    RSQ = 294,                     /* RSQ  */
    LBRACE = 295,                  /* LBRACE  */
    IDENTIFIER = 296,              /* IDENTIFIER  */
    STRLIT = 297,                  /* STRLIT  */
    NATURAL = 298,                 /* NATURAL  */
    DECIMAL = 299,                 /* DECIMAL  */
    UMINUS = 300                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PACKAGE 258
#define RETURN 259
#define ELSE 260
#define FOR 261
#define IF 262
#define VAR 263
#define INT 264
#define FLOAT32 265
#define BOOL 266
#define STRING 267
#define FUNC 268
#define CMDARGS 269
#define PRINT 270
#define PARSEINT 271
#define SEMICOLON 272
#define COMMA 273
#define BLANKID 274
#define ASSIGN 275
#define STAR 276
#define DIV 277
#define MINUS 278
#define PLUS 279
#define EQ 280
#define GE 281
#define GT 282
#define LE 283
#define LPAR 284
#define LSQ 285
#define LT 286
#define MOD 287
#define NE 288
#define NOT 289
#define AND 290
#define OR 291
#define RBRACE 292
#define RPAR 293
#define RSQ 294
#define LBRACE 295
#define IDENTIFIER 296
#define STRLIT 297
#define NATURAL 298
#define DECIMAL 299
#define UMINUS 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "gocompiler.y"

    char* str;
    struct node* node;

#line 238 "y.tab.c"

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
  YYSYMBOL_PACKAGE = 3,                    /* PACKAGE  */
  YYSYMBOL_RETURN = 4,                     /* RETURN  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_VAR = 8,                        /* VAR  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_FLOAT32 = 10,                   /* FLOAT32  */
  YYSYMBOL_BOOL = 11,                      /* BOOL  */
  YYSYMBOL_STRING = 12,                    /* STRING  */
  YYSYMBOL_FUNC = 13,                      /* FUNC  */
  YYSYMBOL_CMDARGS = 14,                   /* CMDARGS  */
  YYSYMBOL_PRINT = 15,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 16,                  /* PARSEINT  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_BLANKID = 19,                   /* BLANKID  */
  YYSYMBOL_ASSIGN = 20,                    /* ASSIGN  */
  YYSYMBOL_STAR = 21,                      /* STAR  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_PLUS = 24,                      /* PLUS  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_GE = 26,                        /* GE  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_LE = 28,                        /* LE  */
  YYSYMBOL_LPAR = 29,                      /* LPAR  */
  YYSYMBOL_LSQ = 30,                       /* LSQ  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_MOD = 32,                       /* MOD  */
  YYSYMBOL_NE = 33,                        /* NE  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_RBRACE = 37,                    /* RBRACE  */
  YYSYMBOL_RPAR = 38,                      /* RPAR  */
  YYSYMBOL_RSQ = 39,                       /* RSQ  */
  YYSYMBOL_LBRACE = 40,                    /* LBRACE  */
  YYSYMBOL_IDENTIFIER = 41,                /* IDENTIFIER  */
  YYSYMBOL_STRLIT = 42,                    /* STRLIT  */
  YYSYMBOL_NATURAL = 43,                   /* NATURAL  */
  YYSYMBOL_DECIMAL = 44,                   /* DECIMAL  */
  YYSYMBOL_UMINUS = 45,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_declarations = 48,              /* declarations  */
  YYSYMBOL_var_declaration = 49,           /* var_declaration  */
  YYSYMBOL_var_spec = 50,                  /* var_spec  */
  YYSYMBOL_type = 51,                      /* type  */
  YYSYMBOL_func_declaration = 52,          /* func_declaration  */
  YYSYMBOL_parameters = 53,                /* parameters  */
  YYSYMBOL_func_body = 54,                 /* func_body  */
  YYSYMBOL_vars_and_statements = 55,       /* vars_and_statements  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_parse_args = 57,                /* parse_args  */
  YYSYMBOL_func_invocation = 58,           /* func_invocation  */
  YYSYMBOL_expr = 59                       /* expr  */
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
#define YYLAST   340

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    60,    63,    66,    69,    75,    79,    86,
      91,   101,   102,   103,   104,   108,   118,   129,   140,   155,
     162,   173,   181,   184,   187,   190,   196,   202,   206,   213,
     223,   230,   234,   237,   238,   239,   243,   250,   259,   264,
     270,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300
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
  "\"end of file\"", "error", "\"invalid token\"", "PACKAGE", "RETURN",
  "ELSE", "FOR", "IF", "VAR", "INT", "FLOAT32", "BOOL", "STRING", "FUNC",
  "CMDARGS", "PRINT", "PARSEINT", "SEMICOLON", "COMMA", "BLANKID",
  "ASSIGN", "STAR", "DIV", "MINUS", "PLUS", "EQ", "GE", "GT", "LE", "LPAR",
  "LSQ", "LT", "MOD", "NE", "NOT", "AND", "OR", "RBRACE", "RPAR", "RSQ",
  "LBRACE", "IDENTIFIER", "STRLIT", "NATURAL", "DECIMAL", "UMINUS",
  "$accept", "program", "declarations", "var_declaration", "var_spec",
  "type", "func_declaration", "parameters", "func_body",
  "vars_and_statements", "statement", "parse_args", "func_invocation",
  "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -29,    24,     8,   -43,    28,   -22,   -13,    28,    20,
      21,    -2,    83,   -43,    11,    39,    42,   -43,   -43,    43,
     -43,   -43,   -43,   -43,    26,   -43,   -27,   -43,   -43,    32,
     110,    23,   110,   -15,   -43,   -43,    70,    44,   -43,   -43,
      50,    23,   108,   108,   108,    54,    75,    69,    79,    65,
      80,   -43,   -43,   -43,   110,    44,   -43,   108,   108,   108,
     108,    74,   -43,   -43,   -43,   263,   150,   170,    84,    92,
      93,   108,   100,   -43,   -43,    97,   113,   -43,   -43,   -43,
     -43,   -43,   209,   -43,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,    75,    75,    95,
     227,    98,   116,   263,   -43,   132,   -43,   -43,   -43,   -43,
     -43,    -1,    -1,   294,   294,   294,   294,   294,   -43,   294,
     307,   279,   122,   123,   -43,   -43,   -43,   101,   108,   -43,
     109,   111,   118,   245,   -43,   140,   147,   -43,   126,   139,
      75,   108,   145,   190,   142,   146,   -43,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     2,     0,
       0,     0,     0,     7,     0,     0,     0,     5,     6,     0,
      11,    12,    13,    14,     0,     9,     0,     3,     4,     0,
       0,     0,     0,     0,     8,    10,     0,     0,    15,    19,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    33,    16,     0,     0,    17,     0,     0,     0,
       0,    59,    57,    58,    60,    31,     0,     0,     0,     0,
       0,     0,     0,    24,    21,     0,     0,    25,    20,    18,
      54,    55,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    38,     0,    22,    23,    61,    51,
      52,    50,    49,    43,    48,    46,    47,    45,    53,    44,
      42,    41,     0,     0,    36,    35,    27,     0,     0,    39,
       0,     0,     0,     0,    30,    28,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   -43,    19,   169,    34,   179,   -43,   -33,   -43,
     -40,   -43,   -36,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,     9,    13,    25,    10,    33,    38,    49,
      50,    51,    64,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    66,    67,    40,    53,     1,    69,    11,    56,    76,
      52,    31,     3,    52,    32,    80,    81,    82,    83,    12,
      84,    85,    79,    41,     4,     5,   100,    15,    14,   103,
     105,    93,    20,    21,    22,    23,     6,    17,    18,    12,
      26,     7,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    48,    27,   122,   123,    28,
      29,    52,    52,    36,    35,    37,    39,    30,    75,    42,
      34,    43,    44,     6,    42,    55,    43,    44,     6,    42,
      45,    43,    44,    68,    36,    45,   133,    70,    78,    71,
      45,    54,    20,    21,    22,    23,    73,    77,    72,   143,
     142,    24,    74,    72,    52,    46,    47,    57,    58,   101,
      46,    47,   102,    59,   106,    46,    47,   132,    60,    20,
      21,    22,    23,    57,    58,    61,    99,    62,    63,    59,
     107,    57,    58,   124,    60,   126,   127,    59,   104,   130,
     131,    61,    60,    62,    63,   138,   134,   136,   135,    61,
     128,    62,    63,    84,    85,    86,    87,    88,    89,    90,
      91,   139,   144,    92,    93,    94,   140,    95,    96,   141,
     129,    84,    85,    86,    87,    88,    89,    90,    91,   146,
      19,    92,    93,    94,   147,    95,    96,    16,     0,     0,
      97,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,    92,    93,    94,     0,    95,    96,     0,     0,     0,
      98,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,    92,    93,    94,     0,    95,    96,     0,     0,   145,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
      92,    93,    94,     0,    95,    96,     0,   108,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,    92,    93,
      94,     0,    95,    96,     0,   125,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,    92,    93,    94,     0,
      95,    96,     0,   137,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,    92,    93,    94,     0,    95,    96,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
      92,    93,    94,     0,    95,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,     0,     0,    -1,    93,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,    92,    93,
      94
};

static const yytype_int16 yycheck[] =
{
      36,    43,    44,    18,    37,     3,    46,    29,    41,    49,
      46,    38,    41,    49,    41,    57,    58,    59,    60,    41,
      21,    22,    55,    38,     0,    17,    68,     8,    41,    71,
      72,    32,     9,    10,    11,    12,     8,    17,    17,    41,
      29,    13,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    36,    17,    97,    98,    17,
      17,    97,    98,    40,    30,    31,    32,    41,    49,     4,
      38,     6,     7,     8,     4,    41,     6,     7,     8,     4,
      15,     6,     7,    29,    40,    15,   128,    18,    54,    20,
      15,    41,     9,    10,    11,    12,    17,    17,    29,   141,
     140,    18,    37,    29,   140,    40,    41,    23,    24,    17,
      40,    41,    19,    29,    17,    40,    41,    16,    34,     9,
      10,    11,    12,    23,    24,    41,    42,    43,    44,    29,
      17,    23,    24,    38,    34,    37,    20,    29,    38,    17,
      17,    41,    34,    43,    44,     5,    37,    29,    37,    41,
      18,    43,    44,    21,    22,    23,    24,    25,    26,    27,
      28,    14,    17,    31,    32,    33,    40,    35,    36,    30,
      38,    21,    22,    23,    24,    25,    26,    27,    28,    37,
      11,    31,    32,    33,    38,    35,    36,     8,    -1,    -1,
      40,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    -1,    35,    36,    -1,    -1,    -1,
      40,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    -1,    35,    36,    -1,    -1,    39,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,    -1,    35,    36,    -1,    38,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33,    -1,    35,    36,    -1,    38,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,    -1,
      35,    36,    -1,    38,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,    -1,    35,    36,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,    -1,    35,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,    41,     0,    17,     8,    13,    48,    49,
      52,    29,    41,    50,    41,    49,    52,    17,    17,    50,
       9,    10,    11,    12,    18,    51,    29,    17,    17,    17,
      41,    38,    41,    53,    38,    51,    40,    51,    54,    51,
      18,    38,     4,     6,     7,    15,    40,    41,    49,    55,
      56,    57,    58,    54,    41,    51,    54,    23,    24,    29,
      34,    41,    43,    44,    58,    59,    59,    59,    29,    56,
      18,    20,    29,    17,    37,    49,    56,    17,    51,    54,
      59,    59,    59,    59,    21,    22,    23,    24,    25,    26,
      27,    28,    31,    32,    33,    35,    36,    40,    40,    42,
      59,    17,    19,    59,    38,    59,    17,    17,    38,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    56,    56,    38,    38,    37,    20,    18,    38,
      17,    17,    16,    59,    37,    37,    29,    38,     5,    14,
      40,    30,    56,    59,    17,    39,    37,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    49,    49,    50,
      50,    51,    51,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    55,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    58,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     2,     2,     2,     5,     2,
       4,     1,     1,     1,     1,     5,     6,     6,     7,     2,
       4,     3,     3,     3,     2,     2,     3,     4,     6,    11,
       6,     2,     1,     1,     1,     4,     4,    11,     3,     4,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     1,     1,     1,
       1,     3
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
  case 2: /* program: PACKAGE IDENTIFIER SEMICOLON declarations  */
#line 51 "gocompiler.y"
    {
        root = new_node(Program, NULL);
        add_child(root, (yyvsp[0].node));
        (yyval.node) = root;
    }
#line 1409 "y.tab.c"
    break;

  case 3: /* declarations: declarations var_declaration SEMICOLON  */
#line 60 "gocompiler.y"
                                           {
        add_child((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = (yyvsp[-2].node);
    }
#line 1417 "y.tab.c"
    break;

  case 4: /* declarations: declarations func_declaration SEMICOLON  */
#line 63 "gocompiler.y"
                                            {
        add_child((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = (yyvsp[-2].node);
    }
#line 1425 "y.tab.c"
    break;

  case 5: /* declarations: var_declaration SEMICOLON  */
#line 66 "gocompiler.y"
                              {
        (yyval.node) = new_node(AUX, NULL); add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1433 "y.tab.c"
    break;

  case 6: /* declarations: func_declaration SEMICOLON  */
#line 69 "gocompiler.y"
                               {
        (yyval.node) = new_node(AUX, NULL); add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1441 "y.tab.c"
    break;

  case 7: /* var_declaration: VAR var_spec  */
#line 75 "gocompiler.y"
                 {
        (yyval.node) = new_node(VarDecl, NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1450 "y.tab.c"
    break;

  case 8: /* var_declaration: VAR LPAR var_spec SEMICOLON RPAR  */
#line 79 "gocompiler.y"
                                     {
        (yyval.node) = new_node(VarDecl, NULL);
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1459 "y.tab.c"
    break;

  case 9: /* var_spec: IDENTIFIER type  */
#line 86 "gocompiler.y"
                    {
        (yyval.node) = new_node((yyvsp[0].node)->category, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-1].str)));
        add_child((yyval.node), id);
    }
#line 1469 "y.tab.c"
    break;

  case 10: /* var_spec: IDENTIFIER COMMA IDENTIFIER type  */
#line 91 "gocompiler.y"
                                     {
        (yyval.node) = new_node((yyvsp[0].node)->category, NULL);
        struct node *id1 = new_node(Identifier, strdup((yyvsp[-3].str)));
        struct node *id2 = new_node(Identifier, strdup((yyvsp[-1].str)));
        add_child((yyval.node), id1);
        add_child((yyval.node), id2);
    }
#line 1481 "y.tab.c"
    break;

  case 11: /* type: INT  */
#line 101 "gocompiler.y"
        { (yyval.node) = new_node(Int, NULL); }
#line 1487 "y.tab.c"
    break;

  case 12: /* type: FLOAT32  */
#line 102 "gocompiler.y"
            { (yyval.node) = new_node(Float32, NULL); }
#line 1493 "y.tab.c"
    break;

  case 13: /* type: BOOL  */
#line 103 "gocompiler.y"
         { (yyval.node) = new_node(Bool, NULL); }
#line 1499 "y.tab.c"
    break;

  case 14: /* type: STRING  */
#line 104 "gocompiler.y"
           { (yyval.node) = new_node(String, NULL); }
#line 1505 "y.tab.c"
    break;

  case 15: /* func_declaration: FUNC IDENTIFIER LPAR RPAR func_body  */
#line 108 "gocompiler.y"
                                        {
        struct node *header = new_node(FuncHeader, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-3].str)));
        struct node *params = new_node(FuncParams, NULL);
        add_child(header, id);
        add_child(header, params);
        (yyval.node) = new_node(FuncDecl, NULL);
        add_child((yyval.node), header);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1520 "y.tab.c"
    break;

  case 16: /* func_declaration: FUNC IDENTIFIER LPAR RPAR type func_body  */
#line 118 "gocompiler.y"
                                             {
        struct node *header = new_node(FuncHeader, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-4].str)));
        struct node *params = new_node(FuncParams, NULL);
        add_child(header, id);
        add_child(header, (yyvsp[-1].node));
        add_child(header, params);
        (yyval.node) = new_node(FuncDecl, NULL);
        add_child((yyval.node), header);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1536 "y.tab.c"
    break;

  case 17: /* func_declaration: FUNC IDENTIFIER LPAR parameters RPAR func_body  */
#line 129 "gocompiler.y"
                                                   {
        struct node *header = new_node(FuncHeader, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-4].str)));
        struct node *params = new_node(FuncParams, NULL);
        add_child(params, (yyvsp[-2].node));
        add_child(header, id);
        add_child(header, params);
        (yyval.node) = new_node(FuncDecl, NULL);
        add_child((yyval.node), header);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1552 "y.tab.c"
    break;

  case 18: /* func_declaration: FUNC IDENTIFIER LPAR parameters RPAR type func_body  */
#line 140 "gocompiler.y"
                                                        {
        struct node *header = new_node(FuncHeader, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-5].str)));
        struct node *params = new_node(FuncParams, NULL);
        add_child(params, (yyvsp[-3].node));
        add_child(header, id);
        add_child(header, (yyvsp[-1].node));
        add_child(header, params);
        (yyval.node) = new_node(FuncDecl, NULL);
        add_child((yyval.node), header);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1569 "y.tab.c"
    break;

  case 19: /* parameters: IDENTIFIER type  */
#line 155 "gocompiler.y"
                    {
        struct node *param = new_node(ParamDecl, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-1].str)));
        add_child(param, (yyvsp[0].node));
        add_child(param, id);
        (yyval.node) = param;
    }
#line 1581 "y.tab.c"
    break;

  case 20: /* parameters: parameters COMMA IDENTIFIER type  */
#line 162 "gocompiler.y"
                                     {
        struct node *param = new_node(ParamDecl, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-1].str)));
        add_child(param, (yyvsp[0].node));
        add_child(param, id);
        add_child((yyvsp[-3].node), param);
        (yyval.node) = (yyvsp[-3].node);
    }
#line 1594 "y.tab.c"
    break;

  case 21: /* func_body: LBRACE vars_and_statements RBRACE  */
#line 173 "gocompiler.y"
                                      {
        (yyval.node) = new_node(FuncBody, NULL);
        add_child((yyval.node), (yyvsp[-1].node));

    }
#line 1604 "y.tab.c"
    break;

  case 22: /* vars_and_statements: vars_and_statements var_declaration SEMICOLON  */
#line 181 "gocompiler.y"
                                                  {
        add_child((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = (yyvsp[-2].node);
    }
#line 1612 "y.tab.c"
    break;

  case 23: /* vars_and_statements: vars_and_statements statement SEMICOLON  */
#line 184 "gocompiler.y"
                                            {
        add_child((yyvsp[-2].node), (yyvsp[-1].node)); (yyval.node) = (yyvsp[-2].node);
    }
#line 1620 "y.tab.c"
    break;

  case 24: /* vars_and_statements: var_declaration SEMICOLON  */
#line 187 "gocompiler.y"
                              {
        (yyval.node) = new_node(AUX, NULL); add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1628 "y.tab.c"
    break;

  case 25: /* vars_and_statements: statement SEMICOLON  */
#line 190 "gocompiler.y"
                        {
        (yyval.node) = new_node(AUX, NULL); add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1636 "y.tab.c"
    break;

  case 26: /* statement: IDENTIFIER ASSIGN expr  */
#line 196 "gocompiler.y"
                           {
        struct node *id = new_node(Identifier, strdup((yyvsp[-2].str)));
        (yyval.node) = new_node(Assign, NULL);
        add_child((yyval.node), id);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1647 "y.tab.c"
    break;

  case 27: /* statement: LBRACE statement SEMICOLON RBRACE  */
#line 202 "gocompiler.y"
                                      {
        (yyval.node) = new_node(Block, NULL);
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1656 "y.tab.c"
    break;

  case 28: /* statement: IF expr LBRACE statement SEMICOLON RBRACE  */
#line 206 "gocompiler.y"
                                              {
        (yyval.node) = new_node(If, NULL);
        struct node *block = new_node(Block, NULL);
        add_child(block, (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), block);
    }
#line 1668 "y.tab.c"
    break;

  case 29: /* statement: IF expr LBRACE statement SEMICOLON RBRACE ELSE LBRACE statement SEMICOLON RBRACE  */
#line 213 "gocompiler.y"
                                                                                     {
        (yyval.node) = new_node(If, NULL);
        struct node *block1 = new_node(Block, NULL);
        struct node *block2 = new_node(Block, NULL);
        add_child(block1, (yyvsp[-7].node));
        add_child(block2, (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[-9].node));
        add_child((yyval.node), block1);
        add_child((yyval.node), block2);
    }
#line 1683 "y.tab.c"
    break;

  case 30: /* statement: FOR expr LBRACE statement SEMICOLON RBRACE  */
#line 223 "gocompiler.y"
                                               {
        (yyval.node) = new_node(For, NULL);
        struct node *block = new_node(Block, NULL);
        add_child(block, (yyvsp[-2].node));
        add_child((yyval.node), (yyvsp[-4].node));
        add_child((yyval.node), block);
    }
#line 1695 "y.tab.c"
    break;

  case 31: /* statement: RETURN expr  */
#line 230 "gocompiler.y"
                {
        (yyval.node) = new_node(Return, NULL);
        add_child((yyval.node), (yyvsp[0].node));
    }
#line 1704 "y.tab.c"
    break;

  case 32: /* statement: RETURN  */
#line 234 "gocompiler.y"
           {
        (yyval.node) = new_node(Return, NULL);
    }
#line 1712 "y.tab.c"
    break;

  case 35: /* statement: PRINT LPAR expr RPAR  */
#line 239 "gocompiler.y"
                         {
        (yyval.node) = new_node(Print, NULL);
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1721 "y.tab.c"
    break;

  case 36: /* statement: PRINT LPAR STRLIT RPAR  */
#line 243 "gocompiler.y"
                           {
        (yyval.node) = new_node(Print, NULL);
        add_child((yyval.node), new_node(StrLit, strdup((yyvsp[-1].str))));
    }
#line 1730 "y.tab.c"
    break;

  case 37: /* parse_args: IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ expr RSQ RPAR  */
#line 250 "gocompiler.y"
                                                                            {
        (yyval.node) = new_node(ParseArgs, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-10].str)));
        add_child((yyval.node), id);
        add_child((yyval.node), (yyvsp[-2].node));
    }
#line 1741 "y.tab.c"
    break;

  case 38: /* func_invocation: IDENTIFIER LPAR RPAR  */
#line 259 "gocompiler.y"
                         {
        (yyval.node) = new_node(Call, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-2].str)));
        add_child((yyval.node), id);
    }
#line 1751 "y.tab.c"
    break;

  case 39: /* func_invocation: IDENTIFIER LPAR expr RPAR  */
#line 264 "gocompiler.y"
                              {
        (yyval.node) = new_node(Call, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-3].str)));
        add_child((yyval.node), id);
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1762 "y.tab.c"
    break;

  case 40: /* func_invocation: IDENTIFIER LPAR expr COMMA expr RPAR  */
#line 270 "gocompiler.y"
                                         {
        (yyval.node) = new_node(Call, NULL);
        struct node *id = new_node(Identifier, strdup((yyvsp[-5].str)));
        add_child((yyval.node), id);
        add_child((yyval.node), (yyvsp[-3].node));
        add_child((yyval.node), (yyvsp[-1].node));
    }
#line 1774 "y.tab.c"
    break;

  case 41: /* expr: expr OR expr  */
#line 280 "gocompiler.y"
                       { (yyval.node) = new_node(Or, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1780 "y.tab.c"
    break;

  case 42: /* expr: expr AND expr  */
#line 281 "gocompiler.y"
                       { (yyval.node) = new_node(And, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1786 "y.tab.c"
    break;

  case 43: /* expr: expr EQ expr  */
#line 282 "gocompiler.y"
                       { (yyval.node) = new_node(Eq, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1792 "y.tab.c"
    break;

  case 44: /* expr: expr NE expr  */
#line 283 "gocompiler.y"
                       { (yyval.node) = new_node(Ne, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1798 "y.tab.c"
    break;

  case 45: /* expr: expr LT expr  */
#line 284 "gocompiler.y"
                       { (yyval.node) = new_node(Lt, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1804 "y.tab.c"
    break;

  case 46: /* expr: expr GT expr  */
#line 285 "gocompiler.y"
                       { (yyval.node) = new_node(Gt, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1810 "y.tab.c"
    break;

  case 47: /* expr: expr LE expr  */
#line 286 "gocompiler.y"
                       { (yyval.node) = new_node(Le, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1816 "y.tab.c"
    break;

  case 48: /* expr: expr GE expr  */
#line 287 "gocompiler.y"
                       { (yyval.node) = new_node(Ge, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1822 "y.tab.c"
    break;

  case 49: /* expr: expr PLUS expr  */
#line 288 "gocompiler.y"
                       { (yyval.node) = new_node(Add, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1828 "y.tab.c"
    break;

  case 50: /* expr: expr MINUS expr  */
#line 289 "gocompiler.y"
                       { (yyval.node) = new_node(Sub, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1834 "y.tab.c"
    break;

  case 51: /* expr: expr STAR expr  */
#line 290 "gocompiler.y"
                       { (yyval.node) = new_node(Mul, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1840 "y.tab.c"
    break;

  case 52: /* expr: expr DIV expr  */
#line 291 "gocompiler.y"
                       { (yyval.node) = new_node(Div, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1846 "y.tab.c"
    break;

  case 53: /* expr: expr MOD expr  */
#line 292 "gocompiler.y"
                       { (yyval.node) = new_node(Mod, NULL); add_child((yyval.node), (yyvsp[-2].node)); add_child((yyval.node), (yyvsp[0].node)); }
#line 1852 "y.tab.c"
    break;

  case 54: /* expr: MINUS expr  */
#line 293 "gocompiler.y"
                            { (yyval.node) = new_node(Minus, NULL); add_child((yyval.node), (yyvsp[0].node)); }
#line 1858 "y.tab.c"
    break;

  case 55: /* expr: PLUS expr  */
#line 294 "gocompiler.y"
                            { (yyval.node) = new_node(Plus, NULL); add_child((yyval.node), (yyvsp[0].node)); }
#line 1864 "y.tab.c"
    break;

  case 56: /* expr: NOT expr  */
#line 295 "gocompiler.y"
                       { (yyval.node) = new_node(Not, NULL); add_child((yyval.node), (yyvsp[0].node)); }
#line 1870 "y.tab.c"
    break;

  case 57: /* expr: NATURAL  */
#line 296 "gocompiler.y"
                       { (yyval.node) = new_node(Natural, strdup((yyvsp[0].str))); }
#line 1876 "y.tab.c"
    break;

  case 58: /* expr: DECIMAL  */
#line 297 "gocompiler.y"
                       { (yyval.node) = new_node(Decimal, strdup((yyvsp[0].str))); }
#line 1882 "y.tab.c"
    break;

  case 59: /* expr: IDENTIFIER  */
#line 298 "gocompiler.y"
                       { (yyval.node) = new_node(Identifier, strdup((yyvsp[0].str))); }
#line 1888 "y.tab.c"
    break;

  case 61: /* expr: LPAR expr RPAR  */
#line 300 "gocompiler.y"
                       { (yyval.node) = (yyvsp[-1].node); }
#line 1894 "y.tab.c"
    break;


#line 1898 "y.tab.c"

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

#line 303 "gocompiler.y"


void yyerror(const char *s) {
    printf("Line %d, column %d: syntax error: %s\n", line, col, yytext);
}
