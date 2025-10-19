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

#line 162 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
