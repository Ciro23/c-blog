#ifndef persistance_h
#define persistance_h

#include <stdio.h>
#include "../post/Post.h"

void store_post(Post post);

Post read_post(FILE* file, int show_user_messages);

static void get_home_path(char* home_path);

static void write_post_information(FILE* file, Post post);

#endif /* persistance_h */
