#include "paths.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>

void get_home_path(char* home_path) {
    const char *homedir;

    if ((homedir = getenv("HOME")) == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
    }
    
    strcpy(home_path, homedir);
    strcat(home_path, "/c-blog");
}
