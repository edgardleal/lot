OUTDIR=./obj
CC=gcc
SRC=src
IDIR=
# CFLAGS=-Wall -Werror 
# CFLAGS=-ansi
CFLAGS=


DEPS=$(SRC)/num.h $(SRC)/tree.h

_OBJ = num.o tree.o
OBJ = $(patsubst %,$(OUTDIR)/%,$(_OBJ))
TEST_OBJ=$(OUTDIR)/minunit.o $(OBJ) $(OUTDIR)/test.o

all: clean test compile production

setup: 
	if [ ! -d "$(OUTDIR)" ]; then mkdir -p $(OUTDIR); fi

$(OUTDIR)/%.o: $(SRC)/%.c $(DEPS)
	@echo "compiling " $@
	$(CC) $(CFLAGS) -c -o $@ $< 

compileDebug: $(OBJ) $(OUTDIR)/main.o 
	$(CC) $(CFLAGS) -g $^ -o $(OUTDIR)/debug

compileTest: $(TEST_OBJ)
	gcc -g $(CFLAGS) $^ -o $(OUTDIR)/test

compileProduction: $(OBJ) $(OUTDIR)/main.o
	$(CC) $(CFLAGS) $^ -o $(OUTDIR)/lot

production: setup compileProduction

compile: setup compileDebug 

memory: compile
	valgrind obj/debug

clean:
	rm -r $(OUTDIR) || true
	ctags -R .

test: setup compileTest
	$(OUTDIR)/test


.DEFAULT: test
.PHONY: clean

