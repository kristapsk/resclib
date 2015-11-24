#include "mathimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

long long int __lroundll (long double x)
    _IMPLEMENT_LROUND(long long int, x)

long long int lroundll (long double x)
    _WEAK_ALIAS_OF("__lroundll");

#ifdef __cplusplus
}
#endif
