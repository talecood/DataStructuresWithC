#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct n {
    int x;
    struct n* next;
};
typedef struct n node;

int main(void) {
    node* root;

    root = (node*)malloc(sizeof(node));

        
    root->x = 10;
    root->next = (node*)malloc(sizeof(node));
    root->next -> x = 20;
    root->next->next = (node*)malloc(sizeof(node));


    root->next->next->x = 30;

    node* iterator;
    iterator = root;

    printf("%d ", iterator->x);
    iterator = iterator->next;

    printf("%d", iterator->x);

    


    return 0;
}
