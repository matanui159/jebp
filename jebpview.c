#define JEBP_IMPLEMENTATION
#include "jebp.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

int main(int argc, char **argv) {
    jebp_error_t err;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <WebP file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    jebp_image_t image = { .rgba = NULL };
    if ((err = jebp_read_size(&image, argv[1])) != JEBP_OK) {
        goto error;
    }
    printf("WebP image size: %ix%i\n", image.width, image.height);

    if ((err = jebp_read(&image, argv[1])) != JEBP_OK) {
        goto error;
    }

error:
    jebp_image_free(&image);
    if (err != JEBP_OK) {
        fprintf(stderr, "%s\n", jebp_error(err));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
