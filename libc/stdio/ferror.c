#include <stdio.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __ferror (FILE* stream)
{
    //assert(stream != NULL);
    return stream->indicators & _FILE_IND_ERROR;
}

int ferror (FILE* stream)
    _WEAK_ALIAS_OF("__ferror");

#ifdef __cplusplus
}
#endif
