#include <stdio.h>
#include <unistd.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

int __fputc (int character, FILE* stream)
{
    // TODO: buffering must be implemented here
    if (__write(stream->fd, &character, 1) == -1) {
        stream->indicators |= _FILE_IND_ERROR;
        return EOF;
    }
    return character;
}

int fputc (int character, FILE* stream)
    _WEAK_ALIAS_OF("__fputc");
int putc (int character, FILE* stream)
    _WEAK_ALIAS_OF("__fputc");

#ifdef __cplusplus
}
#endif
