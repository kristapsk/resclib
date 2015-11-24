#ifdef __cplusplus
extern "C" {
#endif

extern int __puts (const char* str);

// FixMe: how to get rid of this double call? (nasm doesn't support weak syms)
#pragma weak puts
int puts (const char* str)
{
    return __puts(str);
}

#ifdef __cplusplus
}
#endif
