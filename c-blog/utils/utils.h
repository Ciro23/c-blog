#ifndef C_BLOG_NUMBERS_H
#define C_BLOG_NUMBERS_H
#include <stdio.h>

long generate_random_number(void);

void read_string(char *string, int length, FILE* file);
void read_integer(int *integer, FILE* file);
void read_long(long *value, FILE* file);

#endif //C_BLOG_NUMBERS_H
