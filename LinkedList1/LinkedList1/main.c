#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Define a node structure for the linked list
struct n {
    int x;
    struct n* next;  // Pointer to the next node in the list
};
typedef struct n node;  // Create a typedef for easier usage

// Function to print all elements in the linked list
void print(node* r) {
    while (r != NULL) {  // Loop until the end of the list
        printf("%d\t", r->x);  // Print the value of the current node
        r = r->next;  // Move to the next node
    }
}

int main(void) {
    node* root;

    // Allocate memory for the root node
    root = (node*)malloc(sizeof(node));

    // Initialize the first node
    root->x = 10;
    root->next = (node*)malloc(sizeof(node));  // Allocate memory for the next node
    root->next->x = 20;  // Set value for the second node
    root->next->next = (node*)malloc(sizeof(node));  // Allocate memory for the third node

    // Initialize the third node
    root->next->next->x = 30;
    root->next->next->next = NULL;  // Set the next pointer of the last node to NULL

    node* iterator;
    iterator = root;  // Start from the root

    // Print the value of the first node
    printf("%d ", iterator->x);
    iterator = iterator->next;  // Move to the next node

    // Print the value of the second node
    printf("%d\n", iterator->x);

    iterator = root;  // Reset iterator to the root

    int i = 0;
    // Traverse the list and print each node's value with its index
    while (iterator->next != NULL) {
        i++;
        printf("%dth Data : %d\n", i, iterator->x);
        iterator = iterator->next;  // Move to the next node
    }

    // Create 5 more nodes in the list
    for (int i = 0; i < 5; i++) {
        iterator->next = (node*)malloc(sizeof(node));  // Allocate memory for the new node
        iterator = iterator->next;  // Move to the new node
        iterator->x = i * 10;  // Set value for the new node
        iterator->next = NULL;  // Set the next pointer to NULL
    }

    // Print all the nodes in the list
    print(root);

    return 0;
}
