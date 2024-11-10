#include "paths.h"
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

void get_posts_path(char* posts_path) {
    char home_path[PATH_MAX];
    get_home_path(home_path);

    strcat(posts_path, home_path);
    strcat(posts_path, "/posts/");
}

/**
 * Given file_name (extension excluded), its full
 * path is saved inside post_path
 */
void get_post_path(const long id, char* post_path) {
    char file_name[7];
    sprintf(file_name, "%ld", id);

    const char* file_extension = ".txt";

    char posts_path[PATH_MAX] = {"\0"};
    get_posts_path(posts_path);
    
    strcat(post_path, posts_path);
    strcat(post_path, file_name);
    strcat(post_path, file_extension);
}

/**
 * Given a post id, the file path containing all its
 * comments are stored inside comment_path
 */
void get_comments_path(const long post_id, char* comment_path) {
    char file_name[7];
    sprintf(file_name, "%ld", post_id);

    const char* file_extension = ".txt";
    const char* comments_path = "/comments/";

    char home_path[PATH_MAX];
    get_home_path(home_path);

    strcat(comment_path, home_path);
    strcat(comment_path, comments_path);
    strcat(comment_path, file_name);
    strcat(comment_path, file_extension);
}

/**
 * Returns the path which contains all data related
 * to this program.
 * E.g. /Users/ciro23/c-blog on macOS,
 * /home/ciro23/c-blog on Linux
 */
void get_home_path(char* home_path) {
    const char *homedir;

    if ((homedir = getenv("HOME")) == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
    }
    
    strcpy(home_path, homedir);
    strcat(home_path, "/.c-blog");
}
