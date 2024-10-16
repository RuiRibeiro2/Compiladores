%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    bool type = false;
    int line = 1;
    int column = 0;
    int commentLine = 0;
    int commentColumn = 0;
    int commentState= 0;
    #define YY_USER_ACTION column += yyleng; 
%}


digit   [0-9]
letter  [a-zA-Z_]
punctuation "("|")"|","|"*"|"="|"+"|"-"|"|"
keyWords "char"|"else"|"while"|"if"|"int"|"short"|"double"|"return"|"void"
reservedWords "++"|"--"|"["|"]"|"_Bool"|"_Complex"|"_Imaginary"|"auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"long"|"register"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"enum"|"extern"|"float"|"for"|"goto"|"inline"|"restrict"



%x COMMENT
%x COMMENT2
%x CHRLIT


%%

"/*"                    { BEGIN(COMMENT); commentLine = line; commentColumn = column-1; commentState = 1;}
<COMMENT>.              { ; }
<COMMENT>(\n|\r\n)      { line+=1; column = 0; }
<COMMENT>"*/"           { commentState = 0; BEGIN(INITIAL);}

{reservedWords}         { if(type) printf("RESERVED(%s)\n",yytext);}
{keyWords}              { 
    if(type)
    {
        for(int i = 0; i < yyleng;i++)
        {
            printf("%c",yytext[i]-32);
        } 
        printf("\n");
    }
}   



                            
\&                      { if(type) printf("BITWISEAND\n");}
\|                      { if(type) printf("BITWISEOR\n");}
\^                      { if(type) printf("BITWISEXOR\n");}
\&\&                    { if(type) printf("AND\n");}
\=                      { if(type) printf("ASSIGN\n");}
\*                      { if(type) printf("MUL\n");}
\,                      { if(type) printf("COMMA\n");}
\=\=                    { if(type) printf("EQ\n");}
\>\=                    { if(type) printf("GE\n");}
\>                      { if(type) printf("GT\n");}

\/\/                    { BEGIN(COMMENT2);}
<COMMENT2>.             { ; }
<COMMENT2>(\n|\r\n)            { line += 1; column = 0; BEGIN(INITIAL);}
\/                      { if(type) printf("DIV\n");}

\{                      { if(type)printf("LBRACE\n");}
\<\=                    { if(type)printf("LE\n");}
\(                      { if(type)printf("LPAR\n");}
\<                      { if(type)printf("LT\n");}
\-                      { if(type)printf("MINUS\n");}
\%                      { if(type)printf("MOD\n");}
\!\=                    { if(type)printf("NE\n");}
\!                      { if(type)printf("NOT\n");}
\|\|                    { if(type)printf("OR\n");}
\+                      { if(type)printf("PLUS\n");}
\}                      { if(type)printf("RBRACE\n");}
\)                      { if(type)printf("RPAR\n");}
\;                      { if(type)printf("SEMI\n");}

\'([^\n\\']|\\n|\\t|\\\\|\\\'|\\\"|\\([0-7]{1,3}))\' { if(type)printf("CHRLIT(%s)\n",yytext);BEGIN(INITIAL);}
\'([^\n\\']*|\\\'|\\\\|\\[^\n\\']+)+(\\)?            { column -= yyleng-1; printf("Line %d, column %d: unterminated char constant\n",line,column); column += yyleng-1;BEGIN(INITIAL);}
\'([^\n\\']*|\\\'|\\\\|\\[^\n\'])+\'                 { column -= yyleng-1; printf("Line %d, column %d: invalid char constant (%s)\n",line,column,yytext); column += yyleng-1;BEGIN(INITIAL);}
                
" "                     { ; }
\t                      { ; }
\n|\r\n|\r                      { line+=1; column = 0; }

{letter}({digit}|{letter})*                     { if(type)printf("IDENTIFIER(%s)\n",yytext);}
{digit}+                                        { if(type)printf("NATURAL(%s)\n",yytext);}

{digit}+"."([eE][+-]?{digit}+)?|{digit}+"."{digit}+([eE][+-]?{digit}+)? {
    if(type)printf("DECIMAL(%s)\n", yytext);

}

"."{digit}+([eE][+-]?{digit}+)? {
    if(type)printf("DECIMAL(%s)\n", yytext);
}

{digit}+[eE][+-]?{digit}+ {
    if(type)printf("DECIMAL(%s)\n", yytext);
}

.                       { printf("Line %d, column %d: unrecognized character (%s)\n",line,column,yytext);}

%%
extern int yylex();
int main(int argc, char *argv[]) 
{
    if(argv[1] != NULL && strcmp(argv[1],"-l") == 0)
    {
        type = true;
    }
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    if(commentState == 1)
    {
        printf("Line %d, column %d: unterminated comment\n",commentLine,commentColumn);
    }
    return 1;
}
