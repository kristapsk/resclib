#define _RESCLIB_SOURCE
#include <stdlib.h>
#undef _RESCLIB_SOURCE
#include <limits.h>
#include <locale.h>
#include "seatest.h"

static void test_setlocale (void)
{
    // "", "C" and "POSIX" locales must be always present
    assert_string_equal("C", setlocale(LC_ALL, "C"));
    assert_true(setlocale(LC_ALL, "") != NULL);
    assert_true(setlocale(LC_ALL, "POSIX") != NULL);
}

static void test_C_locale (void)
{
    // "C" and "POSIX" locales should match
    char* localenames[] = { "C", "POSIX" };
    for (size_t i = 0; i < _countof(localenames); i++) {
        setlocale(LC_ALL, localenames[i]);
        struct lconv* lc = localeconv();

        // "C" locale values as per C standard
        assert_string_equal(".", lc->decimal_point);
        assert_string_equal("", lc->thousands_sep);
        assert_string_equal("", lc->grouping);
        assert_string_equal("", lc->int_curr_symbol);
        assert_string_equal("", lc->currency_symbol);
        assert_string_equal("", lc->mon_decimal_point);
        assert_string_equal("", lc->mon_thousands_sep);
        assert_string_equal("", lc->mon_grouping);
        assert_string_equal("", lc->positive_sign);
        assert_string_equal("", lc->negative_sign);
        assert_int_equal(CHAR_MAX, lc->frac_digits);
        assert_int_equal(CHAR_MAX, lc->p_cs_precedes);
        assert_int_equal(CHAR_MAX, lc->n_cs_precedes);
        assert_int_equal(CHAR_MAX, lc->p_sep_by_space);
        assert_int_equal(CHAR_MAX, lc->n_sep_by_space);
        assert_int_equal(CHAR_MAX, lc->p_sign_posn);
        assert_int_equal(CHAR_MAX, lc->n_sign_posn);
        assert_int_equal(CHAR_MAX, lc->int_frac_digits);
        assert_int_equal(CHAR_MAX, lc->int_p_cs_precedes);
        assert_int_equal(CHAR_MAX, lc->int_n_cs_precedes);
        assert_int_equal(CHAR_MAX, lc->int_p_sep_by_space);
        assert_int_equal(CHAR_MAX, lc->int_n_sep_by_space);
        assert_int_equal(CHAR_MAX, lc->int_p_sign_posn);
        assert_int_equal(CHAR_MAX, lc->int_n_sign_posn);
    }
}

void test_locale (void)
{
    test_fixture_start();
    run_test(test_setlocale);
    run_test(test_C_locale);
    test_fixture_end();
}
