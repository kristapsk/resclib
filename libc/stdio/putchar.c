#ifdef __cplusplus
extern "C" {
#endif

extern int __putchar (int character);

// FixMe: how to get rid of this double call? (nasm doesn't support weak syms)
#pragma weak putchar
int putchar (int character)
{
    return __putchar(character);
}

#ifdef __cplusplus
}
#endif
