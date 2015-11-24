#include "mathimpl.h"

#ifdef __cplusplus
extern "C" {
#endif

long long int __llroundf (float x)
    _IMPLEMENT_LROUND(long long int, x)

long long int lroundf (float x)
    _WEAK_ALIAS_OF("__llroundf");

#ifdef __cplusplus
}
#endif
