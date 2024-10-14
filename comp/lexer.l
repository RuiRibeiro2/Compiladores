%x COMMENT

%{
    /* Place here any C variables and definitions */
    #include <stdio.h>
    int line = 1;
    int column = 1;
    int inComment = 0;  /* Flag to track if inside a comment */
%}



%%
"/*" {
    BEGIN(COMMENT);  /* Enter the comment state */
    inComment = 1;   /* Set the flag when entering a comment */
}
[ˆ//] {
    line++;
    column += yyleng;
}

<COMMENT>. {
    /* Inside a comment, count characters and lines */
    column += yyleng;
}
<COMMENT>\n {
    /* Inside a comment, increment the line number */
    line++;
    column = 1;
}
<COMMENT>"*/" {
    BEGIN(INITIAL);  /* Exit the comment state */
    inComment = 0;   /* Reset the flag when exiting a comment */
}
. {
    if (!inComment) {
        /* Handle all other characters */
        column++;
    }
}
\r\n {
    if (!inComment) {
        /* Handle newline characters outside of comments */
        line++;
        column = 1;
    }
}
\r\n {
    if (inComment) {
        /* Handle all other characters and report an error for unterminated comments */
        printf("Line %d, column %d: Unterminated comment\n", line, column);
        BEGIN(INITIAL);  /* Exit the comment state */
        inComment = 0;   /* Reset the flag when exiting an unterminated comment */
    }
}
%%
extern int yylex();
int main() {
    yylex();    /* Run the lexical analysis automaton */
    printf("linha: %d", line);
    return 0;
}
int yywrap() {  /* Called on EOF, return 1 to terminate */
    if(inComment == 1){
        printf("Line %d, column %d: Unterminated comment\n", line, column);
    }
    return 1;
}
