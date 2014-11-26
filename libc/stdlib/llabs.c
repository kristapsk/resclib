#include "abs.h"

#ifdef __cplusplus
extern "C" {
#endif

ABS(llabs, long long)

long long llabs (long long x) _WEAK_ALIAS_OF("__llabs");

#ifdef __cplusplus
}
#endif
