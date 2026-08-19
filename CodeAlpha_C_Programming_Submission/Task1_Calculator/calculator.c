#include <stdio.h>

int main(void) {
    double a, b, result;
    int choice;

    printf("=== Simple Calculator ===\n");
    printf("Enter first number: ");
    scanf("%lf", &a);
    printf("Enter second number: ");
    scanf("%lf", &b);

    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Choose an operation: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = a + b;
            printf("Result: %.2f\n", result);
            break;
        case 2:
            result = a - b;
            printf("Result: %.2f\n", result);
            break;
        case 3:
            result = a * b;
            printf("Result: %.2f\n", result);
            break;
        case 4:
            if (b == 0) {
                printf("Error: division by zero is not allowed.\n");
            } else {
                result = a / b;
                printf("Result: %.2f\n", result);
            }
            break;
        default:
            printf("Invalid operation.\n");
    }
    return 0;
}
