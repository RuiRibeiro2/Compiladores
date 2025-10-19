%{
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
%}

%union {
    char* str;
    struct node* node;
}

%token PACKAGE RETURN ELSE FOR IF VAR
%token INT FLOAT32 BOOL STRING
%token FUNC CMDARGS PRINT PARSEINT
%token SEMICOLON COMMA BLANKID ASSIGN
%token STAR DIV MINUS PLUS
%token EQ GE GT LE LPAR LSQ LT MOD
%token NE NOT AND OR RBRACE RPAR RSQ
%token LBRACE
%token <str> IDENTIFIER STRLIT NATURAL DECIMAL

%type <node> program declarations var_declaration var_spec type
%type <node> func_declaration parameters func_body vars_and_statements
%type <node> statement parse_args func_invocation expr

%left OR
%left AND
%nonassoc EQ NE LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%right UMINUS

%%

program:
    PACKAGE IDENTIFIER SEMICOLON declarations
    {
        root = new_node(Program, NULL);
        add_child(root, $4);
        $$ = root;
    }
;


declarations:
    declarations var_declaration SEMICOLON {
        add_child($1, $2); $$ = $1;
    }
  | declarations func_declaration SEMICOLON {
        add_child($1, $2); $$ = $1;
    }
  | var_declaration SEMICOLON {
        $$ = new_node(AUX, NULL); add_child($$, $1);
    }
  | func_declaration SEMICOLON {
        $$ = new_node(AUX, NULL); add_child($$, $1);
    }
;

var_declaration:
    VAR var_spec {
        $$ = new_node(VarDecl, NULL);
        add_child($$, $2);
    }
  | VAR LPAR var_spec SEMICOLON RPAR {
        $$ = new_node(VarDecl, NULL);
        add_child($$, $3);
    }
;

var_spec:
    IDENTIFIER type {
        $$ = new_node($2->category, NULL);
        struct node *id = new_node(Identifier, strdup($1));
        add_child($$, id);
    }
  | IDENTIFIER COMMA IDENTIFIER type {
        $$ = new_node($4->category, NULL);
        struct node *id1 = new_node(Identifier, strdup($1));
        struct node *id2 = new_node(Identifier, strdup($3));
        add_child($$, id1);
        add_child($$, id2);
    }
;

type:
    INT { $$ = new_node(Int, NULL); }
  | FLOAT32 { $$ = new_node(Float32, NULL); }
  | BOOL { $$ = new_node(Bool, NULL); }
  | STRING { $$ = new_node(String, NULL); }
;

func_declaration:
    FUNC IDENTIFIER LPAR RPAR func_body {
        struct node *header = new_node(FuncHeader, NULL);
        struct node *id = new_node(Identifier, strdup($2));
        struct node *params = new_node(FuncParams, NULL);
        add_child(header, id);
        add_child(header, params);
        $$ = new_node(FuncDecl, NULL);
        add_child($$, header);
        add_child($$, $5);
    }
  | FUNC IDENTIFIER LPAR RPAR type func_body {
        struct node *header = new_node(FuncHeader, NULL);
        struct node *id = new_node(Identifier, strdup($2));
        struct node *params = new_node(FuncParams, NULL);
        add_child(header, id);
        add_child(header, $5);
        add_child(header, params);
        $$ = new_node(FuncDecl, NULL);
        add_child($$, header);
        add_child($$, $6);
    }
  | FUNC IDENTIFIER LPAR parameters RPAR func_body {
        struct node *header = new_node(FuncHeader, NULL);
        struct node *id = new_node(Identifier, strdup($2));
        struct node *params = new_node(FuncParams, NULL);
        add_child(params, $4);
        add_child(header, id);
        add_child(header, params);
        $$ = new_node(FuncDecl, NULL);
        add_child($$, header);
        add_child($$, $6);
    }
  | FUNC IDENTIFIER LPAR parameters RPAR type func_body {
        struct node *header = new_node(FuncHeader, NULL);
        struct node *id = new_node(Identifier, strdup($2));
        struct node *params = new_node(FuncParams, NULL);
        add_child(params, $4);
        add_child(header, id);
        add_child(header, $6);
        add_child(header, params);
        $$ = new_node(FuncDecl, NULL);
        add_child($$, header);
        add_child($$, $7);
    }
;

parameters:
    IDENTIFIER type {
        struct node *param = new_node(ParamDecl, NULL);
        struct node *id = new_node(Identifier, strdup($1));
        add_child(param, $2);
        add_child(param, id);
        $$ = param;
    }
  | parameters COMMA IDENTIFIER type {
        struct node *param = new_node(ParamDecl, NULL);
        struct node *id = new_node(Identifier, strdup($3));
        add_child(param, $4);
        add_child(param, id);
        add_child($1, param);
        $$ = $1;
    }
;

func_body:
    LBRACE vars_and_statements RBRACE {
        $$ = new_node(FuncBody, NULL);
        add_child($$, $2);

    }
;

vars_and_statements:
    vars_and_statements var_declaration SEMICOLON {
        add_child($1, $2); $$ = $1;
    }
  | vars_and_statements statement SEMICOLON {
        add_child($1, $2); $$ = $1;
    }
  | var_declaration SEMICOLON {
        $$ = new_node(AUX, NULL); add_child($$, $1);
    }
  | statement SEMICOLON {
        $$ = new_node(AUX, NULL); add_child($$, $1);
    }
;

statement:
    IDENTIFIER ASSIGN expr {
        struct node *id = new_node(Identifier, strdup($1));
        $$ = new_node(Assign, NULL);
        add_child($$, id);
        add_child($$, $3);
    }
  | LBRACE statement SEMICOLON RBRACE {
        $$ = new_node(Block, NULL);
        add_child($$, $2);
    }
  | IF expr LBRACE statement SEMICOLON RBRACE {
        $$ = new_node(If, NULL);
        struct node *block = new_node(Block, NULL);
        add_child(block, $4);
        add_child($$, $2);
        add_child($$, block);
    }
  | IF expr LBRACE statement SEMICOLON RBRACE ELSE LBRACE statement SEMICOLON RBRACE {
        $$ = new_node(If, NULL);
        struct node *block1 = new_node(Block, NULL);
        struct node *block2 = new_node(Block, NULL);
        add_child(block1, $4);
        add_child(block2, $9);
        add_child($$, $2);
        add_child($$, block1);
        add_child($$, block2);
    }
  | FOR expr LBRACE statement SEMICOLON RBRACE {
        $$ = new_node(For, NULL);
        struct node *block = new_node(Block, NULL);
        add_child(block, $4);
        add_child($$, $2);
        add_child($$, block);
    }
  | RETURN expr {
        $$ = new_node(Return, NULL);
        add_child($$, $2);
    }
  | RETURN {
        $$ = new_node(Return, NULL);
    }
  | func_invocation
  | parse_args
  | PRINT LPAR expr RPAR {
        $$ = new_node(Print, NULL);
        add_child($$, $3);
    }
  | PRINT LPAR STRLIT RPAR {
        $$ = new_node(Print, NULL);
        add_child($$, new_node(StrLit, strdup($3)));
    }
;

parse_args:
    IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ expr RSQ RPAR {
        $$ = new_node(ParseArgs, NULL);
        struct node *id = new_node(Identifier, strdup($1));
        add_child($$, id);
        add_child($$, $9);
    }
;

func_invocation:
    IDENTIFIER LPAR RPAR {
        $$ = new_node(Call, NULL);
        struct node *id = new_node(Identifier, strdup($1));
        add_child($$, id);
    }
  | IDENTIFIER LPAR expr RPAR {
        $$ = new_node(Call, NULL);
        struct node *id = new_node(Identifier, strdup($1));
        add_child($$, id);
        add_child($$, $3);
    }
  | IDENTIFIER LPAR expr COMMA expr RPAR {
        $$ = new_node(Call, NULL);
        struct node *id = new_node(Identifier, strdup($1));
        add_child($$, id);
        add_child($$, $3);
        add_child($$, $5);
    }
;

expr:
    expr OR expr       { $$ = new_node(Or, NULL); add_child($$, $1); add_child($$, $3); }
  | expr AND expr      { $$ = new_node(And, NULL); add_child($$, $1); add_child($$, $3); }
  | expr EQ expr       { $$ = new_node(Eq, NULL); add_child($$, $1); add_child($$, $3); }
  | expr NE expr       { $$ = new_node(Ne, NULL); add_child($$, $1); add_child($$, $3); }
  | expr LT expr       { $$ = new_node(Lt, NULL); add_child($$, $1); add_child($$, $3); }
  | expr GT expr       { $$ = new_node(Gt, NULL); add_child($$, $1); add_child($$, $3); }
  | expr LE expr       { $$ = new_node(Le, NULL); add_child($$, $1); add_child($$, $3); }
  | expr GE expr       { $$ = new_node(Ge, NULL); add_child($$, $1); add_child($$, $3); }
  | expr PLUS expr     { $$ = new_node(Add, NULL); add_child($$, $1); add_child($$, $3); }
  | expr MINUS expr    { $$ = new_node(Sub, NULL); add_child($$, $1); add_child($$, $3); }
  | expr STAR expr     { $$ = new_node(Mul, NULL); add_child($$, $1); add_child($$, $3); }
  | expr DIV expr      { $$ = new_node(Div, NULL); add_child($$, $1); add_child($$, $3); }
  | expr MOD expr      { $$ = new_node(Mod, NULL); add_child($$, $1); add_child($$, $3); }
  | MINUS expr %prec UMINUS { $$ = new_node(Minus, NULL); add_child($$, $2); }
  | PLUS expr %prec UMINUS  { $$ = new_node(Plus, NULL); add_child($$, $2); }
  | NOT expr           { $$ = new_node(Not, NULL); add_child($$, $2); }
  | NATURAL            { $$ = new_node(Natural, strdup($1)); }
  | DECIMAL            { $$ = new_node(Decimal, strdup($1)); }
  | IDENTIFIER         { $$ = new_node(Identifier, strdup($1)); }
  | func_invocation
  | LPAR expr RPAR     { $$ = $2; }
;

%%

void yyerror(const char *s) {
    printf("Line %d, column %d: syntax error: %s\n", line, col, yytext);
}
