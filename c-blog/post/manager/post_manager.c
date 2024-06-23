#include "../../persistence/file/file_persistence.h"
#include "post_manager.h"
#include "../../utils/utils.h"

void display_post(Post post) {
    printf("========================================\n");
    printf("Post\n");
    printf("========================================\n");
    printf("Id: %li\n", post.id);
    printf("Author: %s\n", post.author);
    printf("Title: %s\n", post.title);
    printf("Body: %s\n", post.body);
}

void create_post() {
    Post post = read_post_from_file(stdin, 1);
    post.id = generate_random_number();
    store_post(post);
    display_post(post);
}

Post get_post_from_id(const long id) {
    return read_post(id);
}
