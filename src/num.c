#ifndef NUM
#define NUM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num.h"
#include "list.h"
#define IS_DEBUG 1


static unsigned long id_counter = 0;

static void num_load_string(struct Num *this, char *text)
{
	int i = 0;
	int size = strlen(text);
	char tmp[3], lastchar, currentchar;

	tmp[0] = '\0';
	for(i = 0; i < 24; i = i + 1)
	{
		this->bols[i] = 0;
	}

	for(i = 0; i < size; i = i + 1)
	{
		currentchar = text[i];
		if(currentchar != ' ')
		{
			if(tmp[0] == '\0')
			{
				tmp[0] = currentchar;
				tmp[1] = '\0';
			} else {
				tmp[1] = currentchar;
				tmp[2] = '\0';
			}

		}
		else if(tmp[0] != '\0') /* if string tmp is not empty */
		{
			this->bols[atoi(tmp) - 1] = 1;
			tmp[0] = '\0';
		}

	}
	if(tmp[0] != '\0')
		this->bols[atoi(tmp) - 1] = 1;
}

static struct Node * num_load_file(struct Num *this, char *file_name)
{
    char c, 
         in_comment_line = 0, 
         is_new_line = 1,
         last_char = 0,
         *number,
         number_parts[3]; /* last is \0 */
    struct Node *result = newTree();
    FILE *file = fopen(file_name, "r");
    int value = 0;

    while((c = fgetc(file)) != EOF)
    {
        if(!in_comment_line)
        {
            if(c == ' ') /* process number */
            {
                /**
                 * TODO: finalize this implementation 
                 */
                if(number_parts[0] != '\0')
                {
                    number_parts[1] = last_char;
                    number_parts[2] = '\0';
                } else {
                    number_parts[0] = last_char;
                    number_parts[1] = '\0';
                }

                value = atoi(number_parts);
                /*
                 *
                 * TODO: Add to bols 
                 */

                number_parts[0] = '\0';
            } else {

            }

        }
        if(is_new_line)
        {
            if(c == '*')
            {
                in_comment_line = 1;
            }
            is_new_line = 0;
        } else {
            if(c == '\n')
            {
                in_comment_line = 0;
                is_new_line = 1;
            }
        } /* new line */
        last_char = c;
    }

    fclose(file);
    return result;
}

static void num_write_file(struct Num *this, char *fileName)
{
    FILE *fp = fopen(fileName, "w");
    char *out;

    if(!fp)
    {
        printf("Canot open the file [%s]", fileName);
        return;
    } else {
        this->toString(this, out);
        fprintf(fp, "%s", out);
        fclose(fp);
    }
}

static void num_switch(struct Num* this, int a, int b)
{
	int tmp = this->bols[a];
	this->bols[a] = this->bols[b];
	this->bols[b] = tmp;
}	

extern struct Num * num_clone(struct Num *this)
{
	struct Num *result = newNum();
	int i = 0;
	for(i = 0; i < 25; i = i + 1)
	{
		result->bols[i] = this->bols[i];
	}

	return result;
}

/**
 * Returns the number of bols closed to the end ( 25 )
 *
 *
 */
static int bols_in_the_end(struct Num* this)
{
	int i, result = 0;
	for(i = 24; i > -1; i = i + 1)
	{
		if(this->bols[i] == 0)
		{
			break;
		}
		result = result + 1;
	}
	return result;
}

static void num_inc(struct Num* this)
{
	int i = 23;
	if(this->bols[24]) 
	{
		char is_out_of_end_queue = 0;
		for(i = 23; i > -1; i = i - 1) /* if last number is filled */
		{
			if(this->bols[i])
			{
				if(is_out_of_end_queue)
				{
					this->switchNumbers(this, i, i + 1);
					/* get all numbers on the end and put they closed to the number on ( i + 1 ) */
					int bolsInTheEnd = bols_in_the_end(this);
					int newStart = i + 2;
					int j;
					for(j = 0; j <= bolsInTheEnd; j = j + 1)
					{
						this->switchNumbers(this, newStart + j, 24 - (bolsInTheEnd - j)); 
					}

					this->switchNumbers(this, i, i + 1);
					break;
				}
			} else {
				if(is_out_of_end_queue == 0) 
				{
					is_out_of_end_queue = 1;
				}
			}
		}
	} else {                         /* if last number is not filled */
		for(i = 23; i > -1; i = i - 1)
		{
			if(this->bols[i])
			{
				this->switchNumbers(this, i, i + 1);
				break;
			}
		}
	}                                /* if last number is not filled */
}

static void num_print(struct Num *this)
{
	char text[80];
	this->toString(this, text);
	printf("%s", text);
	printf("***************\n");
}

static char* iff(int condition, char* iftrue, char* iffalse)
{
	if ( condition ) {
		return iftrue;
	} else {
		return iffalse;
	}
}

static void num_toString(struct Num *this, char* text)
{
	sprintf(text, "%s %s %s %s %s\n%s %s %s %s %s\n%s %s %s %s %s\n%s %s %s %s %s\n%s %s %s %s %s\n",
			iff(this->bols[0], " 1", "  "),
			iff(this->bols[1], " 2", "  "),
			iff(this->bols[2], " 3", "  "),
			iff(this->bols[3], " 4", "  "),
			iff(this->bols[4], " 5", "  "),
			iff(this->bols[5], " 6", "  "),
			iff(this->bols[6], " 7", "  "),
			iff(this->bols[7], " 8", "  "),
			iff(this->bols[8], " 9", "  "),
			iff(this->bols[9], "10", "  "),
			iff(this->bols[10],"11", "  "),
			iff(this->bols[11],"12", "  "),
			iff(this->bols[12],"13", "  "),
			iff(this->bols[13],"14", "  "),
			iff(this->bols[14],"15", "  "),
			iff(this->bols[15],"16", "  "),
			iff(this->bols[16],"17", "  "),
			iff(this->bols[17],"18", "  "),
			iff(this->bols[18],"19", "  "),
			iff(this->bols[19],"20", "  "),
			iff(this->bols[20],"21", "  "),
			iff(this->bols[21],"22", "  "),
			iff(this->bols[22],"23", "  "),
			iff(this->bols[23],"24", "  "),
			iff(this->bols[24],"25", "  ")
			);
}

extern void num_destroy(struct Num *this)
{
	if(this)
	  free(this);
}

static int num_compare(struct Num *this, struct Num *other)
{
	int i, result = 0;
	for(i = 0; i < 24; i = i + 1)
	{
		if(this->bols[i] && other->bols[i])
		{
			result = result + 1;
		}
	}
	return result;
}

static void num_reset(struct Num *this)
{
	int i;
	for(i = 0; i < 24; i = i + 1)
	{
		if( i < 15)
			this->bols[i] = 1;
		else
			this->bols[i] = 0;
	}
}

extern struct Num *newNum()
{
  struct Num* result     = (struct Num*)malloc(sizeof(struct Num));
	id_counter             = id_counter + 1;
	result->id             = id_counter;
	result->toString       = &num_toString;
	result->print          = &num_print;
	result->inc            = &num_inc;
	result->switchNumbers  = &num_switch;
	result->clone          = &num_clone;
	result->compare        = &num_compare;
	result->destroy        = &num_destroy;
	result->write_to_file  = &num_write_file;
	result->load_string    = &num_load_string;
	result->reset          = &num_reset;


	int i               = 0;
	for(i = 0;i<25;i++) {
		if ( i < 15) {
			result->bols[i] = 1;
		} else { 
			result->bols[i] = 0;
		}
	}

  return result;
}

#endif
