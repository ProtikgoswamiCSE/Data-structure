#include <stdio.h>
#define MAX_SIZE 100

void insertend(int arr[], int *size, int element) {
    if (*size < MAX_SIZE) {
        arr[*size] = element;
        (*size)++;
        printf("Element %d inserted at the end.\n", element);
    } else {
        printf("Error: List is full. Cannot insert element.\n");
    }
}

void deletePosition(int arr[], int *size, int position) {
    if (position >= 0 && position < *size) {
        for (int i = position; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted from position %d.\n", position);
    } else {
        printf("Error: Invalid position. Cannot delete element.\n");
    }
}

void displayList(int arr[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE];
    int size = 0;
    insertend(list, &size, 10);
    insertend(list, &size, 20);
    insertend(list, &size, 30);
    displayList(list, size);
    int positionToDelete = 1;
    deletePosition(list, &size, positionToDelete);

    displayList(list, size);

    return 0;
}
