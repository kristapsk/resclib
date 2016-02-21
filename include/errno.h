#ifndef _ERRNO_H
#define _ERRNO_H

#ifdef _RECLIB_SOURCE
    #include <_errno_t.h>
#endif

#define EDOM        (1)
#define ERANGE      (2)
#define EILSEQ      (3)

#define EINVAL      (4)

int* __errno_location (void);

#define errno (*__errno_location())

#endif
