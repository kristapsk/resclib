#include <stdio.h>
#include <unistd.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __putchar (int character)
{
    if (__write(STDOUT_FILENO, &character, 1) == -1) {
        return EOF;
    }
    else {
        return character;
    }
}

int putchar (int character)
    _WEAK_ALIAS_OF("__putchar");

#ifdef __cplusplus
}
#endif
