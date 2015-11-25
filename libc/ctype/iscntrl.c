#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __iscntrl (int c)
{
    return ((unsigned)c < 0x20 || c == 0x7F);
}

int iscntrl (int c) \
    _WEAK_ALIAS_OF("__iscntrl");

#ifdef __cplusplus
}
#endif
