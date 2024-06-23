#ifndef C_BLOG_COMMENT_MANAGER_H
#define C_BLOG_COMMENT_MANAGER_H

#include "../Comment.h"
#include "../list/linked_list.h"

void display_comments(const LinkedList* comments);

void display_comment(Comment* comment);

void add_comment(void);

LinkedList* read_comments(long post_id);

#endif //C_BLOG_COMMENT_MANAGER_H
