# Makefile para compilar o gocompiler

# Variáveis
CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -Wall -g

# Arquivos
TARGET = gocompiler184
LEX_FILE = gocompiler184.l
YACC_FILE = gocompiler.y
AST_FILES = ast.c ast.h

# Regra padrão
$(TARGET): lex.yy.c y.tab.c $(AST_FILES)
	$(CC) $(CFLAGS) lex.yy.c y.tab.c ast.c -o $(TARGET)

lex.yy.c: $(LEX_FILE)
	$(FLEX) $(LEX_FILE)

y.tab.c: $(YACC_FILE)
	$(BISON) -d -y $(YACC_FILE)

clean:
	rm -f $(TARGET) lex.yy.c y.tab.c y.tab.h