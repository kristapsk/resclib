#ifndef _LOCALE_H
#define _LOCALE_H

#include <_null.h>

#define LC_COLLATE      (1 << 0)
#define LC_CTYPE        (1 << 1)
#define LC_MONETARY     (1 << 2)
#define LC_NUMERIC      (1 << 3)
#define LC_TIME         (1 << 4)
#define LC_ALL          \
    (LC_COLLATE | LC_CTYPE | LC_MONETARY | LC_NUMERIC | LC_TIME)

struct lconv {
    char* decimal_point;
    char* thousands_sep;
    char* grouping;
    char* int_curr_symbol;
    char* currency_symbol;
    char* mon_decimal_point;
    char* mon_thousands_sep;
    char* mon_grouping;
    char* positive_sign;
    char* negative_sign;
    char frac_digits;
    char p_cs_precedes;
    char n_cs_precedes;
    char p_sep_by_space;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
    char int_frac_digits;

    char int_p_cs_precedes;
    char int_n_cs_precedes;
    char int_p_sep_by_space;
    char int_n_sep_by_space;
    char int_p_sign_posn;
    char int_n_sign_posn;
};

#ifdef __cplusplus
extern "C" {
#endif

struct lconv* localeconv (void);
char* setlocale (int category, const char* locale);

#ifdef __cplusplus
}
#endif

#endif
