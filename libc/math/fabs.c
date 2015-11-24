#include "mathimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

double __fabs (double x)
    _IMPLEMENT_FABS(x)

double fabs (double x)
    _WEAK_ALIAS_OF("__fabs");

#ifdef __cplusplus
}
#endif
