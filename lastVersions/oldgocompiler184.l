%{
    /*
    Projeto de Compiladores 2023/2024~
    Meta 2
    2021189478 - Rui Ribeiro
    2021221169 - Francisco Rodrigues
    */
    //gocompiler_v4 teste de substituicao dos comments - resultado correu bem apenas 0 erros agora - corrigido tirar i_semi dos comentarios
    
    int line = 1;
    int comment_lines = 1; 
    int col = 0;
    int comment_cols = 0;
    int flag_1, swaped_line;
    int i_semicolon = 0;
    int start_brace = 0;

    int str_start_line = 0;
    int str_start_col = 0;
    char str_buffer[4096];
    int str_buffer_index = 0;
    int str_error = 0;
    int ml_comment_start_line = 0;
    int ml_comment_start_col = 0;

    void reset_str_buffer() {
        str_buffer_index = 0;
        str_buffer[0] = '\0';
    }
%}

letter  [a-zA-Z_]
number  [0-9]
exp     (e|E)[-+]?{number}+
float   ({number}+"."{number}*)|("."{number}+)
hexa	(0(x|X)[0-9a-fA-F]+)
newline \n|(\r\n)
sp_chr  \\(\"|n|r|t|f|\\)
whispace (" "|\t)

%X SEMICOLON BCOMMENT LCOMMENT STRING DUMMY_QUOTE OCTAL SEMIBCOMMENT SEMILCOMMENT INVALID_STRING SEMICOLON2

%%

";"				{if (flag_1) if(i_semicolon==0){fprintf(yyout, "SEMICOLON\n");}if(i_semicolon==1){fprintf(yyout, "SEMICOLON\n");i_semicolon=0;} col+=yyleng; }
","				{if (flag_1) fprintf(yyout, "COMMA\n"); col+=yyleng; i_semicolon=0;}
"_"				{if (flag_1) fprintf(yyout, "BLANKID\n"); col+=yyleng; i_semicolon=0;}
"="				{if (flag_1) fprintf(yyout, "ASSIGN\n"); col+=yyleng; i_semicolon=0;}
"*"				{if (flag_1) fprintf(yyout, "STAR\n"); col+=yyleng; i_semicolon=0;}
"/"				{if (flag_1) fprintf(yyout, "DIV\n"); col+=yyleng; i_semicolon=0;}
"-"				{if (flag_1) fprintf(yyout, "MINUS\n"); col+=yyleng; i_semicolon=0;}
"+"				{if (flag_1) fprintf(yyout, "PLUS\n"); col+=yyleng; i_semicolon=0;}
"=="			{if (flag_1) fprintf(yyout, "EQ\n"); col+=yyleng; i_semicolon=0;}
">="			{if (flag_1) fprintf(yyout, "GE\n"); col+=yyleng; i_semicolon=0;}
">"				{if (flag_1) fprintf(yyout, "GT\n"); col+=yyleng; i_semicolon=0;}
"{"				{if (flag_1) fprintf(yyout, "LBRACE\n"); start_brace = 1; col+=yyleng;i_semicolon=0;}
"<="			{if (flag_1) fprintf(yyout, "LE\n"); col+=yyleng; i_semicolon=0;}
"("				{if (flag_1) fprintf(yyout, "LPAR\n"); col+=yyleng; i_semicolon=0;}
"["				{if (flag_1) fprintf(yyout, "LSQ\n"); col+=yyleng; i_semicolon=0;}	
"<"				{if (flag_1) fprintf(yyout, "LT\n"); col+=yyleng; i_semicolon=0;}
"%"				{if (flag_1) fprintf(yyout, "MOD\n"); col+=yyleng; i_semicolon=0;}
"!="			{if (flag_1) fprintf(yyout, "NE\n"); col+=yyleng; i_semicolon=0;}
"!"				{if (flag_1) fprintf(yyout, "NOT\n"); col+=yyleng; i_semicolon=0;}
"&&"			{if (flag_1) fprintf(yyout, "AND\n"); col+=yyleng; i_semicolon=0;}
"||"			{if (flag_1) fprintf(yyout, "OR\n"); col+=yyleng; i_semicolon=0;}
"}"				{if (flag_1) fprintf(yyout, "RBRACE\n"); col+=yyleng; i_semicolon=1;}
")"				{if (flag_1) fprintf(yyout, "RPAR\n"); col+=yyleng; i_semicolon=1;}
"]"				{if (flag_1) fprintf(yyout, "RSQ\n"); col+=yyleng; i_semicolon=1;}
"package"		{if (flag_1) fprintf(yyout, "PACKAGE\n"); col+=yyleng; i_semicolon=0;}
"return"		{if (flag_1) fprintf(yyout, "RETURN\n"); col+=yyleng; i_semicolon=1;}
"else"			{if (flag_1) fprintf(yyout, "ELSE\n"); col+=yyleng; i_semicolon=0;}
"for"			{if (flag_1) fprintf(yyout, "FOR\n"); col+=yyleng; i_semicolon=0;}
"if"			{if (flag_1) fprintf(yyout, "IF\n"); col+=yyleng; i_semicolon=0;}
"var"			{if (flag_1) fprintf(yyout, "VAR\n"); col+=yyleng; i_semicolon=0;}
"int"			{if (flag_1) fprintf(yyout, "INT\n"); col+=yyleng; i_semicolon=0;}
"float32"		{if (flag_1) fprintf(yyout, "FLOAT32\n"); col+=yyleng; i_semicolon=0;}
"bool"			{if (flag_1) fprintf(yyout, "BOOL\n"); col+=yyleng; i_semicolon=0;}
"string"		{if (flag_1) fprintf(yyout, "STRING\n"); col+=yyleng; i_semicolon=0;}
"fmt.Println"	{if (flag_1) fprintf(yyout, "PRINT\n"); col+=yyleng; i_semicolon=0;}
"strconv.Atoi"	{if (flag_1) fprintf(yyout, "PARSEINT\n"); col+=yyleng; i_semicolon=0;}
"func"			{if (flag_1) fprintf(yyout, "FUNC\n"); col+=yyleng; i_semicolon=0;}
"os.Args"		{if (flag_1) fprintf(yyout, "CMDARGS\n"); col+=yyleng; i_semicolon=0;}
"/*"			{col++; comment_lines = 0; comment_cols = 0; swaped_line = 0; BEGIN BCOMMENT;}
"//"			{col++; BEGIN LCOMMENT;}

"++"|"--"		{if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"break"         {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"case"          {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"chan"          {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"const"         {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"continue"      {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"default"       {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"defer"         {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"fallthrough"   {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"go"            {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"import"        {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"goto"          {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"interface"     {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"map"           {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"range"         {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"select"        {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"struct"        {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"switch"        {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}
"type"          {if (flag_1) fprintf(yyout, "RESERVED(%s)\n", yytext); col+=yyleng; i_semicolon=0;}

0[0-7]+                         {if (flag_1) fprintf(yyout, "NATURAL(%s)\n", yytext); col+=yyleng; i_semicolon=1; }    // NATURAL: Constantes octais (começa com 0, seguido por dígitos de 0 a 7)
0([0-7]*[8-9]+[0-7]*)+          {if (flag_1) fprintf(yyout, "Line %d, column %d: invalid octal constant (%s)\n",line,++col, yytext); col+=yyleng-1; }    // NATURAL: Constantes octais (começa com 0, seguido por dígitos de 0 a 7)
0[xX][0-9a-fA-F]+               {if (flag_1) fprintf(yyout, "NATURAL(%s)\n", yytext); col+=yyleng; i_semicolon=1;}
[0-9]+                          {if (flag_1) fprintf(yyout, "NATURAL(%s)\n", yytext); col+=yyleng; i_semicolon=1; }    // NATURAL: Constantes decimais (sequência de dígitos 0-9)
({float}{exp}?|{number}+{exp})  {if (flag_1) fprintf(yyout, "DECIMAL(%s)\n", yytext); col+=yyleng; i_semicolon=1;}
{letter}[a-zA-Z0-9_]*			{if (flag_1) fprintf(yyout, "IDENTIFIER(%s)\n", yytext); col+=yyleng; i_semicolon=1;}
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

<STRING>{newline}                                               {fprintf(yyout, "Line %d, column %d: unterminated string literal\n", line, col); line++; col = 0; BEGIN 0;}// ← CORREÇÃO: resetar flag
<STRING>\"(\\(\"|n|r|t|f|\\)|[^\\\"\r\n])*\"                    {if (flag_1) fprintf(yyout, "STRLIT(%s)\n", yytext); col+=yyleng; BEGIN SEMICOLON;}
<STRING>\"[^\"\r\n]*\\[^\\\"nrtf][^\"\r\n]*\"                   {yyless(0); BEGIN DUMMY_QUOTE;}
<STRING>\"[^\"\r\n]*{newline}?                                  {yyless(0); BEGIN DUMMY_QUOTE;}

<DUMMY_QUOTE>\"                            {col++; comment_cols = 1; BEGIN INVALID_STRING;}

<INVALID_STRING>\"                          {col+=comment_cols; BEGIN 0;} // ← CORREÇÃO: resetar flag
<INVALID_STRING>{newline}                   {fprintf(yyout, "Line %d, column %d: unterminated string literal\n", line, col); line++; col = 0; BEGIN 0;} // ← CORREÇÃO: resetar flag
<INVALID_STRING>\\(\"|n|r|t|f|\\)           {comment_cols+=yyleng;}
<INVALID_STRING>\\[^\\\"nrtf\r\n]           {fprintf(yyout, "Line %d, column %d: invalid escape sequence (%s)\n", line, col+comment_cols, yytext); comment_cols+=yyleng;}
<INVALID_STRING>\\                          {fprintf(yyout, "Line %d, column %d: invalid escape sequence (%s)\n", line, col+comment_cols, yytext); comment_cols+=yyleng;}
<INVALID_STRING><<EOF>>                     {fprintf(yyout, "Line %d, column %d: unterminated string literal\n", line, col); yyterminate(); }
<INVALID_STRING>.                           {comment_cols+=yyleng; }


{newline}				    			  {line++; col = 0;if(i_semicolon == 1 && start_brace == 0)fprintf(yyout, "SEMICOLON\n"); i_semicolon=0;start_brace=0;BEGIN 0;}
{whispace}                                {col+=yyleng;}
.				        				  {col+=1; fprintf(yyout, "Line %d, column %d: illegal character (%s)\n", line, col, yytext);col+=yyleng-1;int next_char = input();if (next_char != EOF) {unput(next_char);}}

<<EOF>>                                     { if (i_semicolon == 1) if (flag_1) fprintf(yyout, "SEMICOLON\n");return 0;}
%%

int main(int argc, char *argv[]){
    if (argv[1] != 0 && (argv[1][0] == '-' && argv[1][1] == 'l')){
        //checkig for argument -l like this so we dont have to import string.h
        flag_1 = 1;
    }   

    yylex();
    return 0;
}

int yywrap(){
    return 1;
}

