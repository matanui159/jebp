#ifndef TEST_UTIL_H
#define TEST_UTIL_H
#ifdef __clang__
#pragma GCC diagnostic ignored "-Wgnu-include-next"
#else
#pragma GCC diagnostic ignored "-Wpedantic"
#endif
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEST_INVALID_HEADERS
#include "../jebp.h"

// Largest string is "16384x16384\0"
static char test_buffer[12];

static inline void test_error(const char *error) {
    fprintf(stderr, "%s\n", error);
    exit(EXIT_FAILURE);
}

static inline void test_size(jebp_image_t *image, const char *size_str) {
    sprintf(test_buffer, "%ix%i", image->width, image->height);
    if (strcmp(test_buffer, size_str) != 0) {
        fprintf(stderr, "%s != %s\n", test_buffer, size_str);
        test_error("Invalid size");
    }
}

static inline void test_hash(jebp_image_t *image, const char *hash_str) {
    uint32_t hash = 2166136261;
    for (int i = 0; i < image->width * image->height; i += 1) {
        hash ^= image->pixels[i].r;
        hash *= 16777619;
        hash ^= image->pixels[i].g;
        hash *= 16777619;
        hash ^= image->pixels[i].b;
        hash *= 16777619;
        hash ^= image->pixels[i].a;
        hash *= 16777619;
    }
    sprintf(test_buffer, "%08x", hash);
    if (strcmp(test_buffer, hash_str) != 0) {
        fprintf(stderr, "%s != %s\n", test_buffer, hash_str);
        test_error("Invalid hash");
    }
}

#endif
