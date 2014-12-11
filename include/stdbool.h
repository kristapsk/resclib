#ifndef _STDBOOL_H
#define _STDBOOL_H

#ifndef __cplusplus

#if (__STDC_VERSION__ < 199901L) && (__GNUC__ < 3)
typedef signed char _Bool;
#endif

#define bool _Bool
#define true 1
#define false 0

#endif

#define __bool_true_false_are_defined 1

#endif
