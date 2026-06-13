#include <stdio.h>

#include "mathlib.h"

int clamp(int value, int lo, int hi) {
    if (lo < value && value < hi) {
        return value;
    } else if (value < lo) {
        return lo;
    } else if (value > hi) {
        return hi;
    }

    return 0;
}

double power(double base, int exp) {
    double ans;
    double expo = 1.0;

    if (exp < 0) {
        exp = -exp;
        for (int i = 0; i < exp; i++) {
            expo *= base;
        }
        ans = 1/expo;
    } else {
        for (int i = 0; i < exp; i++) {
            expo *= base;
        }
        ans = expo;
    }

    return ans;
}

int is_prime(int n) {
    int count = 0;
    if (n <= 1) return 0;
    else {
        for (int i = 1; i <= n; i++){
            if (n % i == 0)
            count++;
        }
        if (count > 2) return 0;
        else return 1;
    }

    return 0;
}

int gcd(int a, int b) {
    int big;
    int small;
    int rem;

    if (a > b) {
        big = a;
        small = b;
    } else {
        big = b;
        small = a;
    }

    rem = big % small;

    while (rem != 0) {
        big = small;
        small = rem;
        rem = big % small;
    }

    return small;
}

double average(int arr[], int len) {
    int sum = 0;

    for (int y = 0; y < len; y++) {
        sum += arr[y];
    }

    return (double)sum / len;
}

int count_digits(long long c) {
    if (c == 0) {
        return 1;
    }

    int count = 0;
    while (c != 0) {
        c = c/10;
        count++;
    }

    return count;
}
