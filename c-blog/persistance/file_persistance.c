#include "persistance.h"
#include "../post/Post.h"
#include <sys/types.h>
#include <pwd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "paths.h"

static void write_post_information(FILE* file, Post post) {
    fprintf(file, "%ld\n", post.id);
    fprintf(file, "%s\n", post.author);
    fprintf(file, "%s\n", post.title);
    fprintf(file, "%s\n", post.body);
}

/*
 * Folders needed for storing data are not
 * created by default.
 * Currently it's only
 * {home_directory}/c-blog/posts
 *
 * TODO: Automatically create persistance folders
 */
void store_post(Post post) {
    char id_string[7];
    sprintf(id_string, "%ld", post.id);
    
    char post_path[PATH_MAX];
    get_post_path(id_string, post_path);
    
    FILE* file = fopen(post_path, "w");
    
    if (file == NULL) {
        // TODO: manage error for writing to file
        return;
    }
    
    write_post_information(file, post);

    fclose(file);
}

Post read_post(FILE* file, int show_user_messages) {
    Post post;
    
    if (show_user_messages) {
        printf("What's your username?\n");
    }
    fgets(post.author, SIZE_OF_AUTHOR, file);
    
    if (show_user_messages) {
        printf("What's the title?\n");
    }
    fgets(post.title, SIZE_OF_TITLE, file);
    
    if (show_user_messages) {
        printf("Write the body\n");
    }
    fgets(post.body, SIZE_OF_BODY, file);
    
    return post;
}
