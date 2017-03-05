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
void test_color_scale(void);

void test_color_scale(void)
{
    char *result = color_for_ratio(0, 25, 0);
    ok(strcmp(GIT_COLOR_BOLD_BLUE, result) == 0, "GIT_COLOR_BOLD_BLUE"); 

    result = color_for_ratio(0, 25, 3);
    ok(strcmp(GIT_COLOR_BLUE, result) == 0, "GIT_COLOR_BLUE"); 

    result = color_for_ratio(0, 25, 5);
    ok(strcmp(GIT_COLOR_BOLD_GREEN, result) == 0, "GIT_COLOR_BOLD_GREEN"); 

    result = color_for_ratio(0, 25, 8);
    ok(strcmp(GIT_COLOR_GREEN, result) == 0, "GIT_COLOR_GREEN"); 

    result = color_for_ratio(10, 15, 10);
    ok(strcmp(GIT_COLOR_BOLD_BLUE, result) == 0, "%sGIT_COLOR_BOLD_BLUE%s", result, GIT_COLOR_RESET); 

}
#endif
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
