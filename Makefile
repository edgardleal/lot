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

.DEFAULT: test

$(OUTDIR)/%.o: $(SRC)/%.c $(DEPS)
	echo "compilinkg " $@
	$(CC) $(CFLAGS) -c -o $@ $< 

checklibtap:
	if [ ! -d ./libtap ]; then git submodule update --recursive --remote; fi

$(OUTDIR)/tap.o: libtap/tap.c checklibtap
	$(CC) $(CFLAGS) -c -o $@ $< 

compile: $(OBJ) $(OUTDIR)/main.o
	$(CC) $(CFLAGS) -g $^ -o $(OUTDIR)/debug

production: $(OBJ) $(OUTDIR)/main.o
	$(CC) $(CFLAGS) $^ -o $(OUTDIR)/lot

clean:
	rm *.o || true
	ctags -R .

test: $(TEST_OBJ)
	gcc -g $(CFLAGS) $^ -o $(OUTDIR)/test
	$(OUTDIR)/test

all: clean test compile production

.PHONY: clean

