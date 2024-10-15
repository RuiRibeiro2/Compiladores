digit   [0-9]
alga [a-zA-Z_]
pont2 "'\n'"|"'\t'"|"'\\'"|"'\''"|"'\'"
words "char"|"else"|"while"|"if"|"int"|"short"|"double"|"return"|"void"
reserved "break"|"default"|"func"|"interface"|"select"|"case"|"defer"|"go"|"map"|"struct"|"chan"|"else"|"goto"|"package"|"switch"|"const"|"fallthrough"|"if"|"range"|"type"|"continue"|"for"|"import"|"return"|"var"
%x COMMENT
%x SINGLECOMMENT
%{
    /*Rui Miguel Fonte Ribeiro 2021189478
    Francisco Nunes Simões Rodrigues 2021237081*/
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    int line = 1;
    int column = 1;
    int commentLine = 0;
    int commentColumn = 0;
    int commentState= 0;
    bool exist = false;
%}
%%

"/*"                    { BEGIN(COMMENT); commentLine = line; commentColumn = column-1; commentState = 1;}
<COMMENT>.              { ; }
<COMMENT>(\n|\r\n)      { line+=1; column = 0; }
<COMMENT>"*/"           { commentState = 0; BEGIN(INITIAL);}

\/\/                         { BEGIN(SINGLECOMMENT);}
<SINGLECOMMENT>.             { ; }
<SINGLECOMMENT>(\n|\r\n)     { line += 1; column = 0; BEGIN(INITIAL);}

" "                     { column += 1;}
\t                      { column += 4;}
\n|\r\n|\r              { line+=1; column = 0;}

"&" { if(exist)printf("BITWISEAND\n"); column += 1;}
"^" { if(exist)printf("BITWISEXOR\n"); column += 1;}
"|" { if(exist)printf("BITWISEOR\n"); column += 1;}
"&&" { if(exist)printf("AND\n"); column += 2;}
"=" { if(exist)printf("ASSIGN\n"); column += 1;}
"*" { if(exist)printf("MUL\n"); column += 1;}
"+" { if(exist)printf("PLUS\n"); column += 1;}
"-" { if(exist)printf("MINUS\n"); column += 1;}
"/" { if(exist)printf("DIV\n"); column += 1;}
"==" { if(exist)printf("EQ\n"); column += 2;}
">=" { if(exist)printf("GE\n"); column += 2;}
">" { if(exist)printf("GT\n"); column += 1;}
"{" { if(exist)printf("LBRACE\n");column += 1;}
"<=" { if(exist)printf("LE\n"); column += 2;}
"," { if(exist)printf("COMMA\n"); column += 1;}
"(" { if(exist)printf("LPAR\n"); column += 1;}
"<" { if(exist)printf("LT\n"); column += 1;}
"%" { if(exist)printf("MOD\n"); column += 1;}
"!=" { if(exist)printf("NE\n"); column += 2;}
"!" { if(exist)printf("NOT\n"); column += 1;}
"||" { if(exist)printf("OR\n"); column += 2;}
"}" { if(exist)printf("RBRACE\n"); column += 1;}
";" { if(exist)printf("SEMICOLON\n"); column += 1;}
")" { if(exist)printf("RPAR\n"); column += 1;}


{reserved}                                                                              { if(exist)for(int i=0;i<yyleng;i++)printf("%c", yytext[i]-32);printf("\n"); column += yyleng; }
{words}                                                                                 { if(exist)for(int i = 0; i < yyleng;i++) printf("%c",yytext[i]-32);printf("\n"); column += yyleng;}
{digit}+                                                                                { if(exist)printf("NATURAL(%s)\n", yytext); column += yyleng;}
[a-zA-Z_]+[a-zA-Z0-9_]*                                                                 { if(exist)printf("IDENTIFIER(%s)\n", yytext); column+= yyleng;}
'{alga}'|'{digit}'                                                                      { if(exist)printf("CHRLIT(%s)\n", yytext); column+= yyleng; }
\'([^\n\\']|\\n|\\t|\\\\|\\\'|\\\"|\\[0-7]{1,3}){1}\'                                   { if(exist)printf("CHRLIT(%s)\n", yytext); column+= yyleng; }
(({digit}"."{digit}?("E"|"e")("+"|"-")?{digit}?)|"."{digit}("E"|"e")("+"|"-")?{digit}?|({digit}("E"|"e")("+"|"-")?{digit})) { if(exist)printf("DECIMAL(%s)\n", yytext); column += yyleng;}
\'([^\n\\']|\\n|\\t|\\\\|\\\'|\\\"|\\[0-7]{1,3})*                                       { if(exist)printf("Line %d, column %d: unterminated char constant\n",line,column);column += yyleng;}              
\'.*\'                                                                                  { if(exist)printf("Line %d, column %d: invalid char constant (%s)\n",line,column,yytext);column += yyleng;}

.                                                                                       { printf("Line %d, column %d: unrecognized character (%s)\n",line,column,yytext); column += yyleng;} 

%%
extern int yylex();
int main(int argc, char *argv[]) {
    if(argv[1] != NULL && strcmp(argv[1],"-l") == 0){ exist = true;}
    exist = true;
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    if(commentState == 1){ printf("Line %d, column %d: unterminated comment\n",commentLine,commentColumn); }
    return 1;
}