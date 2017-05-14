#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

static unsigned int r_seed;

int __rand (void)
{
    return __rand_r(&r_seed);
}

int rand (void)
    _WEAK_ALIAS_OF("__rand");

void __srand (unsigned int seed)
{
    r_seed = seed;
}

void srand (unsigned int seed)
    _WEAK_ALIAS_OF("__srand");

#ifdef __cplusplus
}
#endif
