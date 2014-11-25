#include "../intern.h"
#include <limits.h>
#include <stddef.h>

// This is a well known bithack for abs() to avoid branching.
// http://graphics.stanford.edu/~seander/bithacks.html#IntegerAbs

#define ABS(name, type) \
type __ ## name (type x) \
{ \
    type mask = x >> sizeof(type) * CHAR_BIT - 1; \
    return (x + mask) ^ mask; \
} \

