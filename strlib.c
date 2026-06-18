#include "strlib.h"

int str_length(const char *s) {
    /* TODO: walk s with a pointer until '\0', count steps */
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        counter++;
    }
    return counter;
}

void str_copy(char *dst, const char *src, int dst_size) {
    /* TODO: copy characters one at a time, stop at dst_size-1 or '\0' */
    /* Always null-terminate dst */
    return 0;
}

int str_compare(const char *a, const char *b) {
    /* TODO: walk both strings simultaneously, return first difference */
    return 0;
}

void str_reverse(char *s) {
    
    return 0;
}

int str_count_char(const char *s, char c) {
    int counter = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == c) {
            counter++;
        }
    }
    return counter;
}

void str_to_upper(char *s) {
    /* TODO: for each char, if 'a' <= c <= 'z', subtract 32 */

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    }

    return 0;
}

void array_stats(const int arr[], int len, int *out_min, int *out_max, double *out_avg) {
    /* TODO: handle len <= 0 case; otherwise scan for min/max/sum */
    return 0;
}

int array_find(const int arr[], int len, int target) {
    /* TODO: linear scan; return index or -1 */
    return -1;
}