#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "post/manager/post_manager.h"

int main(int argc, const char * argv[]) {
    srand((int) time(NULL));

    create_post();
    return 0;
}
