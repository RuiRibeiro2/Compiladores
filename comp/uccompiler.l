%{
	/*
	João Pedro Costa Ferreiro 2014197760
	Guilherme Cardoso Gomes da Silva 2014226354
	*/
	#include <stdio.h>
	#include <string.h>
	#define LINHA linha++; coluna=1;
	#define COLUNA coluna+=yyleng;
	int flag = 0, coluna = 1, linha = 1, linha_aux = 0, coluna_aux = 0;
	void imprime(char* msg);
	void imprime_com_conteudo(char* msg, char* conteudo);
%}

%X MULTIPCOM_ST

SINGLECOMMENT					"//"
STARTCOMMENT 					"/*"
FINISHCOMMENT 					"*/"

RESERVED						"++"|"--"|"["|"]"|"auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"enum"|"extern"|"float"|"for"|"goto"|"inline"|"long"|"register"|"restrict"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"_Bool"|"_Complex"|"_Imaginary"

CHAR 							"char"
ELSE 							"else"
WHILE 							"while"
IF 								"if"
INT 							"int"
SHORT 							"short"
DOUBLE							"double"
RETURN 							"return"
VOID 							"void"
BITWISEAND 						"&"
BITWISEOR 						"|"
BITWISEXOR 						"^"
AND 							"&&"
ASSIGN 							"="
MUL 							"*"
COMMA 							","
DIV 							"/"
EQ 								"=="
GE 								">="
GT 								">"
LBRACE 							"{"
LE 								"<="
LPAR 							"("
LT 								"<"
MINUS 							"-"
MOD 							"%"
NE 								"!="
NOT 							"!"
OR 								"||"
PLUS 							"+"
RBRACE 							"}"
RPAR 							")"
SEMI 							";"

ID								([a-zA-Z]|"_")([a-zA-Z0-9]|"_")*

DOT								"."
EXPONENTIAL						("E"|"e")("+"|"-")?{INTLIT}
ASP								"'"

INTLIT							[0-9]+
REALLIT							(({INTLIT}{DOT}{INTLIT}?{EXPONENTIAL}?)|({DOT}{INTLIT}{EXPONENTIAL}?)|({INTLIT}{EXPONENTIAL}))
CHRLIT							[^\n\'\\]|\\n|\\t|\\\\|\\'|\\\"|\\[0-7]{1,3}

SPACE							" "
NEWLINE							"\n"
TAB								"\t"
CARRIAGERETURN		 			"\r"
LINETERMINATOR					"\n"|"\r\n"

%%
{SINGLECOMMENT}.*				;

{STARTCOMMENT}					{BEGIN MULTIPCOM_ST; linha_aux = linha; coluna_aux = coluna; COLUNA;}
<MULTIPCOM_ST>.					{COLUNA;}
<MULTIPCOM_ST>{LINETERMINATOR}	{LINHA;}
<MULTIPCOM_ST><<EOF>>			{BEGIN 0;printf("Line %d, col %d: unterminated comment\n",linha_aux,coluna_aux);COLUNA;}
<MULTIPCOM_ST>{FINISHCOMMENT}	{BEGIN 0;COLUNA;}

{RESERVED}						{imprime_com_conteudo("RESERVED", yytext);COLUNA;}

{CHAR} 							{imprime("CHAR");COLUNA;}
{ELSE} 							{imprime("ELSE");COLUNA;}
{WHILE} 						{imprime("WHILE");COLUNA;}
{IF} 							{imprime("IF");COLUNA;}
{INT}							{imprime("INT");COLUNA;}
{SHORT} 						{imprime("SHORT");COLUNA;}
{DOUBLE}						{imprime("DOUBLE");COLUNA;}
{RETURN} 						{imprime("RETURN");COLUNA;}
{VOID} 							{imprime("VOID");COLUNA;}
{BITWISEAND} 					{imprime("BITWISEAND");COLUNA;}
{BITWISEOR} 					{imprime("BITWISEOR");COLUNA;}
{BITWISEXOR} 					{imprime("BITWISEXOR");COLUNA;}
{AND} 							{imprime("AND");COLUNA;}
{ASSIGN} 						{imprime("ASSIGN");COLUNA;}
{MUL} 							{imprime("MUL");COLUNA;}
{COMMA} 						{imprime("COMMA");COLUNA;}
{DIV} 							{imprime("DIV");COLUNA;}
{EQ} 							{imprime("EQ");COLUNA;}
{GE} 							{imprime("GE");COLUNA;}
{GT} 							{imprime("GT");COLUNA;}
{LBRACE} 						{imprime("LBRACE");COLUNA;}
{LE} 							{imprime("LE");COLUNA;}
{LPAR} 							{imprime("LPAR");COLUNA;}
{LT} 							{imprime("LT");COLUNA;}
{MINUS} 						{imprime("MINUS");COLUNA;}
{MOD} 							{imprime("MOD");COLUNA;}
{NE} 							{imprime("NE");COLUNA;}
{NOT} 							{imprime("NOT");COLUNA;}
{OR} 							{imprime("OR");COLUNA;}
{PLUS} 							{imprime("PLUS");COLUNA;}
{RBRACE} 						{imprime("RBRACE");COLUNA;}
{RPAR} 							{imprime("RPAR");COLUNA;}
{SEMI} 							{imprime("SEMI");COLUNA;}

{ID}							{imprime_com_conteudo("ID", yytext);COLUNA;}

{INTLIT}						{imprime_com_conteudo("INTLIT",yytext);COLUNA;}
{REALLIT}						{imprime_com_conteudo("REALLIT",yytext);COLUNA;}
{ASP}{CHRLIT}{ASP}				{imprime_com_conteudo("CHRLIT",yytext); COLUNA;}
{ASP}({CHRLIT}|\\.)*{ASP} 		{printf("Line %d, col %d: invalid char constant (%s)\n",linha,coluna,yytext); COLUNA;}
{ASP}({CHRLIT}|\\.)*\\?			{printf("Line %d, col %d: unterminated char constant\n",linha,coluna);}

{SPACE}							{COLUNA;}
{NEWLINE}						{LINHA;}
{TAB}							{COLUNA;}
{CARRIAGERETURN}				{COLUNA;}
{LINETERMINATOR}				{LINHA;}

.								{printf("Line %d, col %d: illegal character (%s)\n",linha,coluna,yytext);COLUNA;}

%%

void imprime(char* msg){
	if(flag == 1){

		printf("%s\n",msg);
	}
}

void imprime_com_conteudo(char* msg, char* conteudo){
	if(flag == 1){
		printf("%s(%s)\n",msg,conteudo);
	}
}

int main(int argc, char *argv[]){
	if(argc > 1){
		if(strcmp(argv[1],"-l") == 0){
			flag=1;
		}
	}
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}