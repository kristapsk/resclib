#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __fgetc (FILE* stream)
{
    char c;
    if (__read(stream->fd, &c, 1) == -1) {
        stream->indicators |= _FILE_IND_ERROR;
        return EOF;
    }
    return c;
}

int fgetc (FILE* stream)
    _WEAK_ALIAS_OF("__fgetc");
int getc (FILE* stream)
    _WEAK_ALIAS_OF("__fgetc");

#ifdef __cplusplus
}
#endif
