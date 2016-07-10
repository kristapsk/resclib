#include <stdio.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __getchar (void)
{
    return __fgetc(stdin);
}

int getchar (void)
    _WEAK_ALIAS_OF("__getchar");

#ifdef __cplusplus
}
#endif
