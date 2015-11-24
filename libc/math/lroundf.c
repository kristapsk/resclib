#include "mathimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

long int __lroundf (float x)
    _IMPLEMENT_LROUND(long int, x)

long int lroundf (float x)
    _WEAK_ALIAS_OF("__lroundf");

#ifdef __cplusplus
}
#endif
