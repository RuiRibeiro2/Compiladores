%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag_1 = 0;
int line = 1, col = 0;
%}

letter [a-zA-Z_]
digit [0-9]

%%

"package"       { if(flag_1) printf("PACKAGE\n"); col+=yyleng; }
"func"          { if(flag_1) printf("FUNC\n"); col+=yyleng; }
"main"          { if(flag_1) printf("IDENTIFIER(main)\n"); col+=yyleng; }
{letter}+       { if(flag_1) printf("IDENTIFIER(%s)\n", yytext); col+=yyleng; }
";"             { if(flag_1) printf("SEMICOLON\n"); col+=yyleng; }
[ \t]           { col+=yyleng; }  // espaços e tabs
\n              { line++; col=0; }
.               { printf("UNMATCHED: '%c'\n", *yytext); }

%%

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "-l") == 0) {
        flag_1 = 1;
    }
    yylex();
    return 0;
}