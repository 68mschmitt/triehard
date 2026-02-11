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

    if (wordlib_has_word(wl, "hello"))
        printf("Found the word hello\n");

    if (!wordlib_has_word(wl, "goodbye"))
        printf("Did not find the word goodbye\n");

    printf("Word count: %zu\n", wordlib_count(wl));

    wordlib_destroy(wl);
    return 0;
}
