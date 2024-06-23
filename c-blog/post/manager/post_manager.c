#include <stdio.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>

#include "../../persistence/file/file_persistence.h"
#include "post_manager.h"
#include "paths.h"
#include "../../utils/utils.h"

static void display_post_without_header(void* post) {
    display_post(post, 0);
}

void display_post(void* post, const int show_header) {
    Post* actualPost = post;

    if (show_header == 2) {
        printf("========================================\n");
        printf("Post\n");
        printf("========================================\n");
    }
    printf("Id: %li\n", actualPost->id);
    printf("Author: %s\n", actualPost->author);
    printf("Title: %s\n", actualPost->title);
    printf("Body: %s\n", actualPost->body);
    printf("----------------------------------------\n");
}

void display_posts(const LinkedList* posts) {
    printf("========================================\n");
    printf("Posts\n");
    printf("========================================\n");
    traverse_list(posts, display_post_without_header);
}

void create_post() {
    Post post = read_post_from_stream(stdin, 1);
    post.id = generate_random_number();

    store_post(post);
    display_post(&post, 2);
}

Post get_post_from_id(const long id) {
    return read_post(id);
}

LinkedList* get_all_posts() {
    char posts_path[PATH_MAX] = {"\0"};
    get_posts_path(posts_path);
    DIR *dir = opendir(posts_path);

    if (dir == NULL) {
        perror("Unable to open directory");
    }

    LinkedList* posts = create_list(sizeof(Post));
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char* file_name = entry->d_name;
            remove_file_extension(file_name);

            Post post = get_post_from_id(atoi(file_name));
            append(posts, &post);
        }
    }

    closedir(dir);
    return posts;
}
