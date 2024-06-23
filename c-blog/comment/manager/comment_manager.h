#ifndef C_BLOG_COMMENT_MANAGER_H
#define C_BLOG_COMMENT_MANAGER_H

#include "../list/linked_list.h"

// This function is passed as a callback which parameter
// is a void pointer. On Linux it works correctly even if
// the parameter is declared as Comment*, but on macOS it
// doesn't compile, so this is why it's declared as void*.
// It's not a really good solution.
/**
 * Prints a comment humanly readable.
 * @param comment The comment to display.
 * @param show_header Must be 2 for true, for some reasons.
 */
void display_comment(void* comment, int show_header);

void display_comments(const LinkedList* comments);
void add_comment(void);
LinkedList* read_comments(long post_id);

#endif //C_BLOG_COMMENT_MANAGER_H
