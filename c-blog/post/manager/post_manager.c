#include "../../persistance/persistance.h"
#include "post_manager.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void display_post(Post post) {
    printf("========================================\n");
    printf("Title: %s\n", post.title);
    printf("Author: %s\n\n", post.author);
    printf("%s\n", post.body);
    printf("========================================\n");
}

void create_post() {
    Post post = read_post(stdin, 1);
    post.id = generate_id();
    store_post(post);
    display_post(post);
}

    return rand() % 1000000;
}
