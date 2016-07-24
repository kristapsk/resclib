#ifndef _CTYPE_H
#define _CTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

/*** Character classiciation functions *************************************/
int isalnum (int c);
int isalpha (int c);
int iscntrl (int c);
int isdigit (int c);
int isgraph (int c);
int islower (int c);
int isprint (int c);
int ispunct (int c);
int isspace (int c);
int isupper (int c);
int isxdigit (int c);
#if (__STDC_VERSION__ >= 199901L) || (_POSIX_C_SOURCE >= 20112L) || (_XOPEN_SOURCE >= 600)
    int isblank (int c);
#endif
#ifdef _XOPEN_SOURCE
    int isascii (int c);
#endif

/*** Character conversion functions ****************************************/
int tolower (int c);
int toupper (int c);
#if defined(_RECLIB_SOURCE) || defined(_XOPEN_SOURCE)
    #define _tolower(c) (c | 0x20)
    #define _toupper(c) (c & ~0x20)
#endif
#ifdef _XOPEN_SOURCE
    int toascii (int c);
#endif

#ifdef __cplusplus
}
#endif

#endif
