#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

stack* tanim() {  // Definition function to initialize a stack
	stack* s = (stack*)malloc(sizeof(stack));
	s->array = NULL;
	s->size = 2;
	s->top = 0;
	return s;
}

int pop(stack* s) {
	if (s->top <= 0 || s->array == NULL) {
		printf("Stack is empty\n");
		return -1;
	}
	if (s->top <= s->size / 4 && s->size > 2) {
		int* dizi2 = (int*)malloc(sizeof(int) * s->size / 2);
		for (int i = 0; i < s->top; i++)
			dizi2[i] = s->array[i];
		free(s->array);
		s->array = dizi2;
		s->size /= 2;
	}
	return s->array[--s->top];
}

void push(int a, stack* s) {
	if (s->array == NULL) {
		s->array = (int*)malloc(sizeof(int) * 2);
	}
	if (s->top >= s->size) {  // Changed from s->size - 1 to s->size
		int* dizi2 = (int*)malloc(sizeof(int) * s->size * 2);
		for (int i = 0; i < s->size; i++)
			dizi2[i] = s->array[i];
		free(s->array);
		s->array = dizi2;
		s->size *= 2;
	}
	s->array[s->top++] = a;
}

void print(stack* s) {
	printf("Size: %d\n", s->size);
	for (int i = 0; i < s->top; i++) {
		printf("%d ", s->array[i]);
	}
	printf("\n");
}

int main(void) {
	stack* s1 = tanim();  // Changed from definition() to tanim()
	stack* s2 = tanim();  // Changed from definition() to tanim()

	for (int i = 0; i < 10; i++) {
		push(i * 10, s1);
	}

	print(s1);

	for (int i = 0; i < 10; i++) {
		push(pop(s1), s2);
	}

	print(s1);
	print(s2);

	free(s1->array);  // Free the allocated memory
	free(s2->array);  // Free the allocated memory
	free(s1);         // Free the stack structure itself
	free(s2);         // Free the stack structure itself

	return 0;
}
