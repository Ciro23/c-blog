#include "comment_manager.h"
#include "../../utils/numbers.h"
#include "../../persistence/file/file_persistence.h"
#include <stdio.h>

void display_comment(Comment comment) {
    printf("========================================\n");
    printf("Id: %li\n", comment.id);
    printf("Author: %s\n", comment.author);
    printf("%s\n", comment.body);
    printf("========================================\n");
}

void add_comment() {
    Comment comment = read_comment_from_file(stdin, 1);
    comment.id = generate_random_number();

    store_comment(comment);
    display_comment(comment);
}
