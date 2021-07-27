CC=gcc
CCFLG=-m64 -Wall -fPIC -L/usr/lib
CCC=$(CC) $(CCFLG)

ifeq ($(OS), Windows_NT)
	X=.exe
	O=.o
	DL=.dll
else
	# .exe so that .gitignore doesn't track the resulting binaries.
	X=.exe
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
ifeq ($(OS), Windows_NT)
	$(CCC) $^ -o $@
else
	$(CCC) $^ -o $@ -ldl
endif

libinjected-module$(DL): injected-module.c injected-module.h
	$(CCC) -shared $^ -o $@
