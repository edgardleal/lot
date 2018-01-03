OUTDIR=./obj
CC=gcc
SRC=src
IDIR=

ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
endif	

ifeq ($(detected_OS), Linux)
	CFLAGS=-ansi -lm -I $(OUTDIR)
else
	CFLAGS=-ansi -Wall -I $(OUTDIR) /usr/local/Cellar/argp-standalone/1.3/lib/libargp.a
endif


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
	$(CC) -g $(CFLAGS) $^ -o $(OUTDIR)/test

compileProduction: $(OBJ) $(OUTDIR)/main.o
	$(CC) $(CFLAGS) $^ -o $(OUTDIR)/lot

production: setup compileProduction

install: production

compile: setup compileDebug 

doc:
	doxygen .doxygen

memory: compile
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all obj/debug

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

