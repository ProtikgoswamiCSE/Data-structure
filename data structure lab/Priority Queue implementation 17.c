#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    int data;
} Element;
typedef struct {
    Element* array;
    int capacity;
    int size;
} PriorityQueue;
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->array = (Element*)malloc(capacity * sizeof(Element));
    pq->capacity = capacity;
    pq->size = 0;
    return pq;
}
void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(PriorityQueue* pq, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && pq->array[index].priority > pq->array[parent].priority) {
        swap(&pq->array[index], &pq->array[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}
void push(PriorityQueue* pq, int data, int priority) {
    if (pq->size == pq->capacity) {
        printf("Priority queue is full. Cannot insert.\n");
        return;
    }

    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    pq->array[pq->size] = newElement;
    pq->size++;

    heapifyUp(pq, pq->size - 1);
}
void heapifyDown(PriorityQueue* pq, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < pq->size && pq->array[leftChild].priority > pq->array[largest].priority) {
        largest = leftChild;
    }

    if (rightChild < pq->size && pq->array[rightChild].priority > pq->array[largest].priority) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&pq->array[index], &pq->array[largest]);
        heapifyDown(pq, largest);
    }
}
Element pop(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty.\n");
        Element emptyElement = {-1, -1};
        return emptyElement;
    }

    Element maxElement = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;

    heapifyDown(pq, 0);

    return maxElement;
}
int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}
int size(PriorityQueue* pq) {
    return pq->size;
}
void freePriorityQueue(PriorityQueue* pq) {
    free(pq->array);
    free(pq);
}
int main() {
    PriorityQueue* pq = createPriorityQueue(10);

    push(pq, 1, 3);
    push(pq, 2, 1);
    push(pq, 3, 5);
    push(pq, 4, 2);

    while (!isEmpty(pq)) {
        Element e = pop(pq);
        printf("Data: %d, Priority: %d\n", e.data, e.priority);
    }

    freePriorityQueue(pq);

    return 0;
}
