OUTDIR=./obj
CC=gcc
SRC=src
# IDIR=../libtap/
IDIR=
# CFLAGS=-Wall -Werror 
CFLAGS=-ansi


DEPS=$(SRC)/num.h


_OBJ = num.o
OBJ = $(patsubst %,$(OUTDIR)/%,$(_OBJ))
TEST_OBJ=$(OBJ) $(OUTDIR)/test.o $(OUTDIR)/tap.o

checklibtap:
	if [ ! -d "./libtap" ]; then git submodule update --recursive --remote; fi

setup: checklibtap
	if [ ! -d "$(OUTDIR)" ]; then mkdir -p $(OUTDIR); fi

$(OUTDIR)/%.o: $(SRC)/%.c $(DEPS)
	@echo "compiling " $@
	$(CC) $(CFLAGS) -c -o $@ $< 

$(OUTDIR)/tap.o: libtap/tap.c
	$(CC) $(CFLAGS) -c -o $@ $< 

compileDebug: $(OBJ) $(OUTDIR)/main.o 
	ANSI=1 
	$(CC) $(CFLAGS) -g $^ -o $(OUTDIR)/debug

compileTest: $(TEST_OBJ)
	ANSI=1 
	gcc -g $(CFLAGS) $^ -o $(OUTDIR)/test

compileProduction: $(OBJ) $(OUTDIR)/main.o
	ANSI=1 
	$(CC) $(CFLAGS) $^ -o $(OUTDIR)/lot

production: setup compileProduction

compile: setup compileDebug 

clean:
	rm *.o || true
	ctags -R .

test: setup compileTest
	$(OUTDIR)/test

all: clean test compile production

.DEFAULT: test
.PHONY: clean

