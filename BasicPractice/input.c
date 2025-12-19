#include <stdio.h>
#include <string.h>

int main() {

    int age = 0;
    char name[30] = "";

    printf("Enter your age: ");
    scanf(" %d", &age);

    getchar();
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);

    printf("%d %s", age, name);
    return 0;
}