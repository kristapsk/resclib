#ifndef _STDLIB_H
#define _STDLIB_H

#include <limits.h>
#include <stddef.h>

#define EXIT_SUCCESS    (0)
#define EXIT_FAILURE    (1)

#ifdef __cplusplus
extern "C" {
#endif

#if (__STDC_VERSION__ >= 201112L)
    void _Exit (int status);
#endif

int abs (int x);
long labs (long x);
long long llabs (long long x);

int mblen (const char* pmb, size_t max);

#ifdef __cplusplus
}
#endif

#endif
