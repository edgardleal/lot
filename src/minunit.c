/**
 * Unit test for C
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
unsigned char buffer[200];
char *current_module;

extern void test_module(char *module)
{
    current_module = module;
}

extern void print_test( int result, char * message)
{
    char *color,
         *status;
    if(result)
    {
        status = " OK ";
        color = GIT_COLOR_GREEN;
        buffer[tests_run - 1] = 'T';
    } else {
        status = "FAIL";
        color = GIT_COLOR_RED;
        buffer[tests_run - 1] = 'F';
    }
    printf("[%s%s%s] %s - %s\n", color, status, GIT_COLOR_RESET,
            current_module,
            message);
}

extern void test_summary()
{
    char *color;
    if(tests_error_count > 0)
        color = GIT_COLOR_RED;
    else
        color = GIT_COLOR_GREEN;

    printf("%d tests executed.\n", tests_run);
    printf("%d %sErros finded.%s\n", 
            tests_error_count,
            color,
            GIT_COLOR_RESET);
    printf("[%s##########################################%s]\n",
            color,
            GIT_COLOR_RESET);
}

#endif
