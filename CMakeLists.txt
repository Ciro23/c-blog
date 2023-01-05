cmake_minimum_required(VERSION 3.24)
project(c_blog C)

set(CMAKE_C_STANDARD 11)

include_directories(c-blog/menu)
include_directories(c-blog/persistance)
include_directories(c-blog/persistance/file)
include_directories(c-blog/persistance/file/paths)
include_directories(c-blog/post)
include_directories(c-blog/post/manager)

add_executable(
        c_blog
        c-blog/menu/menu.c
        c-blog/menu/menu.h
        c-blog/persistance/file/paths/paths.c
        c-blog/persistance/file/paths/paths.h
        c-blog/persistance/file/file_persistance.c
        c-blog/persistance/file/file_persistance.h
        c-blog/persistance/persistance.h
        c-blog/post/manager/post_manager.c
        c-blog/post/manager/post_manager.h
        c-blog/post/Post.h
        c-blog/main.c
)
