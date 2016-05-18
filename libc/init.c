#include <stdio.h>
#include <unistd.h>
#include "intern.h"

FILE* stdin;
FILE* stdout;
FILE* stderr;
char** __envp;

extern int main (int argc, char** argv);

int __libc_init (int argc, char** argv, char** envp)
{
    __envp = envp;

    // "static" should be enough to zero out data structures by default.
    static FILE stdin_file;
    stdin_file.fd = STDIN_FILENO;
    stdin = &stdin_file;
    static FILE stdout_file;
    stdout_file.fd = STDOUT_FILENO;
    stdout = &stdout_file;
    static FILE stderr_file;
    stderr_file.fd = STDERR_FILENO;
    stderr = &stderr_file;

    return main(argc, argv);
}
