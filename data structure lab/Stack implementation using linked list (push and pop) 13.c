#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};
void initialize(struct Stack* stack) {
    stack->top = NULL;
}
int IsEmpty(struct Stack* stack) {
    return stack->top == NULL;
}
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push %d.\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("Pushed element: %d\n", value);
}
int pop(struct Stack* stack) {
    if (IsEmpty(stack)) {
        printf("Stack underflow: Cannot pop, stack is empty.\n");
        return -1;
    }

    struct Node* poppedNode = stack->top;
    int poppedValue = poppedNode->data;
    stack->top = poppedNode->next;
    free(poppedNode);

    printf("Popped element: %d\n", poppedValue);
    return poppedValue;
}
void display(struct Stack* stack) {
    if (IsEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        struct Node* current = stack->top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
void destroy(struct Stack* stack) {
    while (stack->top != NULL) {
        struct Node* temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    display(&stack);

    pop(&stack);
    display(&stack);

    destroy(&stack);

    return 0;
}
