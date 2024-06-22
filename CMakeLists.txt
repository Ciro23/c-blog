cmake_minimum_required(VERSION 3.24)
project(c_blog C)

set(CMAKE_C_STANDARD 11)

include_directories(c-blog/menu)
include_directories(c-blog/persistence)
include_directories(c-blog/persistence/file)
include_directories(c-blog/persistence/file/paths)
include_directories(c-blog/post)
include_directories(c-blog/post/manager)

file(MAKE_DIRECTORY ~/c-blog/posts)
file(MAKE_DIRECTORY ~/c-blog/comments)

add_executable(
        c_blog
        c-blog/menu/menu.c
        c-blog/menu/menu.h
        c-blog/persistence/file/paths/paths.c
        c-blog/persistence/file/paths/paths.h
        c-blog/persistence/file/file_persistence.c
        c-blog/persistence/file/file_persistence.h
        c-blog/persistence/persistence.h
        c-blog/post/manager/post_manager.c
        c-blog/post/manager/post_manager.h
        c-blog/post/Post.h
        c-blog/main.c
        c-blog/comment/Comment.h c-blog/comment/manager/comment_manager.c c-blog/comment/manager/comment_manager.h c-blog/utils/utils.c c-blog/utils/utils.h)
