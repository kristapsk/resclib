#include "mathimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

long int __lround (double x)
    _IMPLEMENT_LROUND(long int, x)

long int lround (double x)
    _WEAK_ALIAS_OF("__lround");

#ifdef __cplusplus
}
#endif
