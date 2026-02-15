CC=gcc
CFLAGS=-g -W -Wall

LDFLAGS=-lfl
OBJS=src/main.o src/token.o src/lex.yy.o src/lexer.o src/strb.o
EXEC=k0

LEX_RULES=src/k0lex.l
FLEX_OUT=src/lex.yy.c

PARSE_RULES=src/k0gram.y
BISON_OUT=src/k0gram.tab.c

all: lexer $(EXEC)

# Create the final exec
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS) $(LDFLAGS)

# rule to quickly compile the flex rules in .l file to c file
lexer: $(LEXER_RULES)
	flex -o $(FLEX_OUT) $(LEX_RULES)

# rule to quickly compile the bison rules in .y file to c file
parser: $(PARSE_RULES)
	bison -o $(BISON_OUT) $(PARSE_RULES)

# Compile all objs from their respective c source files
%.o: %.c lexer parser
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

# Clean src dir by deleting all object files and core files
.PHONY: clean
clean:
	rm -f $(OBJS) core
