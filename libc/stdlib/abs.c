#include "abs.h"

#ifdef __cplusplus
extern "C" {
#endif

ABS(abs, int)

int abs (int x) _WEAK_ALIAS_OF("__abs");

#ifdef __cplusplus
}
#endif

// TODO test:
//  abs(0) == 0
//  abs(1) > 0
//  abs(INT_MAX) > 0
//  abs(-1) < 0
//  abs(INT_MIN) < 0

