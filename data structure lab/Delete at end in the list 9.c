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

void deleteAtEnd(int arr[], int *size) {
    if (*size > 0) {
        (*size)--;
        printf("Element deleted from the end.\n");
    } else {
        printf("Error: List is empty. Cannot delete from the end.\n");
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
    insertend(list, &size, 40);
    displayList(list, size);
    deleteAtEnd(list, &size);
    displayList(list, size);

    return 0;
}
