#include "paths.h"
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

/*
 * Given file_name (extension exluded), its full
 * path is saved inside post_path
 */
void get_post_path(long id, char* post_path) {
    char file_name[7];
    sprintf(file_name, "%ld", id);

    char* file_extension = ".txt";
    char* posts_path = "/posts/";
    
    char home_path[PATH_MAX];
    get_home_path(home_path);
    
    strcat(post_path, home_path);
    strcat(post_path, posts_path);
    strcat(post_path, file_name);
    strcat(post_path, file_extension);
}

/**
 * Given a post id, the file path containing all its
 * comments is stored inside comment_path
 */
void get_comments_path(long id, char* comment_path) {
    char file_name[7];
    sprintf(file_name, "%ld", id);

    char* file_extension = ".txt";
    char* comments_path = "/comments/";

    char home_path[PATH_MAX];
    get_home_path(home_path);

    strcat(comment_path, home_path);
    strcat(comment_path, comments_path);
    strcat(comment_path, file_name);
    strcat(comment_path, file_extension);
}

/*
 * Eg. /Users/ciro23 on mac,
 * /users/ciro23 on linux
 */
void get_home_path(char* home_path) {
    const char *homedir;

    if ((homedir = getenv("HOME")) == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
    }
    
    strcpy(home_path, homedir);
    strcat(home_path, "/c-blog");
}
