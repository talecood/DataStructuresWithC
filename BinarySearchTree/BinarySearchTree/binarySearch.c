#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
	int data;
	struct n* left;
	struct n* right;
} node;

node* add(node* tree, int data) {
	if (tree == NULL) {
		node* root = (node*)malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		return root;
	}
	if (data < tree->data) {
		tree->left = add(tree->left, data);
	}
	else {
		tree->right = add(tree->right, data);
	}
	return tree;
}

void inOrderTraversal(node* tree) {
	if (tree == NULL) {
		return;
	}
	inOrderTraversal(tree->left);
	printf("%d ", tree->data);
	inOrderTraversal(tree->right);
}

int main(void) {
	node* tree = NULL;

	tree = add(tree, 12);
	tree = add(tree, 200);
	tree = add(tree, 190);
	tree = add(tree, 213);
	tree = add(tree, 56);
	tree = add(tree, 24);
	tree = add(tree, 18);
	tree = add(tree, 27);
	tree = add(tree, 28);

	inOrderTraversal(tree);

	return 0;
}
