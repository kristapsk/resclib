#include "mathimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

long long int __llround (double x)
    _IMPLEMENT_LROUND(long long int, x)

long long int llround (double x)
    _WEAK_ALIAS_OF("__llround");

#ifdef __cplusplus
}
#endif
