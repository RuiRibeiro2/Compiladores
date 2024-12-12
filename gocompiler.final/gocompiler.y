%{
    /*
    Projeto de Compiladores 2023/2024~
    Meta 2
    2021189478 - Rui Ribeiro
    2021221169 - Francisco Rodrigues
    */
#include <stdio.h>
extern int yylex(void);
void yyerror(char *);
extern char *yytext;
%}

%union {
    char* value;
    node* node;   
};

// Yacc tokens 
%token SEMICOLON COMMA 
%token BLANKID
%token ASSIGN STAR DIV MINUS PLUS 
%token EQ GE GT LE LT MOD NE
%token NOT AND OR
%token LBRACE RBRACE LPAR RPAR LSQ RSQ 
%token PACKAGE
%token RETURN PRINT PARSEINT FUNC CMDARGS VAR
%token IF ELSE FOR
%token INT FLOAT32 BOOL STRING STRLIT

%token <value> IDENTIFIER
%token <value> NATURAL DECIMAL

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
    add_child(program_root, $4);
};

// Declarations Rules
Declarations: Declarations2 { $$ = $1; }
            | /* epsilon */ { $$ = NULL; };

Declarations2: Declarations2 VarDeclaration SEMICOLON {
    $$ = $1;
    add_sibling($1, $2);
}
| VarDeclaration SEMICOLON { $$ = $1; }
| Declarations2 FuncDeclaration SEMICOLON {
    $$ = $1;
    add_sibling($1, $2);
}
| FuncDeclaration SEMICOLON { $$ = $1; };

// Variable Declarations
VarDeclaration: VAR VarSpec { $$ = $2; }
              | VAR LPAR VarSpec SEMICOLON RPAR { $$ = $3; };

// Variable Specification
VarSpec: IDENTIFIER Type {
    $$ = newNode("VarDecl", NULL);
    add_child($$, $2);
    add_sibling($2, newNode("IDENTIFIER", $1));
}
| IDENTIFIER VarSpecList Type {
    $$ = newNode("VarDecl", NULL);
    aux = newNode("IDENTIFIER", $1);
    add_child($$, $3);
    add_sibling($3, aux);
    add_sibling($$, $2);

    varspec_aux = $$->sibling;
    while (varspec_aux != NULL && strcmp(varspec_aux->first_child->type, "notype") == 0) {
        strcpy(varspec_aux->first_child->type, $3->type);
        varspec_aux = varspec_aux->sibling;
    }
};

// VarSpecList Rule
VarSpecList: COMMA IDENTIFIER VarSpecList {
    $$ = newNode("VarDecl", NULL);
    varspec_aux_1 = newNode("notype", NULL);
    add_sibling($$, $3);
    add_child($$, varspec_aux_1);
    add_sibling(varspec_aux_1, newNode("IDENTIFIER", $2));
}
| COMMA IDENTIFIER {
    $$ = newNode("VarDecl", NULL);
    aux = newNode("notype", NULL);
    add_child($$, aux);
    add_sibling(aux, newNode("IDENTIFIER", $2));
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
    add_child($$, aux);
    add_sibling(aux, $7);
    add_child(aux, aux2);
    add_sibling($6, $4);
    add_sibling(aux2, $6);
}
| FUNC IDENTIFIER LPAR Parameters RPAR FuncBody {
    $$ = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", $2);
    add_child($$, aux);
    add_sibling(aux, $6);
    add_child(aux, aux2);
    add_sibling(aux2, $4);
}
| FUNC IDENTIFIER LPAR RPAR Type FuncBody {
    $$ = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", $2);
    add_child($$, aux);
    add_sibling(aux, $6);
    add_child(aux, aux2);
    add_sibling(aux2, $5);
    add_sibling($5, newNode("FuncParams", NULL));
}
| FUNC IDENTIFIER LPAR RPAR FuncBody {
    $$ = newNode("FuncDecl", NULL);
    aux = newNode("FuncHeader", NULL);
    aux2 = newNode("IDENTIFIER", $2);
    add_child($$, aux);
    add_child(aux, aux2);
    add_sibling(aux2, newNode("FuncParams", NULL));
    add_sibling(aux, $5);
};

// Parameters Rule
Parameters: IDENTIFIER Type ParametersList {
    $$ = newNode("FuncParams", NULL);
    aux = newNode("ParamDecl", NULL);
    add_child($$, aux);
    add_sibling(aux, $3);
    add_child(aux, $2);
    add_sibling($2, newNode("IDENTIFIER", $1));
}
| IDENTIFIER Type {
    $$ = newNode("FuncParams", NULL);
    aux = newNode("ParamDecl", NULL);
    add_child($$, aux);
    add_child(aux, $2);
    add_sibling($2, newNode("IDENTIFIER", $1));
};

// ParametersList Rule
ParametersList: COMMA IDENTIFIER Type ParametersList {
    $$ = newNode("ParamDecl", NULL);
    add_child($$, $3);
    add_sibling($3, newNode("IDENTIFIER", $2));
    add_sibling($$, $4);
}
| COMMA IDENTIFIER Type {
    $$ = newNode("ParamDecl", NULL);
    add_child($$, $3);
    add_sibling($3, newNode("IDENTIFIER", $2));
};

// Remaining Rules
FuncBody: LBRACE VarsAndStatements RBRACE {
    $$ = newNode("FuncBody", NULL);
    add_child($$, $2);
};

VarsAndStatements: VarsAndStatements VarDeclaration SEMICOLON {
    $$ = $1;
    add_sibling($1, $2);
}
| VarsAndStatements Statement SEMICOLON {
    $$ = $1;
    add_sibling($1, $2);
}
| VarsAndStatements SEMICOLON { $1 = $1; }
| /* epsilon */ { $$ = newNode("NULL", NULL); };

Statement: IDENTIFIER ASSIGN Expr {
    $$ = newNode("Assign", NULL);
    aux = newNode("IDENTIFIER", $1);
    add_child($$, aux);
    add_sibling(aux, $3);
}
// Statement Rules Continued
| LBRACE RBRACE {
    $$ = newNode("NULL", NULL);
}
| LBRACE StatementList RBRACE {
    aux = $2;
    int n = 0;
    while (aux != NULL) {
        if (strcmp(aux->type, "NULL") != 0) n++;
        aux = aux->sibling;
    }
    if (n >= 2) {
        $$ = newNode("Block", NULL);
        add_child($$, $2);
    } else {
        $$ = $2;
    }
}
| IF Expr LBRACE RBRACE {
    $$ = newNode("If", NULL);
    add_child($$, $2);
    aux = newNode("Block", NULL);
    add_sibling($2, aux);
    add_sibling(aux, newNode("Block", NULL));
}
| IF Expr LBRACE StatementList RBRACE {
    $$ = newNode("If", NULL);
    add_child($$, $2);
    aux = newNode("Block", NULL);
    add_sibling($2, aux);
    add_child(aux, $4);
    add_sibling(aux, newNode("Block", NULL));
}
| IF Expr LBRACE RBRACE ELSE LBRACE RBRACE {
    $$ = newNode("If", NULL);
    add_child($$, $2);
    aux = newNode("Block", NULL);
    add_sibling($2, aux);
    add_sibling(aux, newNode("Block", NULL));
}
| IF Expr LBRACE StatementList RBRACE ELSE LBRACE RBRACE {
    $$ = newNode("If", NULL);
    add_child($$, $2);
    aux = newNode("Block", NULL);
    add_sibling($2, aux);
    add_child(aux, $4);
    add_sibling(aux, newNode("Block", NULL));
}
| IF Expr LBRACE RBRACE ELSE LBRACE StatementList RBRACE {
    $$ = newNode("If", NULL);
    add_child($$, $2);
    aux = newNode("Block", NULL);
    aux2 = newNode("Block", NULL);
    add_sibling($2, aux);
    add_sibling(aux, aux2);
    add_child(aux2, $7);
}
| IF Expr LBRACE StatementList RBRACE ELSE LBRACE StatementList RBRACE {
    $$ = newNode("If", NULL);
    add_child($$, $2);
    aux = newNode("Block", NULL);
    aux2 = newNode("Block", NULL);
    add_sibling($2, aux);
    add_child(aux, $4);
    add_sibling(aux, aux2);
    add_child(aux2, $8);
}
| FOR LBRACE RBRACE {
    $$ = newNode("For", NULL);
    add_child($$, newNode("Block", NULL));
}
| FOR LBRACE StatementList RBRACE {
    $$ = newNode("For", NULL);
    aux = newNode("Block", NULL);
    add_child($$, aux);
    add_child(aux, $3);
}
| FOR Expr LBRACE RBRACE {
    $$ = newNode("For", NULL);
    add_child($$, $2);
    add_sibling($2, newNode("Block", NULL));
}
| FOR Expr LBRACE StatementList RBRACE {
    $$ = newNode("For", NULL);
    add_child($$, $2);
    aux = newNode("Block", NULL);
    add_sibling($2, aux);
    add_child(aux, $4);
}
| RETURN {
    $$ = newNode("Return", NULL);
}
| RETURN Expr {
    $$ = newNode("Return", NULL);
    add_child($$, $2);
}
| FuncInvocation {
    $$ = newNode("Call", NULL);
    add_child($$, $1);
}
| ParseArgs {
    $$ = $1;
}
| PRINT LPAR Expr RPAR {
    $$ = newNode("Print", NULL);
    add_child($$, $3);
}
| PRINT LPAR STRLIT RPAR {
    $$ = newNode("Print", NULL);
    aux = newNode("StrLit", $3);
    add_child($$, aux);
}
| error {
    $$ = newNode("Error", NULL);
};

// StatementList Rule
StatementList: StatementList Statement SEMICOLON {
    $$ = $1;
    add_sibling($1, $2);
}
| Statement SEMICOLON {
    $$ = $1;
};

// ParseArgs Rule
ParseArgs: IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR {
    $$ = newNode("ParseArgs", NULL);
    aux = newNode("IDENTIFIER", $1);
    add_child($$, aux);
    add_sibling(aux, $9);
}
| IDENTIFIER COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR {
    $$ = newNode("ParseArgs", NULL);
    aux = newNode("IDENTIFIER", $1);
    add_child($$, aux);
    add_sibling(aux, newNode("Error", NULL));
};

// Function Invocation Rule
FuncID: IDENTIFIER                                                   {$$ = newNode("Id", $1);}
        ;

FuncInvocation: FuncID LPAR RPAR { $$ = $1; }
| FuncID LPAR Expr RPAR {
    $$ = $1;
    add_sibling($1, $3);
}
| FuncID LPAR Expr CommaExpressionList RPAR {
    $$ = $1;
    add_sibling($1, $3);
    add_sibling($3, $4);
}
| FuncID LPAR error RPAR {
    $$ = $1;
    add_sibling($1, newNode("Error", NULL));
};

// CommaExpressionList Rule
CommaExpressionList: CommaExpressionList COMMA Expr {
    $$ = $1;
    add_sibling($1, $3);
}
| COMMA Expr {
    $$ = $2;
};

// Expressions
Expr:   Expr OR Expr {$$ = newNode("Or", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr AND Expr {$$ = newNode("And", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr LT Expr {$$ = newNode("Lt", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr GT Expr {$$ = newNode("Gt", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr EQ Expr {$$ = newNode("Eq", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr NE Expr {$$ = newNode("Ne", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr LE Expr {$$ = newNode("Le", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr GE Expr {$$ = newNode("Ge", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr PLUS Expr {$$ = newNode("Add", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr MINUS Expr {$$ = newNode("Sub", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr STAR Expr {$$ = newNode("Mul", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr DIV Expr {$$ = newNode("Div", NULL); add_child($$, $1); add_sibling($1, $3);}
| Expr MOD Expr {$$ = newNode("Mod", NULL); add_child($$, $1); add_sibling($1, $3);}
| NOT Expr {$$ = newNode("Not", NULL); add_child($$, $2);}
| MINUS Expr %prec DIV {$$ = newNode("Minus", NULL); add_child($$, $2);}
| PLUS Expr %prec DIV {$$ = newNode("Plus", NULL); add_child($$, $2);}
| NATURAL {$$ = newNode("NATURAL", $1);}
| DECIMAL {$$ = newNode("DECIMAL", $1);}
| IDENTIFIER {$$ = newNode("IDENTIFIER", $1);}
| FuncInvocation {$$ = newNode("Call", NULL); add_child($$, $1);}
| LPAR Expr RPAR {$$ = $2;}
| LPAR error RPAR {$$ = newNode("Error", NULL);};
%% 
