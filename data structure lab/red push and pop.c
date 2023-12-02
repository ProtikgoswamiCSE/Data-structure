#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Structure to represent a stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow: Cannot push %d, stack is full.\n", value);
    } else {
        stack->arr[++stack->top] = value;
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow: Cannot pop, stack is empty.\n");
        return -1; // Return a default value indicating an error
    } else {
        printf("Popped element: %d\n", stack->arr[stack->top]);
        return stack->arr[stack->top--];
    }
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; ++i) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    display(&stack);

    pop(&stack); // This will print "coller red"

    display(&stack);

    return 0;
}
