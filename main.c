#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct SequentialStack {
    int top;
    int array[MAX];
} SequentialStack;

SequentialStack *createSequentialStack();

bool isFull(SequentialStack *stack);

bool isEmpty(SequentialStack *stack);

void push(SequentialStack *stack, int data);

int pop(SequentialStack *stack);

SequentialStack *createSequentialStack() {
    SequentialStack *stack = (SequentialStack *) malloc(sizeof(SequentialStack));
    if (stack == NULL) {
        printf("Memory allocation failed in createSequentialStack().\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    return stack;
}

bool isFull(SequentialStack *stack) {
    return stack->top == MAX - 1;
}

bool isEmpty(SequentialStack *stack) {
    return stack->top == -1;
}

void push(SequentialStack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow.\n");
        return;
    }
    stack->array[++stack->top] = data;
    printf("%d pushed to stack.\n", data);
}

int pop(SequentialStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(SequentialStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

int main(void) {
    SequentialStack *stack = createSequentialStack();

    push(stack, 100);
    push(stack, 200);
    push(stack, 300);

    printf("%d popped from stack.\n", pop(stack));
    printf("%d popped from stack.\n", pop(stack));
    printf("%d popped from stack.\n", pop(stack));
    printf("%d popped from stack.\n", pop(stack));

    push(stack, 400);
    printf("Top element is %d.\n", peek(stack));

    free(stack);
    return 0;
}
