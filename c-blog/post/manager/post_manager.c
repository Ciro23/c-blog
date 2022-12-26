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
    Post post = ask_for_post_info();
    post.id = generate_id();
    store_post(post);
    display_post(post);
}

Post ask_for_post_info() {
    Post post;
    
    printf("What's your username?\n");
    fgets(post.author, SIZE_OF_AUTHOR, stdin);
    
    printf("What's the title?\n");
    fgets(post.title, SIZE_OF_TITLE, stdin);
    
    printf("Write the body\n");
    fgets(post.body, SIZE_OF_BODY, stdin);
    
    return post;
}

long generate_id() {
    return rand() % 1000000;
}
