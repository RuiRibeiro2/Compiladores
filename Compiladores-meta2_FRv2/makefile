CC=gcc
CFLAGS=-Wall -g
LEX=flex
YACC=bison -d -y

SOURCES=lex.yy.c y.tab.c ast.c semantics.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=gocompiler

all: $(EXECUTABLE)

$(EXECUTABLE): lex.yy.c y.tab.c ast.o semantics.o
	$(CC) $(CFLAGS) lex.yy.c y.tab.c ast.c semantics.c -o $(EXECUTABLE)

lex.yy.c: gocompiler.l
	$(LEX) gocompiler.l

y.tab.c y.tab.h: gocompiler.y
	$(YACC) gocompiler.y

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c

semantics.o: semantics.c semantics.h ast.h
	$(CC) $(CFLAGS) -c semantics.c

clean:
	rm -f gocompiler lex.yy.c y.tab.c y.tab.h *.o

.PHONY: all clean