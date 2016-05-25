#ifndef _LIBC_STDIO_DOPRINTF
#define _LIBC_STDIO_DOPRINTF

typedef void (*doprintf_helper_func_t)
    (int character, void** outp, size_t* out_nbytes, int* retval);

int __doprintf (void* outp, size_t nbytes, const char* format, va_list args,
    doprintf_helper_func_t outchar);

#endif
