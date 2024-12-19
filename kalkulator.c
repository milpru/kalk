
#include <math.h>
#include <stdio.h>
#include <string.h>

int divzero(float num1, char op[], float num2) {
    if (strcmp(op, "/") == 0) {
        if (num2 == 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
float calc(float num1, char op[], float num2) {
    if (strcmp(op, "+") == 0) {
        return num1 + num2;
    } else if (strcmp(op, "-") == 0) {
        return num1 - num2;
    } else if (strcmp(op, "*") == 0) {
        return num1 * num2;
    } else if (strcmp(op, "^") == 0) {
        return pow(num1, num2);
    } else if (strcmp(op, "/") == 0) {
        return num1 / num2;
    }
}

void calc5(float num1, char op1[], float num2, char op2[], float num3) {
    //printf("check");
    if (strcmp(op1, "^") == 0) {
        printf("Wynik: %.2f", calc(pow(num1, num2), op2, num3));
    } else if (strcmp(op2, "^") == 0) {
        printf("Wynik: %.2f", calc(num1, op1, pow(num2, num3)));
    } else if (strcmp(op2, "*") == 0 || strcmp(op2, "/") == 0) {
        printf("Wynik: %.2f", calc(num1, op1, calc(num2, op2, num3)));
    } else {
        printf("Wynik: %.2f", calc(calc(num1, op1, num2), op2, num3));
    }
}

int main() {
    float num1, num2, num3;
    char op1[5], op2[5] = "";
    char input[100];

    //printf("Wprowadz dane: ");

    if (fgets(input, sizeof(input), stdin)) {

        if (sscanf(input, "%f %s %f %s %f", &num1, op1, &num2, op2, &num3) == 5) {
            //printf("Dane: %f %s %f %s %f\n", num1, op1, num2, op2, num3);
            if (divzero(num1, op1, num2) == 0 && divzero(num2, op2, num3) == 0) {
                calc5(num1, op1, num2, op2, num3);
            } else {
                printf("Błąd: Nie można dzielić przez 0!");
            }
            
        } else if (sscanf(input, "%f %s %f", &num1, op1, &num2) == 3) {
            //printf("Dane: %f %s %f\n", num1, op1, num2);
            if (divzero(num1, op1, num2) == 0) {
                printf("Wynik: %.2f", calc(num1, op1, num2));
            } else if (divzero(num1, op1, num2) == 1) {
                printf("Błąd: Nie można dzielić przez 0!");
            }
            
        } else if (sscanf(input, "%s %f", op1, &num2) == 2 && strcmp(op1, "sqrt") == 0) {
            //printf("dane: %s %f", op1, num2);
            if (num2 < 0) {
                printf("Błąd: Nie można obliczyć pierwiastka z liczby ujemnej!");
                return 1;
            }
            else {
                printf("Wynik: %.2f", sqrt(num2));
                return 0;
            }
        } else {
            printf("Niepoprawny format danych.\n");
        }
    } else {
        printf("Blad wczytywania danych.\n");
    }

    return 0;
}
