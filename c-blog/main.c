#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "menu/menu.h"

int main(int argc, const char * argv[]) {
    srand(time(NULL));

    int should_exit;
    do {
        should_exit = display_choices();
    } while (should_exit != 1);
}
