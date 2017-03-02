/** \file src/test/test_csv.c
 *
 * \brief Tests for file csv.h
 *
 * @author Edgard Leal <edgardleal@gmail.com> 
 *
 **/
#include "../minunit.h"

extern void test_csv(void);
extern void test_csv_new_num_from_string(void);

extern void test_csv(void)
{
    char *text = "XXXX";

    ok(text[0] == 'X', "X founded");

    char *line = "1,2,3\0";
    char **columns = (char**)malloc(sizeof(char**) * 20);

    csv_start_columns(columns, 20);
    ok(1, "Started");

    split_csv(line, columns);
    ok(columns[0][0] == '1', "start");
    ok(columns[1][0] == '2', "second char equal 2");
    ok(columns[2][0] == '3', "third char equal 3");
}

extern void test_csv_new_num_from_string(void)
{
    char *line = "1,222, \"01/02/1500\", 20, 15,2";
    struct Num *result = csv_new_num_from_string(line);

    ok(result->bols[2] == 1, "First ball should be 2");
    ok(result->bols[14] == 1, "Seccond ball should be 15");
    ok(result->bols[19] == 1, "Third ball should be 20");

    free(result);
}
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
