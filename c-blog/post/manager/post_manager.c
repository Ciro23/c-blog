#include "../../persistance/file/file_persistance.h"
#include "post_manager.h"
#include "../../utils/numbers.h"

void display_post(Post post) {
    printf("========================================\n");
    printf("Id: %li\n", post.id);
    printf("Author: %s\n", post.author);
    printf("Title: %s\n\n", post.title);
    printf("%s\n", post.body);
    printf("========================================\n");
}

void create_post() {
    Post post = read_post_from_file(stdin, 1);
    post.id = generate_random_number();
    store_post(post);
    display_post(post);
}

Post get_post_from_id(long id) {
    return read_post(id);
}
