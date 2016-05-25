#include <stdio.h>
#include "../intern.h"
#include "doprintf.h"

#ifdef __cplusplus
extern "C" {
#endif

static void vfprintf_helper (int character, void** outp, size_t* out_nbytes,
    int* retval)
{
    FILE* stream = (FILE*)*outp;
    if (__fputc(character, stream) != EOF) {
        (*retval)++;
    }
}

int __vfprintf (FILE* stream, const char* format, va_list args)
{
    return __doprintf((void*)stream, 0, format, args, vfprintf_helper);
}

int vfprintf (FILE* stream, const char* format, va_list args)
    _WEAK_ALIAS_OF("__vfprintf");

#ifdef __cplusplus
}
#endif
