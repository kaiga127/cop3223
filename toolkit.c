#include <stdio.h>

#include "mathlib.h"

int main(void) {
    int choice;

    do {
        printf("\n= Math Toolkit =\n");
        printf("1. Clamp a value\n");
        printf("2. Compute a power\n");
        printf("3. Prime check\n");
        printf("4. GCD\n");
        printf("5. Array average\n");
        printf("6. Count digits\n");
        printf("7. Quit\n");

        printf("Enter choice (1-7):\n");
        fscanf(stdin, "%d", &choice);
        while (choice < 1 || choice > 7) {
            printf("Invalid choice. Try again.\n");
            printf("Enter choice (1-7): ");
            fscanf(stdin, "%d", &choice);
        }
        
        switch (choice) {
            case 1: 
                int value;
                int lo;
                int hi;
                printf("Enter value, lo, hi: ");
                fscanf(stdin, "%d", &value);
                fscanf(stdin, "%d", &lo);
                fscanf(stdin, "%d", &hi);
                int clamp_res = clamp(value, lo, hi); 
                printf("clamp (%d, %d, %d) = %d\n", value, lo, hi, clamp_res);
                break;
            case 2: 
                double base;
                int exp;
                printf("Enter base and exponent: ");
                fscanf(stdin, "%lf", &base);
                fscanf(stdin, "%d", &exp);
                double power_res = power(base, exp); 
                printf("power(%.2f, %d) = %.2f\n", base, exp, power_res);
                break;
            case 3: 
                int n;
                printf("Enter n: ");
                fscanf(stdin, "%d", &n);
                int prime_res = is_prime(n); 
                if (prime_res == 1) {
                    printf("%d is prime.\n", n);
                } else if (prime_res == 0) {
                    printf("%d is not prime.\n", n);
                }
                break;
            case 4: 
                int a;
                int b;
                printf("Enter a and b: ");
                fscanf(stdin, "%d", &a);
                fscanf(stdin, "%d", &b);
                int gcd_res = gcd(a, b); 
                printf("gcd(%d, %d) = %d\n", a, b, gcd_res);
                break;
            case 5: {
                int len;
                printf("Enter count then values: ");
                fscanf(stdin, "%d", &len);
                int arr[len];
                for (int p = 0; p < len; p++) {
                    fscanf(stdin, "%d", &arr[p]);}
                double ave_res = average(arr, len); 
                printf("average = %.2f\n", ave_res);
                break;}
            case 6: 
                long long c;
                printf("Enter integer: ");
                fscanf(stdin, "%lld", &c); 
                int count_res = count_digits(c); 
                printf("%lld has %d digits.\n", c, count_res);
                break;
            case 7: printf("Goodbye!\n"); break;
        }

    } while (choice != 7);

    return 0;
}