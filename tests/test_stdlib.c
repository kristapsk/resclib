#include <stdlib.h>
#include "seatest.h"

static void test_abs (void)
{
    // abs
    assert_true(abs(0) == 0);
    assert_true(abs(1) == 1);
    assert_true(abs(INT_MAX) == INT_MAX);
    assert_true(abs(-1) == 1);
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
