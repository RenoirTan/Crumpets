ifeq ($(OS), Windows_NT)
	X=.exe
	O=.o
	DL=.dll
	ASFLG=-f win32
	LDFLG=-m i386pe
else
	# .exe so that .gitignore doesn't track the resulting binaries.
	X=.exe
	O=.o
	DL=.so
	ASFLG=-f elf32
	LDFLG=-m elf_i386
endif

AS=nasm
ASC=$(AS) $(ASFLG)

LD=ld
LDC=$(LD) $(LDFLG)

.PHONY: all clean

clean:
	rm -f *.exe *.dll *.o *.so

all: hello$(X) control-flow$(X) strlen$(X)

utils$(O): utils.s
	$(ASC) $^ -o $@

hello$(X): hello$(O)
	$(LDC) $^ -o $@

hello$(O): hello.s
	$(ASC) $^ -o $@

control-flow$(X): control-flow$(O)
	$(LDC) $^ -o $@

control-flow$(O): control-flow.s
	$(ASC) $^ -o $@

strlen$(O): strlen.s
	$(ASC) $^ -o $@

strlen$(X): strlen$(O) utils$(O)
	$(LDC) $^ -o $@
