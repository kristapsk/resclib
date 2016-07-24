
include config.mk

include mkfiles/${CPU_ARCH}.mk

CFLAGS += -std=gnu11 -Wall -nostdinc -I include/ -D CPU_ARCH=$(CPU_ARCH) -D OS_ARCH=$(OS_ARCH) -fno-stack-protector 

BUILDDIR=build/$(CPU_ARCH)-$(OS_ARCH)
LIBC=$(BUILDDIR)/reclibc.a
LIBC_UNSAFE=$(BUILDDIR)/reclibc_unsafe.a
HELLO=$(BUILDDIR)/hello
SMALLEST=$(BUILDDIR)/smallest
TESTS=$(BUILDDIR)/tests

all: $(BUILDIR) libc hello smallest $(TESTS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

LIBC_OBJS= \
	libc/init.o \
	libc/ctype/isalnum.o \
	libc/ctype/isalpha.o \
	libc/ctype/isascii.o \
	libc/ctype/isblank.o \
	libc/ctype/iscntrl.o \
	libc/ctype/isdigit.o \
	libc/ctype/isgraph.o \
	libc/ctype/islower.o \
	libc/ctype/isprint.o \
	libc/ctype/ispunct.o \
	libc/ctype/isspace.o \
	libc/ctype/isupper.o \
	libc/ctype/isxdigit.o \
	libc/ctype/toascii.o \
	libc/ctype/tolower.o \
	libc/ctype/toupper.o \
	libc/locale/locale.o \
	libc/locale/setlocale.o \
	libc/math/fabs.o \
	libc/math/fabsf.o \
	libc/math/fabsl.o \
	libc/math/lround.o \
	libc/math/lroundf.o \
	libc/math/lroundl.o \
	libc/math/llround.o \
	libc/math/llroundf.o \
	libc/math/llroundl.o \
	libc/mbstr/mbschr.o \
	libc/stdio/clearerr.o \
	libc/stdio/doprintf.o \
	libc/stdio/feof.o \
	libc/stdio/ferror.o \
	libc/stdio/fgetc.o \
	libc/stdio/fgets.o \
	libc/stdio/fprintf.o \
	libc/stdio/fputc.o \
	libc/stdio/fputs.o \
	libc/stdio/getchar.o \
	libc/stdio/printf.o \
	libc/stdio/putchar.o \
	libc/stdio/puts.o \
	libc/stdio/snprintf.o \
	libc/stdio/vfprintf.o \
	libc/stdio/vprintf.o \
	libc/stdio/vsnprintf.o \
	libc/stdlib/abs.o \
	libc/stdlib/div.o \
	libc/stdlib/errno.o \
	libc/stdlib/i64toa_s.o \
	libc/stdlib/itoa_s.o \
	libc/stdlib/labs.o \
	libc/stdlib/ldiv.o \
	libc/stdlib/llabs.o \
	libc/stdlib/lldiv.o \
	libc/stdlib/mblen.o \
	libc/stdlib/ui64toa_s.o \
	libc/string/bcopy.o \
	libc/string/bzero.o \
	libc/string/memchr.o \
	libc/string/memcmp.o \
	libc/string/memcpy.o \
	libc/string/memcpy_s.o \
	libc/string/memmove.o \
	libc/string/memmove_s.o \
	libc/string/memset.o \
	libc/string/strchr.o \
	libc/string/strcmp.o \
	libc/string/stricmp.o \
	libc/string/strlen.o \
	libc/string/strncat.o \
	libc/string/strncmp.o \
	libc/string/strnicmp.o \
	libc/string/strpbrk.o \
	libc/string/strrchr.o \
	libc/string/strrev.o \
	libc/string/strspn.o \
	libc/string/strstr.o \
	libc/string/wcopy.o \
	libc/string/wcschr.o \
	libc/string/wcscmp.o \
	libc/string/wcslen.o \
	libc/string/wcsncat.o \
	libc/string/wcsncmp.o \
	libc/string/wcspbrk.o \
	libc/string/wcsrchr.o \
	libc/string/wcsrev.o \
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
	libc/time/asctime_s.o \
	libc/time/difftime.o \
	libc/time/gmtime_s.o \
	libc/time/time.o \
	libc/unistd/read.o \
	libc/unistd/write.o
# Unsafe functions
LIBC_UNSAFE_OBJS = \
	libc/stdio/sprintf.o \
	libc/stdio/vsprintf.o \
	libc/string/strcat.o \
	libc/string/strcpy.o \
	libc/string/wcscat.o \
	libc/string/wcscpy.o \
	libc/time/asctime.o \
	libc/time/gmtime.o

include libc/sys/${CPU_ARCH}-${OS_ARCH}/sys.mk

libc: $(LIBC) $(LIBC_UNSAFE)
$(LIBC): $(LIBC_OBJS) $(BUILDDIR)
	$(RM) $@
	$(AR) cq $@ $(LIBC_OBJS)
$(LIBC_UNSAFE): $(LIBC_OBJS) $(LIBC_UNSAFE_OBJS) $(BUILDDIR)
	$(RM) $@
	$(AR) cq $@ $(LIBC_OBJS) $(LIBC_UNSAFE_OBJS)

TEST_OBJS = \
	third-party/seatest/src/seatest.o \
	tests/test_all.o \
	tests/test_locale.o \
	tests/test_stdlib.o \
	tests/test_string.o \
	tests/test_time.o
$(TESTS): $(LIBC_UNSAFE) $(TEST_OBJS)
	$(LINK) $(LINK_OPTS) -o $@ $(TEST_OBJS) $(LIBC_UNSAFE) $(COMPILER_LIB)

hello: $(HELLO)
$(HELLO): $(LIBC) examples/hello.o
	$(LINK) $(LINK_OPTS) -o $@ examples/hello.o $(LIBC) $(COMPILER_LIB)

smallest: $(SMALLEST)
$(SMALLEST): $(LIBC) examples/smallest.o
	$(LINK) $(LINK_OPTS) -o $@ examples/smallest.o $(LIBC) $(COMPILER_LIB)

clean:
	$(RM) $(LIBC)
	$(RM) $(LIBC_OBJS)
	$(RM) $(LIBC_UNSAFE_OBJS)
	$(RM) $(TESTS) $(TEST_OBJS)
	$(RM) $(HELLO) examples/hello.o

