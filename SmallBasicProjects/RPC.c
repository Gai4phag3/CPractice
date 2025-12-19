#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int getInput();
int getComp();
int getExit();

bool compare(int user, int computer);
bool same(int user, int computer);

void runIt();

int main() {
    runIt();
    return 0;
}

void runIt() {
    int input = 0;
    int compNum = -1;
    srand(time(NULL)); 
    while (true) {
        input = getInput();
        compNum = getComp();

        if (!same(input, compNum)) {
            if (compare(input, compNum)) {
                printf("\nNice! You won!\n\n");
            } else {
                printf("\nDang, you lost!\n\n");
            }
        } else {
            printf("\nTie!\n\n");
        }

        if (!getExit()) {
            break;
        }
    }
}

int getInput() {
    printf("Welcome to rock, paper, scissors! \nHere are your input options: \n"
        "1 for (paper)\n"
        "2 for (scissors)\n"
        "3 for (rock)\n"
        "\nYour choice is: ");
    int input = 0;
    scanf("%d", &input);
    return input;
}

int getComp() {
    int random = 0;
    random = rand() % (3) + 1;
    return random;
}

bool same(int user, int computer) {
    if (user == computer) {
        return true;
    }
    return false;
}

bool compare(int user, int computer) {
    if ((user + 1) % 3 == computer) {
        return false;
    }
    return true;
    
}

int getExit() {
    printf("Would you like to try again? 1 to continue, 0 to stop: ");
    int input = 0;
    scanf("%d", &input);
    return input;
}
