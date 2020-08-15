#ifndef _ASSERT_H
#define _ASSERT_H

#ifdef NDEBUG

#define assert(ignore)((void) 0)

#else

void __assert_fail (const char* expr, const char* file, int line);

#define assert(expr) \
    if (!(expr)) \
        __assert_fail(#expr, __FILE__, __LINE__)

#endif

#endif

