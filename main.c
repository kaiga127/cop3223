#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "roster.h"

int main(void) {
    int choice;
    Roster roster = {
        .count = 0
    };

    do {
        printf("\n= Student Roster System =\n");
        printf("1. Add student\n");
        printf("2. Remove student (by ID)\n");
        printf("3. Find student (by ID)\n");
        printf("4. Find student (by last name)\n");
        printf("5. Sort by name\n");
        printf("6. Sort by GPA\n");
        printf("7. Print roster\n");
        printf("8. Quit\n");

        printf("Enter choice (1-8): ");
        fscanf(stdin, "%d", &choice);
        while (choice < 1 || choice > 8) {
            printf("Invalid choice. Try again.\n");
            printf("Enter choice (1-8): ");
            fscanf(stdin, "%d", &choice);
        }

        switch (choice) {
            case 1: 
                char first_name[32];
                char last_name[32];
                int id;
                double gpa;
                printf("First Name: ");
                fscanf(stdin, "%s", first_name);
                printf("Last Name: ");
                fscanf(stdin, "%s", last_name);
                printf("Student ID: ");
                fscanf(stdin, "%d", &id);
                printf("GPA: ");
                fscanf(stdin, "%lf", &gpa);

                Student student = create_student(first_name, last_name, id, gpa);
                int ros_add_res = roster_add(&roster, student);

                if (ros_add_res == 1) {
                    printf("Student added.\n"); break;
                } else if (ros_add_res == 0) {
                    printf("Roster Full, Student Not Added\n"); break;
                } else if (ros_add_res == -1) {
                    printf("ID Already Exists, Student Not Added\n"); break;
                }
                break;
            case 2:
                printf("Enter student ID: ");
                fscanf(stdin, "%d", &id);

                int ros_rem_res = roster_remove(&roster, id);

                if (ros_rem_res == 1) {
                    printf("Student removed.\n"); break;
                } else if (ros_rem_res == 0) {
                    printf("Student Not Found\n"); break;
                }
                break;
            case 3:
                printf("Enter student ID: ");
                fscanf(stdin, "%d", &id);

                Student *p = roster_find_by_id(&roster, id);
                
                if (p == NULL) {
                    printf("Student not found.\n"); break;
                } else {
                    print_student(p); break;
                }
                
            case 4:
                printf("Enter last name: ");
                fscanf(stdin, "%s", last_name);

                Student *q = roster_find_by_name(&roster, last_name);

                if (q == NULL) {
                    printf("Student not found.\n"); break;
                } else {
                    print_student(q); break;
                }
            case 5:
                roster_sort_by_name(&roster);
                break;
            case 6:
                roster_sort_by_gpa(&roster);
                break;
            case 7:
                print_roster(&roster);
                break;
            case 8: printf("Goodbye!\n"); break;
        }

    } while (choice != 8);

    return 0;
}