#include <stdio.h>

int main(void) {
    int age;
    char initial;
    float decimal;


    printf("Enter your age (1-120): ");
    fscanf(stdin, "%d", &age);
    do {
        printf("Invalid input. Try again.\n");
        printf("Enter your age (1-120): ");
        fscanf(stdin, "%d", &age);
    }while (age < 1 || age > 120);


    printf("Enter your initial (A-Z): ");
    fscanf(stdin, " %c", &initial);
    do {
        printf("Invalid input. Try again.\n");
        printf("Enter you initial (A-Z): ");
        fscanf(stdin, " %c", &initial);
    }while ((initial < 'a' || initial > 'z') && (initial < 'A' || initial > 'Z'));


    printf("Enter a positive decimal: ");
    fscanf(stdin, "%f", &decimal);
    do {
        printf("Invalid input. Try again.\n");
        printf("Enter a positive decimal: ");
        fscanf(stdin, "%f", &decimal);
    }while (decimal <= 0.0);

    printf("Hello, %c. You are %d years old. Your number: %f", initial, age, decimal);
}