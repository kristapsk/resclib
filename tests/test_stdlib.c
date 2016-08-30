#include <stdlib.h>
#include "seatest.h"

static void test_abs (void)
{
    // abs
    assert_int_equal(0, abs(0));
    assert_int_equal(1, abs(1));
    assert_int_equal(INT_MAX, abs(INT_MAX));
    assert_int_equal(1, abs(-1));
    // labs
    assert_true(labs(0) == 0);
    assert_true(labs(1) == 1);
    assert_true(labs(LONG_MAX) == LONG_MAX);
    assert_true(labs(-1) == 1);
    // llabs
    assert_true(llabs(0) == 0);
    assert_true(llabs(1) == 1);
    assert_true(llabs(LLONG_MAX) == LLONG_MAX);
    assert_true(llabs(-1) == 1);
}

void test_stdlib (void)
{
    test_fixture_start();
    run_test(test_abs);
    test_fixture_end();
}
