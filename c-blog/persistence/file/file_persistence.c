#include "file_persistence.h"
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "paths.h"

static void write_post_information(FILE* file, Post post) {
    // TODO: it's not actually needed to store the id twice!
    // it's already in the file name!
    fprintf(file, "%ld\n", post.id);
    fprintf(file, "%s\n", post.author);
    fprintf(file, "%s\n", post.title);
    fprintf(file, "%s\n", post.body);
}

static void write_comment_information(FILE* file, Comment comment) {
    fprintf(file, "%ld\n", comment.id);
    fprintf(file, "%s\n", comment.author);
    fprintf(file, "%s\n", comment.body);
}

/*
 * Folders needed for storing data are not
 * created by default.
 * TODO: automatically create required paths:
 * {home_directory}/c-blog/posts
 * and {home_directory}/c-blog/comments
 */
void store_post(Post post) {
    char post_path[PATH_MAX] = {"\0"};
    get_post_path(post.id, post_path);
    
    FILE* file = fopen(post_path, "w");
    
    if (file == NULL) {
        // TODO: manage error for writing to file
        return;
    }
    
    write_post_information(file, post);

    fclose(file);
}

Post read_post(long id) {
    char post_path[PATH_MAX] = {"\0"};
    get_post_path(id, post_path);
    
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

    // When it's been read from cli, the id does
    // not exist yet
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

void store_comment(Comment comment) {
    char comments_path[PATH_MAX] = {"\0"};
    get_comments_path(comment.post_id, comments_path);

    FILE* file = fopen(comments_path, "w");

    if (file == NULL) {
        // TODO: manage error for writing to file
        return;
    }

    write_comment_information(file, comment);

    fclose(file);
}

void read_post_comments(long post_id, Comment* comments, size_t number_of_coments) {
    char comments_path[PATH_MAX] = {"\0"};
    get_comments_path(post_id, comments_path);

    FILE *file = fopen(comments_path, "r");

    if (file == NULL) {
        // TODO: manage error for reading from file
    }

    for (int i = 0; i < number_of_coments; i++) {
        comments[i] = read_comment_from_file(file, 0);
    }

    fclose(file);
}

Comment read_comment_from_file(FILE* file, int reading_from_cli) {
    Comment comment;

    // When it's been read from cli, the id does
    // not exist yet
    if (!reading_from_cli) {
        // Long requires 6 bytes, remaining ones
        // are for "\n"
        char comment_id_string[8];
        fgets(comment_id_string, sizeof(comment_id_string), file);
        comment.id = atol(comment_id_string);
    }

    if (reading_from_cli) {
        printf("What's the post id?\n");
    }
    fscanf(file, "%li", &comment.post_id);

    fflush(file);

    if (reading_from_cli) {
        printf("What's your username?\n");
    }
    fgets(comment.author, SIZE_OF_AUTHOR, file);

    // Replace "\n" with end of string characters
    comment.author[strcspn(comment.author, "\n")] = '\0';

    if (reading_from_cli) {
        printf("What's your comment?\n");
    }
    fgets(comment.body, SIZE_OF_BODY, file);
    comment.body[strcspn(comment.body, "\n")] = '\0';

    return comment;
}
