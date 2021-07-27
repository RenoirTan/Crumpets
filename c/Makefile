CC=gcc
CCFLG=-m64 -Wall -fPIC -L/usr/lib
CCC=$(CC) $(CCFLG)

ifeq ($(OS), Windows_NT)
	X=.exe
	O=.o
	DL=.dll
else
	X=
	O=.o
	DL=.so
endif


.PHONY: all

all: clstty$(X) popen$(X) injected-app$(X) libinjected-module$(DL)


clstty$(X): clstty.c
	$(CCC) $^ -o $@

popen$(X): popen.c
	$(CCC) $^ -o $@

injected-app$(X): injected-app.c
	$(CCC) $^ -o $@

libinjected-module$(DL): injected-module.c injected-module.h
	$(CCC) -shared $^ -o $@
