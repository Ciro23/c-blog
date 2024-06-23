#ifndef paths_h
#define paths_h

void get_posts_path(char* posts_path);
void get_post_path(long id, char* post_path);

void get_comments_path(long post_id, char* comment_path);

void get_home_path(char* home_path);

#endif /* paths_h */
