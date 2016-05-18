#include <stdio.h>
#include <unistd.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __fputs (const char* str, FILE* stream)
{
    size_t len = __strlen(str);
    size_t i;
    for (i = 0; i < len; i++) {
        int res = __fputc(str[i], stream);
        if (res == EOF) {
            return res;
        }
    }
    return 0;
}

int fputs (const char* str, FILE* stream)
    _WEAK_ALIAS_OF("__fputs");

#ifdef __cplusplus
}
#endif
