#ifndef __PORTAB_H
#define __PORTAB_H

#ifdef __GNUC__
    #if __x86_64__ || __ppc64__
        #define __WORDSIZE 64
    #else
        #define __WORDSIZE 32
    #endif
#endif

#endif
