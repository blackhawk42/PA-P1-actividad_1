Para compilar los primeros dos programas:

```
gcc -o 01.exe 01.c
gcc -o 02.exe 02.c
```

Para compilar el tercer programa, se debe entrar a la
carpeta ```bignum``` (con ```cd```, por ejemplo) y
desde ahí correr:

```
gcc -c bitwise.c
gcc -c arithmetic.c
gcc -c bignum.c
ar rs libbignum.a bitwise.o arithmetic.o bignum.o
```

Esto generará un archivo llamado ```libbignum.a```. Mueva este archivo a la carpeta anterior,
vuelva a ella y desde ahí corra:

```
gcc -o 03.exe 03.c libbignum.a
```

También, si tiene la herramienta GNU Make y una shell que lo soporte, puede hacer tofo lo anterior automáticamente con correr:

```
make
```

Al final, tendrá los archivos
```
01.exe
02.exe
03.exe
```
correspondientes al número de ejercicio.
