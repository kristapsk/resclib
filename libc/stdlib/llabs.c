#include "stdimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

long long __llabs (long long x)
    _IMPLEMENT_ABS(long long, x)

long long llabs (long long x)
    _WEAK_ALIAS_OF("__llabs");

#ifdef __cplusplus
}
#endif

