#ifndef _STRINGS_H
#define _STRINGS_H

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

void bcopy (const void* ptr1, void* ptr2, size_t nbytes);
void bzero (void* dest, size_t nbytes);
int strcasecmp (const char* str1, const char* str2);
int strncasecmp (const char* str1, const char* str2, size_t num);

// Extensions
#if defined(_RESCLIB_SOURCE)
    void wcopy (const wchar_t* ptr1, wchar_t* ptr2, size_t num); 
    void wzero (wchar_t* dest, size_t num);
#endif

#ifdef __cplusplus
}
#endif

#endif
