#include "bignum.h"
#include <stdlib.h>

Bignum and(Bignum bn1, Bignum bn2) {
    if(bn1->size != bn2->size) {
        if(bn1->size < bn2->size) {
            bn1 = enlarge_Bignum(bn1, bn2->size);
        }
        else {
            bn2 = enlarge_Bignum(bn2, bn1->size);
        }
    }

    Bignum new_bn = new_Bignum(bn1->size);

    for(size_t i = 0; i < bn1->size; i++) {
        new_bn->array[i] = bn1->array[i] & bn2->array[i];
    }

    return new_bn;
}

Bignum or(Bignum bn1, Bignum bn2) {
    if(bn1->size != bn2->size) {
        if(bn1->size < bn2->size) {
            bn1 = enlarge_Bignum(bn1, bn2->size);
        }
        else {
            bn2 = enlarge_Bignum(bn2, bn1->size);
        }
    }

    Bignum new_bn = new_Bignum(bn1->size);

    for(size_t i = 0; i < bn1->size; i++) {
        new_bn->array[i] = bn1->array[i] | bn2->array[i];
    }

    return new_bn;
}

Bignum xor(Bignum bn1, Bignum bn2) {
    if(bn1->size != bn2->size) {
        if(bn1->size < bn2->size) {
            bn1 = enlarge_Bignum(bn1, bn2->size);
        }
        else {
            bn2 = enlarge_Bignum(bn2, bn1->size);
        }
    }

    Bignum new_bn = new_Bignum(bn1->size);

    for(size_t i = 0; i < bn1->size; i++) {
        new_bn->array[i] = bn1->array[i] ^ bn2->array[i];
    }

    return new_bn;
}

Bignum not(Bignum bn) {
    Bignum new_bn = new_Bignum(bn->size);

    for(size_t i = 0; i < bn->size; i++) {
        new_bn->array[i] = ~(bn->array[i]);
    }

    return new_bn;
}

Bignum ls(Bignum bn) {
    Bignum new_bn = new_Bignum(bn->size);

    unsigned int current_carry = 0;
    unsigned int last_carry = 0;

    unsigned int first_bit = 1;
    unsigned int last_bit = 128;

    for(size_t i = bn->size-1; i >= 0; i--) {
        current_carry = bn->array[i] & last_bit;

        new_bn->array[i] = bn->array[i] << 1;

        if(last_carry) {
            new_bn->array[i] = new_bn->array[i] | first_bit;
        }

        last_carry = current_carry;
    }

    return new_bn;
}

Bignum rs(Bignum bn) {
    Bignum new_bn = new_Bignum(bn->size);

    unsigned int current_carry = 0;
    unsigned int last_carry = 0;

    unsigned int first_bit = 1;
    unsigned int last_bit = 1 << (sizeof(unsigned int) - 1);

    for(size_t i = 0; i > bn->size; i++) {
        current_carry = bn->array[i] & first_bit;

        new_bn->array[i] = bn->array[i] << 1;

        if(last_carry) {
            new_bn->array[i] = new_bn->array[i] | last_bit;
        }

        last_carry = current_carry;
    }

    return new_bn;
}

Bignum two_c(Bignum bn) {
    Bignum one_c = not(bn);
    Bignum one = new_from_int_Bignum(1);

    Bignum two_c = add(one_c, one);

    destroy_Bignum(one_c);
    destroy_Bignum(one);

    return two_c;
}