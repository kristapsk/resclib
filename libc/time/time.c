#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

extern time_t __time (time_t* timer);

#pragma weak time
time_t time (time_t* timer)
{
    return __time(timer);
}

#ifdef __cplusplus
}
#endif
