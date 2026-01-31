CC=gcc
CFLAGS=-g
OBJS=src/main.o src/strb.o
EXEC=output
LDFLAGS=-lfl

all: $(EXEC)

# Create the final exec
$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS) $(LDFLAGS)

# Compile all objs from their respective c source files
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

# Clean src dir by deleting all object files and core files
.PHONY: clean
clean:
	rm -f $(OBJS) core
