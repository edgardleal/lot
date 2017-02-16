#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "num.h"

char * check_balls(struct Num* this);
char * test_compare();
char * test_init();
char * test_all();


int
main()
{
    char *result = 0;

    result = test_all();

    return tests_error_count != 0;
}

char *
test_all()
{
    mu_run_test(test_init);
    mu_run_test(test_compare);
		mu_run_test(test_reset);
		mu_run_test(test_load_string);
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

    free(num);
    return 0;
}

char *
test_compare()
{
	struct Num *this = newNum(),
		  *other = newNum();
	int result = this->compare(this, other);
	mu_assert("Result should be 15", result == 15);

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


void test_load_string()
{
	char *text = "15 16 17 18\n19 20 21 22 23 24 25";
	struct Num *num = newNum();
	ok(num->bols[16] == 0, "Ball 17 should be 0 before load_string");
	num->load_string(num, text);
	
	ok(num->bols[14] == 1, "Ball 15 should be 1 in test_load_string");
	ok(num->bols[15] == 1, "Ball 16 should be 1 in test_load_string");
	ok(num->bols[16] == 1, "Ball 17 should be 1 in test_load_string");
	ok(num->bols[24] == 1, "Ball 25 should be 1 in test_load_string");

	num->destroy(num);
}

/* vim: set expandtab tabstop=4 :*/
