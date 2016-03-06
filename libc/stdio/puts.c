#include <stdio.h>
#include <unistd.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __puts (const char* str)
{
    size_t len = __strlen(str);
    if (__write(STDOUT_FILENO, str, len) == -1) {
        return EOF;
    }
    if (__write(STDOUT_FILENO, "\n", 1) == -1) {
        return EOF;
    }
    return 1;
}

int puts (const char* str)
    _WEAK_ALIAS_OF("__puts");

#ifdef __cplusplus
}
#endif
