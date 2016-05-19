#ifndef _STDIO_H
#define _STDIO_H

#include <_va_list.h>
#include <stddef.h>

#define EOF (-1)

#define _FILE_IND_EOF   (1 << 0)
#define _FILE_IND_ERROR (1 << 1)

typedef struct {
    int fd;
    char indicators;
} FILE;

extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

#ifdef __cplusplus
extern "C" {
#endif

/*** Formatted input/output ************************************************/
int fprintf (FILE* stream, const char* format, ...);
int printf (const char* format, ...);
int snprintf (char* buf, size_t buf_nbytes, const char* format, ...);
int vfprintf (FILE* stream, const char* format, va_list args);
int vprintf (const char* format, va_list args);
int vsnprintf (char* buf, size_t buf_nbytes, const char* format,
    va_list args);

/*** Character input/output ************************************************/
int fputc (int character, FILE* stream);
int fputs (const char* str, FILE* stream);
int putc (int character, FILE* stream);
int putchar (int character);
int puts (const char* str);

/*** Error-handling ********************************************************/
void clearerr (FILE* stream);
int feof (FILE* stream);
int ferror (FILE* stream);

#ifdef __cplusplus
}
#endif

#endif
