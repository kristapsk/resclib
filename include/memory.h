#ifndef _MEMORY_H
#define _MEMORY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void* memchr (const void* str, int c, size_t nbytes);
int memcmp (const void* str1, const void* str2, size_t nbytes);
void* memcpy (void* dest, const void* source, size_t nbytes);
void* memmove (void* dest, const void* source, size_t nbytes);
void* memset (void* dest, int c, size_t nbytes);

#if (__STDC_VERSION__ >= 201112L)
    #include <_errno_t.h>
    errno_t memcpy_s
        (void* dest, size_t dest_nbytes, const void* src, size_t num);
    errno_t memmove_s
        (void* dest, size_t dest_nbytes, const void* src, size_t num);
#endif

#ifdef __cplusplus
}
#endif

#endif
