#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"
#include "num.h"
#include "csv.h"

char * check_balls(struct Num* this);
char * test_compare();
char * test_init();
char * test_all();
void test_reset(void);
void test_load_string(void);
void test_csv(void);
void test_line_count(void);
void test_strcpy();

int
main()
{
    test_all();
    test_summary();
    return tests_error_count != 0;
}

char *
test_all()
{
    mu_run_test(test_init);
    mu_run_test(test_strcpy);
    mu_run_test(test_compare);
    mu_run_test(test_reset);
    mu_run_test(test_load_string);
    mu_run_test(test_line_count);
    mu_run_test(test_csv);
    return 0;
}

char *
test_init() 
{
    struct Num *num;
    num = newNum();

    check_balls(num);
    num->inc(num);

    mu_assert("Ball 15 should be zero after first inc operation", num->bols[14] == 0);

    num->inc(num);
    mu_assert("Ball 16 should be zero after seccond inc operation", num->bols[15] == 0);
    mu_assert("Ball 17 should be one after seccond inc operation ", num->bols[16] == 1);

    num->inc(num);
    num->inc(num);
    num->inc(num);
    num->inc(num);
    num->inc(num);
    num->inc(num);
    num->inc(num);
    num->inc(num);
    ok(num->bols[24] == 1, "25 should be 1");

    /* after 25 should reset */
    num->inc(num);
    ok(num->bols[24] == 0, "25 should be 0 after first reset");
    ok(num->bols[13] == 0, "14 should be 0 after first reset");
    ok(num->bols[14] == 1, "15 should be 1 after first reset");
    ok(num->bols[15] == 1, "16 should be 1 after first reset");

    num->destroy(num);
    return 0;
}

char *
test_compare()
{
    struct Num *this = newNum(),
          *other = newNum();
    int result = this->compare(this, other);
    mu_assert("Result should be 15", result == 15);
    other->inc(other);
    result = other->compare(other, this);
    ok(14 == result, "Equals bols decrease after inc ");

    other->inc(other);
    result = other->compare(other, this);
    ok(14 == result, "When second inc the last ball is 17 and result of compare continue 14");


    this->destroy(this);
    other->destroy(other);
    return 0;
}

char *
test_toString()
{
    struct Num *this = newNum();

    char *text;
    this->toString(this, text);

    free(this);
    return 0;
}

char *
check_balls(struct Num *this)
{
    mu_assert("Ball 12 should be one  ", this->bols[11]);
    mu_assert("Ball 13 should be one  ", this->bols[12]);
    mu_assert("Ball 14 should be one  ", this->bols[13]);
    mu_assert("Ball 15 should be one  ", this->bols[14]);
    ok(this->bols[15] == 0, "Ball 16 should be zero");
    
    ok(this->bols[16] == 0, "Ball 17 should be zero");
    ok(this->bols[17] == 0, "Ball 18 should be zero");
    return 0;
}

void test_reset()
{
    struct Num *num = newNum();
    num->inc(num);
    num->reset(num);
    
    ok(num->bols[14] == 1, "Ball 15 should be 1 in test_reset");

    num->destroy(num);
}

void test_line_count() {
    struct Num *num = newNum();
    num->inc(num);
    num->reset(num);

    ok(num_line(num, 1) == 5, "Line 1 have five numbers");
    ok(num_line(num, 2) == 5, "Line 2 have five numbers");
    ok(num_line(num, 3) == 5, "Line 3 have five numbers");
    ok(num_line(num, 4) == 0, "Line 4 have five numbers");
    ok(num_line(num, 5) == 0, "Line 5 have five numbers");
    
    num->destroy(num);
}

void test_load_string()
{
    char *text = "15 16 17 18\n19 20 21 22 23 24 25";
    struct Num *num = newNum();
    ok(num->bols[16] == 0, "Ball 17 should be 0 before load_string");
    num->load_string(num, text);
    
    ok(num->bols[14] == 1, "Ball 15 should be 1 in ");
    ok(num->bols[15] == 1, "Ball 16 should be 1 in ");
    ok(num->bols[16] == 1, "Ball 17 should be 1 in ");
    ok(num->bols[24] == 1, "Ball 25 should be 1 in ");

    num->destroy(num);
}

void test_strcpy()
{
    char dest[5];
    char src[200];
    src[0] = 'A';
    src[1] = 'B';
    src[2] = 'C';
    src[3] = '\0';

    strcpy(dest, src);
    ok(dest[0] == 'A', "first letter");
    ok(dest[1] == 'B', "seccond letter");
    ok(dest[2] == 'C', "third letter");
}

void test_csv()
{
    char *text = "XXXX";

    ok(text[0] == 'X', "X founded");

    char *line = "1,2,3\0";
    char **columns = (char**)malloc(sizeof(char**) * 20);
    /*
     *
    */
    csv_start_columns(columns, 20);
    ok(1, "Started");

    split_csv(line, columns);
    ok(columns[0][0] == '1', "start");
    ok(columns[1][0] == '2', "second char equal 2");
    ok(columns[2][0] == '3', "third char equal 3");
}

/* vim: set expandtab tabstop=4 tabshift=4 :*/
