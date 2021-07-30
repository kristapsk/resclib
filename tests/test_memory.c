#include <errno.h>
#include <memory.h>
#include "seatest.h"

static const char abcde[] = "abcde";
static const char abcdx[] = "abcdx";

static void test_memchr (void)
{
    assert_int_equal(6, sizeof(abcde));

    assert_true(memchr(abcde, 'c',  5) == &abcde[2]);
    assert_true(memchr(abcde, 'a',  1) == &abcde[0]);
    assert_true(memchr(abcde, 'a',  0) == NULL);
    assert_true(memchr(abcde, '\0', 5) == NULL);
    assert_true(memchr(abcde, '\0', 6) == &abcde[5]);
}

static void test_memcmp (void)
{
    static const char xxxxx[] = "x";

    assert_true(sizeof(abcde) >= 5);
    assert_true(sizeof(abcdx) >= 4);

    assert_true(memcmp(abcde, abcdx, 5) < 0);
    assert_int_equal(0, memcmp(abcde, abcdx, 4));
    assert_int_equal(0, memcmp(abcde, xxxxx, 0));
    assert_true(memcmp(xxxxx, abcde, 1) > 0);
}

static void test_memcpy (void)
{
    char s[] = "xxxxxxxxxxx";

    assert_true(sizeof(abcde) > 5);

    assert_true(memcpy(s, abcde, 6) == s);
    assert_true(s[4] == 'e');
    assert_true(s[5] == '\0');
    assert_true(memcpy(s + 5, abcde, 5) == s + 5);
    assert_true(s[9] == 'e');
    assert_true(s[10] == 'x');
}

static void test_memcpy_s (void)
{
    static char s1[] = "xxxxxxxx";
    static char s2[] = "yyyyyyyy";

    assert_true(memcpy_s(s1, 1, s2, 0) == 0);
    assert_true(memcpy_s(NULL, 1, s2, 1) == EINVAL);
    assert_true(memcpy_s(s1, 1, NULL, 1) == EINVAL);
    assert_true(memcpy_s(s1, 1, s2, 2) == ERANGE);
}

static void test_memmove (void)
{
    char s[] = "xxxxabcde";

    assert_true(memmove(s, s + 4, 5) == s);
    assert_true(s[0] == 'a');
    assert_true(s[4] == 'e');
    assert_true(s[5] == 'b');
    assert_true(memmove(s + 4, s, 5) == s + 4);
    assert_true(s[4] == 'a');
}

static void test_memmove_s (void)
{
    static char s1[] = "xxxxxxxx";
    static char s2[] = "yyyyyyyy";

    assert_true(memmove_s(NULL, 1, s2, 1) == EINVAL);
    assert_true(memmove_s(s1, 1, NULL, 1) == EINVAL);
    assert_true(memmove_s(s1, 1, s2, 2) == ERANGE);
}

static void test_memset (void)
{
    char s[] = "xxxxxxxxx";

    assert_true(sizeof(s) >= 10);

    assert_true(memset(s, 'o', 10) == s);
    assert_true(s[9] == 'o');
    assert_true(memset(s, '_', 0) == s);
    assert_true(s[0] == 'o');
    assert_true(memset(s, '_', 1) == s);
    assert_true(s[0] == '_');
    assert_true(s[1] == 'o');
}

void test_memory (void)
{
    test_fixture_start();
    run_test(test_memchr);
    run_test(test_memcmp);
    run_test(test_memcpy);
    run_test(test_memcpy_s);
    run_test(test_memmove);
    run_test(test_memmove_s);
    run_test(test_memset);
    test_fixture_end();
}
