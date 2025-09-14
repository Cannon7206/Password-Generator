#include <stdlib.h>
#include "/home/christian/dev/C/password_gen/include/functions.h"
void delay(int ms) {
    clock_t start = clock();
    clock_t target = start + (ms * CLOCKS_PER_SEC / 1000);
    while (clock() > target) {
    }
}

void initRandom() { srand(time(NULL)); }
