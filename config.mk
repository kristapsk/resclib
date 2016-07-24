CPU_ARCH=x86_64
#OS_ARCH=none
OS_ARCH=linux

TCHAIN_PREFIX=
CC=$(TCHAIN_PREFIX)gcc
AR=$(TCHAIN_PREFIX)ar
LINK=$(TCHAIN_PREFIX)ld
RM=rm -f
MKDIR=mkdir -p

# This may be needed for some architectures, for example i386.
# Configure this, if you have errors like this when building examples, tests:
#	build/i386-linux/resclibc.a(lldiv.o): In function `__lldiv':
#	lldiv.c:(.text+0x3b): undefined reference to `__divdi3'
#	lldiv.c:(.text+0x61): undefined reference to `__moddi3'
# Example: /usr/lib64/gcc/x86_64-pc-linux-gnu/4.7.3/32/libgcc.a
COMPILER_LIB=

