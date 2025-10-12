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

#ifndef YY_YY_GOCOMPILER_TAB_H_INCLUDED
# define YY_YY_GOCOMPILER_TAB_H_INCLUDED
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
    SEMICOLON = 258,               /* SEMICOLON  */
    STRING = 259,                  /* STRING  */
    COMMA = 260,                   /* COMMA  */
    BLANKID = 261,                 /* BLANKID  */
    ASSIGN = 262,                  /* ASSIGN  */
    STAR = 263,                    /* STAR  */
    DIV = 264,                     /* DIV  */
    MINUS = 265,                   /* MINUS  */
    PLUS = 266,                    /* PLUS  */
    EQ = 267,                      /* EQ  */
    GE = 268,                      /* GE  */
    GT = 269,                      /* GT  */
    LE = 270,                      /* LE  */
    LT = 271,                      /* LT  */
    MOD = 272,                     /* MOD  */
    NE = 273,                      /* NE  */
    NOT = 274,                     /* NOT  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    LBRACE = 277,                  /* LBRACE  */
    RBRACE = 278,                  /* RBRACE  */
    LPAR = 279,                    /* LPAR  */
    RPAR = 280,                    /* RPAR  */
    LSQ = 281,                     /* LSQ  */
    RSQ = 282,                     /* RSQ  */
    PACKAGE = 283,                 /* PACKAGE  */
    RETURN = 284,                  /* RETURN  */
    PRINT = 285,                   /* PRINT  */
    PARSEINT = 286,                /* PARSEINT  */
    FUNC = 287,                    /* FUNC  */
    CMDARGS = 288,                 /* CMDARGS  */
    VAR = 289,                     /* VAR  */
    IF = 290,                      /* IF  */
    ELSE = 291,                    /* ELSE  */
    FOR = 292,                     /* FOR  */
    INT = 293,                     /* INT  */
    FLOAT32 = 294,                 /* FLOAT32  */
    BOOL = 295,                    /* BOOL  */
    IDENTIFIER = 296,              /* IDENTIFIER  */
    NATURAL = 297,                 /* NATURAL  */
    DECIMAL = 298,                 /* DECIMAL  */
    STRLIT = 299                   /* STRLIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "gocompiler.y"

    char* value;
    struct node* node;   

#line 113 "gocompiler.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GOCOMPILER_TAB_H_INCLUDED  */
