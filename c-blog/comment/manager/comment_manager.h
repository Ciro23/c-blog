#ifndef C_BLOG_COMMENT_MANAGER_H
#define C_BLOG_COMMENT_MANAGER_H

#include <stddef.h>
#include "../Comment.h"

void display_comments(Comment comments[], size_t number_of_comments);

void display_comment(Comment comment);

void add_comment(void);

void read_comments(long post_id, Comment* comments, size_t number_of_comments);

#endif //C_BLOG_COMMENT_MANAGER_H
