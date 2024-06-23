#include "comment_manager.h"
#include "../../utils/utils.h"
#include "../../persistence/file/file_persistence.h"
#include <stdio.h>

void display_comment(void* comment) {
    Comment* actual_comment = comment;

    printf("Id: %li\n", actual_comment->id);
    printf("Author (32): %s\n", actual_comment->author);
    printf("Message (256): %s\n", actual_comment->body);
    printf("----------------------------------------\n");
}

void display_comments(const LinkedList* comments) {
    printf("========================================\n");
    printf("Comments\n");
    printf("========================================\n");
    traverse_list(comments, display_comment);
}

void add_comment() {
    Comment comment;
    read_comment_from_file(stdin, &comment, 1);
    comment.id = generate_random_number();

    store_comment(comment);
    display_comment(&comment);
}

LinkedList* read_comments(const long post_id) {
    return read_post_comments(post_id);
}
