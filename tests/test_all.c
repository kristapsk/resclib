#include "seatest.h"

extern void test_string (void);

void all_tests (void)
{
    test_string();
}

int main (int argc, char** argv)
{
    return run_tests(all_tests) ? 0 : 1;
}
