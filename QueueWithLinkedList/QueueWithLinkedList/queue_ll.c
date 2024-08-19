#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	node* next;
};
typedef struct n node;

node* root = NULL;
void enqueue(int a) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->data = a;
		root->next = NULL;

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

}


int main(void) {



	return 0;
}