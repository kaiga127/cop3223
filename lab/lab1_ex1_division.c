#include <stdio.h>

int main(void) {
    printf("7 / 2 = %d\n", 7/2);

    printf("7.0 / 2 = %.6f\n", 7.0/2);

    printf("7 / 2.0 = %.6f\n", 7/2.0);

    printf("(double)7 / 2 = %.6f\n", (double)7/2);

    printf("(double)(7 / 2) = %.6f\n", (double)(7/2));

    printf("7 %% 2 = %d\n", 7%2);

    printf("-7 / 2 = %d\n", -7/2);

    printf("-7 %% 2 = %d\n", -7%2);
}