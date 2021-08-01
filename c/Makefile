CC=gcc
CCFLG=-m64 -Wall -fPIC -L/usr/lib -I/usr/include
CCC=$(CC) $(CCFLG)

PKGCONF=pkg-config
PKGCONFFLG=--cflags --libs
PKGCONFC=$(PKGCONF) $(PKGCONFFLG)

LIBGLIB=glib-2.0

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


.PHONY: all clean

clean:
	rm -f *.exe *.dll *.o *.so

all: clstty$(X) popen$(X) injected-app$(X) libinjected-module$(DL)
all: glib-glist$(X) glib-gslist$(X) argp$(X)


clstty$(X): clstty.c
	$(CCC) $^ -o $@

popen$(X): popen.c
	$(CCC) $^ -o $@

injected-app$(X): injected-app.c
ifeq ($(OS), Windows_NT)
	$(CCC) $^ -o $@ -ldl
else
	$(CCC) $^ -o $@ -ldl
endif

libinjected-module$(DL): injected-module.c injected-module.h
	$(CCC) -shared $^ -o $@

glib-glist$(X): glib-glist.c
	$(CCC) $^ -o $@ $$($(PKGCONFC) $(LIBGLIB))

glib-gslist$(X): glib-gslist.c
	$(CCC) $^ -o $@ $$($(PKGCONFC) $(LIBGLIB))

argp$(X): argp.c
	$(CCC) $^ -o $@ -largp
