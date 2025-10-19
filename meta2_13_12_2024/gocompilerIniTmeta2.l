%{
    /*
    Projeto de Compiladores 2023/2024~
    Meta 2
    2021189478 - Rui Ribeiro
    2021221169 - Francisco Rodrigues
    */
    //gocompiler_v4 teste de substituicao dos comments - resultado correu bem apenas 0 erros agora - corrigido tirar i_semi dos comentarios
    
    #include "y.tab.h"
    #include "ast.h"
    //#include "semantic.h"
    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    int yyparse(void);
    extern struct node *program_root;
    int line = 1;
    int comment_lines = 1; 
    int col = 0;
    int comment_cols = 0;
    int flag_1 = 0, flag_2 = 0, swaped_line;
    int flag_3 = 0;  // flag para erros sintáticos
    int syntax_error_line = 1;
    int syntax_error_column = 1;
    int i_semicolon = 0;
    int start_brace = 0;
    #define PASS_TOKEN() yylval.token = strdup(yytext); 
%}

letter      [a-zA-Z_]
number      [0-9]
exp         (e|E)[-+]?{number}+
float       ({number}+"."{number}*)|("."{number}+)
hexadecimal (0[xX][0-9a-fA-F]+)
octal       0[0-7]+
natural     {octal}|{hexadecimal}|{number}+
newline     \n|(\r\n)
sp_chr      \\(\"|n|r|t|f|\\)
whispace    (" "|\t)
reservedWords "++"|"--"|"break"|"case"|"chan"|"const"|"continue"|"default"|"defer"|"fallthrough"|"go"|"import"|"goto"|"interface"|"map"|"range"|"select"|"struct"|"switch"|"type"

%X SEMICOLON BCOMMENT LCOMMENT STRING DUMMY_QUOTE SEMIBCOMMENT SEMILCOMMENT INVALID_STRING

%%

";" { if (flag_1) { if(i_semicolon==0){fprintf(yyout, "SEMICOLON\n");} if(i_semicolon==1){fprintf(yyout, "SEMICOLON\n"); i_semicolon=0;} col+=yyleng; } else { col+=yyleng; yylval.value = (char*) strdup(yytext); return SEMICOLON; } }
"," { if (flag_1) { fprintf(yyout, "COMMA\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return COMMA; } }
"_" { if (flag_1) { fprintf(yyout, "BLANKID\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return BLANKID; } }
"=" { if (flag_1) { fprintf(yyout, "ASSIGN\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return ASSIGN; } }
"*" { if (flag_1) { fprintf(yyout, "STAR\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return STAR; } }
"/" { if (flag_1) { fprintf(yyout, "DIV\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return DIV; } }
"-" { if (flag_1) { fprintf(yyout, "MINUS\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return MINUS; } }
"+" { if (flag_1) { fprintf(yyout, "PLUS\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return PLUS; } }
"==" { if (flag_1) { fprintf(yyout, "EQ\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return EQ; } }
">=" { if (flag_1) { fprintf(yyout, "GE\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return GE; } }
">" { if (flag_1) { fprintf(yyout, "GT\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return GT; } }
"{" { if (flag_1) { fprintf(yyout, "LBRACE\n"); start_brace = 1; col+=yyleng; i_semicolon=0; } else { start_brace = 1; col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return LBRACE; } }
"<=" { if (flag_1) { fprintf(yyout, "LE\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return LE; } }
"(" { if (flag_1) { fprintf(yyout, "LPAR\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return LPAR; } }
"[" { if (flag_1) { fprintf(yyout, "LSQ\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return LSQ; } }
"<" { if (flag_1) { fprintf(yyout, "LT\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return LT; } }
"%" { if (flag_1) { fprintf(yyout, "MOD\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return MOD; } }
"!=" { if (flag_1) { fprintf(yyout, "NE\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return NE; } }
"!" { if (flag_1) { fprintf(yyout, "NOT\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return NOT; } }
"&&" { if (flag_1) { fprintf(yyout, "AND\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return AND; } }
"||" { if (flag_1) { fprintf(yyout, "OR\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return OR; } }
"}" { if (flag_1) { fprintf(yyout, "RBRACE\n"); col+=yyleng; i_semicolon=1; } else { col+=yyleng; i_semicolon=1; yylval.value = (char*) strdup(yytext); return RBRACE; } }
")" { if (flag_1) { fprintf(yyout, "RPAR\n"); col+=yyleng; i_semicolon=1; } else { col+=yyleng; i_semicolon=1; yylval.value = (char*) strdup(yytext); return RPAR; } }
"]" { if (flag_1) { fprintf(yyout, "RSQ\n"); col+=yyleng; i_semicolon=1; } else { col+=yyleng; i_semicolon=1; yylval.value = (char*) strdup(yytext); return RSQ; } }
"package" { if (flag_1) { fprintf(yyout, "PACKAGE\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return PACKAGE; } }
"return" { if (flag_1) { fprintf(yyout, "RETURN\n"); col+=yyleng; i_semicolon=1; } else { col+=yyleng; i_semicolon=1; yylval.value = (char*) strdup(yytext); return RETURN; } }
"else" { if (flag_1) { fprintf(yyout, "ELSE\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return ELSE; } }
"for" { if (flag_1) { fprintf(yyout, "FOR\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return FOR; } }
"if" { if (flag_1) { fprintf(yyout, "IF\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return IF; } }
"var" { if (flag_1) { fprintf(yyout, "VAR\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return VAR; } }
"int" { if (flag_1) { fprintf(yyout, "INT\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return INT; } }
"float32" { if (flag_1) { fprintf(yyout, "FLOAT32\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return FLOAT32; } }
"bool" { if (flag_1) { fprintf(yyout, "BOOL\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return BOOL; } }
"string" { if (flag_1) { fprintf(yyout, "STRING\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return STRING; } }
"fmt.Println" { if (flag_1) { fprintf(yyout, "PRINT\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return PRINT; } }
"strconv.Atoi" { if (flag_1) { fprintf(yyout, "PARSEINT\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return PARSEINT; } }
"func" { if (flag_1) { fprintf(yyout, "FUNC\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return FUNC; } }
"os.Args" { if (flag_1) { fprintf(yyout, "CMDARGS\n"); col+=yyleng; i_semicolon=0; } else { col+=yyleng; i_semicolon=0; yylval.value = (char*) strdup(yytext); return CMDARGS; } }
"/*"			{col++; comment_lines = 0; comment_cols = 0; swaped_line = 0; BEGIN BCOMMENT;}
"//"			{col++; BEGIN LCOMMENT;}

{reservedWords}                 {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
0([0-7]*[8-9]+[0-7]*)+          {if (flag_1) fprintf(yyout, "Line %d, column %d: invalid octal constant (%s)\n",line,++col, yytext); col+=yyleng-1; }    // NATURAL: Constantes octais (começa com 0, seguido por dígitos de 0 a 7)
{natural}                       {if (flag_1) fprintf(yyout, "NATURAL(%s)\n", yytext); col+=yyleng; yylval.value = (char*) strdup(yytext); i_semicolon=1; }    // NATURAL: Todos os naturais
({float}{exp}?|{number}+{exp})  {if (flag_1) fprintf(yyout, "DECIMAL(%s)\n", yytext); col+=yyleng; yylval.value = (char*) strdup(yytext); i_semicolon=1;}
{letter}[a-zA-Z0-9_]*			{if (flag_1) fprintf(yyout, "IDENTIFIER(%s)\n", yytext); col+=yyleng; yylval.value = (char*) strdup(yytext); i_semicolon=1;}
\"                              {yyless(0); BEGIN STRING;}  


<BCOMMENT>"*/" 	        				  {line+=comment_lines; if (swaped_line) col = 0; else col++; col+=comment_cols+yyleng; BEGIN 0;}
<BCOMMENT>{newline}        	              {comment_lines++; comment_cols = 0; swaped_line = 1;}
<BCOMMENT><<EOF>>                         {fprintf(yyout, "Line %d, column %d: unterminated comment\n", line, col); yyterminate();}
<BCOMMENT>.     	        	          {comment_cols+=yyleng;}

<LCOMMENT>{newline} 	        		  {if(flag_1 && i_semicolon==1) fprintf(yyout, "SEMICOLON\n");i_semicolon=0;line++; col = 0; BEGIN 0;}
<LCOMMENT>. 	        				  {;}

<SEMICOLON>{newline}                      {if (flag_1) fprintf(yyout, "SEMICOLON\n");line++; col = 0; BEGIN 0;}
<SEMICOLON>{whispace}	                  {col+=yyleng;}
<SEMICOLON>"/*"                           {col++; comment_lines = 0; comment_cols = 0; swaped_line = 0; BEGIN SEMIBCOMMENT;}
<SEMICOLON>"//"                           {BEGIN SEMILCOMMENT;}
<SEMICOLON>.                              {yyless(0); BEGIN 0;}
<SEMICOLON><<EOF>>                        {if (flag_1) fprintf(yyout, "SEMICOLON\n"); yyterminate();}



<SEMIBCOMMENT>"*/" 	        				  {line+=comment_lines; if (swaped_line) col = 0; else col++; col+=comment_cols+yyleng; if (swaped_line) {fprintf(yyout, "SEMICOLON\n"); BEGIN 0;} else BEGIN SEMICOLON;}
<SEMIBCOMMENT>{newline}        	              {comment_lines++; comment_cols = 0; swaped_line=1; }
<SEMIBCOMMENT><<EOF>>                         {fprintf(yyout, "SEMICOLON\n"); fprintf(yyout, "Line %d, column %d: unterminated comment\n", line, col); yyterminate();}
<SEMIBCOMMENT>.     	        	          {comment_cols+=yyleng;}

<SEMILCOMMENT>{newline} 	        		  {yyless(0); BEGIN SEMICOLON;}
<SEMILCOMMENT><<EOF>>                         {fprintf(yyout, "SEMICOLON\n"); yyterminate();}
<SEMILCOMMENT>. 	        				  {;}

<STRING>{newline}                                               {fprintf(yyout, "Line %d, column %d: unterminated string literal\n", line, col); line++; col = 0; BEGIN 0;}
<STRING>\"(\\(\"|n|r|t|f|\\)|[^\\\"\r\n])*\"                    {if (flag_1) fprintf(yyout, "STRLIT(%s)\n", yytext); col+=yyleng; BEGIN SEMICOLON;}
<STRING>\"[^\"\r\n]*\\[^\\\"nrtf][^\"\r\n]*\"                   {yyless(0); BEGIN DUMMY_QUOTE;}
<STRING>\"[^\"\r\n]*{newline}?                                  {yyless(0); BEGIN DUMMY_QUOTE;}


<DUMMY_QUOTE>\"                             {col++; comment_cols = 1; BEGIN INVALID_STRING;}
<INVALID_STRING>\"                          {col+=comment_cols; BEGIN 0;}
<INVALID_STRING>{newline}                   {fprintf(yyout, "Line %d, column %d: unterminated string literal\n", line, col); line++; col = 0; BEGIN 0;}
<INVALID_STRING>\\(\"|n|r|t|f|\\)           {comment_cols+=yyleng;}
<INVALID_STRING>\\[^\\\"nrtf\r\n]           {fprintf(yyout, "Line %d, column %d: invalid escape sequence (%s)\n", line, col+comment_cols, yytext); comment_cols+=yyleng;}
<INVALID_STRING>\\                          {fprintf(yyout, "Line %d, column %d: invalid escape sequence (%s)\n", line, col+comment_cols, yytext); comment_cols+=yyleng;}
<INVALID_STRING><<EOF>>                     {fprintf(yyout, "Line %d, column %d: unterminated string literal\n", line, col); yyterminate();}
<INVALID_STRING>.                           {comment_cols+=yyleng;}


{newline}				    			  {line++; col = 0;if(i_semicolon == 1 && start_brace == 0)fprintf(yyout, "SEMICOLON\n"); yylval.value = (char*) strdup(yytext); i_semicolon=0;start_brace=0;BEGIN 0;}
{whispace}                                {col+=yyleng; }
.				        				  {col+=1; fprintf(yyout, "Line %d, column %d: illegal character (%s)\n", line, col, yytext);col+=yyleng-1;int next_char = input();if (next_char != EOF) {unput(next_char);}}

<<EOF>>                                     { if (i_semicolon == 1) if (flag_1) fprintf(yyout, "SEMICOLON\n");return 0;}
%%
/*
int main(int argc, char *argv[]){
    if (argv[1] != 0 && (argv[1][0] == '-' && argv[1][1] == 'l')){
        //checkig for argument -l like this so we dont have to import string.h
        flag_1 = 1;
        yylex();
    } 
    if (argv[1] != 0 && (argv[1][0] == '-' && argv[1][1] == 't')){
        //flag para returns
        //flag_2 = 1;    //CRIAR FLAG2 PARA OS RETURNS -> VER flag_return DA meta3_sb_v1
        yyparse();

        //CRIAR FLAG3 PARA OS ERROS SINTATICOS -> VER flag_syntax_error DA meta3_sb_v1
        //flag para erros de sintase
        if(flag_3 == 0){  
            printtree(program_root, 0);
        }
    }  
    
    return 0;
}
*/
int main(int argc, char *argv[]){
    yyout = stdout;
    /*
      Behavior:
      - ./gocompiler -l    => lexical analysis only: print tokens/errors
      - ./gocompiler -t    => lexical + syntactic analysis; if no syntax errors print AST, otherwise only errors
      - ./gocompiler        => parse-only: print only error messages (lexical and syntactic), do not print AST or tokens
    */
    if (argc > 1) {
        if (strcmp(argv[1], "-l") == 0) {
            /* Lexical analysis only: enable token printing in lexer and drive lexer until EOF */
            flag_1 = 1;
            while (yylex() != 0) { /* consume all tokens, lexer prints tokens when flag_1==1 */ }
        } else if (strcmp(argv[1], "-t") == 0) {
            /* Parse and print AST only if no syntax errors. Do NOT enable token printing. */
            flag_1 = 0;
            yyparse();
            if (flag_3 == 0) {
                printtree(program_root, 0);
            }
        } else {
            /* Unknown option: fallback to parse-only with error messages */
            flag_1 = 0;
            yyparse();
        }
    } else {
        /* No arguments: parse-only (errors only) */
        flag_1 = 0;
        yyparse();
    }

    return 0;
}

/*void yyerror(const char *s) {
    flag_3_syntax_error = 1;
    fprintf(stderr, "%s\n", s); // Apenas imprime a mensagem de erro
    //printf ("Line %d, column %d: %s: %s\n", last_line_pos, last_col_pos, str, yytext);
}*/

void yyerror(const char *s) {
    flag_3 = 1;
    printf("Line %d, column %d: syntax error: %s\n", syntax_error_line, syntax_error_column, yytext);
}

int yywrap(){
    return 1;
}