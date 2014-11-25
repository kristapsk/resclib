#ifndef __INTERN_H
#define __INTERN_H

#include <stddef.h>

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

void* __memcpy (void* dest, const void* source, size_t nbytes);
void* __memmove (void* dest, const void* source, size_t nbytes);
void* __memset (void* dest, int c, size_t nbytes);

#ifdef __cplusplus
}
#endif

#endif
