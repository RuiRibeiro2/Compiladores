#flex gocompiler.l
#gcc lex.yy.c -o gocompiler
# 1. Gerar parser com bison
bison -d gocompiler.y          # Isto gera y.tab.h e y.tab.c

# 2. Gerar lexer com flex  
flex gocompiler.l              # Isto gera lex.yy.c

# 3. Compilar tudo junto
gcc lex.yy.c y.tab.c -o gocompiler