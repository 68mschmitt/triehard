#ifndef UTIL
#define UTIL

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *copy = malloc(len);
    if (copy) memcpy(copy, s, len);
    return copy;
}

#endif // !UTIL
