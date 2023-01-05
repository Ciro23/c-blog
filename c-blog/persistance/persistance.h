#ifndef persistance_h
#define persistance_h

#include "../post/Post.h"

void store_post(Post post);

Post read_post(long id);

#endif /* persistance_h */
