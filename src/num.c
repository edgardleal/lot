#ifndef NUM
#define NUM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num.h"
#include "list.h"
#include "args.h"

static unsigned long id_counter = 0;
static void inc_next_filled(struct Num *this, unsigned int start);

static void num_load_string(struct Num *this, char *text)
{
    int i = 0;
    size_t size = strlen(text);
    char tmp[3];

    tmp[0] = '\0';
    for(i = 0; i < 24; i = i + 1)
    {
        this->balls[i] = 0;
    }

    for(i = 0; i < size; i = i + 1)
    {
        char currentchar = text[i];
        if(currentchar != ' ' && currentchar != '\n')
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
            this->balls[atoi(tmp) - 1] = 1;
            tmp[0] = '\0';
        }

    }
    if(tmp[0] != '\0')
        this->balls[atoi(tmp) - 1] = 1;
}

static struct Node * num_load_file(struct Num *this, char *file_name)
{
    char c, 
         in_comment_line = 0, 
         is_new_line = 1,
         last_char = 0,
         number_parts[3]; /* last is \0 */
    struct Node *result = newTree();
    FILE *file = fopen(file_name, "r");

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

                /*
                 *
                 * TODO: Add to balls
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

    if(!fp)
    {
        die("Canot open the file [%s]", fileName);
        return;
    } else {
				char *out;
        this->toString(this, out);
        fprintf(fp, "%s", out);
        fclose(fp);
    }
}

static void num_switch(struct Num* this, int a, int b)
{
    int tmp = this->balls[a];
    this->balls[a] = this->balls[b];
    this->balls[b] = tmp;
}    

extern struct Num * num_clone(struct Num *this)
{
    struct Num *result = newNum();
    int i = 0;
    for(i = 0; i < 25; i = i + 1)
    {
        result->balls[i] = this->balls[i];
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
    for(i = 24; i > -1; i = i - 1)
    {
        if(this->balls[i] == 0)
        {
            break;
        }
        result = result + 1;
    }
    return result;
}

static void inc_next_filled(struct Num *this, unsigned int start)
{
    int i;
    for(i = start; i >= 0; i = i - 1)
    {
        if(this->balls[i])
        {
            this->switchNumbers(this, i, i + 1);
            break;
        }
    }
}

/*
 * Steps: 
 *
 * 1 - if last number isnt filled                   | Done  
 *   1.2 - Find next filled and inc this            | Done 
 * 2 - Find empty numbers                      - i am here
 *   2.1 - Register last filled 
 *   2.2 - find next filled 
 *     2.2.1 - 
 *   2.1 - register last  empty number 
 *   2.2 - register penultimate empty number 
 * 3 - Find next filled number 
 *   3.1 - If finded 
 *     3.1.1 - switch number finded with last empty 
 * 4 -  
 *
 *
 */
static void num_inc(struct Num* this)
{
    if(this->balls[24] == 0)
    {
        inc_next_filled(this, 24);
    } else {                         /* if last number is not filled */
        int lastFilled;
                int i = 23;
        for(i = 23; i >= 0; i = i - 1)
        {
            if(this->balls[i] == 0)
            {
                int j;
                lastFilled = i + 1;
                for(j = i; j >= 0; j = j - 1)
                {
                    if(this->balls[j]) /* finded next filled */
                    {
                        this->switchNumbers(this, j, j + 1);
                        int k, lastsNumbersIndex = 0;
                        for(k = lastFilled; k < 25; k = k + 1) /* reset number in the end */
                        {
                            this->switchNumbers(this, k, j + 2 + lastsNumbersIndex);
                            lastsNumbersIndex = lastsNumbersIndex = 1;
                        }
                        break; /* j */
                    }
                }
                break; /* i */
            }
        }
    }                                /* if last number is not filled */
}

static void num_print(struct Num *this)
{
    char text[80];
    text[0] = '\0';

    num_toString(this, text);
    out("%s", text);
    debug("***************\n");
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
    text[0] = '\0';
    if(config.OUTPUT_FORMAT[0] == 'g')
    {
        sprintf(text, "%s %s %s %s %s\n%s %s %s %s %s\n%s %s %s %s %s\n%s %s %s %s %s\n%s %s %s %s %s\n",
                iff(this->balls[0], " 1", "  "),
                iff(this->balls[1], " 2", "  "),
                iff(this->balls[2], " 3", "  "),
                iff(this->balls[3], " 4", "  "),
                iff(this->balls[4], " 5", "  "),
                iff(this->balls[5], " 6", "  "),
                iff(this->balls[6], " 7", "  "),
                iff(this->balls[7], " 8", "  "),
                iff(this->balls[8], " 9", "  "),
                iff(this->balls[9], "10", "  "),
                iff(this->balls[10],"11", "  "),
                iff(this->balls[11],"12", "  "),
                iff(this->balls[12],"13", "  "),
                iff(this->balls[13],"14", "  "),
                iff(this->balls[14],"15", "  "),
                iff(this->balls[15],"16", "  "),
                iff(this->balls[16],"17", "  "),
                iff(this->balls[17],"18", "  "),
                iff(this->balls[18],"19", "  "),
                iff(this->balls[19],"20", "  "),
                iff(this->balls[20],"21", "  "),
                iff(this->balls[21],"22", "  "),
                iff(this->balls[22],"23", "  "),
                iff(this->balls[23],"24", "  "),
                iff(this->balls[24],"25", "  ")
        );
    } else 
    if(config.OUTPUT_FORMAT[0] == 'b')
    {
        sprintf(text, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
                this->balls[0],
                this->balls[1],
                this->balls[2],
                this->balls[3],
                this->balls[4],
                this->balls[5],
                this->balls[6],
                this->balls[7],
                this->balls[8],
                this->balls[9],
                this->balls[10],
                this->balls[11],
                this->balls[12],
                this->balls[13],
                this->balls[14],
                this->balls[15],
                this->balls[16],
                this->balls[17],
                this->balls[18],
                this->balls[19],
                this->balls[20],
                this->balls[21],
                this->balls[22],
                this->balls[23],
                this->balls[24]);
    } else {
       sprintf(text, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",
                iff(this->balls[0], "  1", ""),
                iff(this->balls[1], "  2", ""),
                iff(this->balls[2], "  3", ""),
                iff(this->balls[3], "  4", ""),
                iff(this->balls[4], "  5", ""),
                iff(this->balls[5], "  6", ""),
                iff(this->balls[6], "  7", ""),
                iff(this->balls[7], "  8", ""),
                iff(this->balls[8], "  9", ""),
                iff(this->balls[9], " 10", ""),
                iff(this->balls[10]," 11", ""),
                iff(this->balls[11]," 12", ""),
                iff(this->balls[12]," 13", ""),
                iff(this->balls[13]," 14", ""),
                iff(this->balls[14]," 15", ""),
                iff(this->balls[15]," 16", ""),
                iff(this->balls[16]," 17", ""),
                iff(this->balls[17]," 18", ""),
                iff(this->balls[18]," 19", ""),
                iff(this->balls[19]," 20", ""),
                iff(this->balls[20]," 21", ""),
                iff(this->balls[21]," 22", ""),
                iff(this->balls[22]," 23", ""),
                iff(this->balls[23]," 24", ""),
                iff(this->balls[24]," 25", "")
        );
 
    }
}

extern void num_destroy(struct Num *this)
{
    debug("Destroing the number id: %ld\n", this->id);
    if(this)
      free(this);
}

/**
 * Return the amount of numbers are equals in both numbers.
 *
 */
static int num_compare(struct Num *this, struct Num *other)
{
    int i, result = 0;
    for(i = 0; i < 25; i = i + 1)
    {
        if(this->balls[i] == 1 && other->balls[i] == 1)
        {
            result = result + 1;
        }
    }
    return result;
}

extern int num_line(struct Num *this, int line)
{
    int i, start = (line - 1) * 5, result = 0;
    for(i = start; i < start + 5; i = i + 1)
    {
        if(this->balls[i])
            result = result + 1;

    }

    return result;
}

static void num_reset(struct Num *this)
{
    int i;
    for(i = 0; i < 24; i = i + 1)
    {
        if( i < 15)
            this->balls[i] = 1;
        else
            this->balls[i] = 0;
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
            result->balls[i] = 1;
        } else { 
            result->balls[i] = 0;
        }
    }

  return result;
}

#endif
/* vim: set ts : */
