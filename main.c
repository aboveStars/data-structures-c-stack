#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack {
    int top;
    int capacity;
    int *array;
}Stack;


Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));


    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(sizeof(int) * capacity);

    return stack;

}

int isFull(Stack* stack) {
    return stack->top == stack->capacity -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}


void push(Stack* stack, int value) {
    if(isFull(stack)) {
        printf("Stack is full.\n");
        return;
    }

    stack->array[++stack->top] = value;
    printf("%d is added to stack.\n", value);

}

int pop(Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }

    return stack->array[stack->top--];

}

int main(void) {

    Stack* stack = createStack(3);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    push(stack, 40);

    printf("\n");

    printf("%d is popped out of stack.\n" ,pop(stack));
    printf("%d is popped out of stack.\n" ,pop(stack));
    printf("%d is popped out of stack.\n" ,pop(stack));

    printf("%d is popped out of stack.\n" ,pop(stack));


    free(stack);

    return 0;
}
