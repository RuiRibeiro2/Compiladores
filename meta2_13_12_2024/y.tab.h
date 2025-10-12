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

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
