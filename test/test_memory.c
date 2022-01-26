#include <errno.h>
#define JEBP_NO_STDIO
#define JEBP_NO_SIMD // On some platforms SIMD-headers import system headers
#undef JEBP_LOG_ERRORS
#include "test_util.h"
#define JEBP_IMPLEMENTATION
#include "../jebp.h"

int main(int argc, char **argv) {
    (void)argc;
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        test_error(strerror(errno));
    }
    fseek(file, 0, SEEK_END);
    size_t size = (size_t)ftell(file);
    void *data = malloc(size);
    if (data == NULL) {
        test_error("Out of memory");
    }
    fseek(file, 0, SEEK_SET);
    fread(data, 1, size, file);
    fclose(file);

    jebp_image_t image;
    jebp_error_t err = jebp_decode_size(&image, size, data);
    if (err != JEBP_OK) {
        test_error(jebp_error_string(err));
    }
    test_size(&image, argv[2]);

    err = jebp_decode(&image, size, data);
    if (err != JEBP_OK) {
        test_error(jebp_error_string(err));
    }
    test_hash(&image, argv[3]);
    jebp_free_image(&image);
    free(data);
    return EXIT_SUCCESS;
}
