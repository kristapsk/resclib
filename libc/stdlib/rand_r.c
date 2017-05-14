// Simple Linear congruential generator (LCG) PRNG

#include <stdlib.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

// http://wiki.osdev.org/Random_Number_Generator#Linear_congruential_generator
#define LCG_M   (0xFFFFFFFF)
#define LCG_A   (1103515245)
#define LCG_C   (12345)

int __rand_r (unsigned int* seed)
{
    *seed = (LCG_A * *seed + LCG_C) % LCG_M;
    return __abs((int)*seed);
}

int rand_r (unsigned int* seed)
    _WEAK_ALIAS_OF("__rand_r");

#ifdef __cplusplus
}
#endif
