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
        * Projeto de Compiladores 2021/2022
        * Meta 3
        * 2019218953 João Miguel Ferreira Castelo Branco Catré
        * 2019227240 Sofia Botelho Vieira Alves
      */ 
        #include "ast.h"
        #include "structures.h"
        #include "semantic_analysis.h"


        int yylex();
        int yyparse();
        void yyerror (const char *str);
        
        int flag_syntax_error=0;

        ast_node* varspec_aux = NULL;
        ast_node* varspec_aux_1 = NULL;
        ast_node* aux = NULL; 
        ast_node* aux2 = NULL;
        //ast_node* program_root = NULL; //root node of astree     ORIGINAL
        //extern ast_node * program_root;                          
        extern ast_node * program_root;

        // Nós superfluos -> while a correr os nos irmaos, tem que ter no minimo 2 nos irmaos. caso contrário, não printa
        table_t *tables_root = NULL;



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
# define YYDEBUG 1
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
    SEMICOLON = 258,               /* SEMICOLON  */
    COMMA = 259,                   /* COMMA  */
    BLANKID = 260,                 /* BLANKID  */
    ASSIGN = 261,                  /* ASSIGN  */
    STAR = 262,                    /* STAR  */
    DIV = 263,                     /* DIV  */
    MINUS = 264,                   /* MINUS  */
    PLUS = 265,                    /* PLUS  */
    EQ = 266,                      /* EQ  */
    GE = 267,                      /* GE  */
    GT = 268,                      /* GT  */
    LE = 269,                      /* LE  */
    LT = 270,                      /* LT  */
    MOD = 271,                     /* MOD  */
    NE = 272,                      /* NE  */
    NOT = 273,                     /* NOT  */
    AND = 274,                     /* AND  */
    OR = 275,                      /* OR  */
    LBRACE = 276,                  /* LBRACE  */
    RBRACE = 277,                  /* RBRACE  */
    LPAR = 278,                    /* LPAR  */
    RPAR = 279,                    /* RPAR  */
    LSQ = 280,                     /* LSQ  */
    RSQ = 281,                     /* RSQ  */
    PACKAGE = 282,                 /* PACKAGE  */
    RETURN = 283,                  /* RETURN  */
    PRINT = 284,                   /* PRINT  */
    PARSEINT = 285,                /* PARSEINT  */
    FUNC = 286,                    /* FUNC  */
    CMDARGS = 287,                 /* CMDARGS  */
    VAR = 288,                     /* VAR  */
    IF = 289,                      /* IF  */
    ELSE = 290,                    /* ELSE  */
    FOR = 291,                     /* FOR  */
    INT = 292,                     /* INT  */
    FLOAT32 = 293,                 /* FLOAT32  */
    BOOL = 294,                    /* BOOL  */
    STRING = 295,                  /* STRING  */
    UNARY = 296,                   /* UNARY  */
    ID = 297,                      /* ID  */
    STRLIT = 298,                  /* STRLIT  */
    INTLIT = 299,                  /* INTLIT  */
    REALLIT = 300,                 /* REALLIT  */
    RESERVED = 301                 /* RESERVED  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define SEMICOLON 258
#define COMMA 259
#define BLANKID 260
#define ASSIGN 261
#define STAR 262
#define DIV 263
#define MINUS 264
#define PLUS 265
#define EQ 266
#define GE 267
#define GT 268
#define LE 269
#define LT 270
#define MOD 271
#define NE 272
#define NOT 273
#define AND 274
#define OR 275
#define LBRACE 276
#define RBRACE 277
#define LPAR 278
#define RPAR 279
#define LSQ 280
#define RSQ 281
#define PACKAGE 282
#define RETURN 283
#define PRINT 284
#define PARSEINT 285
#define FUNC 286
#define CMDARGS 287
#define VAR 288
#define IF 289
#define ELSE 290
#define FOR 291
#define INT 292
#define FLOAT32 293
#define BOOL 294
#define STRING 295
#define UNARY 296
#define ID 297
#define STRLIT 298
#define INTLIT 299
#define REALLIT 300
#define RESERVED 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "gocompiler.y"

        char* value;
        ast_node* node;   

#line 253 "y.tab.c"

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
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 4,                      /* COMMA  */
  YYSYMBOL_BLANKID = 5,                    /* BLANKID  */
  YYSYMBOL_ASSIGN = 6,                     /* ASSIGN  */
  YYSYMBOL_STAR = 7,                       /* STAR  */
  YYSYMBOL_DIV = 8,                        /* DIV  */
  YYSYMBOL_MINUS = 9,                      /* MINUS  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_EQ = 11,                        /* EQ  */
  YYSYMBOL_GE = 12,                        /* GE  */
  YYSYMBOL_GT = 13,                        /* GT  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_MOD = 16,                       /* MOD  */
  YYSYMBOL_NE = 17,                        /* NE  */
  YYSYMBOL_NOT = 18,                       /* NOT  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_LBRACE = 21,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 22,                    /* RBRACE  */
  YYSYMBOL_LPAR = 23,                      /* LPAR  */
  YYSYMBOL_RPAR = 24,                      /* RPAR  */
  YYSYMBOL_LSQ = 25,                       /* LSQ  */
  YYSYMBOL_RSQ = 26,                       /* RSQ  */
  YYSYMBOL_PACKAGE = 27,                   /* PACKAGE  */
  YYSYMBOL_RETURN = 28,                    /* RETURN  */
  YYSYMBOL_PRINT = 29,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 30,                  /* PARSEINT  */
  YYSYMBOL_FUNC = 31,                      /* FUNC  */
  YYSYMBOL_CMDARGS = 32,                   /* CMDARGS  */
  YYSYMBOL_VAR = 33,                       /* VAR  */
  YYSYMBOL_IF = 34,                        /* IF  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_INT = 37,                       /* INT  */
  YYSYMBOL_FLOAT32 = 38,                   /* FLOAT32  */
  YYSYMBOL_BOOL = 39,                      /* BOOL  */
  YYSYMBOL_STRING = 40,                    /* STRING  */
  YYSYMBOL_UNARY = 41,                     /* UNARY  */
  YYSYMBOL_ID = 42,                        /* ID  */
  YYSYMBOL_STRLIT = 43,                    /* STRLIT  */
  YYSYMBOL_INTLIT = 44,                    /* INTLIT  */
  YYSYMBOL_REALLIT = 45,                   /* REALLIT  */
  YYSYMBOL_RESERVED = 46,                  /* RESERVED  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_Program = 48,                   /* Program  */
  YYSYMBOL_Declarations = 49,              /* Declarations  */
  YYSYMBOL_Declarations2 = 50,             /* Declarations2  */
  YYSYMBOL_VarDeclaration = 51,            /* VarDeclaration  */
  YYSYMBOL_VarSpec = 52,                   /* VarSpec  */
  YYSYMBOL_VarSpecList = 53,               /* VarSpecList  */
  YYSYMBOL_Type = 54,                      /* Type  */
  YYSYMBOL_FuncDeclaration = 55,           /* FuncDeclaration  */
  YYSYMBOL_Parameters = 56,                /* Parameters  */
  YYSYMBOL_ParametersList = 57,            /* ParametersList  */
  YYSYMBOL_FuncBody = 58,                  /* FuncBody  */
  YYSYMBOL_VarsAndStatements = 59,         /* VarsAndStatements  */
  YYSYMBOL_Statement = 60,                 /* Statement  */
  YYSYMBOL_StatementList = 61,             /* StatementList  */
  YYSYMBOL_ParseArgs = 62,                 /* ParseArgs  */
  YYSYMBOL_FuncID = 63,                    /* FuncID  */
  YYSYMBOL_FuncInvocation = 64,            /* FuncInvocation  */
  YYSYMBOL_CommaExpressionList = 65,       /* CommaExpressionList  */
  YYSYMBOL_Expr = 66                       /* Expr  */
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
#define YYLAST   476

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    89,    90,    93,    94,    95,    96,    99,
     100,   103,   107,   117,   121,   128,   129,   130,   131,   134,
     143,   151,   160,   170,   177,   185,   190,   196,   199,   200,
     201,   202,   205,   210,   211,   223,   229,   236,   242,   249,
     257,   266,   269,   274,   278,   284,   285,   287,   289,   290,
     292,   295,   298,   299,   302,   307,   315,   318,   319,   320,
     321,   324,   325,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "COMMA",
  "BLANKID", "ASSIGN", "STAR", "DIV", "MINUS", "PLUS", "EQ", "GE", "GT",
  "LE", "LT", "MOD", "NE", "NOT", "AND", "OR", "LBRACE", "RBRACE", "LPAR",
  "RPAR", "LSQ", "RSQ", "PACKAGE", "RETURN", "PRINT", "PARSEINT", "FUNC",
  "CMDARGS", "VAR", "IF", "ELSE", "FOR", "INT", "FLOAT32", "BOOL",
  "STRING", "UNARY", "ID", "STRLIT", "INTLIT", "REALLIT", "RESERVED",
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
     -23,   -28,    25,    24,   -72,   -20,   -14,    -5,   -72,   -20,
      54,    57,    35,    19,    12,   -72,    61,    87,   -72,   -72,
      44,   104,    67,   -72,   -72,   -72,   -72,    55,   -72,   -72,
     -72,    66,    55,    84,    86,   107,   -72,   -72,    92,   -72,
     110,    66,   -72,   -72,    99,   -72,    73,   -72,    92,   -72,
     -72,   -72,   115,   -72,   279,   101,   279,   269,    13,   126,
     128,   -72,   111,   -72,    55,   -72,   -72,   135,   125,   279,
     279,   279,    21,   116,   -72,   -72,   -72,   422,   262,   392,
     141,   407,   143,   279,   -72,   -72,    11,   110,   -72,   -72,
     137,   -72,   -72,   -72,   132,   356,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   136,
     374,   151,   -72,   167,   170,   144,   422,   140,   -72,   318,
     -72,   -72,   -72,   -72,   -72,   -72,    81,    81,   460,   460,
     460,   460,   460,   -72,   460,   449,   436,   -72,   -72,   131,
     189,   -72,   -72,   193,   146,   -72,   279,   -72,    -1,   153,
     147,   -72,   155,   422,   279,   -72,   212,   160,     9,   422,
     -72,   215,   231,   162,   159,   -72,   -72,   241,   -72,   279,
     -72,   336,   173,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     2,     3,
       0,     0,     0,     0,     0,     9,     0,     0,     6,     8,
       0,     0,     0,    15,    16,    17,    18,     0,    11,     5,
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
     -72,   -72,   -72,   -72,    -2,   187,   172,   -26,   196,   -72,
     121,   117,   -72,   -42,   -71,   -72,   -72,   -44,   -72,   -24
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
      63,    36,    60,   154,     1,    38,    40,    16,    63,   113,
     163,     6,   117,     7,     3,    48,    22,    82,    13,    83,
      69,    70,    94,   155,    63,     4,    90,     5,    12,    71,
      69,    70,    79,    81,    72,   118,    63,    14,    87,    71,
     140,   164,    59,   143,    72,    91,    92,    93,    95,    23,
      24,    25,    26,    73,   110,    74,    75,    18,    20,   116,
      19,    14,   119,    73,    29,    74,    75,    63,    31,    63,
      63,    90,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   161,    32,    37,    96,    97,
      30,   167,    23,    24,    25,    26,    63,   105,    90,    63,
      50,    90,    51,    23,    24,    25,    26,    34,    41,    35,
      42,    22,    63,    37,    46,    64,    50,    63,    63,    90,
      52,    53,   153,    63,    78,    90,    50,    54,    55,    84,
     159,    85,     7,    56,    86,    57,    52,    66,    88,   -56,
     121,    58,    50,    54,    55,   171,    52,    89,   115,    56,
     144,    57,    50,    54,    55,    45,   122,    58,    49,    56,
     137,    57,    52,   112,   145,    65,   149,    58,    50,    54,
      55,    50,    52,   139,   156,    56,   152,    57,   158,    54,
      55,   162,   157,    58,   169,    56,   168,    57,    52,   141,
      50,    52,   142,    58,    50,    54,    55,   173,    54,    55,
      21,    56,     0,    57,    56,    17,    57,    43,   120,    58,
      52,   150,    58,    50,    52,   151,    50,    54,    55,     0,
       0,    54,    55,    56,     0,    57,     0,    56,     0,    57,
       0,    58,    50,    52,   160,    58,    52,   165,     0,     0,
      54,    55,    50,    54,    55,     0,    56,     0,    57,    56,
       0,    57,    52,   166,    58,     0,     0,    58,     0,    54,
      55,     0,    52,   170,     0,    56,     0,    57,     0,    54,
      55,    69,    70,    58,     0,    56,     0,    57,    69,    70,
      71,     0,     0,    58,     0,    72,     0,    71,    69,    70,
      80,     0,    72,     0,     0,     0,     0,    71,     0,     0,
       0,     0,    72,     0,    73,   109,    74,    75,     0,     0,
       0,    73,     0,    74,    75,     0,     0,     0,     0,     0,
       0,    73,   146,    74,    75,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,   107,   108,     0,
       0,     0,   147,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,     0,     0,     0,
       0,     0,   172,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,     0,     0,     0,
     123,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   107,   108,     0,     0,     0,   138,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,   107,   108,   111,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,   114,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,   107,   108,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    96,    97,    98,
      99,     0,     0,     0,     0,     0,   105
};

static const yytype_int16 yycheck[] =
{
      44,    27,    44,     4,    27,    31,    32,     9,    52,    80,
       1,    31,     1,    33,    42,    41,     4,     4,    23,     6,
       9,    10,     1,    24,    68,     0,    68,     3,    42,    18,
       9,    10,    56,    57,    23,    24,    80,    42,    64,    18,
     111,    32,    44,   114,    23,    69,    70,    71,    72,    37,
      38,    39,    40,    42,    78,    44,    45,     3,    23,    83,
       3,    42,    86,    42,     3,    44,    45,   111,    24,   113,
     114,   113,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   156,    42,    21,     7,     8,
       3,   162,    37,    38,    39,    40,   140,    16,   140,   143,
       1,   143,     3,    37,    38,    39,    40,     3,    24,    42,
      24,     4,   156,    21,     4,    42,     1,   161,   162,   161,
      21,    22,   146,   167,    23,   167,     1,    28,    29,     3,
     154,     3,    33,    34,    23,    36,    21,    22,     3,    23,
       3,    42,     1,    28,    29,   169,    21,    22,     5,    34,
       6,    36,     1,    28,    29,    38,    24,    42,    41,    34,
      24,    36,    21,    22,    24,    48,    35,    42,     1,    28,
      29,     1,    21,    22,    21,    34,    30,    36,    23,    28,
      29,    21,    35,    42,    25,    34,    24,    36,    21,    22,
       1,    21,    22,    42,     1,    28,    29,    24,    28,    29,
      13,    34,    -1,    36,    34,     9,    36,    35,    87,    42,
      21,    22,    42,     1,    21,    22,     1,    28,    29,    -1,
      -1,    28,    29,    34,    -1,    36,    -1,    34,    -1,    36,
      -1,    42,     1,    21,    22,    42,    21,    22,    -1,    -1,
      28,    29,     1,    28,    29,    -1,    34,    -1,    36,    34,
      -1,    36,    21,    22,    42,    -1,    -1,    42,    -1,    28,
      29,    -1,    21,    22,    -1,    34,    -1,    36,    -1,    28,
      29,     9,    10,    42,    -1,    34,    -1,    36,     9,    10,
      18,    -1,    -1,    42,    -1,    23,    -1,    18,     9,    10,
      21,    -1,    23,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    42,     4,    44,    45,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    20,    -1,
      -1,    -1,    24,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    -1,    -1,    -1,
      24,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    -1,    -1,    -1,    24,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    48,    42,     0,     3,    31,    33,    49,    50,
      51,    55,    42,    23,    42,    52,    51,    55,     3,     3,
      23,    52,     4,    37,    38,    39,    40,    53,    54,     3,
       3,    24,    42,    56,     3,    42,    54,    21,    54,    58,
      54,    24,    24,    53,    59,    58,     4,    57,    54,    58,
       1,     3,    21,    22,    28,    29,    34,    36,    42,    51,
      60,    62,    63,    64,    42,    58,    22,    60,    61,     9,
      10,    18,    23,    42,    44,    45,    64,    66,    23,    66,
      21,    66,     4,     6,     3,     3,    23,    54,     3,    22,
      60,    66,    66,    66,     1,    66,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    19,    20,    43,
      66,    21,    22,    61,    21,     5,    66,     1,    24,    66,
      57,     3,    24,    24,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    24,    24,    22,
      61,    22,    22,    61,     6,    24,     4,    24,    65,    35,
      22,    22,    30,    66,     4,    24,    21,    35,    23,    66,
      22,    61,    21,     1,    32,    22,    22,    61,    24,    25,
      22,    66,    26,    24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    54,    55,
      55,    55,    55,    56,    56,    57,    57,    58,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66
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
  case 2: /* Program: PACKAGE ID SEMICOLON Declarations  */
#line 85 "gocompiler.y"
                                                {program_root = newNode("Program", NULL);
                                                add_child(program_root, (yyvsp[0].node));}
#line 1470 "y.tab.c"
    break;

  case 3: /* Declarations: Declarations2  */
#line 89 "gocompiler.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1476 "y.tab.c"
    break;

  case 4: /* Declarations: %empty  */
#line 90 "gocompiler.y"
                                        {(yyval.node) = NULL;}
#line 1482 "y.tab.c"
    break;

  case 5: /* Declarations2: Declarations2 VarDeclaration SEMICOLON  */
#line 93 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-2].node); add_sibling((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1488 "y.tab.c"
    break;

  case 6: /* Declarations2: VarDeclaration SEMICOLON  */
#line 94 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 1494 "y.tab.c"
    break;

  case 7: /* Declarations2: Declarations2 FuncDeclaration SEMICOLON  */
#line 95 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-2].node); add_sibling((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1500 "y.tab.c"
    break;

  case 8: /* Declarations2: FuncDeclaration SEMICOLON  */
#line 96 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 1506 "y.tab.c"
    break;

  case 9: /* VarDeclaration: VAR VarSpec  */
#line 99 "gocompiler.y"
                                                      {(yyval.node) = (yyvsp[0].node);}
#line 1512 "y.tab.c"
    break;

  case 10: /* VarDeclaration: VAR LPAR VarSpec SEMICOLON RPAR  */
#line 100 "gocompiler.y"
                                                      {(yyval.node) = (yyvsp[-2].node);}
#line 1518 "y.tab.c"
    break;

  case 11: /* VarSpec: ID Type  */
#line 103 "gocompiler.y"
                                {(yyval.node) = newNode("VarDecl", NULL); add_child((yyval.node), (yyvsp[0].node));
                                add_sibling((yyvsp[0].node), newNode("Id", (yyvsp[-1].value)));
                                }
#line 1526 "y.tab.c"
    break;

  case 12: /* VarSpec: ID VarSpecList Type  */
#line 107 "gocompiler.y"
                                {(yyval.node) = newNode("VarDecl", NULL); aux = newNode("Id", (yyvsp[-2].value)); 
                                add_child((yyval.node), (yyvsp[0].node)); add_sibling((yyvsp[0].node), aux); add_sibling((yyval.node), (yyvsp[-1].node));
                                varspec_aux = (yyval.node)->sibling;
                                while(varspec_aux != NULL && strcmp(varspec_aux->first_child->id, "notype") == 0){
                                        strcpy(varspec_aux->first_child->id, (yyvsp[0].node)->id);
                                        varspec_aux = varspec_aux->sibling;
                                }
                                }
#line 1539 "y.tab.c"
    break;

  case 13: /* VarSpecList: COMMA ID VarSpecList  */
#line 117 "gocompiler.y"
                                        {(yyval.node) = newNode("VarDecl", NULL); varspec_aux_1 = newNode("notype", NULL);
                                        add_sibling((yyval.node), (yyvsp[0].node)); add_child((yyval.node), varspec_aux_1); 
                                        add_sibling(varspec_aux_1, newNode("Id", (yyvsp[-1].value)));
                                        }
#line 1548 "y.tab.c"
    break;

  case 14: /* VarSpecList: COMMA ID  */
#line 121 "gocompiler.y"
                                        {(yyval.node) = newNode("VarDecl", NULL);
                                        aux = newNode("notype", NULL);
                                        add_child((yyval.node), aux);
                                        add_sibling(aux, newNode("Id", (yyvsp[0].value))); 
                                        }
#line 1558 "y.tab.c"
    break;

  case 15: /* Type: INT  */
#line 128 "gocompiler.y"
               {(yyval.node) = newNode("Int", NULL);}
#line 1564 "y.tab.c"
    break;

  case 16: /* Type: FLOAT32  */
#line 129 "gocompiler.y"
               {(yyval.node) = newNode("Float32", NULL);}
#line 1570 "y.tab.c"
    break;

  case 17: /* Type: BOOL  */
#line 130 "gocompiler.y"
               {(yyval.node) = newNode("Bool", NULL);}
#line 1576 "y.tab.c"
    break;

  case 18: /* Type: STRING  */
#line 131 "gocompiler.y"
               {(yyval.node) = newNode("String", NULL);}
#line 1582 "y.tab.c"
    break;

  case 19: /* FuncDeclaration: FUNC ID LPAR Parameters RPAR Type FuncBody  */
#line 134 "gocompiler.y"
                                                                {(yyval.node) = newNode("FuncDecl", NULL); 
                                                                aux = newNode("FuncHeader", NULL);
                                                                aux2 = newNode("Id", (yyvsp[-5].value));
                                                                add_child((yyval.node), aux);                                                                                
                                                                add_sibling(aux, (yyvsp[0].node));
                                                                add_child(aux, aux2);
                                                                add_sibling((yyvsp[-1].node), (yyvsp[-3].node));
                                                                add_sibling(aux2, (yyvsp[-1].node));
                                                                }
#line 1596 "y.tab.c"
    break;

  case 20: /* FuncDeclaration: FUNC ID LPAR Parameters RPAR FuncBody  */
#line 143 "gocompiler.y"
                                                                {(yyval.node) = newNode("FuncDecl", NULL);
                                                                aux = newNode("FuncHeader", NULL);
                                                                aux2 = newNode("Id", (yyvsp[-4].value));
                                                                add_child((yyval.node), aux);
                                                                add_sibling(aux, (yyvsp[0].node));
                                                                add_child(aux, aux2);
                                                                add_sibling(aux2, (yyvsp[-2].node));
                                                                }
#line 1609 "y.tab.c"
    break;

  case 21: /* FuncDeclaration: FUNC ID LPAR RPAR Type FuncBody  */
#line 151 "gocompiler.y"
                                                                {(yyval.node) = newNode("FuncDecl", NULL);
                                                                aux = newNode("FuncHeader", NULL);
                                                                add_child((yyval.node), aux);
                                                                aux2 = newNode("Id", (yyvsp[-4].value));
                                                                add_sibling(aux, (yyvsp[0].node));
                                                                add_child(aux, aux2);
                                                                add_sibling(aux2, (yyvsp[-1].node));
                                                                add_sibling((yyvsp[-1].node), newNode("FuncParams", NULL));
                                                                }
#line 1623 "y.tab.c"
    break;

  case 22: /* FuncDeclaration: FUNC ID LPAR RPAR FuncBody  */
#line 160 "gocompiler.y"
                                                                {(yyval.node) = newNode("FuncDecl", NULL);
                                                                aux = newNode("FuncHeader", NULL);
                                                                aux2 = newNode("Id", (yyvsp[-3].value));
                                                                add_child((yyval.node), aux);
                                                                add_child(aux, aux2);
                                                                add_sibling(aux2, newNode("FuncParams", NULL));
                                                                add_sibling(aux, (yyvsp[0].node));
                                                                }
#line 1636 "y.tab.c"
    break;

  case 23: /* Parameters: ID Type ParametersList  */
#line 170 "gocompiler.y"
                                                {(yyval.node) = newNode("FuncParams", NULL);
                                                aux = newNode("ParamDecl", NULL);
                                                add_child((yyval.node), aux);        
                                                add_sibling(aux, (yyvsp[0].node));
                                                add_child(aux, (yyvsp[-1].node));
                                                add_sibling((yyvsp[-1].node), newNode("Id", (yyvsp[-2].value)));
                                                }
#line 1648 "y.tab.c"
    break;

  case 24: /* Parameters: ID Type  */
#line 177 "gocompiler.y"
                                                {(yyval.node) = newNode("FuncParams", NULL);
                                                aux = newNode("ParamDecl", NULL);
                                                add_child((yyval.node), aux);        
                                                add_child(aux, (yyvsp[0].node));
                                                add_sibling((yyvsp[0].node), newNode("Id", (yyvsp[-1].value)));
                                                }
#line 1659 "y.tab.c"
    break;

  case 25: /* ParametersList: COMMA ID Type ParametersList  */
#line 185 "gocompiler.y"
                                                        {(yyval.node) = newNode("ParamDecl", NULL);
                                                        add_child((yyval.node), (yyvsp[-1].node));
                                                        add_sibling((yyvsp[-1].node), newNode("Id", (yyvsp[-2].value)));
                                                        add_sibling((yyval.node), (yyvsp[0].node));
                                                        }
#line 1669 "y.tab.c"
    break;

  case 26: /* ParametersList: COMMA ID Type  */
#line 190 "gocompiler.y"
                                                        {(yyval.node) = newNode("ParamDecl", NULL);
                                                        add_child((yyval.node), (yyvsp[0].node));
                                                        add_sibling((yyvsp[0].node), newNode("Id", (yyvsp[-1].value)));
                                                        }
#line 1678 "y.tab.c"
    break;

  case 27: /* FuncBody: LBRACE VarsAndStatements RBRACE  */
#line 196 "gocompiler.y"
                                                  {(yyval.node) = newNode("FuncBody", NULL); add_child((yyval.node), (yyvsp[-1].node));}
#line 1684 "y.tab.c"
    break;

  case 28: /* VarsAndStatements: VarsAndStatements VarDeclaration SEMICOLON  */
#line 199 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-2].node); add_sibling((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1690 "y.tab.c"
    break;

  case 29: /* VarsAndStatements: VarsAndStatements Statement SEMICOLON  */
#line 200 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-2].node); add_sibling((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1696 "y.tab.c"
    break;

  case 30: /* VarsAndStatements: VarsAndStatements SEMICOLON  */
#line 201 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 1702 "y.tab.c"
    break;

  case 31: /* VarsAndStatements: %empty  */
#line 202 "gocompiler.y"
                                                                {(yyval.node) = newNode("NULL", NULL);}
#line 1708 "y.tab.c"
    break;

  case 32: /* Statement: ID ASSIGN Expr  */
#line 205 "gocompiler.y"
                                                                        {(yyval.node) = newNode("Assign", NULL);
                                                                        aux = newNode("Id", (yyvsp[-2].value));
                                                                        add_child((yyval.node), aux);
                                                                        add_sibling(aux, (yyvsp[0].node));
                                                                        }
#line 1718 "y.tab.c"
    break;

  case 33: /* Statement: LBRACE RBRACE  */
#line 210 "gocompiler.y"
                                                                        {(yyval.node) = newNode("NULL", NULL);}
#line 1724 "y.tab.c"
    break;

  case 34: /* Statement: LBRACE StatementList RBRACE  */
#line 211 "gocompiler.y"
                                                                        {aux = (yyvsp[-1].node);
                                                                        int n = 0;
                                                                        while(aux != NULL){
                                                                                if(strcmp(aux->id, "NULL") != 0) n++;
                                                                                aux = aux->sibling;
                                                                        }
                                                                        if(n>=2){
                                                                                (yyval.node) = newNode("Block", NULL);
                                                                                add_child((yyval.node), (yyvsp[-1].node));
                                                                        }
                                                                        else (yyval.node) = (yyvsp[-1].node);
                                                                        }
#line 1741 "y.tab.c"
    break;

  case 35: /* Statement: IF Expr LBRACE RBRACE  */
#line 223 "gocompiler.y"
                                                                        {(yyval.node) = newNode("If", NULL );
                                                                        add_child((yyval.node), (yyvsp[-2].node));
                                                                        aux=newNode("Block", NULL);
                                                                        add_sibling((yyvsp[-2].node), aux);
                                                                        add_sibling(aux, newNode("Block", NULL));
                                                                        }
#line 1752 "y.tab.c"
    break;

  case 36: /* Statement: IF Expr LBRACE StatementList RBRACE  */
#line 229 "gocompiler.y"
                                                                        {(yyval.node) = newNode("If", NULL);
                                                                        add_child((yyval.node), (yyvsp[-3].node));
                                                                        aux=newNode("Block", NULL);
                                                                        add_sibling((yyvsp[-3].node), aux);
                                                                        add_child(aux, (yyvsp[-1].node));
                                                                        add_sibling(aux, newNode("Block", NULL));
                                                                        }
#line 1764 "y.tab.c"
    break;

  case 37: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE RBRACE  */
#line 236 "gocompiler.y"
                                                                        {(yyval.node) = newNode("If", NULL);
                                                                        add_child((yyval.node), (yyvsp[-5].node));
                                                                        aux=newNode("Block", NULL);
                                                                        add_sibling((yyvsp[-5].node), aux);
                                                                        add_sibling(aux, newNode("Block", NULL));
                                                                        }
#line 1775 "y.tab.c"
    break;

  case 38: /* Statement: IF Expr LBRACE StatementList RBRACE ELSE LBRACE RBRACE  */
#line 242 "gocompiler.y"
                                                                        {(yyval.node) = newNode("If", NULL);
                                                                        add_child((yyval.node), (yyvsp[-6].node));
                                                                        aux=newNode("Block", NULL);
                                                                        add_sibling((yyvsp[-6].node), aux);
                                                                        add_child(aux, (yyvsp[-4].node));
                                                                        add_sibling(aux, newNode("Block", NULL));
                                                                        }
#line 1787 "y.tab.c"
    break;

  case 39: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE StatementList RBRACE  */
#line 249 "gocompiler.y"
                                                                        {(yyval.node) = newNode("If", NULL);
                                                                        add_child((yyval.node), (yyvsp[-6].node));
                                                                        aux=newNode("Block", NULL);
                                                                        aux2=newNode("Block", NULL);
                                                                        add_sibling((yyvsp[-6].node), aux);
                                                                        add_sibling(aux, aux2);
                                                                        add_child(aux2, (yyvsp[-1].node));
                                                                        }
#line 1800 "y.tab.c"
    break;

  case 40: /* Statement: IF Expr LBRACE StatementList RBRACE ELSE LBRACE StatementList RBRACE  */
#line 257 "gocompiler.y"
                                                                               {(yyval.node) = newNode("If", NULL);
                                                                                add_child((yyval.node), (yyvsp[-7].node));
                                                                                aux=newNode("Block", NULL);
                                                                                aux2=newNode("Block", NULL);
                                                                                add_sibling((yyvsp[-7].node), aux);
                                                                                add_child(aux, (yyvsp[-5].node));
                                                                                add_sibling(aux, aux2);
                                                                                add_child(aux2, (yyvsp[-1].node));
                                                                                }
#line 1814 "y.tab.c"
    break;

  case 41: /* Statement: FOR LBRACE RBRACE  */
#line 266 "gocompiler.y"
                                                                        {(yyval.node) = newNode("For", NULL);
                                                                        add_child((yyval.node), newNode("Block", NULL));
                                                                        }
#line 1822 "y.tab.c"
    break;

  case 42: /* Statement: FOR LBRACE StatementList RBRACE  */
#line 269 "gocompiler.y"
                                                                        {(yyval.node) = newNode("For", NULL);
                                                                        aux=newNode("Block", NULL);
                                                                        add_child((yyval.node), aux);
                                                                        add_child(aux, (yyvsp[-1].node));
                                                                        }
#line 1832 "y.tab.c"
    break;

  case 43: /* Statement: FOR Expr LBRACE RBRACE  */
#line 274 "gocompiler.y"
                                                                        {(yyval.node) = newNode("For", NULL);
                                                                        add_child((yyval.node), (yyvsp[-2].node));
                                                                        add_sibling((yyvsp[-2].node), newNode("Block", NULL));
                                                                        }
#line 1841 "y.tab.c"
    break;

  case 44: /* Statement: FOR Expr LBRACE StatementList RBRACE  */
#line 278 "gocompiler.y"
                                                                        {(yyval.node) = newNode("For", NULL);
                                                                        add_child((yyval.node), (yyvsp[-3].node));
                                                                        aux=newNode("Block", NULL);
                                                                        add_sibling((yyvsp[-3].node), aux);
                                                                        add_child(aux, (yyvsp[-1].node));
                                                                        }
#line 1852 "y.tab.c"
    break;

  case 45: /* Statement: RETURN  */
#line 284 "gocompiler.y"
                                                                        {(yyval.node) = newNode("Return", NULL);}
#line 1858 "y.tab.c"
    break;

  case 46: /* Statement: RETURN Expr  */
#line 285 "gocompiler.y"
                                                                        {(yyval.node) = newNode("Return", NULL);
                                                                        add_child((yyval.node), (yyvsp[0].node));}
#line 1865 "y.tab.c"
    break;

  case 47: /* Statement: FuncInvocation  */
#line 287 "gocompiler.y"
                                                                        {(yyval.node) = newNode("Call", NULL);
                                                                        add_child((yyval.node), (yyvsp[0].node));}
#line 1872 "y.tab.c"
    break;

  case 48: /* Statement: ParseArgs  */
#line 289 "gocompiler.y"
                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1878 "y.tab.c"
    break;

  case 49: /* Statement: PRINT LPAR Expr RPAR  */
#line 290 "gocompiler.y"
                                                                        {(yyval.node) = newNode("Print", NULL);
                                                                        add_child((yyval.node), (yyvsp[-1].node));}
#line 1885 "y.tab.c"
    break;

  case 50: /* Statement: PRINT LPAR STRLIT RPAR  */
#line 292 "gocompiler.y"
                                                                        {(yyval.node) = newNode("Print", NULL);
                                                                        aux = newNode("StrLit", (yyvsp[-1].value));
                                                                        add_child((yyval.node), aux);}
#line 1893 "y.tab.c"
    break;

  case 51: /* Statement: error  */
#line 295 "gocompiler.y"
                                                                        {(yyval.node) = newNode("Error", NULL); free_ast(program_root);}
#line 1899 "y.tab.c"
    break;

  case 52: /* StatementList: StatementList Statement SEMICOLON  */
#line 298 "gocompiler.y"
                                                        {(yyval.node) = (yyvsp[-2].node); add_sibling((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1905 "y.tab.c"
    break;

  case 53: /* StatementList: Statement SEMICOLON  */
#line 299 "gocompiler.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1911 "y.tab.c"
    break;

  case 54: /* ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR  */
#line 302 "gocompiler.y"
                                                                                {(yyval.node) = newNode("ParseArgs", NULL);
                                                                                aux = newNode("Id", (yyvsp[-10].value));
                                                                                add_child((yyval.node), aux);
                                                                                add_sibling(aux, (yyvsp[-2].node));
                                                                                }
#line 1921 "y.tab.c"
    break;

  case 55: /* ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR  */
#line 307 "gocompiler.y"
                                                                                {(yyval.node) = newNode("ParseArgs", NULL);
                                                                                aux = newNode("Id", (yyvsp[-7].value));
                                                                                add_child((yyval.node), aux);
                                                                                add_sibling(aux, newNode("Error", NULL));
                                                                                free_ast(program_root);
                                                                                }
#line 1932 "y.tab.c"
    break;

  case 56: /* FuncID: ID  */
#line 315 "gocompiler.y"
                                                             {(yyval.node) = newNode("Id", (yyvsp[0].value));}
#line 1938 "y.tab.c"
    break;

  case 57: /* FuncInvocation: FuncID LPAR RPAR  */
#line 318 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-2].node);}
#line 1944 "y.tab.c"
    break;

  case 58: /* FuncInvocation: FuncID LPAR Expr RPAR  */
#line 319 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-3].node); add_sibling((yyvsp[-3].node), (yyvsp[-1].node));}
#line 1950 "y.tab.c"
    break;

  case 59: /* FuncInvocation: FuncID LPAR Expr CommaExpressionList RPAR  */
#line 320 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-4].node); add_sibling((yyvsp[-4].node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1956 "y.tab.c"
    break;

  case 60: /* FuncInvocation: FuncID LPAR error RPAR  */
#line 321 "gocompiler.y"
                                                                {(yyval.node) = (yyvsp[-3].node); add_sibling((yyvsp[-3].node), newNode("Error", NULL)); free_ast(program_root);}
#line 1962 "y.tab.c"
    break;

  case 61: /* CommaExpressionList: CommaExpressionList COMMA Expr  */
#line 324 "gocompiler.y"
                                                             {(yyval.node) = (yyvsp[-2].node); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 1968 "y.tab.c"
    break;

  case 62: /* CommaExpressionList: COMMA Expr  */
#line 325 "gocompiler.y"
                                                             {(yyval.node) = (yyvsp[0].node);}
#line 1974 "y.tab.c"
    break;

  case 63: /* Expr: Expr OR Expr  */
#line 329 "gocompiler.y"
                                {(yyval.node) = newNode("Or", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 1980 "y.tab.c"
    break;

  case 64: /* Expr: Expr AND Expr  */
#line 330 "gocompiler.y"
                                {(yyval.node) = newNode("And", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 1986 "y.tab.c"
    break;

  case 65: /* Expr: Expr LT Expr  */
#line 331 "gocompiler.y"
                                {(yyval.node) = newNode("Lt",NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 1992 "y.tab.c"
    break;

  case 66: /* Expr: Expr GT Expr  */
#line 332 "gocompiler.y"
                                {(yyval.node) = newNode("Gt",NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 1998 "y.tab.c"
    break;

  case 67: /* Expr: Expr EQ Expr  */
#line 333 "gocompiler.y"
                                {(yyval.node) = newNode("Eq", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 2004 "y.tab.c"
    break;

  case 68: /* Expr: Expr NE Expr  */
#line 334 "gocompiler.y"
                                {(yyval.node) = newNode("Ne", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 2010 "y.tab.c"
    break;

  case 69: /* Expr: Expr LE Expr  */
#line 335 "gocompiler.y"
                                {(yyval.node) = newNode("Le", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 2016 "y.tab.c"
    break;

  case 70: /* Expr: Expr GE Expr  */
#line 336 "gocompiler.y"
                                {(yyval.node) = newNode("Ge", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 2022 "y.tab.c"
    break;

  case 71: /* Expr: Expr PLUS Expr  */
#line 337 "gocompiler.y"
                                {(yyval.node) = newNode("Add", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 2028 "y.tab.c"
    break;

  case 72: /* Expr: Expr MINUS Expr  */
#line 338 "gocompiler.y"
                                {(yyval.node) = newNode("Sub", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 2034 "y.tab.c"
    break;

  case 73: /* Expr: Expr STAR Expr  */
#line 339 "gocompiler.y"
                                {(yyval.node) = newNode("Mul", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 2040 "y.tab.c"
    break;

  case 74: /* Expr: Expr DIV Expr  */
#line 340 "gocompiler.y"
                                {(yyval.node) = newNode("Div", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 2046 "y.tab.c"
    break;

  case 75: /* Expr: Expr MOD Expr  */
#line 341 "gocompiler.y"
                                {(yyval.node) = newNode("Mod", NULL); add_child((yyval.node), (yyvsp[-2].node)); add_sibling((yyvsp[-2].node), (yyvsp[0].node));}
#line 2052 "y.tab.c"
    break;

  case 76: /* Expr: NOT Expr  */
#line 342 "gocompiler.y"
                                {(yyval.node) = newNode("Not", NULL); add_child((yyval.node), (yyvsp[0].node));}
#line 2058 "y.tab.c"
    break;

  case 77: /* Expr: MINUS Expr  */
#line 343 "gocompiler.y"
                                {(yyval.node) = newNode("Minus", NULL); add_child((yyval.node), (yyvsp[0].node));}
#line 2064 "y.tab.c"
    break;

  case 78: /* Expr: PLUS Expr  */
#line 344 "gocompiler.y"
                                {(yyval.node) = newNode("Plus", NULL); add_child((yyval.node), (yyvsp[0].node));}
#line 2070 "y.tab.c"
    break;

  case 79: /* Expr: INTLIT  */
#line 345 "gocompiler.y"
                                {(yyval.node) = newNode("IntLit", (yyvsp[0].value));}
#line 2076 "y.tab.c"
    break;

  case 80: /* Expr: REALLIT  */
#line 346 "gocompiler.y"
                                {(yyval.node) = newNode("RealLit", (yyvsp[0].value));}
#line 2082 "y.tab.c"
    break;

  case 81: /* Expr: ID  */
#line 347 "gocompiler.y"
                                {(yyval.node) = newNode("Id", (yyvsp[0].value));}
#line 2088 "y.tab.c"
    break;

  case 82: /* Expr: FuncInvocation  */
#line 348 "gocompiler.y"
                                {(yyval.node) = newNode("Call", NULL); add_child((yyval.node), (yyvsp[0].node));}
#line 2094 "y.tab.c"
    break;

  case 83: /* Expr: LPAR Expr RPAR  */
#line 349 "gocompiler.y"
                                {(yyval.node) = (yyvsp[-1].node);}
#line 2100 "y.tab.c"
    break;

  case 84: /* Expr: LPAR error RPAR  */
#line 350 "gocompiler.y"
                                {(yyval.node) = newNode("Error", NULL); free_ast(program_root);}
#line 2106 "y.tab.c"
    break;


#line 2110 "y.tab.c"

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

#line 352 "gocompiler.y"
