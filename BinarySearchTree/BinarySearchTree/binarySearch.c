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
	} else {
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

int search(node* tree, int expected) {
	if (tree == NULL) {
		return -1;
	}
	if (tree->data == expected) {
		return 1;
	}
	if (search(tree->right,expected) == 1) {
		return 1;
	}
	if (search(tree->left, expected) == 1) {
		return 1;
	}
	return -1;
	
}

int maxValue(node* tree) {
	while (tree->right != NULL) {
		tree = tree->right;
	}
	return tree->data;

}
int minValue(node* tree) {
	while (tree->left != NULL) {
		tree = tree->left;
	}
	return tree->data;

}

node* delete(node* tree,int x) {
	if (tree == NULL) {
		return NULL;
	}
	if (tree->data == x) {
		if (tree->left == NULL && tree->right == NULL) {
			return NULL;
		}
		if (tree->right != NULL) {
			tree->data = minValue(tree->right);
			tree->right = delete(tree->right, minValue(tree->right));
			return tree;
		}
		tree->data = maxValue(tree->left);
		tree->left = delete(tree->left, maxValue(tree->left));
		return tree;
	}
	if (tree->data < x) {
		tree->right= delete(tree->right, x);
		return tree;
	}
	tree->left = delete(tree->left, x); 
	return tree;

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

	printf("\nSearch Result = %d\n", search(tree, 190));
	printf("Max Value = %d, Min Value = %d\n", maxValue(tree), minValue(tree));

	tree = delete(tree, 190);
	inOrderTraversal(tree);
	return 0;
}
