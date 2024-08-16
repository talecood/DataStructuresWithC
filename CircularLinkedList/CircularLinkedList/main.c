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
    node* iterator = r;
    printf("%d", iterator->x);
    while (iterator != r) {  // Loop until the end of the list
        printf("%d -> ", iterator->x);  // Print the value of the current node
        iterator = iterator->next;  // Move to the next node
    }
    printf("\n");
}

// Function to append a new node with value x at the end of the list
void append(node* r, int x) {
    node* iterator = r;
    while (iterator->next != r) {  // Loop to find the end of the list
        iterator = iterator->next;
    }

    iterator->next = (node*)malloc(sizeof(node));  // Allocate memory for the new node
    iterator->next->x = x;  // Set the value of the new node
    iterator->next->next = r;  // Set the next pointer of the new node to Root
}

// Function to insert a new node with value x in the correct order
node* appendByOrder(node* r, int x) {
    if (r == NULL) {  // If the list is empty
        r = (node*)malloc(sizeof(node));  // Allocate memory for the new node
        r->next = r;  // Set the next pointer to NULL
        r->x = x;  // Set the value of the new node
    }
    if (r->x > x) {  // If the new value should be inserted before the head
        node* temp = (node*)malloc(sizeof(node));  // Allocate memory for the new node
        temp->x = x;  // Set the value of the new node
        temp->next = r;  // Set the next pointer to the current head
        node* iterator = r;
        while (iterator->next != r) {
            iterator = iterator->next;
        }
        iterator->next = temp;
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

// Function to delete the first node with value x from the linked list
node* delete(node* r, int x) {
    node* temp;  // Pointer to hold the node to be deleted
    node* iterator = r;  // Pointer to traverse the list

    if (r->x == x) {
        while (iterator->next != r) {
            iterator = iterator->next;
        }
        iterator->next = r->next;
        free(r);
        return iterator->next;
    }
    while (iterator->next != r && iterator->next->x != x) {
        iterator = iterator->next;
    }
    if (iterator->next == r) {
        printf("Value Not Found.");
        return r;
    }
    temp = iterator->next;
    iterator->next = iterator->next->next;
    free(temp);
    return r;
}


int main(void) {
    node* root;
    root = NULL;
    root = appendByOrder(root, 400);
    root = appendByOrder(root, 40);
    root = appendByOrder(root, 4);
    root = appendByOrder(root, 450);
    root = appendByOrder(root, 50);
    bastir(root);
    root = delete(root, 50);
    print(root);
    root = delete(root, 999);
    print(root);
    root = delete(root, 4);
    print(root);
    root = delete(root, 450);
    print(root);

    return 0;
}