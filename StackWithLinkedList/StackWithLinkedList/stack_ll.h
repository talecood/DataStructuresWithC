#ifndef stack_ll
#define stack_ll

struct n {
	node* next;
	int data;
}; typedef struct n node;

int pop(node*);
void push(node*, int);


#endif
