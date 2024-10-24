# Makefile para compilar o gocompiler

gocompiler: lex.yy.c
	gcc lex.yy.c -o gocompiler

lex.yy.c: gocompiler.l
	flex gocompiler.l

clean:
	rm -f gocompiler lex.yy.c
