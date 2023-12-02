#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        for (int i = 1; i < position - 1 && current != NULL; ++i) {
            current = current->next;
        }

        if (current == NULL) {
            printf("Invalid position\n");
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* head = NULL;
    displayList(head);

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 1);
    displayList(head);

    insertAtPosition(&head, 2, 2);
    displayList(head);

    return 0;
}

