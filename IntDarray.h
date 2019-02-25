#ifndef INTDARRAY_H
#define INTDARRAY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
	size_t len;
	int *array;
} IntDarray_s, *IntDarray;

IntDarray new_darray(int *init_values, size_t init_length) {
	IntDarray darray = (IntDarray)malloc(sizeof(IntDarray_s));

	darray->array = (int *)malloc(sizeof(int)*init_length);
	darray->len = init_length;

	for(int i = 0; i < init_length; i++) {
		darray->array[i] = init_values[i];
	}

	return darray;
}

void destroy_darray(IntDarray darray) {
	free(darray->array);
	free(darray);
}


void darray_push(IntDarray darray, int i) {
	darray->array = (int *)realloc(darray->array, sizeof(int)*darray->len+1);

	darray->array[darray->len] = i;

	darray->len++;
}


int darray_pop(IntDarray darray) {
	int i = darray->array[darray->len-1];

	darray->array = (int *)realloc(darray->array, sizeof(int)*darray->len-1);
	darray->len--;

	return i;
}


void print_darray(IntDarray darray) {
	printf("IntDarray{ ");
	for(int i = 0; i < darray->len; i++) {
		printf("%d ", darray->array[i]);
	}
	printf("}\n");
}

#endif /** INTDARRAY_H **/
