#include "../libtap/tap.h"
#include "num.h"

void check_balls(struct Num* this);
void test_compare();

int
main()
{
    struct Num *num;
    num = newNum();
    char error = 0;

    plan(11);
    check_balls(num);
    num->inc(num);

    ok(num->bols[14] == 0, "Ball 15 should be zero after first inc operation and is: %d", num->bols[14]);

    num->inc(num);
    ok(num->bols[15] == 0, "Ball 16 should be zero after seccond inc operation and is: %d", num->bols[15]);
    ok(num->bols[16] == 1, "Ball 17 should be one after seccond inc operation and is: %d", num->bols[16]);

		test_compare();
    done_testing();

    free(num);

    return 0;
}

void test_compare()
{
	struct Num *this = newNum(),
		  *other = newNum();
	int result = this->compare(this, other);
	is(result, 15, "Result should be 15");

	this->destroy(this);
	other->destroy(other);
}

void
test_toString()
{
    struct Num *this = newNum();

    todo();
    char *text;
    this->toString(this, text);

    free(this);
}

void
check_balls(struct Num *this)
{
    is(this->bols[11], 1, "Ball 12 should be one and is: %d", this->bols[11]);
    is(this->bols[12], 1, "Ball 13 should be one and is: %d", this->bols[12]);
    is(this->bols[13], 1, "Ball 14 should be one and is: %d", this->bols[13]);
    is(this->bols[14], 1, "Ball 15 should be one and is: %d", this->bols[14]);
    isnt(this->bols[15], 1, "Ball 16 should be zero and is: %d", this->bols[15]);
    isnt(this->bols[16], 1, "Ball 17 should be zero and is: %d", this->bols[16]);
    isnt(this->bols[17], 1, "Ball 18 should be zero and is: %d", this->bols[17]);
}
