#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void getInput(char *input, int size) {
    printf("Please enter a word or phrase: ");
    fgets(input, size, stdin);
}

void getInput2(char *comp, int size) {
    printf("Please try to enter the same phrase again: ");
    fgets(comp, size, stdin);
}

bool check(char *input, char *comp) {
    if (sizeof(*input) == sizeof(*comp)) {
        int index = 0;
        while (input[index] != 0) {
            if (input[index] != comp[index]) {
                return false;
            }
            index++;
        }
        return true;
    }
    return false;
}

void runIt() {
    char input[50] = "";
    getInput(input, sizeof(input));
    char comp[50] = "";
    getInput2(comp, sizeof(comp));
    if (check(input, comp)) {
        printf("NICE JOB. SAME THING!");
    } else {
        printf("WRONG. NOT THE SAME THING");
    }

}

int main() {
    runIt();
    return 0;
}

