#!/bin/sh
# Limpeza de arquivos gerados anteriormente
rm -f gocompiler lex.yy.c y.tab.c y.tab.h y.output y.gv

# Gerar os arquivos com Yacc
yacc -d -v -t -g --report=all gocompiler.y
# -d: Gera o ficheiro de cabeçalho (y.tab.h), que contém as definições de tokens. Este ficheiro deve ser incluído no teu analisador léxico (ficheiro Flex/Lex).
# -v: Gera um relatório detalhado da análise sintática no ficheiro y.output, útil para depuração.
# -t: Ativa a rastreabilidade de depuração, inserindo código para impressão de passos durante a execução.
# -g: Gera uma descrição gráfica da gramática num ficheiro y.dot, que pode ser convertido para imagem com ferramentas como dot do Graphviz.
# --report=all: Fornece informações detalhadas sobre a gramática, como conflitos (shift/reduce e reduce/reduce).

# Gerar os arquivos com Flex
lex gocompiler.l

# Compilar o projeto
cc -o gocompiler lex.yy.c ast.c y.tab.c -lfl -Wall -Wno-unused-function
