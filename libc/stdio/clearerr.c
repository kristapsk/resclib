#include <stdio.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

void __clearerr (FILE* stream)
{
    //assert(stream != NULL);
    stream->indicators = 0;
}

void clearerr (FILE* stream)
    _WEAK_ALIAS_OF("__clearerr");

#ifdef __cplusplus
}
#endif
