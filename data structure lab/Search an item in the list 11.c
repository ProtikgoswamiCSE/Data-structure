#include <stdio.h>

int main() {
    int myarray[] = {1, 2, 3, 4, 5};
    int itemCount = sizeof(myarray) / sizeof(myarray[0]);
    printf("List elements: ");
    for (int i = 0; i < itemCount; i++) {
        printf("%d ", myarray[i]);
    }
    int searchItem;
    printf("\nEnter the item to search: ");
    scanf("%d", &searchItem);
    int found = 0;

    for (int i = 0; i < itemCount; i++) {
        if (myarray[i] == searchItem) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("%d is found in the list.\n", searchItem);
    } else {
        printf("%d is not found in the list.\n", searchItem);
    }

    return 0;
}
