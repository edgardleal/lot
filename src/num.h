#ifndef NUM_H
#define NUM_H

struct Num {
	long id;
	int bols[25];
	void (*toString)(struct Num*, char*);
	void (*print)(struct Num*);
	void (*inc)  (struct Num*);
	void (*switchNumbers)(struct Num*, int, int);
	void (*destroy)(struct Num*);
	int  (*compare)(struct Num*, struct Num*);
	struct Num* (*clone)(struct Num*);
};

extern struct Num * newNum();
extern void num_destroy(struct Num *this);
extern struct Num * num_clone(struct Num *this);
static void num_switch(struct Num *this, int a, int b);
static int bols_in_the_end(struct Num *this);
static int num_compare(struct Num *this, struct Num *other);
static void num_inc(struct Num *this);
static void num_print(struct Num *this);
static char * iff(int condition, char *iftrue, char *iffalse);

#endif
