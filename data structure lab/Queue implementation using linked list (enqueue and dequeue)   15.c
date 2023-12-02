#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
void initialize(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue %d.\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Enqueued element: %d\n", value);
}

int dequeue(struct Queue* queue) {
    int dequeuedValue = -1;
    if (isEmpty(queue)) {
        printf("Queue underflow: Cannot dequeue, queue is empty.\n");
    } else {
        struct Node* temp = queue->front;
        dequeuedValue = temp->data;

        queue->front = temp->next;
        free(temp);

        if (queue->front == NULL) {
            queue->rear = NULL;
        }

        printf("Dequeued element: %d\n", dequeuedValue);
    }

    return dequeuedValue;
}
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        struct Node* current = queue->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
void destroy(struct Queue* queue) {
    while (queue->front != NULL) {
        struct Node* temp = queue->front;
        queue->front = temp->next;
        free(temp);
    }
    queue->rear = NULL;
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    display(&queue);

    dequeue(&queue);
    display(&queue);

    destroy(&queue);

    return 0;
}

