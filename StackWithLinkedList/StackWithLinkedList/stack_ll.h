#ifndef stack_ll
#define stack_ll

// Forward declaration of node structure
typedef struct n node;

struct n {
    int data;
    struct n* next;  // Using typedef'd 'node' after its declaration
};

// Function prototypes
int pop(node**);          // Accepting a pointer to pointer to modify the root
node* push(node*, int);

#endif
