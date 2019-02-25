#include "IntDarray.h"
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	if (argc <= 1) {
		printf("Please pass the inital (numerical) values as command line arguments\n");
		exit(1);
	}

	int init_length = argc-1;

	int *initial_values = (int *)malloc(sizeof(int)*init_length);
	for(int i = 1; i < argc; i++) {
		initial_values[i-1] = atoi(argv[i]);
	}

	IntDarray darray = new_IntDarray(initial_values, init_length);

	free(initial_values);

	printf("Current array:\n");
	print_IntDarray(darray);
	printf("\n");

	int new_i;
	printf("Give me another number to add: ");
	scanf("%d", &new_i);
	fflush(stdin);

	IntDarray_push(darray, new_i);

	printf("New array:\n");
	print_IntDarray(darray);
	printf("\n");

	printf("Removig an element from the array: %d\n", IntDarray_pop(darray));

	printf("New array:\n");

	print_IntDarray(darray);
	destroy_IntDarray(darray);

	return 0;
}
