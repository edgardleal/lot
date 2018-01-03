/** \file 
 * 
 * \brief Description 
 * @author Edgard Leal <edgardleal@gmail.com> 
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include "command.h"


int show_results(char* text)
{

}

int show_my(char* text)
{

}

int update(char* text)
{

}

struct Command* command_new(char* text)
{
    struct Command *result;
    result = (struct Command*) malloc(sizeof(struct Command));
    result->free = &command_free;
    result->load = &command_load;

    return result;
}

void command_free(struct Command* this)
{
    free(this->name);
    free(this->command_line);
    free(this);
}

void command_load(struct Command* this, char* text)
{
    /* TODO: */
}
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
