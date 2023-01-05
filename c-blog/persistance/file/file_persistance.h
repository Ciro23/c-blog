#ifndef file_persistance_h
#define file_persistance_h

#include "../../post/Post.h"
#include "persistance.h"

Post read_post_from_file(FILE* file, int show_user_messages);

#endif /* file_persistance_h */
