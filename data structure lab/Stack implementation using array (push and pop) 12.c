#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push %d, stack is full.\n", value);
    } else {
        stack->top++;
        stack->items[stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop from an empty stack.\n");
        return -1;
    } else {
        int poppedItem = stack->items[stack->top];
        stack->top--;
        printf("Popped %d from the stack.\n", poppedItem);
        return poppedItem;
    }
}

int main() {
    struct Stack myStack;
    initialize(&myStack);

    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);

    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    pop(&myStack);

    return 0;
}
