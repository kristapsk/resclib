#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../intern.h"
#include "doprintf.h"

// Partially based on a public domain code
// http://pages.cs.wisc.edu/~klingens/files/rprintf.c

static void outstring (const char* str,
    bool pad_left_flag, char pad_char, size_t pad_num, size_t width_num,
    void** outp, size_t* nbytes, int* retval,
    doprintf_helper_func_t outchar)
{
    size_t len = __strlen(str);
    size_t pad_count = 0;
    size_t i;
    if (pad_num > len) {
        pad_count = pad_num - len;
    }
    if (!pad_left_flag) {
        for (i = 0; i < pad_count; i++) {
            outchar(pad_char, outp, nbytes, retval);
        }
    }
    for (i = 0; i < len; i++) {
        outchar(str[i], outp, nbytes, retval);
        if (--width_num <= 0) {
            break;
        }
    }
    if (pad_left_flag) {
        for (i = 0; i < pad_count; i++) {
            outchar(pad_char, outp, nbytes, retval);
        }
    }
}

static int getnum (const char** str)
{
    int n = 0;
    const char* cp = *str;
    while (__isdigit(*cp)) {
        n = n * 10 + ((*cp++) - '0');
    }
    *str = cp;
    return n;
}

int __doprintf (void* outp, size_t nbytes, const char* format, va_list args,
    doprintf_helper_func_t outchar)
{
    int retval = 0;
    bool left_flag;
    bool sign_flag;
    bool space_flag;
    char pad_char;
    size_t width_num;
    bool dot_flag;
    size_t precision_num;
    char ch;

    for (; *format; format++) {
        // just output until control character is found
        if (*format != '%') {
            outchar(*format, &outp, &nbytes, &retval);
            continue;
        }
        // process format
        left_flag = false;
        sign_flag = false;
        space_flag = false;
        dot_flag = false;
        pad_char = ' ';
        width_num = 0;
        precision_num = INT_MAX;

try_next: 
        ch = *(++format);

        if (__isdigit(ch)) {
            if (dot_flag) {
                precision_num = getnum(&format);
            }
            else {
                if (ch == '0') {
                    pad_char = '0';
                }
                width_num = getnum(&format);
            }
            format--;
            goto try_next;
        }

        switch (ch) {
            case '%':
                outchar('%', &outp, &nbytes, &retval);
                continue;
            case '-':
                left_flag = true;
                break;
            case '+':
                sign_flag = true;
                break;
            case ' ':
                space_flag = true;
                break;
            case '.':
                dot_flag = true;
                break;
            case 'l':
                // long flag - ignore for now
                break;
            case 'd':
            case 'i':
            case 'o':
            case 'x':
            case 'X':
            case 'u': {
                int radix;
                if (ch == 'o') {
                    radix = 8;
                }
                else if (ch == 'x' || ch == 'X') {
                    radix = 16;
                }
                else {
                    radix = 10;
                }
                char numbuf[21]; // enough for a biggest 64-bit number
                int num = va_arg(args, int);
                if (precision_num == 0 && num == 0) {
                    continue;
                }
                if (ch == 'u') {
                    num = __abs(num);
                }
                ___itoa_s(num, numbuf, sizeof(numbuf), radix);
                if (ch == 'x') {
                    size_t i;
                    for (i = 0; i < __strlen(numbuf); i++) {
                        numbuf[i] = __tolower(numbuf[i]);
                    }
                }
                if (sign_flag && num >= 0) {
                    outchar('+', &outp, &nbytes, &retval);
                }
                else if (space_flag && num >= 0) {
                    outchar(' ', &outp, &nbytes, &retval);
                }
                if ((precision_num > width_num) && (precision_num < INT_MAX)) {
                    width_num = precision_num;
                }
                outstring(numbuf, left_flag, pad_char, width_num, INT_MAX,
                    &outp, &nbytes, &retval, outchar);
                continue;
            }
            case 'c':
                outchar(va_arg(args, int), &outp, &nbytes, &retval);
                continue;
            case 's':
                outstring(va_arg(args, char*), left_flag, pad_char, width_num,
                    precision_num, &outp, &nbytes, &retval, outchar);
                continue;
            default:
                continue;
        }
        goto try_next;
    }
    
    return retval;
}
