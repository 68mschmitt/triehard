#ifndef UTIL
#define UTIL

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *copy = malloc(len);
    if (copy) memcpy(copy, s, len);
    return copy;
}

uint32_t fnv1a(const char *str) {
    uint32_t hash = 2166136261u;    // FNV offset basis
    while (*str) {
        hash ^= (uint8_t)*str++;
        hash *= 16777619u;          // FNV prime
    }
    return hash;
}

#endif // !UTIL
