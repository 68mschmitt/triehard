#ifndef WORDLIB_H
#define WORDLIB_H

#include <stddef.h>

typedef struct WordLib WordLib;

// Lifecycle
WordLib *wordlib_create(void);
void wordlib_destroy(WordLib *wl);

// Basic operations
int wordlib_add_word(WordLib *wl, const char *word);
size_t wordlib_count(const WordLib *wl);

#endif // !WORDLIB_H
