/**
 *
 * @author Edgard Leal <edgardleal@gmail.com> 
 * @language C
 * @libs minunit git_color 
 *
 **/
#ifndef MINUNIT_C
#define MINUNIT_C
#include "minunit.h"
#include "color.h"

int tests_run = 0;
int tests_error_count = 0;

extern void print_test( int result, char * message)
{
    char *color,
         *status;
    if(result)
    {
        status = "Ok";
        color = GIT_COLOR_GREEN;
    } else {
        status = "Fail";
        color = GIT_COLOR_RED;
    }
    printf("[%s%s%s] %s\n", color, status, GIT_COLOR_RESET,
            message);
}

#endif
