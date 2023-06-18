#include "comment_manager.h"
#include "../../utils/numbers.h"
#include "../../persistence/file/file_persistence.h"
#include <stdio.h>

void display_comment(Comment comment) {
    printf("========================================\n");
    printf("Id: %li\n", comment.id);
    printf("Author: %s\n", comment.author);
    printf("%s\n", comment.body);
}

void display_comments(Comment comments[], size_t number_of_comments) {
    printf("========================================\n");
    printf("Comments\n");
    for (int i = 0; i < number_of_comments; i++) {
        Comment comment = comments[i];
        display_comment(comment);
    }
}

void add_comment() {
    Comment comment = read_comment_from_file(stdin, 1);
    comment.id = generate_random_number();

    store_comment(comment);
    display_comment(comment);
}

void read_comments(long post_id, Comment* comments, size_t number_of_comments) {
    read_post_comments(post_id, comments, number_of_comments);
}
