/** \file src/test/test_csv.c
 *
 * \brief Tests for file csv.h
 *
 * @author Edgard Leal <edgardleal@gmail.com> 
 *
 **/
#ifndef TEST_CSV_C
#define TEST_CSV_C

#include <stdlib.h>
#include "../minunit.h"
#include "../csv.h"

void test_csv(void);
void test_csv_new_num_from_string(void);
void test_atoi(void);

void test_csv(void)
{
    char *line = "1,2,3\0";
    char **columns = (char**)malloc(sizeof(char**) * 20);

    csv_start_columns(columns, 20);
    ok(1, "Started");

    split_csv(line, columns, 20);
    ok(columns[0][0] == '1', "start");
    ok(columns[1][0] == '2', "second char equal 2");
    ok(columns[2][0] == '3', "third char equal 3");
}

/** \fn test_csv_new_num_from_string
 *  Test the creation of a new Num from an csv String.
 */
void test_csv_new_num_from_string(void)
{
    char *line = "1,222, \"01/02/1500\", 20, 15,2";
    struct Num *result = csv_new_num_from_string(line);

    ok(result->balls[2] == 1, "First ball should be 2");
    ok(result->balls[14] == 1, "Seccond ball should be 15");
    ok(result->balls[19] == 1, "Third ball should be 20");

    free(result);
}

/**
 * \fn test_atoi
 * \brief check conversion from string to int 
 *
 */
void test_atoi(void)
{
    ok(atoi("01") == 1, "conversion from 01 to int 1");
}

#endif
/** vim: set expandtab tabstop=4 shiftwidth=4 :*/
