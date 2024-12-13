#!/bin/sh
# Limpeza de arquivos gerados anteriormente
rm -f gocompiler lex.yy.c y.tab.c y.tab.h y.output y.gv

# Gerar os arquivos com Yacc
yacc -d -v -t -g --report=all gocompiler.y

# Gerar os arquivos com Flex
lex gocompiler.l

# Compilar o projeto
cc -o gocompiler lex.yy.c y.tab.c ast.c auxiliar_functions.c symbol_table.c semantic_analysis.c -lfl -Wall -Wno-unused-function
