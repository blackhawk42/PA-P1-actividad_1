#include <stdio.h>
#include "bignum/bignum.h"

int main() {
	int n;
	Bignum fib;

	do {
		printf("Calculate fibonacci (-1 or lower to exit) n=");
		scanf("%d", &n);
		fflush(stdin);

		if(n < 0) {
			break;
		}

		fib = Bignum_fibonacci(n, 3);

		print_as_binary(fib);

		destroy_Bignum(fib);
	}while(1);

	return 0;
}
