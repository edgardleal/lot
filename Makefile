OUTDIR=./obj
CC=gcc
SRC=src
IDIR=$(OUTDIR)

ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
endif	

ifeq ($(detected_OS), Linux)
	CFLAGS=-ansi --static -lm -I $(IDIR)
else
	CFLAGS=-ansi -Wall -I $(IDIR) /usr/local/Cellar/argp-standalone/1.3/lib/libargp.a
endif

DONE = echo ✓ $@ done

_DEPS= csv.h args.h num.h list.h strbuffer.h lang.h number/output.h report.h number/simulation.h
DEPS=$(patsubst %,$(SRC)/%,$(_DEPS)) ./genann/genann.h

_OBJ = args.o num.o list.o strbuffer.o csv.o report.o lang.o number/output.o number/simulation.o
OBJ = $(patsubst %,$(OUTDIR)/%,$(_OBJ)) genann/genann.o

_TEST = test_csv.o test_report.o test_num.o
TEST = $(patsubst %,$(OUTDIR)/test/%,$(_TEST))
TEST_OBJ=$(OUTDIR)/minunit.o $(OBJ) $(TEST) $(OUTDIR)/test.o

all: ## all: run all tasks
all: clean test compile production

setup: ## setup: create needed diretories to this application
setup: 
	if [ ! -d "$(OUTDIR)/num" ]; then mkdir -p $(OUTDIR)/num; fi
	if [ ! -d "$(OUTDIR)/number" ]; then mkdir -p $(OUTDIR)/number; fi
	if [ ! -d "$(OUTDIR)/test" ]; then mkdir -p $(OUTDIR)/test; fi

$(OUTDIR)/%.o: $(SRC)/%.c $(DEPS)
	@echo "compiling " $@
	$(CC) -g $(CFLAGS) -c -o $@ $< 

compileDebug: $(OBJ) $(OUTDIR)/main.o 
	$(CC) $(CFLAGS) -g $^ -o $(OUTDIR)/debug

compileTest: $(TEST_OBJ)
	$(CC) -g $(CFLAGS) $^ -o $(OUTDIR)/run_tests -lm

compileProduction: $(OBJ) $(OUTDIR)/main.o
	$(CC) $(CFLAGS) $^ -o $(OUTDIR)/lot

production: ## production: compile the project for distributions porpuse
production: setup compileProduction

install: production

compile: ## compile: setup and compile source code for debug
compile: setup compileDebug 

doc: ## doc: generate doxygen documentation
doc:
	doxygen .doxygen
	$(DONE)

memory: ## memory: use valgrind to analyse memory leak
memory: compile
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all obj/debug
	$(DONE)

clean: ## clean: remove build files
clean:
	rm -r $(OUTDIR) || true
	mkdir -p $(OUTDIR)/number
	ctags -R .
	$(DONE)

test: ## test: run unit tests
test: setup compileTest
	$(OUTDIR)/run_tests
	$(DONE)

debug: setup compileDebug 
	gdb $(OUTDIR)/test

hel%: ## help: Show this help message.
	@echo "usage: make [target] ..."
	@echo ""
	@echo "targets:"
	@grep -Eh '^.+:\ ##\ .+' ${MAKEFILE_LIST} | cut -d ' ' -f '3-' | column -t -s ':'

.DEFAULT: test
.PHONY: clean

