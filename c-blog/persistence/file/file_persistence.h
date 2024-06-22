#ifndef file_persistence_h
#define file_persistence_h

#include "../../post/Post.h"
#include "persistence.h"

Post read_post_from_file(FILE* file, int reading_from_cli);

Comment read_comment_from_file(FILE* file, int reading_from_cli);

#endif /* file_persistence_h */
