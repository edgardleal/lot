
#include "../minunit.h"
#include "test_num.h"
#include "../num.h"

void test_num_cols(void)
{
    struct Num *num = newNum();
    num->clear(num);

    ok(num->cols[0] == 0, "cols 1 should be 0");
    ok(num->cols[1] == 0, "cols 2 should be 0");
    ok(num->cols[2] == 0, "cols 3 should be 0");
    ok(num->cols[3] == 0, "cols 4 should be 0");
    ok(num->cols[4] == 0, "cols 5 should be 0");

    num->load_string(num, "1 2 3 ");
    ok(num->cols[1] == 1, "col 1 should be 1");
    ok(num->cols[2] == 1, "col 2 should be 1");

    num->destroy(num);
}

extern void test_num_lines(void)
{
    struct Num *num = newNum();
    num->clear(num);

    ok(num->lines[0] == 0, "line 1 should be 0");
    ok(num->lines[1] == 0, "line 2 should be 0");
    ok(num->lines[2] == 0, "line 3 should be 0");
    ok(num->lines[3] == 0, "line 4 should be 0");
    ok(num->lines[4] == 0, "line 5 should be 0");

    num->destroy(num);
}

extern void test_num_reset(void)
{
    struct Num *num = newNum();
    num->clear(num);
    int i;
    for (i = 0; i < 25; i++ )
    {
        ok(num->balls[i] == 0, "Ball %d should be 0", i);
    }

    ok(num->lines[0] == 0, "line 1 should be 0");
    ok(num->lines[1] == 0, "line 2 should be 0");
    ok(num->lines[2] == 0, "line 3 should be 0");
    ok(num->lines[3] == 0, "line 4 should be 0");
    ok(num->lines[4] == 0, "line 5 should be 0");

    ok(num->cols[0] == 0, "col 1 should be 0");
    ok(num->cols[1] == 0, "col 2 should be 0");
    ok(num->cols[2] == 0, "col 3 should be 0");
    ok(num->cols[3] == 0, "col 4 should be 0");
    ok(num->cols[4] == 0, "col 5 should be 0");

    num->reset(num);

    for (i = 0; i < 25; i++ )
    {
        if (i < 15)
        {
            ok(num->balls[i], "Ball %d should be 1", i);
        }
        else
        {
            ok(num->balls[i] == 0, "Ball %d should be 0", i);
        }
    }

    ok(num->lines[0] == 5, "line 1 should be 5");
    ok(num->lines[1] == 5, "line 2 should be 5");
    ok(num->lines[2] == 5, "line 3 should be 5");
    ok(num->lines[3] == 0, "line 4 should be 0");
    ok(num->lines[4] == 0, "line 5 should be 0");

    ok(num->cols[0] == 3, "col 1 should be 3");
    ok(num->cols[1] == 3, "col 2 should be 3");
    ok(num->cols[2] == 3, "col 3 should be 3");
    ok(num->cols[3] == 3, "col 4 should be 3 and now is %d", 
            num->cols[3]);
    ok(num->cols[4] == 3, "col 5 should be 3");

    num->destroy(num);
}
