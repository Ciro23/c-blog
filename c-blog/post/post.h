#ifndef post_h
#define post_h

#define SIZE_OF_AUTHOR 32
#define SIZE_OF_TITLE 128
#define SIZE_OF_BODY 256

typedef struct {
    long id;
    char author[SIZE_OF_AUTHOR];
    char title[SIZE_OF_TITLE];
    char body[SIZE_OF_BODY];
} Post;

#endif /* post_h */
