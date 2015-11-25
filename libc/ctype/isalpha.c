#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

// 0x20 is a well known ASCII case change bithack,
// see, for example, http://www.catonmat.net/blog/ascii-case-conversion-trick/
int __isalpha (int c)
{
    return (((unsigned)c | 0x20) - 'a') < 26;
}

int isalpha (int c) \
    _WEAK_ALIAS_OF("__isalpha");

#ifdef __cplusplus
}
#endif
