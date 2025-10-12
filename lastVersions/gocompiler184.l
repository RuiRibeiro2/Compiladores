%{
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

%X SINGLE_LINE_COMMENT MULTI_LINE_COMMENT STRING
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
"/*"			{col++; comment_lines = 0; comment_cols = 0; swaped_line = 0; BEGIN MULTI_LINE_COMMENT;}
"//"			{col++; BEGIN SINGLE_LINE_COMMENT;}

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

"//"                                { BEGIN(SINGLE_LINE_COMMENT); }
<SINGLE_LINE_COMMENT><<EOF>>        { 
    fprintf(yyout, "Line %d, column %d: unterminated comment\n", line, col); 
    BEGIN(INITIAL); 
    i_semicolon = 0;
}
<SINGLE_LINE_COMMENT>{newline}      { 
    BEGIN(INITIAL); 
    if(i_semicolon && flag_1) fprintf(yyout, "SEMICOLON\n"); 
    i_semicolon = 0;
    line++; 
    col = 1; 
}
<SINGLE_LINE_COMMENT>.              { ; }

"/*"                                { 
    BEGIN(MULTI_LINE_COMMENT); 
    ml_comment_start_line = line;
    ml_comment_start_col = col;
}
<MULTI_LINE_COMMENT><<EOF>>         { 
    fprintf(yyout, "Line %d, column %d: unterminated comment\n", ml_comment_start_line, ml_comment_start_col); 
    BEGIN(INITIAL); 
    i_semicolon = 0;
}
<MULTI_LINE_COMMENT>"*/"            { BEGIN(INITIAL); }
<MULTI_LINE_COMMENT>{newline}       { line++; col = 1; }
<MULTI_LINE_COMMENT>.               { ; }

\" { 
    BEGIN(STRING); 
    reset_str_buffer();
    str_error = 0;
    str_start_line = line;
    str_start_col = col;
    i_semicolon = 1;  // Assume que vai ser válida inicialmente
}

<STRING><<EOF>> { 
    fprintf(yyout, "Line %d, column %d: unterminated string literal\n", str_start_line, str_start_col); 
    BEGIN(INITIAL); 
    i_semicolon = 0;  // ERRO: sem SEMICOLON
}

<STRING>\n {
    fprintf(yyout, "Line %d, column %d: unterminated string literal\n", str_start_line, str_start_col);
    line++;
    col = 1;
    BEGIN(INITIAL);
    i_semicolon = 0;  // ERRO: sem SEMICOLON
}

<STRING>\\[nrtf\\\"] {
    // Escape válido - adiciona ao buffer
    if (str_buffer_index < 4095) {
        str_buffer[str_buffer_index++] = yytext[0];
        str_buffer[str_buffer_index++] = yytext[1];
    }
}

<STRING>\\[^nrtf\\\"] {
    // Escape inválido
    fprintf(yyout, "Line %d, column %d: invalid escape sequence (%s)\n", line, col, yytext);
    str_error = 1;
    i_semicolon = 0;  // ERRO: sem SEMICOLON
}

<STRING>\" {
    // Fim da string
    str_buffer[str_buffer_index] = '\0';
    if (!str_error && flag_1) {
        fprintf(yyout, "STRLIT(%s)\n", str_buffer);
        i_semicolon = 1;  // VÁLIDA: com SEMICOLON
    } else {
        i_semicolon = 0;  // TEVE ERROS: sem SEMICOLON
    }
    BEGIN(INITIAL);
}

<STRING>[^\\\"\n]+ {
    // Caracteres normais - adiciona ao buffer
    int len = yyleng;
    if (str_buffer_index + len < 4095) {
        strncpy(&str_buffer[str_buffer_index], yytext, len);
        str_buffer_index += len;
    }
}


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

