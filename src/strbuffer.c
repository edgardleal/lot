#ifndef STRBUFFER_C
#define STRBUFFER_C
#include <string.h>
#include "strbuffer.h"

static int str_size(struct StrBuffer *this)
{
    return strlen(this->buffer);
}

extern struct StrBuffer *new_string(char* text)
{
    struct StrBuffer *result = newBuffer();

    return result;
}

extern void str_free_pool()
{
    for (int i = 0; i < sizeof(str_poll); i++)
    {

    }
    free(str_poll);
}

extern struct StrBuffer *newBuffer()
{
	struct StrBuffer *result = (struct StrBuffer*)malloc(sizeof(struct StrBuffer));
	result->buffer[0] = '\0';
    if (str_poll == NULL)
    {
        str_poll = (struct StrPool*) malloc(sizeof(struct StrPool));
        str_poll->capacity = 10;
        str_poll->size = 0;
        str_poll->itens = (struct StrBuffer**) malloc(sizeof(struct StrBuffer) * 10);
    }
	result->cat = &str_cat;
	result->strcat = &str_strcat;
	result->clear = &str_clear;
	result->size = &str_size;

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

