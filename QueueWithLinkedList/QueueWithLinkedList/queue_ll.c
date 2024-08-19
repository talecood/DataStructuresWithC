#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	node* next;
};
typedef struct n node;

node* root = NULL;
node* last = NULL;

void enqueue(int a) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->data = a;
		root->next = NULL;
		last = root;
	}
	else {
		last->next = (node*)malloc(sizeof(node));
		last->next->data = a;
		last = last->next;
	}
}

int dequeue() {
	if (root == NULL) {
		printf("Queue is empty.");
		return -1;
	}
	int rvalue = root->data;
	node* temp = root;
	root = root->next;
	free(temp);
	return rvalue;

}


int main(void) {

	enqueue(10);
	enqueue(20);


	return 0;
}