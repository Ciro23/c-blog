#include "file_persistence.h"
#include <limits.h>
#include "paths.h"
#include "../../utils/utils.h"
#include "../../list/linked_list.h"

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
 * Parent folders needed for storing data are not
 * always created by default.
 * TODO: automatically create required paths:
 * {home_directory}/.c-blog/posts
 * and {home_directory}/.c-blog/comments
 */
void store_post(const Post post) {
    char post_path[PATH_MAX] = {"\0"};
    get_post_path(post.id, post_path);
    
    FILE* file = fopen(post_path, "w");
    
    if (file == NULL) {
        perror("Error writing to filesystem to persist the post information");
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
        perror("Cannot read the post from the filesystem");
    }

    const Post post = read_post_from_stream(file, 0);
    fclose(file);

    return post;
}

Post read_post_from_stream(FILE* stream, const int print_output_messages) {
    Post post;

    // When it's been read from cli, the id is yet to be generated.
    if (print_output_messages) {
        post.id = 0;
    } else {
        read_long(&post.id, stream);
    }
    
    if (print_output_messages) {
        printf("What's your username (32)?\n");
    }
    read_string(post.author, sizeof post.author, stream);

    if (print_output_messages) {
        printf("What's the title (128)?\n");
    }
    read_string(post.title, sizeof post.title, stream);

    if (print_output_messages) {
        printf("Write the body (256):\n");
    }
    read_string(post.body, sizeof post.body, stream);

    return post;
}

void store_comment(const Comment comment) {
    char comments_path[PATH_MAX] = {"\0"};
    get_comments_path(comment.post_id, comments_path);

    FILE* file = fopen(comments_path, "a");

    if (file == NULL) {
        perror("Error writing to filesystem to persist the comment information");
        return;
    }

    write_comment_information(file, comment);
    fclose(file);
}

LinkedList* read_post_comments(const long post_id) {
    char comments_path[PATH_MAX] = {"\0"};
    get_comments_path(post_id, comments_path);

    FILE *file = fopen(comments_path, "r");
    LinkedList* comments = create_list(sizeof(Comment));

    if (file == NULL) {
        return comments;
    }

    Comment comment;
    while (read_comment_from_stream(file, &comment, 0)) {
        append(comments, &comment);
    }

    fclose(file);
    return comments;
}

int read_comment_from_stream(FILE* stream, Comment* comment, const int print_output_messages) {
    // When it's been read from cli, the id is yet to be generated.
    if (print_output_messages) {
        comment->id = 0;
    } else if (read_long(&comment->id, stream) != 1) {
        return 0;
    }

    if (print_output_messages) {
        printf("What's the post id?\n");
    }
    if (read_long(&comment->post_id, stream) != 1) {
        return 0;
    }

    if (print_output_messages) {
        printf("What's your username (32)?\n");
    }
    if (read_string(comment->author, sizeof comment->author, stream) != 1) {
        return 0;
    }

    if (print_output_messages) {
        printf("What's your comment (256)?\n");
    }
    if (read_string(comment->body, sizeof comment->body, stream) != 1) {
        return 0;
    }

    return 1;
}
