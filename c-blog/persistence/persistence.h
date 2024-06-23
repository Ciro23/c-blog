#ifndef persistence_h
#define persistence_h

#include "../post/Post.h"
#include "../comment/Comment.h"
#include "../list/linked_list.h"

void store_post(Post post);

Post read_post(long id);

void store_comment(Comment comment);

int get_number_of_comments(long post_id);

LinkedList* read_post_comments(long post_id);

#endif /* persistence_h */
