OUTDIR=./obj
CC=gcc
SRC=src
IDIR=
# CFLAGS=-Wall -Werror 
CFLAGS=-ansi -I $(OUTDIR) /usr/local/Cellar/argp-standalone/1.3/lib/libargp.a
# CFLAGS=-ansi /usr/local/Cellar/argp-standalone/1.3/lib/libargp.a


_DEPS= csv.h args.h num.h list.h strbuffer.h lang.h number/output.h report.h number/simulation.h
DEPS=$(patsubst %,$(SRC)/%,$(_DEPS)) ./genann/genann.h

_OBJ = args.o num.o list.o strbuffer.o csv.o report.o lang.o number/output.o number/simulation.o
OBJ = $(patsubst %,$(OUTDIR)/%,$(_OBJ)) genann/genann.o

_TEST = test_csv.o test_report.o
TEST = $(patsubst %,$(OUTDIR)/test/%,$(_TEST))
TEST_OBJ=$(OUTDIR)/minunit.o $(OBJ) $(OUTDIR)/test.o

all: clean test compile production

setup: 
	if [ ! -d "$(OUTDIR)" ]; then mkdir -p $(OUTDIR); fi

$(OUTDIR)/%.o: $(SRC)/%.c $(DEPS)
	@echo "compiling " $@
	$(CC) -g $(CFLAGS) -c -o $@ $< 

compileDebug: $(OBJ) $(OUTDIR)/main.o 
	$(CC) $(CFLAGS) -g $^ -o $(OUTDIR)/debug

compileTest: $(TEST_OBJ)
	gcc -g $(CFLAGS) $^ -o $(OUTDIR)/test

compileProduction: $(OBJ) $(OUTDIR)/main.o
	$(CC) $(CFLAGS) $^ -o $(OUTDIR)/lot

production: setup compileProduction

install: production

compile: setup compileDebug 

doc:
	doxygen .doxygen

memory: compile
	valgrind obj/debug

clean:
	rm -r $(OUTDIR) || true
	mkdir -p $(OUTDIR)/number
	ctags -R .

test: setup compileTest
	$(OUTDIR)/test

debug: setup compileDebug 
	gdb $(OUTDIR)/test


.DEFAULT: test
.PHONY: clean

