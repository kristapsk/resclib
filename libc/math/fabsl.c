#include "mathimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

long double __fabsl (long double x)
    _IMPLEMENT_FABS(x)

long double fabsl (long double x)
    _WEAK_ALIAS_OF("__fabsl");

#ifdef __cplusplus
}
#endif
