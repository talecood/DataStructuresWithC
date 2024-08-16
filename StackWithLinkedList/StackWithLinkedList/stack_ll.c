#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

int pop(node* root) {
	if (root == NULL) {
		printf("Stack is Empty.");
		return -1;
	}
	
	node* iterator = root;
	while (iterator->next->next != NULL) {
		iterator = iterator->next;
	}
	node* temp = iterator->next;
	int rvalue = temp->data;

	free(temp);
	iterator->next = NULL;
	return root;
}

void push(node* root, int a) {
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

	return 0;
}