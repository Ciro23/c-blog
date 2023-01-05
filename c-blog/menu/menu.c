#include "menu.h"
#include "../post/manager/post_manager.h"

void display_choices() {
    printf("==============================\n");
    printf("1. Create post\n");
    printf("2. Add comment\n");
    printf("3. View post\n");
    printf("4. List of all posts\n");
    printf("==============================\n");
    
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    // Flush is necessary because the end of line character
    // remains in buffer, automatically "skipping" next input
    // request
    fflush(stdin);
    
    call_selected_feature((int) choice);
}

void call_selected_feature(int feature) {
    switch (feature) {
        case 1:
            create_post();
            break;
            
        case 3: {
            long id;
            printf("Enter post id: ");
            scanf("%li", &id);
            
            Post post = get_post_from_id(id);
            display_post(post);
            break;
        }

        default:
            printf("Unknown choice");
    }
}
