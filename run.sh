lex gocompiler2.l
cc lex.yy.c -o lexer
./lexer <input2.txt