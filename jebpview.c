#define JEBP_IMPLEMENTATION
#include "jebp.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

static void jebpview_error(jebp_error_t error) {
    fprintf(stderr, "%s\n", jebp_error_string(error));
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <WebP file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    jebp_image_t image;
    jebp_error_t err = jebp_read_size(&image, argv[1]);
    if (err != JEBP_OK) {
        jebpview_error(err);
    }
    printf("WebP image size: %ix%i\n", image.width, image.height);

    err = jebp_read(&image, argv[1]);
    if (err != JEBP_OK) {
        jebpview_error(err);
    }

    jebp_free_image(&image);
    return EXIT_SUCCESS;
}
