/** \file num.h
 *  \brief This file represents a combination of numbers 
 *
 *  Represents a uniq combination of number an your funcionalities.
 */
#ifndef NUM_H
#define NUM_H
#define MAX_NUMBER 3268720

/** \struct Num
 *  \brief A combination of numbers 
 *
 *  This represents a combination of number for Lotofacil.
 */
struct Num {
    long id;
    int balls[25];
    int cols[5];
    int lines[5];
    void (*toString)(struct Num*, char*);
    void (*print)(struct Num*);
    void (*inc)  (struct Num*);
    void (*switchNumbers)(struct Num*, int, int);
    void (*destroy)(struct Num*);
    int  (*compare)(struct Num*, struct Num*);
    void (*write_to_file)(struct Num*, char*);
    void (*load_string)(struct Num*, char*);
    void (*reset)(struct Num*);
    void (*clear)(struct Num*);
    int  (*density)(struct Num*);
    struct Num* (*clone)(struct Num*);
};

extern struct Num * 
newNum();

extern struct Num * 
num_clone(struct Num *);
extern int num_line(struct Num *, int line);
extern void num_destroy(struct Num *);

static int 
bols_in_the_end(struct Num *);

static int num_compare(struct Num *, struct Num *other);
static struct Node * num_load_file(struct Num*, char*);
static void num_inc(struct Num *);
static void num_load_string(struct Num *, char *text);
static void num_print(struct Num *);
static void num_reset(struct Num *);
static void num_clear(struct Num *);
static void num_switch(struct Num *, int a, int b);
static void num_toString(struct Num *, char* text);
static void num_write_file(struct Num*, char*);
static int  num_density(struct Num*);
extern int num_line(struct Num *, int);
extern int num_cols(struct Num *, int);
static void setup_cols_and_lines(struct Num *num, int ball);

#endif
