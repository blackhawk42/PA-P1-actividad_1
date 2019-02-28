#include "bignum.h"

Bignum add(Bignum b1, Bignum b2) {
    Bignum temp;

    Bignum carry = and(b1, b2);
    Bignum result = xor(b1, b2);
    while(to_bool(carry)) {
        Bignum shiftedcarry = ls(carry);
        destroy_Bignum(carry);

        carry = and(result, shiftedcarry);

        temp = result;
        result = xor(temp, shiftedcarry);
        destroy_Bignum(temp);
    }

    destroy_Bignum(carry);

    return result;
}