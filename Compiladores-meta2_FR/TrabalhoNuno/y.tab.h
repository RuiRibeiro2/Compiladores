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
    STAR = 260,                    /* STAR  */
    DIV = 261,                     /* DIV  */
    MINUS = 262,                   /* MINUS  */
    PLUS = 263,                    /* PLUS  */
    EQ = 264,                      /* EQ  */
    GE = 265,                      /* GE  */
    GT = 266,                      /* GT  */
    LBRACE = 267,                  /* LBRACE  */
    LE = 268,                      /* LE  */
    LPAR = 269,                    /* LPAR  */
    LSQ = 270,                     /* LSQ  */
    LT = 271,                      /* LT  */
    MOD = 272,                     /* MOD  */
    NE = 273,                      /* NE  */
    NOT = 274,                     /* NOT  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    PACKAGE = 277,                 /* PACKAGE  */
    ELSE = 278,                    /* ELSE  */
    FOR = 279,                     /* FOR  */
    IF = 280,                      /* IF  */
    VAR = 281,                     /* VAR  */
    INT = 282,                     /* INT  */
    FLOAT32 = 283,                 /* FLOAT32  */
    BOOL = 284,                    /* BOOL  */
    STRING = 285,                  /* STRING  */
    PRINT = 286,                   /* PRINT  */
    PARSEINT = 287,                /* PARSEINT  */
    FUNC = 288,                    /* FUNC  */
    CMDARGS = 289,                 /* CMDARGS  */
    BLANKID = 290,                 /* BLANKID  */
    RBRACE = 291,                  /* RBRACE  */
    RPAR = 292,                    /* RPAR  */
    RETURN = 293,                  /* RETURN  */
    RSQ = 294,                     /* RSQ  */
    ASSIGN = 295,                  /* ASSIGN  */
    STRLIT = 296,                  /* STRLIT  */
    RESERVED = 297,                /* RESERVED  */
    IDENTIFIER = 298,              /* IDENTIFIER  */
    NATURAL = 299,                 /* NATURAL  */
    DECIMAL = 300,                 /* DECIMAL  */
    LOW = 301                      /* LOW  */
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
#define STAR 260
#define DIV 261
#define MINUS 262
#define PLUS 263
#define EQ 264
#define GE 265
#define GT 266
#define LBRACE 267
#define LE 268
#define LPAR 269
#define LSQ 270
#define LT 271
#define MOD 272
#define NE 273
#define NOT 274
#define AND 275
#define OR 276
#define PACKAGE 277
#define ELSE 278
#define FOR 279
#define IF 280
#define VAR 281
#define INT 282
#define FLOAT32 283
#define BOOL 284
#define STRING 285
#define PRINT 286
#define PARSEINT 287
#define FUNC 288
#define CMDARGS 289
#define BLANKID 290
#define RBRACE 291
#define RPAR 292
#define RETURN 293
#define RSQ 294
#define ASSIGN 295
#define STRLIT 296
#define RESERVED 297
#define IDENTIFIER 298
#define NATURAL 299
#define DECIMAL 300
#define LOW 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "gocompiler.y"

    char *lexeme;
    struct node *node;

#line 164 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
