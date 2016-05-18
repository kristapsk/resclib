#ifndef __INTERN_H
#define __INTERN_H

#define _RECLIB_SOURCE

#include <_errno_t.h>
#include <_ssize_t.h>
#include <stddef.h>
#include <stdio.h>

#ifdef __GNUC__

#define _ALIAS_OF(x) __attribute__ ((alias (x)))
#define _WEAK_ALIAS_OF(x) __attribute__ ((weak, alias (x)))
#define _TYPE_ALIGN(x) __attribute__ ((aligned (x)))

#endif

// Library functions used by other library functions should be defined here
// with their canonical names. Weak aliases may be overriden by application.

#ifdef __cplusplus
extern "C" {
#endif

int __abs (int x);
long long __llabs (long long x);
void __bzero (void* dest, size_t nbytes);
int __fputc (int character, FILE* stream);
int __fputs (const char* str, FILE* stream);
int __isalnum (int c);
int __isalpha (int c);
int __isdigit (int c);
int __isgraph (int c);
void* __memcpy (void* dest, const void* source, size_t nbytes);
void* __memmove (void* dest, const void* source, size_t nbytes);
void* __memset (void* dest, int c, size_t nbytes);
errno_t ___set_errno (int value);
char* __strchr (const char* str, int c);
size_t __strlen (const char* str);
int __strncmp (const char* str1, const char* str2, size_t num);
char* __strrev (char* str);
char* __strstr (char* str1, const char* str2);
wchar_t* __wcschr (const wchar_t* str, wchar_t c);
size_t __wcslen (const wchar_t* str);
int __wcsncmp (const wchar_t* str1, const wchar_t* str2, size_t num);
wchar_t* __wcsrev (wchar_t* str);
wchar_t* __wmemcpy (wchar_t* dest, const wchar_t* source, size_t num);
wchar_t* __wmemmove (wchar_t* dest, const wchar_t* source, size_t num);
wchar_t* __wmemset (wchar_t* dest, wchar_t c, size_t num);
ssize_t __write (int fd, const void* buf, size_t nbytes);
void __wzero (wchar_t* dest, size_t num);

#ifdef __cplusplus
}
#endif

#endif
