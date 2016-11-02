#include <inttypes.h>
#include "stdimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

lldiv_t __lldiv (long long numer, long long denom)
    _IMPLEMENT_DIV(lldiv_t, numer, denom)

lldiv_t lldiv (long long number, long long denom)
    _WEAK_ALIAS_OF("__lldiv");

imaxdiv_t imaxdiv (intmax_t number, intmax_t denom)
    _WEAK_ALIAS_OF("__lldiv");

#ifdef __cplusplus
}
#endif
