#include <stdio.h>

int main(void) {
    char name[64];
    fscanf(stdin, "%63s", name);

    printf("%s\n", name);

    int score;
    float total;
    for (int i = 0; i < 5; i++) {
        fscanf(stdin, "%d", &score);
        printf("%d\n", score);
        printf("i = %d\n", i);
        total += score; 
        printf("%f\n", total);
}

}