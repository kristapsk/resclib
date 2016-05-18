#include <stdio.h>
#include <unistd.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __putchar (int character)
{
    return __fputc(character, stdout);
}

int putchar (int character)
    _WEAK_ALIAS_OF("__putchar");

#ifdef __cplusplus
}
#endif
