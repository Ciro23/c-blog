#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

long generate_random_number() {
    return rand() % 1000000;
}

void read_string(char *string, const int length, FILE* file) {
    fgets(string, length, file);
    while (*string != '\n') {
        string++;
    }
    *string = '\0';
}

void read_integer(int *integer, FILE* file) {
    char input[20];

    read_string(input, sizeof(input), file);
    *integer = atoi(input);
}

void read_long(long *value, FILE* file) {
    char input[30];

    read_string(input, sizeof(input), file);
    *value = atol(input);
}
