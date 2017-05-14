#include <inttypes.h>
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
    // imaxabs
    assert_true(imaxabs(0) == 0);
    assert_true(imaxabs(1) == 1);
    assert_true(imaxabs(INTMAX_MAX) == INTMAX_MAX);
    assert_true(imaxabs(-1) == 1);
    assert_true(imaxabs(INTMAX_MIN + 1) == - (INTMAX_MIN + 1));
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
    // imaxdiv
    {
        imaxdiv_t result;
        result = imaxdiv(5, 2);
        assert_true(result.quot == 2 && result.rem == 1);
        result = imaxdiv(-5, 2);
        assert_true(result.quot == -2 && result.rem == -1);
        result = imaxdiv(5, -2);
        assert_true(result.quot == -2 && result.rem == 1);
        assert_true(sizeof(result.quot) == sizeof(intmax_t));
        assert_true(sizeof(result.rem) == sizeof(intmax_t));
    }
}

static void test_rand (void)
{
    assert_true(RAND_MAX >= 32767);
    // By C standard, same seeds should generate the same random numbers and
    // seed should change only by calls to srand() and rand().
    // All numbers need to be between 0 and RAND_MAX.
    srand(123456);
    int rand_a1 = rand();
    assert_true(rand_a1 >= 0);
    assert_true(rand_a1 <= RAND_MAX);
    int rand_b1 = rand();
    assert_true(rand_b1 >= 0);
    assert_true(rand_b1 <= RAND_MAX);
    srand(123456);
    int rand_a2 = rand();
    assert_true(rand_a2 >= 0);
    assert_true(rand_a2 <= RAND_MAX);
    int rand_b2 = rand();
    assert_true(rand_b2 >= 0);
    assert_true(rand_b2 <= RAND_MAX);
    assert_int_equal(rand_a1, rand_a2);
    assert_int_equal(rand_b1, rand_b2);
}

void test_stdlib (void)
{
    test_fixture_start();
    run_test(test_abs);
    run_test(test_div);
    run_test(test_rand);
    test_fixture_end();
}
