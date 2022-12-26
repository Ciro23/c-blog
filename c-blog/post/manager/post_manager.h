#ifndef post_manager_h
#define post_manager_h

#include <stdio.h>
#include "../Post.h"

void display_post(Post post);

void create_post(void);

Post get_post_from_id(long id);

long generate_id(void);

#endif /* post_h */
