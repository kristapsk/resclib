#include <stdio.h>
#include "../intern.h"
#include "doprintf.h"

#ifdef __cplusplus
extern "C" {
#endif

static void vsnprintf_helper (int character, void** outp, size_t* out_nbytes,
    int* retval)
{
    if (*out_nbytes > 0) {
        char** outc = (char**)outp;
        *(*outc)++ = character;
        (*out_nbytes)--;
        (*retval)++;
    }
}

int __vsnprintf (char* buf, size_t buf_nbytes, const char* format,
    va_list args)
{
    int num = __doprintf(buf, buf_nbytes, format, args, vsnprintf_helper);
    if (num < buf_nbytes) {
        buf[num++] = '\0';
    }
    return num;
}

int vsnprintf (char* buf, size_t buf_nbytes, const char* format,
    va_list args)
    _WEAK_ALIAS_OF("__vsnprintf");

#ifdef __cplusplus
}
#endif
