#include <stdio.h>

#include "strlib.h"


int main(void) {
    int choice;

    do {
        printf("\n= String & Array Toolkit =\n");
        printf("1. String length\n");
        printf("2. String copy (with truncation demo)\n");
        printf("3. String compare\n");
        printf("4. Reverse a string\n");
        printf("5. Count a character\n");
        printf("6. Convert to uppercase\n");
        printf("7. Array stats (min/max/avg)\n");
        printf("8. Find value in array\n");
        printf("9. Quit\n");

        printf("Enter choice (1-9): ");
        fscanf(stdin, "%d", &choice);
        while (choice < 1 || choice > 9) {
            printf("Invalid choice. Try again.\n");
            printf("Enter choice (1-9): ");
            fscanf(stdin, "%d", &choice);
        }

        char s[100];
        switch (choice) {
            case 1: 
                printf("Enter string: ");
                fscanf(stdin, "%s", s);
                printf("Length: %d\n", str_length(s));
                break;
            case 2: 
                
                printf("Enter string: ");

                printf("Destination: \n");
                break;
            case 3: 
                printf("Enter string: ");

                printf(" comes before \n");

                printf(" equals \n");

                printf(" comes after \n");
                break;
            case 4:
                
                printf("Enter string: ");
                
                
                printf("Reversed: \n");
                break;
            case 5: 
                char c;
                printf("Enter string: ");
                fscanf(stdin, "%s", s);
                printf("Enter target: ");
                fscanf(stdin, " %c", &c);
                printf("Count: %d\n", str_count_char(s, c));
                break;
            case 6: 
                printf("Enter string: ");
                fscanf(stdin, "%s", s);
                str_to_upper(s);
                printf("Upper: %s\n", s);
                break;
            case 7: 
                printf("Enter count then values: ");

                printf("min=  max=  avg= \n");
                break;
            case 8: 
                printf("Enter count then values: ");
                printf("Enter target: ");

                printf("Found at index .\n");

                printf("Not found.\n");
                break;
            case 9: printf("Goodbye!\n");  break;
        }

    } while (choice != 9);

    return 0;
}