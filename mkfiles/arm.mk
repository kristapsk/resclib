AS=$(TCHAIN_PREFIX)as

.s.o:
	$(AS) -o $@ $<

