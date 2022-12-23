#include "persistance.h"
#include "../post/Post.h"
#include <sys/types.h>
#include <pwd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void get_home_path(char* home_path) {
    const char *homedir;

    if ((homedir = getenv("HOME")) == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
    }
    
    strcpy(home_path, homedir);
    strcat(home_path, "/c-blog");
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
    
    char* file_extension = ".txt";
    char* posts_path = "/posts/";
    
    char home_path[PATH_MAX];
    get_home_path(home_path);
    
    char post_path[PATH_MAX];
    strcat(post_path, home_path);
    strcat(post_path, posts_path);
    strcat(post_path, id_string);
    strcat(post_path, file_extension);
    
    FILE* file = fopen(post_path, "w");
    
    if (file == NULL) {
        // TODO: manage error for writing to file
        return;
    }
    
    fprintf(file, "%ld", post.id);
    fprintf(file, "%s", "\n");
    fprintf(file, "%s", post.author);
    fprintf(file, "%s", "\n");
    fprintf(file, "%s", post.title);
    fprintf(file, "%s", "\n");
    fprintf(file, "%s", post.body);
    fprintf(file, "%s", "\n");

    fclose(file);
}
