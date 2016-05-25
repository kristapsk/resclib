#include <string.h>
#include "seatest.h"

static void test_strcmp (void)
{
    assert_int_equal(0, strcmp("", ""));
    assert_int_equal(0, strcmp("one", "one"));
}

void test_string (void)
{
    test_fixture_start();
    run_test(test_strcmp);
    test_fixture_end();
}
