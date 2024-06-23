#include "comment_manager.h"
#include "../../utils/utils.h"
#include "../../persistence/file/file_persistence.h"
#include <stdio.h>

static void display_comment_without_header(void* comment) {
    display_comment(comment, 0);
}

void display_comment(void* comment, const int show_header) {
    Comment* actual_comment = comment;

    if (show_header == 2) {
        printf("========================================\n");
        printf("Comment\n");
        printf("========================================\n");
    }
    printf("Id: %li\n", actual_comment->id);
    printf("Author: %s\n", actual_comment->author);
    printf("Message: %s\n", actual_comment->body);
    printf("----------------------------------------\n");
}

void display_comments(const LinkedList* comments) {
    printf("========================================\n");
    printf("Comments\n");
    printf("========================================\n");
    traverse_list(comments, display_comment_without_header);
}

void add_comment() {
    Comment comment;
    read_comment_from_stream(stdin, &comment, 1);
    comment.id = generate_random_number();

    store_comment(comment);
    display_comment(&comment, 2);
}

LinkedList* read_comments(const long post_id) {
    return read_post_comments(post_id);
}
