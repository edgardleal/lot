#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "num.h"

char * check_balls(struct Num* this);
char * test_compare();
char * test_init();
char * test_all();

int tests_run = 0;

int
main()
{
    char *result = 0;

    result = test_all();
    if(result)
    {
        printf("%s\n", result);
    }else {
        printf("All Tests Passed!\n");
    }

    return result != 0;
}

char *
test_all()
{
    mu_run_test(test_init);
    mu_run_test(test_compare);

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
    mu_assert("Ball 16 should be zero ", this->bols[15]);
    mu_assert("Ball 17 should be zero ", this->bols[16]);
    mu_assert("Ball 18 should be zero ", this->bols[17]);
    return 0;
}
