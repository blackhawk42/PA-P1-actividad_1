#ifndef BIGNUM_H

#define BIGNUM_H

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

Bignum sum(Bignum, Bignum);

Bignum and(Bignum, Bignum);
Bignum or(Bignum, Bignum);
Bignum xor(Bignum, Bignum);
Bignum not(Bignum);
Bignum two_c(Bignum);
Bignum ls(Bignum);
Bignum rs(Bignum);

#endif /** BIGNUM_H */
