#ifndef C_BLOG_COMMENT_MANAGER_H
#define C_BLOG_COMMENT_MANAGER_H

#include "../comment.h"
#include "../list/linked_list.h"

void display_comments(const LinkedList* comments);

// This function is passed as a callback which parameter
// is a void pointer. On Linux it works correctly even if
// the parameter is declared as Comment*, but on macOS it
// doesn't compile, so this is why it's declared as void*.
// It's not a really good solution.
void display_comment(void* comment);

void add_comment(void);

LinkedList* read_comments(long post_id);

#endif //C_BLOG_COMMENT_MANAGER_H
