#include <stdio.h>
#include <ctype.h>

int main() {
    char expr[256];
    printf("Enter expression: ");
    fgets(expr, sizeof(expr), stdin);

    int i = 0;
    long result = 0;
    long current = 0;
    char op = '+';

    while (expr[i]) {
        if (isdigit(expr[i])) {
            current = 0;
            while (isdigit(expr[i])) {
                current = current * 10 + (expr[i] - '0');
                i++;
            }

            if (op == '+') result += current;
            else if (op == '-') result -= current;
            else if (op == '*') result = result * current;
            else if (op == '/') result = result / current;
            continue;
        }

        if (expr[i] == '+' || expr[i] == '-' ||
            expr[i] == '*' || expr[i] == '/') {
            op = expr[i];
        }

        i++;
    }

    printf("Result: %ld\n", result);
    return 0;
}
