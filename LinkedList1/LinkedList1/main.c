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
        printf("%d -> ", r->x);  // Print the value of the current node
        r = r->next;  // Move to the next node
    }
}

void append(node* r, int x) {
    while (r->next != NULL) {
        r = r->next;
    }
    r->next = (node*)malloc(sizeof(node));
    r->next->x = x;
    r->next->next = NULL;
}

int main(void) {
    node* root;
    root = (node*)malloc(sizeof(node));
    root->next = NULL;

    node* iterator;
    iterator = root;
    
    root->x = 500;

    // Create 5 more nodes in the list
    for (int i = 0; i < 5; i++) {
        append(root, i * 10);
    }

    // Print all the nodes in the list
    print(root);

    //Add a new node between the nodes
    for (int i = 0; i < 3; i++) {
        iterator = iterator->next;
   }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iterator->next;

    iterator->next = temp;
    temp->x = 100;

    printf("\nNew LinkedList : \n");
    print(root);






    return 0;
}
