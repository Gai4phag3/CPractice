#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void strip_newline(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '\n') {
            s[i] = '\0';
            return;
        }
        i++;
    }
}

void getInput(char *input, int size) {
    printf("Please enter a word or phrase: ");
    fgets(input, size, stdin);
}

void getInput2(char *comp, int size) {
    printf("Please try to enter the same phrase again: ");
    fgets(comp, size, stdin);
}

bool check(char *input, char *comp) {
    int i = 0;

    while (input[i] != '\0' && comp[i] != '\0') {
        if (input[i] != comp[i]) {
            return false;
        }
        i++;
    }

    return input[i] == '\0' && comp[i] == '\0';
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

