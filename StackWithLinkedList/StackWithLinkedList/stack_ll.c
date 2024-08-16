#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

typedef struct node {
	int data;
	struct node* next;
} node;

int pop(node** root) {
	if (*root == NULL) {
		printf("Stack is empty.\n");
		return -1;
	}

	node* iterator = *root;
	if (iterator->next == NULL) {  // Case where there's only one element
		int rvalue = iterator->data;
		free(iterator);
		*root = NULL;
		return rvalue;
	}

	while (iterator->next->next != NULL) {
		iterator = iterator->next;
	}

	node* temp = iterator->next;
	int rvalue = temp->data;

	free(temp);
	iterator->next = NULL;
	return rvalue;
}

void print(node* r) {
	while (r != NULL) {
		printf("%d -> ", r->data);
		r = r->next;
	}
	printf("NULL\n");
}

node* push(node* root, int a) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->data = a;
		root->next = NULL;
		return root;
	}

	node* iterator = root;
	while (iterator->next != NULL) {
		iterator = iterator->next;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp->data = a;
	temp->next = NULL;
	iterator->next = temp;
	return root;
}

int main(void) {
	node* s = NULL;

	s = push(s, 10);
	s = push(s, 20);
	s = push(s, 30);
	s = push(s, 40);
	print(s);

	printf("Popped: %d\n", pop(&s));
	printf("Popped: %d\n", pop(&s));
	print(s);

	return 0;
}
