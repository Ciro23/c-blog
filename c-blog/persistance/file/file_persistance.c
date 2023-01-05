#include "file_persistance.h"
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
    
    char post_path[PATH_MAX] = {"\0"};
    get_post_path(id_string, post_path);
    
    FILE* file = fopen(post_path, "w");
    
    if (file == NULL) {
        // TODO: manage error for writing to file
        return;
    }
    
    write_post_information(file, post);

    fclose(file);
}

Post read_post(long id) {
    char id_string[7];
    sprintf(id_string, "%ld", id);
    
    char post_path[PATH_MAX] = {"\0"};
    get_post_path(id_string, post_path);
    
    FILE* file = fopen(post_path, "r");
    
    if (file == NULL) {
        // TODO: manage error for reading from file
    }
    
    Post post = read_post_from_file(file, 0);
    
    fclose(file);

    return post;
}

Post read_post_from_file(FILE* file, int reading_from_cli) {
    Post post;
    
    if (!reading_from_cli) {
        // Long requires 6 bytes, remaining ones
        // are for "\n"
        char post_id_string[8];
        fgets(post_id_string, sizeof(post_id_string), file);
        post.id = atol(post_id_string);
    }
    
    if (reading_from_cli) {
        printf("What's your username?\n");
    }
    fgets(post.author, SIZE_OF_AUTHOR, file);
    
    // Replace "\n" with end of string characters
    post.author[strcspn(post.author, "\n")] = '\0';
    
    if (reading_from_cli) {
        printf("What's the title?\n");
    }
    fgets(post.title, SIZE_OF_TITLE, file);
    post.title[strcspn(post.title, "\n")] = '\0';
    
    if (reading_from_cli) {
        printf("Write the body\n");
    }
    fgets(post.body, SIZE_OF_BODY, file);
    post.body[strcspn(post.body, "\n")] = '\0';
    
    return post;
}
