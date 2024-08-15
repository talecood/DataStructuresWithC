#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Define a node structure for the linked list
struct n {
    int x;              // Value of the node
    struct n* next;     // Pointer to the next node in the list
};
typedef struct n node;  // Create a typedef for easier usage

// Function to print all elements in the linked list
void print(node* r) {
    while (r != NULL) {  // Loop until the end of the list
        printf("%d -> ", r->x);  // Print the value of the current node
        r = r->next;  // Move to the next node
    }
}

// Function to append a new node with value x at the end of the list
void append(node* r, int x) {
    while (r->next != NULL) {  // Loop to find the end of the list
        r = r->next;
    }
    r->next = (node*)malloc(sizeof(node));  // Allocate memory for the new node
    r->next->x = x;  // Set the value of the new node
    r->next->next = NULL;  // Set the next pointer of the new node to NULL
}

// Function to insert a new node with value x in the correct order
node* appendByOrder(node* r, int x) {
    if (r == NULL) {  // If the list is empty
        r = (node*)malloc(sizeof(node));  // Allocate memory for the new node
        r->next = NULL;  // Set the next pointer to NULL
        r->x = x;  // Set the value of the new node
    }
    if (r->x > x) {  // If the new value should be inserted before the head
        node* temp = (node*)malloc(sizeof(node));  // Allocate memory for the new node
        temp->x = x;  // Set the value of the new node
        temp->next = r;  // Set the next pointer to the current head
        return temp;  // Return the new node as the new head
    }
    node* iter = r;  // Initialize iterator to traverse the list
    while (iter->next != NULL && iter->next->x < x) {  // Find the correct position for the new node
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));  // Allocate memory for the new node
    temp->next = iter->next;  // Set the next pointer of the new node
    iter->next = temp;  // Insert the new node into the list
    temp->x = x;  // Set the value of the new node
    return r;  // Return the head of the list
}

int main(void) {
    node* root;  // Pointer to the head of the list
    root = (node*)malloc(sizeof(node));  // Allocate memory for the head node
    root = NULL;  // Initialize the list as empty
    node* iterator;  // Pointer to traverse the list
    iterator = root;

    // Insert nodes into the list in order
    root = appendByOrder(root, 400);
    root = appendByOrder(root, 40);
    root = appendByOrder(root, 4);
    root = appendByOrder(root, 450);
    root = appendByOrder(root, 50);


    // Print all the nodes in the list
    print(root);

    // Add a new node with value 100 between nodes
    for (int i = 0; i < 3; i++) {
        iterator = iterator->next;  // Move to the desired position
    }
    node* temp = (node*)malloc(sizeof(node));  // Allocate memory for the new node
    temp->next = iterator->next;  // Set the next pointer of the new node
    iterator->next = temp;  // Insert the new node into the list
    temp->x = 100;  // Set the value of the new node

    printf("\nNew LinkedList : \n");
    print(root);  // Print the updated list

    return 0;
}
