CC=clang
CFLAGS=-g -Wall
SRC=src
OBJ=obj
BINDIR=bin
TEST=tests
BIN=$(BINDIR)/output
CFILES=$(wildcard $(SRC)/*.c)
OBJECTS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CFILES))
LIBOBJS=$(filter-out $(OBJ)/main.o, $(OBJECTS))
TESTS=$(wildcard $(TEST)/*.c)
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

all: $(BINDIR) $(OBJ) $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

test: $(TEST)/bin $(OBJ) $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

$(TEST)/bin/%: $(TEST)/%.c $(LIBOBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST)/bin:
	mkdir $@

$(OBJ):
	mkdir $@

$(BINDIR):
	mkdir $@

clean: $(TEST)/bin $(OBJ) $(BINDIR)
	rm -r $(BINDIR) $(OBJ) $(TEST)/bin

run: all
	$(BIN)
