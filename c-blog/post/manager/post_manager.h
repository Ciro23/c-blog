#ifndef post_manager_h
#define post_manager_h

#include <stdio.h>
#include "../Post.h"

void create_post(void);

Post ask_for_post_info(void);

void store_post(Post post);

long generate_id(void);

#endif /* post_h */
