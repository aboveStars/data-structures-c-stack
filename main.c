#include <stdio.h>
#include <stdlib.h>


typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

StackNode *newNode(int data) {
    StackNode *nNode = (StackNode *) malloc(sizeof(StackNode));

    nNode->data = data;
    nNode->next = NULL;

    return nNode;
}

int isEmpty(StackNode *root) {
    return root == NULL;
}

void push(StackNode **root, int data) {
    StackNode *nNode = newNode(data);

    nNode->next = *root;
    *root = nNode;
    printf("%d is added to stack.\n", data);
}


int pop(StackNode **root) {
    StackNode *tempNewRoot = (*root)->next;

    int poppeddata = (*root)->data;

    *root = NULL;
    free(*root);
    *root = tempNewRoot;

    printf("%d is removed from stack.\n", poppeddata);
}


int main() {
    StackNode *root = newNode(0);

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    pop(&root);
    pop(&root);
    pop(&root);

    free(root);

    return 0;
}
