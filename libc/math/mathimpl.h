#ifndef _MATHIMPL_H
#define _MATHIMPL_H

#include "../intern.h"

#define _IMPLEMENT_FABS(x) \
{ \
    return (x < 0 ? -x : x); \
}

#define _IMPLEMENT_LROUND(type, x) \
{ \
    type intpart = x; \
    x -= intpart; \
    if (x >= 0.5) { \
        intpart++; \
    } \
    return intpart; \
}

#endif
