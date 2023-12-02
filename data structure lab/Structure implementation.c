#include <stdio.h>
struct Person {
    char name[50];
    int age;
    float height;
};
void initializePerson(struct Person *person, const char *name, int age, float height) {
    snprintf(person->name, sizeof(person->name), "%s", name);
    person->age = age;
    person->height = height;
}
void displayPerson(const struct Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %.2f\n", person->height);
}

int main() {
    struct Person person1;

    initializePerson(&person1, "Protik goswami", 23, 175.5);
    printf("Person Information:\n");
    displayPerson(&person1);

    return 0;
}

