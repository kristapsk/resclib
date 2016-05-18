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

void clearerr (FILE* stream);
int feof (FILE* stream);
int ferror (FILE* stream);
int fputc (int character, FILE* stream);
int fputs (const char* str, FILE* stream);
int putc (int character, FILE* stream);
int putchar (int character);
int puts (const char* str);

#endif
