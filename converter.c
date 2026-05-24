#include <stdio.h>

/*these are the conversion constants*/
const double C_TO_F_SCALE  = 9.0 / 5.0;
const double F_TO_C_SCALE  = 5.0 / 9.0;
const double C_TO_F_OFFSET = 32.0;
const double MI_TO_KM      = 1.60934;
const double LB_TO_KG      = 0.453592;

void convert_temperature(void);
void convert_distance(void);
void convert_weight(void);
void convert_speed(void);


int main(void) {
    int choice;

    do {
        printf("\n= Unit Conversion Station =\n");
        printf("1. Temperature  (Celsius <-> Fahrenheit)\n");
        printf("2. Distance     (Miles <-> Kilometers)\n");
        printf("3. Weight       (Pounds <-> Kilograms)\n");
        printf("4. Speed        (MPH <-> KPH)\n");
        printf("5. Quit\n");

        printf("Enter choice (1-5): ");
        fscanf(stdin, "%d", &choice);
        while (choice < 1 || choice > 5) {
            printf("Invalid choice. Try again.\n");
            printf("Enter choice (1-5): ");
            fscanf(stdin, "%d", &choice);
        }

        switch (choice) {
            case 1: convert_temperature(); break;
            case 2: convert_distance();    break;
            case 3: convert_weight();      break;
            case 4: convert_speed();       break;
            case 5: printf("Goodbye!\n");  break;
        }

    } while (choice != 5);

    return 0;
}


void convert_temperature(void) {
    int temp_choice;
    printf("\n--- Temperature ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    printf("Enter direction (1-2): ");
    fscanf(stdin, "%d", &temp_choice);
    while (temp_choice < 1 || temp_choice > 2) {
        printf("Invalid direction. Try again.\n");
        printf("Enter direction (1-2): ");
        fscanf(stdin, "%d", &temp_choice);
    }

    if (temp_choice == 1) {
        float celsius_input;
        float fahren_output;
        printf("Enter temperature in Celsius: ");
        fscanf(stdin, "%f", &celsius_input);

        fahren_output = celsius_input * (C_TO_F_SCALE) + C_TO_F_OFFSET;

        printf("%.2f°C = %.2f°F\n", celsius_input, fahren_output);
    }

    if (temp_choice == 2) {
        float fahren_input;
        float celcius_output;
        printf("Enter temperature in Fahrenheit: ");
        fscanf(stdin, "%f", &fahren_input);

        celcius_output = (fahren_input - C_TO_F_OFFSET) * (F_TO_C_SCALE);

        printf("%.2f°F = %.2f°C\n", fahren_input, celcius_output);
    }
};

void convert_distance(void) {
    int dist_choice;
    printf("\n--- Distance ---\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Kilometers to Miles\n");

    printf("Enter direction (1-2): ");
    fscanf(stdin, "%d", &dist_choice);
    while (dist_choice < 1 || dist_choice > 2) {
        printf("Invalid direction. Try again.\n");
        printf("Enter direction (1-2): ");
        fscanf(stdin, "%d", &dist_choice);
    }

    if (dist_choice == 1) {
        float miles_input;
        float kilo_output;
        printf("Enter distance in miles: ");
        fscanf(stdin, "%f", &miles_input);

        kilo_output = miles_input * MI_TO_KM;

        printf("%.2f miles = %.2f km\n", miles_input, kilo_output);
    }

    if (dist_choice == 2) {
        float kilo_input;
        float miles_output;
        printf("Enter the distance in kilometers: ");
        fscanf(stdin, "%f", &kilo_input);

        miles_output = kilo_input / MI_TO_KM;

        printf("%.2f km = %.2f miles\n", kilo_input, miles_output);
    }
};

void convert_weight(void) {
    int weight_choice;
    printf("\n--- Weight ---\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");

    printf("Enter direction (1-2): ");
    fscanf(stdin, "%d", &weight_choice);
    while (weight_choice < 1 || weight_choice > 2) {
        printf("Invalid direction. Try again.\n");
        printf("Enter direction (1-2): ");
        fscanf(stdin, "%d", &weight_choice);
    }

    if (weight_choice == 1) {
        float pound_input;
        float kgram_output;
        printf("Enter weight in pounds: ");
        fscanf(stdin, "%f", &pound_input);

        kgram_output = pound_input * LB_TO_KG;

        printf("%.2f lb = %.2f kg\n", pound_input, kgram_output);
    }

    if (weight_choice == 2) {
        float kgram_input;
        float pound_output;
        printf("Enter weight in kilograms: ");
        fscanf(stdin, "%f", &kgram_input);

        pound_output = kgram_input / LB_TO_KG;

        printf("%.2f kg = %.2f lb\n", kgram_input, pound_output);
    }    
};

void convert_speed(void) {
    int speed_choice;
    printf("\n--- Speed ---\n");
    printf("1. MPH to KPH\n");
    printf("2. KPH to MPH\n");

    printf("Enter direction (1-2): ");
    fscanf(stdin, "%d", &speed_choice);
    while (speed_choice < 1 || speed_choice > 2) {
        printf("Invalid direction. Try again.\n");
        printf("Enter direction (1-2): ");
        fscanf(stdin, "%d", &speed_choice);
    }

    if (speed_choice == 1) {
        float mph_input;
        float kph_output;
        printf("Enter speed in MPH: ");
        fscanf(stdin, "%f", &mph_input);

        kph_output = mph_input * MI_TO_KM;

        printf("%.2f mph = %.2f kph\n", mph_input, kph_output);
    }

    if (speed_choice == 2) {
        float kph_input;
        float mph_output;
        printf("Enter speed in KPH: ");
        fscanf(stdin, "%f", &kph_input);

        mph_output = kph_input / MI_TO_KM;

        printf("%.2f kph = %.2f mph\n", kph_input, mph_output);
    }
};