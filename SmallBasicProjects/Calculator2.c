#include <stdio.h>
#include <ctype.h>

void parse_side(char *s, int sign, double *coef_x, double *constant) {
    int i = 0;
    double num = 0;
    int num_sign = 1;
    int has_num = 0;

    while (s[i]) {
        if (s[i] == '+') {
            num_sign = 1;
            i++;
        } else if (s[i] == '-') {
            num_sign = -1;
            i++;
        } else if (isdigit(s[i])) {
            num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            has_num = 1;
        } else if (s[i] == 'x') {
            double coeff = has_num ? num : 1;
            *coef_x += sign * num_sign * coeff;
            num = 0;
            has_num = 0;
            i++;
        } else if (s[i] == ' ') {
            i++;
        } else {
            i++;
        }

        if (has_num && (s[i] != '*') && (s[i] != 'x')) {
            *constant += sign * num_sign * num;
            num = 0;
            has_num = 0;
        }
    }
}

int main() {
    char eq[256];
    printf("Enter equation (example: 2*x + 3 = 11):\n");
    fgets(eq, sizeof(eq), stdin);

    char *lhs = eq;
    char *rhs = NULL;

    for (int i = 0; eq[i]; i++) {
        if (eq[i] == '=') {
            eq[i] = '\0';
            rhs = &eq[i + 1];
            break;
        }
    }

    if (!rhs) {
        printf("Invalid equation (missing '=')\n");
        return 1;
    }

    double coef_x = 0;
    double constant = 0;

    parse_side(lhs, 1, &coef_x, &constant);
    parse_side(rhs, -1, &coef_x, &constant);

    if (coef_x == 0) {
        if (constant == 0)
            printf("Infinite solutions\n");
        else
            printf("No solution\n");
        return 0;
    }

    double x = -constant / coef_x;
    printf("x = %.2f\n", x);
    return 0;
}
