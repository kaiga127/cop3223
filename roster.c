#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "roster.h"

Student  create_student(const char *first, const char *last, int id, double gpa) {
    Student s = {
        .student_id = id,
        .gpa = gpa
    };
    strncpy(s.first_name, first, sizeof(s.first_name) - 1);
    s.first_name[sizeof(s.first_name) - 1] = '\0';
    strncpy(s.last_name, last, sizeof(s.last_name) - 1);
    s.last_name[sizeof(s.last_name) - 1] = '\0';

    if (s.gpa <= 4.0 && s.gpa >= 3.5) {
        s.standing = GRADE_A;
    } else if (s.gpa <= 3.49 && s.gpa >= 3.0) {
        s.standing = GRADE_B;
    } else if (s.gpa <= 2.99 && s.gpa >= 2.0) {
        s.standing = GRADE_C;
    } else if (s.gpa <= 1.99 && s.gpa >= 1.0) {
        s.standing = GRADE_D;
    } else if (s.gpa < 1.0) {
        s.standing = GRADE_F;
    } else if (s.gpa >= 4.0 || s.gpa <= 0.0) {
        s.standing = GRADE_INVALID;
    }

    return s;
}

int      roster_add(Roster *r, Student s) {
    for (int i = 0; i < r->count; i++) {
        if (r->students[i].student_id == s.student_id) {
            return -1;
        }
    }

    if (r->count == MAX_STUDENTS) {
        return 0;
    }

    r->students[r->count] = s;
    r->count++;
    return 1;
}

int      roster_remove(Roster *r, int student_id) {
    for (int i = 0; i < r->count; i++) {
        if (student_id == r->students[i].student_id) {
            for (int y = i; y < r->count - 1; y++) {
                r->students[y] = r->students[y + 1];
            }
            r->count--;
            return 1;
        }
    }
    return 0;
}

Student *roster_find_by_id(Roster *r, int student_id) {
    for (int i = 0; i < r->count; i++) {
        if (student_id == r->students[i].student_id) {
            return &r->students[i];
        }
    }
    return NULL;
}

Student *roster_find_by_name(Roster *r, const char *last_name) {
    for (int i = 0; i < r->count; i++) {
        if (strcmp(r->students[i].last_name, last_name) == 0) {
            return &(r->students[i]);
        }
    }
    return NULL;
}

void     roster_sort_by_name(Roster *r) {
    for(int i = 0; i < r->count - 1; i++) {
        for(int j = 0; j < r->count - i - 1; j++) {
            if(strcmp(r->students[j].last_name, r->students[j+1].last_name) > 0) {
                Student temp = r->students[j];
                r->students[j] = r->students[j+1];
                r->students[j+1] = temp;
            } else if (strcmp(r->students[j].last_name, r->students[j+1].last_name) == 0) {
                if(strcmp(r->students[j].first_name, r->students[j+1].first_name) > 0) {
                    Student temp = r->students[j];
                    r->students[j] = r->students[j+1];
                    r->students[j+1] = temp;
                }
            }
        }
    }
}

void     roster_sort_by_gpa(Roster *r) {
    for(int i = 0; i < r->count - 1; i++) {
        for(int j = 0; j < r->count - i - 1; j++) {
            if(r->students[j].gpa < r->students[j+1].gpa) {
                Student temp = r->students[j];
                r->students[j] = r->students[j+1];
                r->students[j+1] = temp;
            }
        }
    }
}

void     print_student(const Student *s) {
    printf("[%d]    %s, %s  GPA: %.2f    Standing: %s\n", s->student_id, s->last_name, s->first_name, s->gpa, grade_to_string(s->standing));
}

void     print_roster(const Roster *r) {
    printf("\n╔══════════════════════════════════════════════════╗\n");
    printf("║  Student Roster (%d students)                    ║\n", r->count);
    printf("╠══════════════════════════════════════════════════╣\n");
    for (int i = 0; i < r->count; i++) {
        print_student(&r->students[i]);
    }
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║  Class average GPA: %.2f                         ║\n", roster_average_gpa(r));
    printf("╚══════════════════════════════════════════════════╝\n");
}

const char *grade_to_string(Grade g) {
    switch (g) {
        case 0: return "A";
        case 1: return "B";
        case 2: return "C";
        case 3: return "D";
        case 4: return "F";
        case 5: return "Incomplete";
        default: return "Incomplete";
    }
}

double   roster_average_gpa(const Roster *r) {
    double sum = 0.0;

    for (int i = 0; i < r->count; i++) {
        sum += r->students[i].gpa;
    }

    return sum / r->count;
}
