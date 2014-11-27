#ifndef __STDIMPL_H
#define __STDIMPL_H

#include "../intern.h"
#include <limits.h>

// This is a well known bithack for abs() to avoid branching.
// http://graphics.stanford.edu/~seander/bithacks.html#IntegerAbs
#define _IMPLEMENT_ABS(type) \
{ \
    type mask = x >> sizeof(type) * CHAR_BIT - 1; \
    return (x + mask) ^ mask; \
} 

#endif
