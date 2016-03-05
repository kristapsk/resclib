AS=$(TCHAIN_PREFIX)as

# For ARM Cortex-Mx cores, supporting only Thumb instruction sets.
CFLAGS += -mthumb

.s.o:
	$(AS) -o $@ $<

