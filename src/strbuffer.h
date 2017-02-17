#ifndef STRBUFFER_H
#define STRBUFFER_H
#include <stdlib.h>
#include <string.h>

struct StrBuffer {
	char buffer[255];
	void (*cat)(struct StrBuffer*, char);
	void (*strcat)(struct StrBuffer*, char*);
	void (*clear)(struct StrBuffer*);
	int  (*size)(struct StrBuffer*);
};

extern struct StrBuffer *newBuffer();
static void str_cat(struct StrBuffer *this, char c);
static void str_strcat(struct StrBuffer *this, char *c);
static void str_clear(struct StrBuffer *this);
static int str_size(struct StrBuffer *this);


#endif

