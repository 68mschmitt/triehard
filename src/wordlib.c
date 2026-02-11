#ifndef WORDLIB
#define WORDLIB

#include "../include/wordlib.h"
#include "util.c"
#include <stdbool.h>
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
    for (size_t i = 0; i < wl->count; ++i) {
        free(wl->words[i]);
    }
    free(wl->words);
    free(wl);
}

// Basic operations
int wordlib_add_word(WordLib *wl, const char *word) {
    // Resize the words size
    if (wl->count >= wl->capacity) {
        size_t newCapacity = wl->capacity + 10;
        wl->words = realloc(wl->words, newCapacity * sizeof(char*));
        wl->capacity = newCapacity;
        printf("Capacity Increased to %zu\n", wl->capacity);
    }

    wl->words[wl->count] = my_strdup(word);
    return wl->count++;
}

size_t wordlib_count(const WordLib *wl) {
    return wl->count;
}

bool wordlib_has_word(WordLib *wl, const char *word) {
    for (size_t i = 0; i < wl->count; ++i)
        if (!strcmp(wl->words[i], word))
            return true;

    return false;
}

#endif // !WORDLIB
