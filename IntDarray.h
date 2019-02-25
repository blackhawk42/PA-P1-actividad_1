#ifndef INTDARRAY_H
#define INTDARRAY_H

#include <stdlib.h>
#include <stdio.h>

/**
 * IntDarray is a dynamic array for integers.
 *
 * IntDarray_s defines the structure itself, but we'll often work with IntDarray,
 * which is implemented as a pointer for efficiency's sake.
 */
typedef struct {
	size_t len; /**< Current length of the array. */
	int *array; /**< Pointer to current physical array in which the data is stored. */
} IntDarray_s, *IntDarray;

/**
 * new_darray creates a new IntDarray from an int array with the initial
 * values.
 *
 * @param  init_values Pointer to the array containing the initial values.
 * @param  init_length Length of the initial array and of the new IntDarray.
 * @return             The new IntDarray.
 */
IntDarray new_IntDarray(int *init_values, size_t init_length) {
	IntDarray darray = (IntDarray)malloc(sizeof(IntDarray_s));

	darray->array = (int *)malloc(sizeof(int)*init_length);
	darray->len = init_length;

	for(int i = 0; i < init_length; i++) {
		darray->array[i] = init_values[i];
	}

	return darray;
}

/**
 * destroy_darray destroys the given IntDarray and frees it's memory.
 *
 * @param darray The IntDarray to destroy.
 */
void destroy_IntDarray(IntDarray darray) {
	free(darray->array);
	free(darray);
}

/**
 * darray_push pushes a new value at the end of a dynamic array.
 *
 * @param darray The dynamic array to push into.
 * @param i      The integer to push.
 */
void IntDarray_push(IntDarray darray, int i) {
	darray->array = (int *)realloc(darray->array, sizeof(int)*darray->len+1);

	darray->array[darray->len] = i;

	darray->len++;
}

/**
 * darray_pop pops the last value of the dynamic array.
 *
 * In the case of an empty IntDarray, this will simply return 0 without
 * modification to the IntDarray.
 *
 * @param darray The dynamic array to pop from.
 * @return       The popped integer.
 */
int IntDarray_pop(IntDarray darray) {
	if (darray->len == 0) {
		return 0;
	}

	int i = darray->array[darray->len-1];

	darray->array = (int *)realloc(darray->array, sizeof(int)*darray->len-1);
	darray->len--;

	return i;
}


/**
 * Utility function to print an IntDarray.
 *
 * @param darray IntArray to print.
 */
void print_IntDarray(IntDarray darray) {
	printf("IntDarray{ ");
	for(int i = 0; i < darray->len; i++) {
		printf("%d ", darray->array[i]);
	}
	printf("}\n");
}

#endif /** INTDARRAY_H **/
