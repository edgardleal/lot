/** \file test_report.c
 *  \brief units tests for report.h
 *
 *    Description:  Unit test for report funcionalities
 *
 *        Version:  1.0
 *        Created:  04-03-2017 20:39:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Edgard Leal (edgardleal@gmail.com), 
 *   Organization:  
 *
 */
#ifndef TEST_REPORT_C
#define TEST_REPORT_C

#include <string.h>
#include "../report.h"
#include "../minunit.h"
#include "test_report.h"

char *get_ratio(void);
int min, max, value;
char *result;

char *get_ratio()
{
    result = color_for_ratio(min, max, value);
    return result;
}

void test_color_scale(void)
{

    ok(1, "%sGIT_COLOR_BOLD_BLUE%s",  GIT_COLOR_BOLD_BLUE, GIT_COLOR_RESET);
    ok(1, "%sGIT_COLOR_BLUE%s",       GIT_COLOR_BLUE, GIT_COLOR_RESET);
    ok(1, "%sGIT_COLOR_BOLD_GREEN%s", GIT_COLOR_BOLD_GREEN, GIT_COLOR_RESET);
    ok(1, "%sGIT_COLOR_GREEN%s",      GIT_COLOR_GREEN, GIT_COLOR_RESET);
    ok(1, "%sGIT_COLOR_BOLD_YELLOW%s",GIT_COLOR_BOLD_YELLOW, GIT_COLOR_RESET);

    min = 0;
    max = 25;
    value = 0;
    ok(strcmp(GIT_COLOR_BOLD_BLUE, get_ratio()) == 0, "Value = 0 %sGIT_COLOR_BOLD_BLUE%s", result, GIT_COLOR_RESET); 

    min   = 10;
    max   = 15;
    value = 10;
    ok(strcmp(GIT_COLOR_BOLD_BLUE, get_ratio()) == 0, "%sGIT_COLOR_BOLD_BLUE%s", get_ratio(), GIT_COLOR_RESET); 
}
#endif
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
