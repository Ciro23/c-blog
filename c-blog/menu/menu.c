#include "menu.h"

#include <stdlib.h>

#include "../post/manager/post_manager.h"
#include "../comment/manager/comment_manager.h"
#include "../utils/utils.h"

int display_choices() {
    printf("##############################\n");
    printf("# 0. Exit                    #\n");
    printf("# 1. Create post             #\n");
    printf("# 2. Add comment             #\n");
    printf("# 3. View post               #\n");
    printf("# 4. List all posts          #\n");
    printf("##############################\n");
    
    int choice;
    printf("Enter choice: ");
    read_integer(&choice, stdin);

    call_selected_feature(choice);

    if (choice == 0) {
        return 1;
    }
    return 0;
}

void call_selected_feature(const int feature) {
    switch (feature) {
        case 0:
            printf("Bye!\n");
            break;

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

            Post post = get_post_from_id(id);
            display_post(&post, 2);

            LinkedList* comments = read_comments(id);
            if (!is_empty(comments)) {
                display_comments(comments);
            }
            free_list(comments);

            break;
        }

        case 4: {
            const LinkedList* posts = get_all_posts();
            display_posts(posts);
            break;
        }

        default:
            printf("Unknown choice\n");
    }
}
