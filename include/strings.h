#ifndef _STRINGS_H
#define _STRINGS_H

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

void bcopy (const void* ptr1, void* ptr2, size_t nbytes);
void bzero (void* dest, size_t nbytes);

// Extensions
#if defined(_RECLIB_SOURCE)
void wcopy (const wchar_t* ptr1, wchar_t* ptr2, size_t num); 
void wzero (wchar_t* dest, size_t num);
#endif

#ifdef __cplusplus
}
#endif

#endif
