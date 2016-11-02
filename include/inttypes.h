#ifndef _INTTYPES_H
#define _INTTYPES_H

#include <stdint.h>

typedef struct {
    intmax_t quot;
    intmax_t rem;
} imaxdiv_t;

#ifdef __cplusplus
extern "C" {
#endif

intmax_t imaxabs (intmax_t n);
imaxdiv_t imaxdiv (intmax_t number, intmax_t denom);

#ifdef __cplusplus
}
#endif

#endif
