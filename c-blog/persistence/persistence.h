#ifndef persistence_h
#define persistence_h

#include "../post/Post.h"

void store_post(Post post);

Post read_post(long id);

#endif /* persistence_h */
