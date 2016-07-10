#include <stdio.h>
#include "../intern.h"
#include "doprintf.h"

#ifdef __cplusplus
extern "C" {
#endif

static void vsprintf_helper (int character, void** outp, size_t* out_nbytes,
    int* retval)
{
    char** outc = (char**)outp;
    *(*outc)++ = character;
    (*retval)++;
}

int __vsprintf (char* buf, const char* format, va_list args)
{
    int num = __doprintf(buf, 0, format, args, vsprintf_helper);
    buf[num++] = '\0';
    return num;
}

int vsprintf (char* buf, const char* format, va_list args)
    _WEAK_ALIAS_OF("__vsprintf");

#ifdef __cplusplus
}
#endif
