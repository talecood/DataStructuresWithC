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
    struct n* prev;
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
    if (r == NULL) { 
        r = (node*)malloc(sizeof(node));
        r->next = NULL;
        r->prev = NULL;
        r->x = x;
        return r;
    }
    if (r->x > x) {
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = r;
        r->prev = temp;
        return temp;
    }
    node* iter = r;
    while (iter->next != NULL && iter->next->x < x) {
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->prev = iter;
    if (temp->next != NULL)
        temp->next->prev = temp;
    temp->x = x;
    return r;
}

// Function to delete the first node with value x from the linked list
node* delete(node* r, int x) {
    node* temp;
    node* iter = r;
    if (r->x == x) {
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }
    while (iter->next != NULL && iter->next->x != x) {
        iter = iter->next;
    }
    if (iter->next == NULL) {
        printf("Value Not Found");
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    if (iter->next != NULL)
        iter->next->prev = iter;
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