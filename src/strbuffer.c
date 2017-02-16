#ifndef STRBUFFER_C
#define STRBUFFER_C
#include <string.h>
#include "strbuffer.h"

extern struct StrBuffer *newBuffer()
{
	struct StrBuffer *result = (struct StrBuffer*)malloc(sizeof(struct StrBuffer));
	result->buffer[0] = '\0';

	result->cat = &str_cat;
	result->strcat = &str_strcat;
	result->clear = &str_clear;

	return result;
}


static void str_cat(struct StrBuffer *this, char c)
{
	unsigned int i;
	for(i = 0; i < 254; i = i + 1)
	{
		if(this->buffer[i] == '\0')
		{
			this->buffer[i] = c;
			this->buffer[i + 1] = '\0';
			break;
		}
	}
}

static void str_strcat(struct StrBuffer *this, char *c)
{
	strcat(this->buffer, c);
}


static void str_clear(struct StrBuffer *this)
{
	this->buffer[0] = '\0';
}


#endif

