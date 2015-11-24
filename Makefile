
include config.mk

include mkfiles/${CPU_ARCH}.mk

CFLAGS += -nostdinc -I include/ -D CPU_ARCH=$(CPU_ARCH) -D OS_ARCH=$(OS_ARCH)

BUILDDIR=build/$(CPU_ARCH)-$(OS_ARCH)
LIBC=$(BUILDDIR)/reclibc.a
HELLO=$(BUILDDIR)/hello

all: $(BUILDIR) $(LIBC) $(HELLO)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

LIBC_OBJS= \
	libc/math/fabs.o \
	libc/math/fabsf.o \
	libc/math/fabsl.o \
	libc/math/lround.o \
	libc/math/lroundf.o \
	libc/math/lroundl.o \
	libc/math/llround.o \
	libc/math/llroundf.o \
	libc/math/llroundl.o \
	libc/stdio/putchar.o \
	libc/stdio/puts.o \
	libc/stdlib/abs.o \
	libc/stdlib/labs.o \
	libc/stdlib/llabs.o \
	libc/stdlib/mblen.o \
	libc/string/bcopy.o \
	libc/string/bzero.o \
	libc/string/memchr.o \
	libc/string/memcmp.o \
	libc/string/memcpy.o \
	libc/string/memcpy_s.o \
	libc/string/memmove.o \
	libc/string/memmove_s.o \
	libc/string/memset.o \
	libc/string/strcat.o \
	libc/string/strchr.o \
	libc/string/strcmp.o \
	libc/string/strcpy.o \
	libc/string/strlen.o \
	libc/string/strncat.o \
	libc/string/strncmp.o \
	libc/string/strpbrk.o \
	libc/string/strrchr.o \
	libc/string/strspn.o \
	libc/string/strstr.o \
	libc/string/wcopy.o \
	libc/string/wcscat.o \
	libc/string/wcschr.o \
	libc/string/wcscmp.o \
	libc/string/wcscpy.o \
	libc/string/wcslen.o \
	libc/string/wcsncat.o \
	libc/string/wcsncmp.o \
	libc/string/wcspbrk.o \
	libc/string/wcsrchr.o \
	libc/string/wcsspn.o \
	libc/string/wcsstr.o \
	libc/string/wmemchr.o \
	libc/string/wmemcmp.o \
	libc/string/wmemcpy.o \
	libc/string/wmemcpy_s.o \
	libc/string/wmemmove.o \
	libc/string/wmemmove_s.o \
	libc/string/wmemset.o \
	libc/string/wzero.o \
	libc/sys/$(CPU_ARCH)-$(OS_ARCH)/crt0.o \
	libc/sys/$(CPU_ARCH)-$(OS_ARCH)/syscalls.o

$(LIBC): $(LIBC_OBJS) $(BUILDDIR)
	$(AR) cru $@ $(LIBC_OBJS)

$(HELLO): $(LIBC) hello.o
	$(LINK) $(LINK_OPTS) -o $@ hello.o $(LIBC)

clean:
	$(RM) $(LIBC)
	$(RM) $(LIBC_OBJS)
	$(RM) $(HELLO) hello.o

