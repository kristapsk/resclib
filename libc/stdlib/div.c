#include "stdimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

div_t __div (int numer, int denom)
    _IMPLEMENT_DIV(div_t, numer, denom)

div_t div (int number, int denom)
    _WEAK_ALIAS_OF("__div");

#ifdef __cplusplus
}
#endif
