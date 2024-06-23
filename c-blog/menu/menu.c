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

    // TODO: not implemented yet
    // printf("4. List of all posts\n");
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
            printf("Bye!");
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

            const Post post = get_post_from_id(id);
            display_post(post);

            LinkedList* comments = read_comments(id);
            if (!is_empty(comments)) {
                display_comments(comments);
            }
            free_list(comments);

            break;
        }

        default:
            printf("Unknown choice");
    }
}
