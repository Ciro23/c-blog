#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long generate_random_number() {
    return rand() % 1000000;
}

int read_string(char *string, const int maxLength, FILE* stream) {
    const char* result = fgets(string, maxLength, stream);
    while (*string != '\n') {
        string++;
    }
    *string = '\0';

    return result != NULL;
}

int read_integer(int *integer, FILE* stream) {
    char input[20];

    const int result = read_string(input, sizeof(input), stream);
    *integer = atoi(input);

    return result;
}

int read_long(long *value, FILE* stream) {
    char input[30];

    const int result = read_string(input, sizeof(input), stream);
    *value = atol(input);

    return result;
}

void remove_file_extension(char* filename) {
    // Finds the last dot in the string.
    char* dot = strrchr(filename, '.');
    if (dot != NULL) {
        // Terminates the string at the position of the dot.
        *dot = '\0';
    }
}
