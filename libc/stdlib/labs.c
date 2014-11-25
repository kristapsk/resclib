#include "abs.h"

#ifdef __cplusplus
extern "C" {
#endif

ABS(labs, long)

long labs (long x) _WEAK_ALIAS_OF("__labs");

#ifdef __cplusplus
}
#endif

