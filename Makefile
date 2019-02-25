CC=gcc
CFLAGS=

DISTDIR=dists/
ZIPFILE=actividad_1.zip

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(wildcard *.h)
EXES=$(SOURCES:.c=.exe)

README=README.md

.PHONY: all dist clean run

all: $(EXES)

$(EXES): %.exe: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<

$(DISTDIR):
	mkdir -p $(DISTDIR)


dist: $(SOURCES) | $(DISTDIR)
	rm -rf $(DISTDIR)*
	zip $(DISTDIR)$(ZIPFILE) $(SOURCES) $(HEADERS) $(README) Makefile

clean:
	rm -rf $(EXES) $(DISTDIR)
