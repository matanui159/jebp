#include <stddef.h>

static void *test_alloc(size_t size);
static void test_free(void *ptr);

#define JEBP_ALLOC test_alloc
#define JEBP_FREE test_free
#include "test_util.h"
#define JEBP_IMPLEMENTATION
#include "../jebp.h"

static char test_alloc_buffer[1024 * 1024];
static size_t test_alloc_size = 1024 * 1024;
static char *test_alloc_ptr = test_alloc_buffer;

static void *test_alloc(size_t size) {
    if (size > test_alloc_size) {
        return NULL;
    }
    void *ptr = test_alloc_ptr;
    test_alloc_size -= size;
    test_alloc_ptr += size;
    return ptr;
}

static void test_free(void *ptr) {
    (void)ptr;
}

int main(int argc, char **argv) {
    (void)argc;
    jebp_image_t image;
    jebp_error_t err = jebp_read_size(&image, argv[1]);
    if (err != JEBP_OK) {
        test_error(jebp_error_string(err));
    }
    test_size(&image, argv[2]);

    err = jebp_read(&image, argv[1]);
    if (err != JEBP_OK) {
        test_error(jebp_error_string(err));
    }
    test_hash(&image, argv[3]);
    jebp_free_image(&image);
    return EXIT_SUCCESS;
}
