CC=gcc
CFLAGS=

DISTDIR=dists/
ZIPFILE=actividad_1.zip

README=README.md

.PHONY: all dist clean run

all: 01.exe 02.exe 03.exe

01.exe: 01.c
	gcc -o $@ 01.c

02.exe: 02.c
	gcc -o $@ 02.c

bignum/arithmetic.o: bignum/arithmetic.c
	gcc -o $@ -c bignum/arithmetic.c

bignum/bitwise.o: bignum/bitwise.c
	gcc -o $@ -c bignum/bitwise.c

bignum/bignum.o: bignum/bignum.c
	gcc -o $@ -c bignum/bignum.c

libbignum.a: bignum/arithmetic.o bignum/bitwise.o bignum/bignum.o bignum/bignum.h
	ar rs $@ bignum/arithmetic.o bignum/bitwise.o bignum/bignum.o

03.exe: 03.c libbignum.a
	gcc -o $@ 03.c libbignum.a

$(DISTDIR):
	mkdir -p $(DISTDIR)


dist: $(SOURCES) | $(DISTDIR)
	rm -rf $(DISTDIR)*
	zip $(DISTDIR)$(ZIPFILE) *.c *.h bignum/*.c bignum/*.h Makefile

clean:
	rm -rf bignum/*.o *.o *.a *.exe $(DISTDIR)
