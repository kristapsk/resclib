#include <limits.h>
#include <locale.h>
#include "../intern.h"

#ifdef __cplusplus
extern "C" {
#endif

#define C_LOCALE { \
    .decimal_point = ".", \
    .thousands_sep = "", \
    .grouping = "", \
    .int_curr_symbol = "", \
    .currency_symbol = "", \
    .mon_decimal_point = "", \
    .mon_thousands_sep = "", \
    .mon_grouping = "", \
    .positive_sign = "", \
    .negative_sign = "", \
    .frac_digits = CHAR_MAX, \
    .p_cs_precedes = CHAR_MAX, \
    .n_cs_precedes = CHAR_MAX, \
    .p_sep_by_space = CHAR_MAX, \
    .n_sep_by_space = CHAR_MAX, \
    .p_sign_posn = CHAR_MAX, \
    .n_sign_posn = CHAR_MAX, \
    .int_frac_digits = CHAR_MAX, \
    .int_p_cs_precedes = CHAR_MAX, \
    .int_n_cs_precedes = CHAR_MAX, \
    .int_p_sep_by_space = CHAR_MAX, \
    .int_n_sep_by_space = CHAR_MAX, \
    .int_p_sign_posn = CHAR_MAX, \
    .int_n_sign_posn = CHAR_MAX \
}

const struct lconv __C_locale = C_LOCALE;

static struct lconv current_locale = C_LOCALE;

struct lconv* __localeconv (void)
{
    return &current_locale;
}

struct lconv* localeconv (void)
    _WEAK_ALIAS_OF("__localeconv");

#ifdef __cplusplus
}
#endif
