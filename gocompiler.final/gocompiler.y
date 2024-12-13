%{
    /*
    Projeto de Compiladores 2023/2024~
    Meta 2
    2021189478 - Rui Ribeiro
    2021221169 - Francisco Rodrigues
    */
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "y.tab.h"
extern int yylex(void);
void yyerror(char *);
extern char *yytext;
node* program_root = NULL;
node* aux;
node* varspec_aux;
node* varspec_aux1 = NULL;
node* aux2 = NULL;

%}

%union {
    char* value;
    struct node* node;   
};

// Yacc tokens 
%token SEMICOLON
%token STRING 
%token COMMA 
%token BLANKID
%token ASSIGN STAR DIV MINUS PLUS 
%token EQ GE GT LE LT MOD NE
%token NOT AND OR
%token LBRACE RBRACE LPAR RPAR LSQ RSQ 
%token PACKAGE
%token RETURN PRINT PARSEINT FUNC CMDARGS VAR
%token IF ELSE FOR
%token INT FLOAT32 BOOL  

%token <value> IDENTIFIER
%token <value> NATURAL DECIMAL
%token <value> STRLIT

%type <node> Program Declarations Declarations2
%type <node> VarDeclaration Parameters ParametersList
%type <node> VarSpec VarSpecList Type FuncDeclaration 
%type <node> FuncBody VarsAndStatements
%type <node> Statement StatementList ParseArgs
%type <node> CommaExpressionList Expr
%type <node> FuncInvocation FuncID

// Precedence and associativity
%left COMMA
%right ASSIGN
%left OR 
%left AND
%left LT LE GT GE EQ NE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%left LPAR RPAR LSQ RSQ

%%

// Program Rule
Program: PACKAGE IDENTIFIER SEMICOLON Declarations {
    program_root = newNode("Program", NULL);
    addchild(program_root, $4);
};

// Declarations Rules
Declarations: Declarations2 { $$ = $1; }
            | /* epsilon */ { $$ = NULL; };

Declarations2: Declarations2 VarDeclaration SEMICOLON {
    $$ = $1;
    addsiblings($1, $2);
}
| VarDeclaration SEMICOLON { $$ = $1; }
| Declarations2 FuncDeclaration SEMICOLON {
    $$ = $1;
    addsiblings($1, $2);
}
| FuncDeclaration SEMICOLON { $$ = $1; };

// Variable Declarations
VarDeclaration: VAR VarSpec { $$ = $2; }
              | VAR LPAR VarSpec SEMICOLON RPAR { $$ = $3; };

// Variable Specification
VarSpec: IDENTIFIER Type {
    $$ = newNode("VarDecl", NULL);
    addchild($$, $2);
    addsiblings($2, newNode("IDENTIFIER", $1));
}
| IDENTIFIER VarSpecList Type {
    $$ = newNode("VarDecl", NULL);
    aux = newNode("IDENTIFIER", $1);
    addchild($$, $3);
    addsiblings($3, aux);
    addsiblings($$, $2);

    varspec_aux = $$->sibling;
    while (varspec_aux != NULL && strcmp(varspec_aux->children->node->token, "notype") == 0) {
        strcpy(varspec_aux->children->node->token, $3->token);
        varspec_aux = varspec_aux->sibling;
    }
};

// VarSpecList Rule
VarSpecList: COMMA IDENTIFIER VarSpecList {
    $$ = newNode("VarDecl", NULL);
    varspec_aux1 = newNode("notype", NULL);
    addsiblings($$, $3);
    addchild($$, varspec_aux1);
    addsiblings(varspec_aux1, newNode("IDENTIFIER", $2));
}
| COMMA IDENTIFIER {
    $$ = newNode("VarDecl", NULL);
    aux = newNode("notype", NULL);
    addchild($$, aux);
    addsiblings(aux, newNode("IDENTIFIER", $2));
};

// Type Rule
Type: INT { $$ = newNode("Int", NULL); }
    | FLOAT32 { $$ = newNode("Float32", NULL); }
    | BOOL { $$ = newNode("Bool", NULL); }
    | STRING { $$ = newNode("String", NULL); };

// Function Declaration Rules
FuncDeclaration: FUNC IDENTIFIER LPAR Parameters RPAR Type FuncBody {
    $$ = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", $2);
    addchild($$, aux);
    addsiblings(aux, $7);
    addchild(aux, aux2);
    addsiblings($6, $4);
    addsiblings(aux2, $6);
}
| FUNC IDENTIFIER LPAR Parameters RPAR FuncBody {
    $$ = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", $2);
    addchild($$, aux);
    addsiblings(aux, $6);
    addchild(aux, aux2);
    addsiblings(aux2, $4);
}
| FUNC IDENTIFIER LPAR RPAR Type FuncBody {
    $$ = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", $2);
    addchild($$, aux);
    addsiblings(aux, $6);
    addchild(aux, aux2);
    addsiblings(aux2, $5);
    addsiblings($5, newNode("FuncParams", NULL));
}
| FUNC IDENTIFIER LPAR RPAR FuncBody {
    $$ = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", $2);
    addchild($$, aux);
    addchild(aux, aux2);
    addsiblings(aux2, newNode("FuncParams", NULL));
    addsiblings(aux, $5);
};

// Parameters Rule
Parameters: IDENTIFIER Type ParametersList {
    $$ = newNode("FuncParams", NULL);
    aux = newNode("ParamDecl", NULL);
    addchild($$, aux);
    addsiblings(aux, $3);
    addchild(aux, $2);
    addsiblings($2, newNode("IDENTIFIER", $1));
}
| IDENTIFIER Type {
    $$ = newNode("FuncParams", NULL);
    aux = newNode("ParamDecl", NULL);
    addchild($$, aux);
    addchild(aux, $2);
    addsiblings($2, newNode("IDENTIFIER", $1));
};

// ParametersList Rule
ParametersList: COMMA IDENTIFIER Type ParametersList {
    $$ = newNode("ParamDecl", NULL);
    addchild($$, $3);
    addsiblings($3, newNode("IDENTIFIER", $2));
    addsiblings($$, $4);
}
| COMMA IDENTIFIER Type {
    $$ = newNode("ParamDecl", NULL);
    addchild($$, $3);
    addsiblings($3, newNode("IDENTIFIER", $2));
};

// Remaining Rules
FuncBody: LBRACE VarsAndStatements RBRACE {
    $$ = newNode("FuncBody", NULL);
    addchild($$, $2);
};

VarsAndStatements: VarsAndStatements VarDeclaration SEMICOLON {
    $$ = $1;
    addsiblings($1, $2);
}
| VarsAndStatements Statement SEMICOLON {
    $$ = $1;
    addsiblings($1, $2);
}
| VarsAndStatements SEMICOLON { $1 = $1; }
| /* epsilon */ { $$ = newNode("NULL", NULL); };

Statement: IDENTIFIER ASSIGN Expr {
    $$ = newNode("Assign", NULL);
    aux = newNode("IDENTIFIER", $1);
    addchild($$, aux);
    addsiblings(aux, $3);
}
// Statement Rules Continued
| LBRACE RBRACE {
    $$ = newNode("NULL", NULL);
}
| LBRACE StatementList RBRACE {
    aux = $2;
    int n = 0;
    while (aux != NULL) {
        if (strcmp(aux->token, "NULL") != 0) n++;
        aux = aux->sibling;
    }
    if (n >= 2) {
        $$ = newNode("Block", NULL);
        addchild($$, $2);
    } else {
        $$ = $2;
    }
}
| IF Expr LBRACE RBRACE {
    $$ = newNode("If", NULL);
    addchild($$, $2);
    aux = newNode("Block", NULL);
    addsiblings($2, aux);
    addsiblings(aux, newNode("Block", NULL));
}
| IF Expr LBRACE StatementList RBRACE {
    $$ = newNode("If", NULL);
    addchild($$, $2);
    aux = newNode("Block", NULL);
    addsiblings($2, aux);
    addchild(aux, $4);
    addsiblings(aux, newNode("Block", NULL));
}
| IF Expr LBRACE RBRACE ELSE LBRACE RBRACE {
    $$ = newNode("If", NULL);
    addchild($$, $2);
    aux = newNode("Block", NULL);
    addsiblings($2, aux);
    addsiblings(aux, newNode("Block", NULL));
}
| IF Expr LBRACE StatementList RBRACE ELSE LBRACE RBRACE {
    $$ = newNode("If", NULL);
    addchild($$, $2);
    aux = newNode("Block", NULL);
    addsiblings($2, aux);
    addchild(aux, $4);
    addsiblings(aux, newNode("Block", NULL));
}
| IF Expr LBRACE RBRACE ELSE LBRACE StatementList RBRACE {
    $$ = newNode("If", NULL);
    addchild($$, $2);
    aux = newNode("Block", NULL);
    aux2 = newNode("Block", NULL);
    addsiblings($2, aux);
    addsiblings(aux, aux2);
    addchild(aux2, $7);
}
| IF Expr LBRACE StatementList RBRACE ELSE LBRACE StatementList RBRACE {
    $$ = newNode("If", NULL);
    addchild($$, $2);
    aux = newNode("Block", NULL);
    aux2 = newNode("Block", NULL);
    addsiblings($2, aux);
    addchild(aux, $4);
    addsiblings(aux, aux2);
    addchild(aux2, $8);
}
| FOR LBRACE RBRACE {
    $$ = newNode("For", NULL);
    addchild($$, newNode("Block", NULL));
}
| FOR LBRACE StatementList RBRACE {
    $$ = newNode("For", NULL);
    aux = newNode("Block", NULL);
    addchild($$, aux);
    addchild(aux, $3);
}
| FOR Expr LBRACE RBRACE {
    $$ = newNode("For", NULL);
    addchild($$, $2);
    addsiblings($2, newNode("Block", NULL));
}
| FOR Expr LBRACE StatementList RBRACE {
    $$ = newNode("For", NULL);
    addchild($$, $2);
    aux = newNode("Block", NULL);
    addsiblings($2, aux);
    addchild(aux, $4);
}
| RETURN {
    $$ = newNode("Return", NULL);
}
| RETURN Expr {
    $$ = newNode("Return", NULL);
    addchild($$, $2);
}
| FuncInvocation {
    $$ = newNode("Call", NULL);
    addchild($$, $1);
}
| ParseArgs {
    $$ = $1;
}
| PRINT LPAR Expr RPAR {
    $$ = newNode("Print", NULL);
    addchild($$, $3);
}
| PRINT LPAR STRLIT RPAR { $$ = newNode("Print", NULL); aux = newNode("StrLit", $3); addchild($$, aux);}

| error {
    $$ = newNode("Error", NULL);
};

// StatementList Rule
StatementList: StatementList Statement SEMICOLON {
    $$ = $1;
    addsiblings($1, $2);
}
| Statement SEMICOLON {
    $$ = $1;
};

// ParseArgs Rule
ParseArgs: IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR {
    $$ = newNode("ParseArgs", NULL);
    aux = newNode("IDENTIFIER", $1);
    addchild($$, aux);
    addsiblings(aux, $9);
}
| IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR {
    $$ = newNode("ParseArgs", NULL);
    aux = newNode("IDENTIFIER", $1);
    addchild($$, aux);
    addsiblings(aux, newNode("Error", NULL));
};

// Function Invocation Rule
FuncID: IDENTIFIER                                                   {$$ = newNode("Id", $1);}
        ;

FuncInvocation: FuncID LPAR RPAR { $$ = $1; }
| FuncID LPAR Expr RPAR {
    $$ = $1;
    addsiblings($1, $3);
}
| FuncID LPAR Expr CommaExpressionList RPAR {
    $$ = $1;
    addsiblings($1, $3);
    addsiblings($3, $4);
}
| FuncID LPAR error RPAR {
    $$ = $1;
    addsiblings($1, newNode("Error", NULL));
};

// CommaExpressionList Rule
CommaExpressionList: CommaExpressionList COMMA Expr {
    $$ = $1;
    addsiblings($1, $3);
}
| COMMA Expr {
    $$ = $2;
};

// Expressions
Expr:   Expr OR Expr {$$ = newNode("Or", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr AND Expr {$$ = newNode("And", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr LT Expr {$$ = newNode("Lt", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr GT Expr {$$ = newNode("Gt", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr EQ Expr {$$ = newNode("Eq", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr NE Expr {$$ = newNode("Ne", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr LE Expr {$$ = newNode("Le", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr GE Expr {$$ = newNode("Ge", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr PLUS Expr {$$ = newNode("Add", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr MINUS Expr {$$ = newNode("Sub", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr STAR Expr {$$ = newNode("Mul", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr DIV Expr {$$ = newNode("Div", NULL); addchild($$, $1); addsiblings($1, $3);}
| Expr MOD Expr {$$ = newNode("Mod", NULL); addchild($$, $1); addsiblings($1, $3);}
| NOT Expr {$$ = newNode("Not", NULL); addchild($$, $2);}
| MINUS Expr %prec DIV {$$ = newNode("Minus", NULL); addchild($$, $2);}
| PLUS Expr %prec DIV {$$ = newNode("Plus", NULL); addchild($$, $2);}
| NATURAL {$$ = newNode("NATURAL", $1);}
| DECIMAL {$$ = newNode("DECIMAL", $1);}
| IDENTIFIER {$$ = newNode("IDENTIFIER", $1);}
| FuncInvocation {$$ = newNode("Call", NULL); addchild($$, $1);}
| LPAR Expr RPAR {$$ = $2;}
| LPAR error RPAR {$$ = newNode("Error", NULL);};
%% 
