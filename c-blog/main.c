#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "menu/menu.h"

int main(int argc, const char * argv[]) {
    srand((int) time(NULL));

    display_choices();
    return 0;
}
