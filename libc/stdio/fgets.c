#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __fgets (char* str, int num, FILE* stream)
{
    char* ptr = str;
    while (num-- > 1) {
        char c = __fgetc(stream);
        if (c == EOF) {
            break;
        }
        *ptr++ = c;
    }
    if (ptr != str) {
        *ptr = '\0';
        return str;
    }
    else {
        return NULL;
    }
}

char* fgets (char* str, int num, FILE* stream)
    _WEAK_ALIAS_OF("__fgets");

#ifdef __cplusplus
}
#endif
