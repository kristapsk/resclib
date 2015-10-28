CFLAGS += -m32
LINK_OPTS += -m elf_i386

.s.o:
	nasm -f elf -o $@ $<

