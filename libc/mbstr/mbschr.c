#include <mbstr.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

char* __mbschr (char* str, mbchar_t c)
{
    return (c < 0x80 ? __strchr(str, c) : __strstr(str, (const char*)&c));
}

char* mbschr (char* str, mbchar_t c) \
    _WEAK_ALIAS_OF("__mbschr");

#ifdef __cplusplus
}
#endif
