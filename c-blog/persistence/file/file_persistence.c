#include "file_persistence.h"
#include <limits.h>
#include <stdlib.h>
#include "paths.h"
#include "../../utils/utils.h"

/**
 * The post information is stored in sequential lines, in the
 * order: id, author, title, body.
 */
static void write_post_information(FILE* file, Post post) {
    fprintf(file, "%ld\n", post.id);
    fprintf(file, "%s\n", post.author);
    fprintf(file, "%s\n", post.title);
    fprintf(file, "%s\n", post.body);
}

/**
 * The comment information is stored in sequential lines, in the
 * order: id, post id, author, body.
 */
static void write_comment_information(FILE* file, Comment comment) {
    fprintf(file, "%ld\n", comment.id);
    fprintf(file, "%ld\n", comment.post_id);
    fprintf(file, "%s\n", comment.author);
    fprintf(file, "%s\n", comment.body);
}

/**
 * Folders needed for storing data are not
 * created by default.
 * TODO: automatically create required paths:
 * {home_directory}/c-blog/posts
 * and {home_directory}/c-blog/comments
 */
void store_post(const Post post) {
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

Post read_post(const long id) {
    char post_path[PATH_MAX] = {"\0"};
    get_post_path(id, post_path);
    
    FILE* file = fopen(post_path, "r");
    
    if (file == NULL) {
        // TODO: manage error for reading from file
    }

    const Post post = read_post_from_file(file, 0);
    fclose(file);

    return post;
}

Post read_post_from_file(FILE* file, const int print_output_messages) {
    Post post;

    // When it's been read from cli, the id is yet to be generated.
    if (print_output_messages) {
        post.id = 0;
    } else {
        read_long(&post.id, file);
    }
    
    if (print_output_messages) {
        printf("What's your username?\n");
    }
    read_string(post.author, sizeof post.author, file);

    if (print_output_messages) {
        printf("What's the title?\n");
    }
    read_string(post.title, sizeof post.title, file);

    if (print_output_messages) {
        printf("Write the body:\n");
    }
    read_string(post.body, sizeof post.body, file);

    return post;
}

void store_comment(const Comment comment) {
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

void read_post_comments(const long post_id, Comment* comments, size_t number_of_coments) {
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

Comment read_comment_from_file(FILE* file, const int print_output_messages) {
    Comment comment;

    // When it's been read from cli, the id is yet to be generated.
    if (print_output_messages) {
        comment.id = 0;
    } else {
        read_long(&comment.id, file);
    }

    if (print_output_messages) {
        printf("What's the post id?\n");
    }
    read_long(&comment.post_id, file);

    if (print_output_messages) {
        printf("What's your username?\n");
    }
    read_string(comment.author, sizeof comment.author, file);

    if (print_output_messages) {
        printf("What's your comment?\n");
    }
    read_string(comment.body, sizeof comment.body, file);

    return comment;
}
