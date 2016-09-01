#include <ctype.h>
#include "seatest.h"

static void test_isalnum (void)
{
    assert_true(isalnum('a'));
    assert_true(isalnum('z'));
    assert_true(isalnum('A'));
    assert_true(isalnum('Z'));
    assert_true(isalnum('0'));
    assert_true(isalnum('9'));
    assert_false(isalnum(' '));
    assert_false(isalnum('\n'));
    assert_false(isalnum('@'));
}

static void test_isalpha (void)
{
    assert_true(isalpha('a'));
    assert_true(isalpha('z'));
    assert_false(isalpha(' '));
    assert_false(isalpha('1'));
    assert_false(isalpha('@'));
}

static void test_isblank (void)
{
    assert_true(isblank(' '));
    assert_true(isblank('\t'));
    assert_false(isblank('\v'));
    assert_false(isblank('\r'));
    assert_false(isblank('x'));
    assert_false(isblank('@'));
}

static void test_iscntrl (void)
{
    assert_true(iscntrl('\a'));
    assert_true(iscntrl('\b'));
    assert_true(iscntrl('\n'));
    assert_false(iscntrl(' '));
}

static void test_isdigit (void)
{
    assert_true(isdigit('0'));
    assert_true(isdigit('9'));
    assert_false(isdigit(' '));
    assert_false(isdigit('a'));
    assert_false(isdigit('@'));
}

static void test_isgraph (void)
{
    assert_true(isgraph('a'));
    assert_true(isgraph('z'));
    assert_true(isgraph('A'));
    assert_true(isgraph('Z'));
    assert_true(isgraph('@'));
    assert_false(isgraph('\t'));
    assert_false(isgraph('\0'));
    assert_false(isgraph(' '));
}

static void test_islower (void)
{
    assert_true(islower('a'));
    assert_true(islower('z'));
    assert_false(islower('A'));
    assert_false(islower('Z'));
    assert_false(islower(' '));
    assert_false(islower('@'));
}

static void test_isprint (void)
{
    assert_true(isprint('a'));
    assert_true(isprint('z'));
    assert_true(isprint('A'));
    assert_true(isprint('Z'));
    assert_true(isprint('@'));
    assert_false(isprint('\t'));
    assert_false(isprint('\0'));
    assert_true(isprint(' '));
}

static void test_ispunct (void)
{
    assert_false(ispunct('a'));
    assert_false(ispunct('z'));
    assert_false(ispunct('A'));
    assert_false(ispunct('Z'));
    assert_true(ispunct('@'));
    assert_true(ispunct('.'));
    assert_false(ispunct('\t'));
    assert_false(ispunct('\0'));
    assert_false(ispunct(' '));
}

static void test_isspace (void)
{
    assert_true(isspace(' '));
    assert_true(isspace('\f'));
    assert_true(isspace('\n'));
    assert_true(isspace('\r'));
    assert_true(isspace('\t'));
    assert_true(isspace('\v'));
    assert_false(isspace('a'));
}

static void test_isupper (void)
{
    assert_true(isupper('A'));
    assert_true(isupper('Z'));
    assert_false(isupper('a'));
    assert_false(isupper('z'));
    assert_false(isupper(' '));
    assert_false(isupper('@'));
}

static void test_isxdigit (void)
{
    assert_true(isxdigit('0'));
    assert_true(isxdigit('9'));
    assert_true(isxdigit('a'));
    assert_true(isxdigit('f'));
    assert_false(isxdigit('g'));
    assert_true(isxdigit('A'));
    assert_true(isxdigit('F'));
    assert_false(isxdigit('G'));
    assert_false(isxdigit('@'));
    assert_false(isxdigit(' '));
}

static void test_tolower (void)
{
    assert_int_equal('a', tolower('A'));
    assert_int_equal('z', tolower('Z'));
    assert_int_equal('a', tolower('a'));
    assert_int_equal('z', tolower('z'));
    assert_int_equal('@', tolower('@'));
    assert_int_equal('[', tolower('['));
}

static void test_toupper (void)
{
    assert_int_equal('A', toupper('a'));
    assert_int_equal('Z', toupper('z'));
    assert_int_equal('A', toupper('A'));
    assert_int_equal('Z', toupper('Z'));
    assert_int_equal('@', toupper('@'));
    assert_int_equal('[', toupper('['));
}

void test_ctype (void)
{
    test_fixture_start();
    run_test(test_isalnum);
    run_test(test_isalpha);
    run_test(test_isblank);
    run_test(test_iscntrl);
    run_test(test_isdigit);
    run_test(test_isgraph);
    run_test(test_islower);
    run_test(test_isprint);
    run_test(test_ispunct);
    run_test(test_isspace);
    run_test(test_isupper);
    run_test(test_isxdigit);
    run_test(test_tolower);
    run_test(test_toupper);
    test_fixture_end();
}
