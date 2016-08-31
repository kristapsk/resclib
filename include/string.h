#ifndef _STRING_H
#define _STRING_H

#include <memory.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

char* strchr (const char* str, int character);
char* strrchr (const char* str, int character);
size_t strcspn (const char* str1, const char* str2);
int strcmp (const char* str1, const char* str2);
size_t strlen (const char* str);
char* strncat (char* destination, const char* source, size_t num);
int strncmp (const char* str1, const char* str2, size_t num);
char* strncpy (char* destination, const char* source, size_t num);
char* strpbrk (const char* str1, const char* str2);
size_t strspn (const char* str1, const char* str2);
char* strstr (const char* str1, const char* str2 );

#ifdef _RESCLIB_SOURCE
    char* strrev (char* str);
    int _stricmp (const char* str1, const char* str2);
    int _strnicmp (const char* str1, const char* str2, size_t num);
#else
// unsafe
    char* strcat (char* dest, const char* src);
    char* strcpy (char* destination, const char* source);
#endif

#ifdef __cplusplus
}
#endif

#endif
