#ifndef C_BLOG_NUMBERS_H
#define C_BLOG_NUMBERS_H
#include <stdio.h>

long generate_random_number(void);

/**
 * Comfortably reads a string as everybody would expect, removing
 * end-of-line characters and all.
 * @param string The string being read.
 * @param maxLength The maximum length of the string being read.
 * @param stream A file stream, stdin...
 * @return 0 if end-of-file is encountered, or an error occurred.
 */
int read_string(char *string, int maxLength, FILE* stream);

/**
 * Comfortably reads an integer as everybody would expect, removing
 * end-of-line characters and all.
 * @param integer The integer being read.
 * @param stream A file stream, stdin...
 * @return 0 if end-of-file is encountered, or an error occurred.
 */
int read_integer(int *integer, FILE* stream);

/**
 * Comfortably reads a long as everybody would expect, removing
 * end-of-line characters and all.
 * @param value The long being read.
 * @param stream A file stream, stdin...
 * @return 0 if end-of-file is encountered, or an error occurred.
 */
int read_long(long *value, FILE* stream);

void remove_file_extension(char *filename);

#endif //C_BLOG_NUMBERS_H
