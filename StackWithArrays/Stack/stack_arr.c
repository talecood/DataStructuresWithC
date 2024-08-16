#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

int size = 2;
int top = 0;
int* array;

int pop() {
	if (array == NULL) {
		printf("Array is empty");
		return -1;
	}

	if (top > 0 && top < size / 4) {
		int* arr2 = (int*)malloc(sizeof(int) * size / 2);  // Halve the size of the array
		for (int i = 0; i < top; i++) {  // Copy only the used elements
			arr2[i] = array[i];
		}
		free(array);
		array = arr2;
		size /= 2;
	}
	return array[--top];
}

void push(int a) {
	if (array == NULL) {
		array = (int*)malloc(sizeof(int) * size);  // Dynamically allocate memory for the array
	}
	if (top >= size) {
		int* arr2 = (int*)malloc(sizeof(int) * size * 2);  // Double the size of the array
		for (int i = 0; i < top; i++) {  // Copy only the used elements
			arr2[i] = array[i];
		}
		free(array);
		array = arr2;
		size *= 2;
	}
	array[top++] = a;
}

void print() {
	printf("Size : %d\n", size);
	for (int i = 0; i < top; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(void) {
	array = (int*)malloc(sizeof(int) * size);  // Dynamically allocate memory for the array

	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	print();

	printf("\npopped %d\n", pop());
	printf("popped %d\n", pop());
	printf("popped %d\n", pop());
	printf("popped %d\n", pop());
	printf("popped %d\n", pop());

	print();

	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);

	print();

	free(array);  // Don't forget to free the dynamically allocated memory before exiting

	return 0;
}
