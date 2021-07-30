#include "seatest.h"

extern void test_ctype (void);
extern void test_errno (void);
extern void test_locale (void);
extern void test_memory (void);
extern void test_stdlib (void);
extern void test_string (void);
extern void test_time (void);

void all_tests (void)
{
    test_ctype();
    test_errno();
    test_locale();
    test_memory();
    test_stdlib();
    test_string();
    test_time();
}

int main (int argc, char** argv)
{
    return run_tests(all_tests) ? 0 : 1;
}
