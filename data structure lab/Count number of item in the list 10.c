#include <stdio.h>

int main() {
    int myArray[] = {1, 2, 3, 4, 5};
    int itemCount = sizeof(myArray) / sizeof(myArray[0]);

    printf("List elements: ");
    for (int i = 0; i < itemCount; i++) {
        printf("%d ", myArray[i]);
    }

    printf("\nNumber of items in the list: %d\n", itemCount);

    return 0;
}
