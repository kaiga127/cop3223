#include <stdio.h>

int main(void) {
    double w;
    double h;

    get_dimensions(&w, &h);
    compute_area(w, h);
    compute_perimeter(w, h);

}

void get_dimensions(double *w, double *h) {
    printf("Enter width: ");
    fscanf(stdin, "%lf", w);
    printf("Enter height: ");
    fscanf(stdin, "%lf", h);
}

double compute_area(double w, double h) {
    double area = w * h;
}

double compute_perimeter(double w, double h) {
    double perimeter = 2.0 * (w + h);
}

void classify_rectangle(double w, double h) {

}

void print_results(double area, double perimeter) {
    printf("Area:   %.2f\n", area);
    printf("Perimeter:  %.2f\n", perimeter);
}