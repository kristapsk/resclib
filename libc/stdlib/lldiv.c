#include <inttypes.h>
#include "stdimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

lldiv_t __lldiv (long long numer, long long denom)
    _IMPLEMENT_DIV(lldiv_t, numer, denom)

lldiv_t lldiv (long long number, long long denom)
    _WEAK_ALIAS_OF("__lldiv");

// intmax_t is the same as long long, silent GCC8 incompatible type warning
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattribute-alias"
imaxdiv_t imaxdiv (intmax_t number, intmax_t denom)
    _WEAK_ALIAS_OF("__lldiv");
#pragma GCC diagnostic pop

#ifdef __cplusplus
}
#endif
