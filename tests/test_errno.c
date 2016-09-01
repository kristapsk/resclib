#include <errno.h>
#include "seatest.h"

static void test_errno_ (void)
{
    errno = 0;
    assert_int_equal(0, errno);
    errno = EDOM;
    assert_int_equal(EDOM, errno);
    errno = ERANGE;
    assert_int_equal(ERANGE, errno);
}

void test_errno (void)
{
    test_fixture_start();
    run_test(test_errno_);
    test_fixture_end();
}
