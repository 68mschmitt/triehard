#include <stdio.h>
#include "../include/wordlib.h"

int main(void) {
    WordLib *wl = wordlib_create();
    if (!wl) {
        fprintf(stderr, "Failed to create WordLib\n");
        return 1;
    }

    wordlib_add_word(wl, "hello");
    wordlib_add_word(wl, "world");

    printf("Word count: %zu\n", wordlib_count(wl));

    wordlib_destroy(wl);
    return 0;
}
