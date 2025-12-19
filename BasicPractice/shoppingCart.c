#include <stdio.h>
char* getFood() {
  char* food = "";
  fgets(food, sizeof(food), stdin);
  return food;
}

double getCost() {
    int price = 0;
    scanf("%d", &price);
    return price;
}

int getNum() {
    int num = 0;
    scanf("%d", &num);
    return num;
}

void runIt() {
    char* food = getFood();
    double pricePerPiece = getCost();
    int numberOfPieces = getNum();

    double cost = pricePerPiece * numberOfPieces;

    printf("You have bought %d %s", numberOfPieces, food);
    printf("The total is: $%.2f", cost);
}

int main() {
    runIt();
}

