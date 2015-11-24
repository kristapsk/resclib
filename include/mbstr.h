#ifndef _MBSTR_H
#define _MBSTR_H

typedef unsigned long long mbchar_t;

#ifdef __cplusplus
extern "C" {
#endif

char* mbschr (char* str, mbchar_t c);

#ifdef __cplusplus
}
#endif

#endif
