
include config.mk

CFLAGS += -nostdinc -I include/

BUILDDIR=build/$(CPU_ARCH)-$(OS_ARCH)
LIBC=$(BUILDDIR)/reclibc.a

all: $(BUILDIR) $(LIBC)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

LIBC_OBJS=libc/stdlib/abs.o \
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
	libc/string/wmemchr.o \
	libc/string/wmemcmp.o \
	libc/string/wmemcpy.o \
	libc/string/wmemcpy_s.o \
	libc/string/wmemmove.o \
	libc/string/wmemmove_s.o \
	libc/string/wmemset.o

$(LIBC): $(LIBC_OBJS) $(BUILDDIR)
	$(AR) cru $@ $(LIBC_OBJS)

clean:
	$(RM) $(LIBC)
	$(RM) $(LIBC_OBJS)

