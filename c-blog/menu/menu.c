#include "menu.h"

#include "../post/manager/post_manager.h"
#include "../comment/manager/comment_manager.h"
#include "../utils/utils.h"

void display_choices() {
    printf("==============================\n");
    printf("1. Create post\n");
    printf("2. Add comment\n");
    printf("3. View post\n");

    // TODO: not implemented yet
    // printf("4. List of all posts\n");
    printf("==============================\n");
    
    int choice;
    printf("Enter choice: ");
    read_integer(&choice, stdin);

    call_selected_feature(choice);
}

void call_selected_feature(const int feature) {
    switch (feature) {
        case 1:
            create_post();
            break;

        case 2:
            add_comment();
            break;
            
        case 3: {
            long id;
            printf("Enter post id: ");
            read_long(&id, stdin);

            // TODO: totaly broken feature
            // const int max_number_of_comments = 100;
            // Comment comments[max_number_of_comments];
            // read_comments(id, comments, max_number_of_comments);

            const Post post = get_post_from_id(id);
            display_post(post);
            // display_comments(comments, max_number_of_comments);

            break;
        }

        default:
            printf("Unknown choice");
    }
}
