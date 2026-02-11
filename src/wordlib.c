#ifndef WORDLIB
#define WORDLIB

#include "../include/wordlib.h"
#include "util.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WordLib {
    size_t count;
    size_t capacity;
    char **words;
};

WordLib *wordlib_create(void) {
    WordLib *wl = (WordLib*)malloc(sizeof(WordLib));
    if (!wl) {
        fprintf(stderr, "Failed to create word lib\n");
        return NULL;
    }

    char **words = (char**)malloc(10 * sizeof(char*));
    if (!words) {
        fprintf(stderr, "Failed to create words within wordlib");
        return NULL;
    }

    wl->words = words;
    wl->count = 0;
    wl->capacity = 10;

    return wl;
}

void wordlib_destroy(WordLib *wl) {
    for (size_t i = 0; i < wl->capacity; ++i) {
        free(wl->words[i]);
    }
    free(wl->words);
    free(wl);
}

// Basic operations
int wordlib_add_word(WordLib *wl, const char *word) {
    wl->words[wl->count + 1] = my_strdup(word);
    return wl->count++;
}

size_t wordlib_count(const WordLib *wl) {
    return wl->count;
}

#endif // !WORDLIB
