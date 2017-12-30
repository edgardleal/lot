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
    int bols[25];
    void (*toString)(struct Num*, char*);
    void (*print)(struct Num*);
    void (*inc)  (struct Num*);
    void (*switchNumbers)(struct Num*, int, int);
    void (*destroy)(struct Num*);
    int  (*compare)(struct Num*, struct Num*);
    void (*write_to_file)(struct Num*, char*);
    void (*load_string)(struct Num*, char*);
    void (*reset)(struct Num*);
    struct Num* (*clone)(struct Num*);
};

extern struct Num * newNum();
extern struct Num * num_clone(struct Num *this);
extern int num_line(struct Num *this, int line);
extern void num_destroy(struct Num *this);
static char * iff(int condition, char *iftrue, char *iffalse);
static int num_compare(struct Num *this, struct Num *other);
static struct Node * num_load_file(struct Num*, char*);
static void num_inc(struct Num *this);
static void num_load_string(struct Num *this, char *text);
static void num_print(struct Num *this);
static void num_reset(struct Num *this);
static void num_switch(struct Num *this, int a, int b);
static void num_toString(struct Num *this, char* text);
static void num_write_file(struct Num*, char*);

#endif
