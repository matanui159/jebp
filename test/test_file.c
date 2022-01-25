#include "test_util.h"
#define JEBP_IMPLEMENTATION
#include "../jebp.h"

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
