#ifndef BIGNUM_H

#define BIGNUM_H

#include <stdlib.h>

typedef struct
{
    size_t size;
    unsigned int *array;
} Bignum_s, *Bignum;

Bignum new_Bignum(size_t);
Bignum new_from_int_Bignum(unsigned int);
void destroy_Bignum(Bignum);
Bignum enlarge_Bignum(Bignum, size_t);
int to_bool(Bignum);
void print_as_binary(Bignum);

Bignum sum(Bignum, Bignum);

Bignum and(Bignum, Bignum);
Bignum or(Bignum, Bignum);
Bignum xor(Bignum, Bignum);
Bignum not(Bignum);
Bignum two_c(Bignum);
Bignum ls(Bignum);
Bignum rs(Bignum);

Bignum add(Bignum, Bignum);

Bignum Bignum_fibonacci(unsigned int, size_t);

#endif /** BIGNUM_H */
