#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

Bignum new_Bignum(size_t init_size) {
    Bignum bn = (Bignum)malloc(sizeof(Bignum_s));

    bn->size = init_size;
    bn->array = (unsigned int *)malloc(sizeof(unsigned int) * init_size);

    return bn;
}

Bignum new_from_int_Bignum(unsigned int i) {
    Bignum bn = new_Bignum(1);

    bn->array[bn->size-1] = i;

    return bn;
}

void destroy_Bignum(Bignum bn) {
    free(bn->array);
    free(bn);
}

Bignum enlarge_Bignum(Bignum bn, size_t new_size) {
    if(bn->size >= new_size) {
        return bn;
    }

    size_t zeroes = new_size - bn->size;

    Bignum new_bn = new_Bignum(new_size);

    for(size_t new_i = zeroes, old_i = 0; new_i < new_bn->size; new_i++, old_i++) {
        new_bn->array[new_i] = bn->array[old_i++];
    }

    for(size_t i = 0; i < zeroes; i++) {
        new_bn->array[i] = 0;
    }

    return new_bn;
}

int to_bool(Bignum bn) {
    for(size_t i = 0; i < bn->size; i++) {
        if(bn->array[i]) {
            return 1;
        }
    }

    return 0;
}

void print_as_binary(Bignum bn) {
    int leading_zeroes = 1;

    for(size_t i = 0; i < bn->size; i++) {
        for(unsigned int current_bit = 2147483648;
        current_bit;
        current_bit = current_bit >> 1) {
            if(bn->array[i] & current_bit) {
                printf("1");
                leading_zeroes = 0;
            }
            else {
                if(!leading_zeroes) {
                    printf("0");
                }
            }
        }
    }
    printf("\n");
}

void print_as_dec(Bignum bn) {

}
