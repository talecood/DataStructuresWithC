#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct n {
	int data;
	node* left;
	node* right;
};
typedef struct n node;

node* add(node* tree, int data) {
	if (tree == NULL) {
		node* root = (node*)malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		return root;
	}
	if (tree->data < data) {
		tree->right = add(tree->right, data);
		tree->left = add(tree->left, data);

	}

}

int main(void) {

	return 0;
}