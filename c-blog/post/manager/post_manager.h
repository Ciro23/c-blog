#ifndef post_manager_h
#define post_manager_h

#include "../post.h"
#include "../list/linked_list.h"

// This function is passed as a callback which parameter
// is a void pointer. On Linux it works correctly even if
// the parameter is declared as Post*, but on macOS it
// doesn't compile, so this is why it's declared as void*.
// It's not a really good solution.
/**
 * Prints a post humanly readable.
 * @param post The post to display.
 * @param show_header Must be 2 for true, for some reasons.
 */
void display_post(void* post, int show_header);

void display_posts(const LinkedList* posts);
void create_post(void);
Post get_post_from_id(long id);
LinkedList* get_all_posts();

#endif /* post_manager_h */
