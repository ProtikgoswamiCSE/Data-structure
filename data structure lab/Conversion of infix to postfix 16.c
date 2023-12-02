#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a stack structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack with given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to return the top element of the stack
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to push an element to the stack
void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // A sentinel value indicating an empty stack
}

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // Assuming that '(' has the lowest precedence
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j;

    for (i = 0, j = -1; infix[i]; ++i) {
        if (isalnum(infix[i]))
            infix[++j] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                infix[++j] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(stack); // Pop '('
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                infix[++j] = pop(stack);
            push(stack, infix[i]);
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(stack))
        infix[++j] = pop(stack);

    infix[++j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    printf("Postfix expression: %s\n", infix);

    return 0;
}

