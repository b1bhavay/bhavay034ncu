#include <stdio.h>
#include <math.h>  // For logarithmic and square root functions

// Function prototypes
void addition();
void subtraction();
void multiplication();
void division();
void logarithm();
void squareRoot();

int main() {
    int choice;

    // Menu to choose an operation
    do {
        printf("\nSimple Calculator\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Logarithmic values\n");
        printf("6. Square roots\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addition(); break;
            case 2: subtraction(); break;
            case 3: multiplication(); break;
            case 4: division(); break;
            case 5: logarithm(); break;
            case 6: squareRoot(); break;
            case 7: printf("Exiting the program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 7);  // Loop until the user chooses to exit

    return 0;
}

// Function for Addition
void addition() {
    double num1, num2;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Result: %.2lf\n", num1 + num2);
}

// Function for Subtraction
void subtraction() {
    double num1, num2;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Result: %.2lf\n", num1 - num2);
}

// Function for Multiplication
void multiplication() {
    double num1, num2;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Result: %.2lf\n", num1 * num2);
}

// Function for Division
void division() {
    double num1, num2;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    
    // Check for division by zero
    if (num2 == 0) {
        printf("Error! Division by zero.\n");
    } else {
        printf("Result: %.2lf\n", num1 / num2);
    }
}

// Function for Logarithmic values (log base e)
void logarithm() {
    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);
    
    // Check for positive values, as log of non-positive values is undefined
    if (num <= 0) {
        printf("Error! Logarithm of non-positive values is undefined.\n");
    } else {
        printf("Logarithm (base e) of %.2lf: %.2lf\n", num, log(num));
    }
}

// Function for Square roots
void squareRoot() {
    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);

    // Check for non-negative values
    if (num < 0) {
        printf("Error! Square root of a negative number is undefined.\n");
    } else {
        printf("Square root of %.2lf: %.2lf\n", num, sqrt(num));
    }
}
