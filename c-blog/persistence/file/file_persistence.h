#ifndef file_persistence_h
#define file_persistence_h

#include <stdio.h>

#include "../../post/post.h"
#include "persistence.h"

Post read_post_from_stream(FILE* stream, int print_output_messages);

int read_comment_from_stream(FILE* stream, Comment* comment, int print_output_messages);

#endif /* file_persistence_h */
