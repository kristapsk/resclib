#include <stdio.h>
#include <stdlib.h>

void __assert_fail (const char* expr, const char* file, int line)
{
    fprintf(stderr, "%s:%d: Assertion failed: %s\n", file, line, expr);
    _Exit(EXIT_FAILURE);
}
