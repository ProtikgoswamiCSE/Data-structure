#include <stdio.h>
#define MAX_SIZE 10

struct Queue{
    int arr[MAX_SIZE];
    int front, rear;
};
void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}
int IsEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}


void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow: Cannot enqueue %d, queue is full.\n", value);
    } else {
        if (IsEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->arr[queue->rear] = value;
        printf("Enqueued element: %d\n", value);
    }
}
int dequeue(struct Queue* queue) {
    int dequeuedValue = -1;

    if (IsEmpty(queue)) {
        printf("Queue underflow: Cannot dequeue, queue is empty.\n");
    } else {
        dequeuedValue = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            initialize(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("Dequeued element: %d\n", dequeuedValue);
    }

    return dequeuedValue;
}
void display(struct Queue* queue) {
    if (IsEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = queue->front;
        do {
            printf("%d ", queue->arr[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
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

    return 0;
}

