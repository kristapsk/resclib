#include "mathimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

long int __lroundl (long double x)
    _IMPLEMENT_LROUND(long int, x)

long int lroundl (long double x)
    _WEAK_ALIAS_OF("__lroundl");

#ifdef __cplusplus
}
#endif
