#include <stdlib.h>
#include "seatest.h"

static void test_abs (void)
{
    // abs
    assert_int_equal(0, abs(0));
    assert_int_equal(1, abs(1));
    assert_int_equal(INT_MAX, abs(INT_MAX));
    assert_int_equal(1, abs(-1));
    assert_int_equal(-(INT_MIN + 1), abs(INT_MIN + 1));
    // labs
    assert_true(labs(0) == 0);
    assert_true(labs(1) == 1);
    assert_true(labs(LONG_MAX) == LONG_MAX);
    assert_true(labs(-1) == 1);
    assert_true(labs(LONG_MIN + 1) == -(LONG_MIN + 1));
    // llabs
    assert_true(llabs(0) == 0);
    assert_true(llabs(1) == 1);
    assert_true(llabs(LLONG_MAX) == LLONG_MAX);
    assert_true(llabs(-1) == 1);
    assert_true(llabs(LLONG_MIN + 1) == - (LLONG_MIN + 1));
}

static void test_div (void)
{
    // div
    {
        div_t result;
        result = div(5, 2);
        assert_int_equal(2, result.quot);
        assert_int_equal(1, result.rem);
        result = div(-5, 2);
        assert_int_equal(-2, result.quot);
        assert_int_equal(-1, result.rem);
        result = div(5, -2);
        assert_int_equal(-2, result.quot);
        assert_int_equal(1, result.rem);
        assert_true(sizeof(result.quot) == sizeof(int));
        assert_true(sizeof(result.rem) == sizeof(int));
    }
    // ldiv
    {
        ldiv_t result;
        result = ldiv(5, 2);
        assert_true(result.quot == 2 && result.rem == 1);
        result = ldiv(-5, 2);
        assert_true(result.quot == -2 && result.rem == -1);
        result = ldiv(5, -2);
        assert_true(result.quot == -2 && result.rem == 1);
        assert_true(sizeof(result.quot) == sizeof(long));
        assert_true(sizeof(result.rem) == sizeof(long));
    }
    // lldiv
    {
        lldiv_t result;
        result = lldiv(5, 2);
        assert_true(result.quot == 2 && result.rem == 1);
        result = lldiv(-5, 2);
        assert_true(result.quot == -2 && result.rem == -1);
        result = lldiv(5, -2);
        assert_true(result.quot == -2 && result.rem == 1);
        assert_true(sizeof(result.quot) == sizeof(long long));
        assert_true(sizeof(result.rem) == sizeof(long long));
    }
}

void test_stdlib (void)
{
    test_fixture_start();
    run_test(test_abs);
    run_test(test_div);
    test_fixture_end();
}
