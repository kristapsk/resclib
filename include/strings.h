#ifndef _STRINGS_H
#define _STRINGS_H

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

void bcopy (const void* ptr1, const void* ptr2, size_t nbytes);
void bzero (void* dest, size_t nbytes);

#ifdef __cplusplus
}
#endif

#endif
