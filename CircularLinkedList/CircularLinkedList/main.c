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
    while (iterator != r) {  // Loop until the end of the list
        printf("%d -> ", iterator->x);  // Print the value of the current node
        iterator = iterator->next;  // Move to the next node
    }
    printf("\n");
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

// Function to delete the first node with value x from the linked list
node* delete(node* r, int x) {
    node* temp;  // Pointer to hold the node to be deleted
    node* iterator = r;  // Pointer to traverse the list

    // If the node to be deleted is the head of the list
    if (r->x == x) {
        temp = r;  // Save the current head node to temp
        r = r->next;  // Move the head pointer to the next node
        free(temp);  // Free the memory of the old head node
        return r;  // Return the new head of the list
    }

    // Traverse the list to find the node to be deleted
    while (iterator->next != NULL && iterator->next->x != x) {
        iterator = iterator->next;  // Move to the next node
    }

    // If the node to be deleted is not found
    if (iterator->next == NULL) {
        printf("Number not found.\n");  // Print an error message
        return r;  // Return the unchanged list
    }

    // Node to be deleted is found, remove it from the list
    temp = iterator->next;  // Save the node to be deleted
    iterator->next = iterator->next->next;  // Bypass the node to be deleted
    free(temp);  // Free the memory of the node to be deleted

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

    root = delete(root, 50);
    root = delete(root, 999);
    root = delete(root, 4);
    root = delete(root, 450);
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