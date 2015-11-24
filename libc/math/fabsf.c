#include "mathimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

float __fabsf (float x)
    _IMPLEMENT_FABS(x)

float fabsf (float x)
    _WEAK_ALIAS_OF("__fabsf");

#ifdef __cplusplus
}
#endif
