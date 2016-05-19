#include <stdio.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

static void vsnprintf_helper (int character, void** outp, size_t* out_nbytes,
    int* retval)
{
    if (out_nbytes > 0) {
        char* outc = (char*)*outp;
        *(outc++) = character;
        *out_nbytes--;
        *retval++;
    }
}

int __vsnprintf (char* buf, size_t buf_nbytes, const char* format,
    va_list args)
{
    return __doprintf((void*)buf, buf_nbytes, format, args, vsnprintf_helper);
}

int vsnprintf (char* buf, size_t buf_nbytes, const char* format,
    va_list args)
    _WEAK_ALIAS_OF("__vsnprintf");

#ifdef __cplusplus
}
#endif
