#include "comment_manager.h"
#include "../../utils/numbers.h"
#include <stdio.h>

void display_comment(Comment comment) {
    printf("========================================\n");
    printf("Id: %li\n", comment.id);
    printf("Author: %s\n", comment.author);
    printf("%s\n", comment.body);
    printf("========================================\n");
}

void add_comment() {

}