#include "stdimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

ldiv_t __ldiv (long numer, long denom)
    _IMPLEMENT_DIV(ldiv_t, numer, denom)

ldiv_t ldiv (long number, long denom)
    _WEAK_ALIAS_OF("__ldiv");

#ifdef __cplusplus
}
#endif
