#include <stdio.h>
#include "bignum.h"

Bignum fibonacci(unsigned int n, size_t bignum_size) {
    if(n == 0) {
        return enlarge_Bignum(new_from_int_Bignum(0), bignum_size);
    }
    if(n == 1) {
        return enlarge_Bignum(new_from_int_Bignum(0), bignum_size);
    }

    Bignum f1 = enlarge_Bignum(new_from_int_Bignum(0), bignum_size);
    Bignum f2 = enlarge_Bignum(new_from_int_Bignum(1), bignum_size);
    Bignum fi = enlarge_Bignum(new_from_int_Bignum(0), bignum_size);

    for(unsigned int i = 2; i <= n; i++) {
        //destroy_Bignum(fi);
        fi = add(f1, f2);

        //destroy_Bignum(f1);
        f1 = f2;
        //destroy_Bignum(f2);
        f2 = fi;
    }

    return fi;
}

int main() {
    Bignum f = fibonacci(120, 3);
    print_as_binary(f);

    return 0;
}
