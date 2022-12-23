#include "post_manager.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

void create_post() {
    Post post = ask_for_post_info();
}

Post ask_for_post_info() {
    Post post;
    
    printf("What's your username?\n");
    scanf("%s", post.author);
    
    printf("What's the title?\n");
    scanf("%s", post.title);
    
    printf("Write the body\n");
    scanf("%s", post.body);
    
    return post;
}

long generate_id() {
    return rand() % 1000000;
}
