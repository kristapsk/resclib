#include <stdio.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __feof (FILE* stream)
{
    //assert(stream != NULL);
    return stream->indicators & _FILE_IND_EOF;
}

int feof (FILE* stream)
    _WEAK_ALIAS_OF("__feof");

#ifdef __cplusplus
}
#endif
