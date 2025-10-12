LEX=flex
CC=gcc
LEX_SRC=gocompiler184.l
LEX_OUT=lex.yy.c
TARGET=gocompiler184

all: $(TARGET)

$(LEX_OUT): $(LEX_SRC)
	$(LEX) $(LEX_SRC)

$(TARGET): $(LEX_OUT)
	$(CC) -o $(TARGET) $(LEX_OUT) -lfl

clean:
	rm -f $(LEX_OUT) $(TARGET)