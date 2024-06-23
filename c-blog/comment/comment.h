#ifndef comment_h
#define comment_h

#define SIZE_OF_AUTHOR 32
#define SIZE_OF_BODY 256

typedef struct {
    long id;
    long post_id;
    char author[SIZE_OF_AUTHOR];
    char body[SIZE_OF_BODY];
} Comment;

#endif //comment_h
