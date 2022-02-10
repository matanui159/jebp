#ifdef NDEBUG
#undef NDEBUG
#endif // NDEBUG
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define JEBP_IMPLEMENTATION
#include "../jebp.h"

static jebp_uint test_image_hash(jebp_image_t *image) {
    jebp_uint hash = 2166136261;
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
    return hash;
}

int main(int argc, char **argv) {
    assert(argc == 4);
    const char *path = argv[1];
    jebp_int width, height;
    assert(sscanf(argv[2], "%ix%i", &width, &height) == 2);
    jebp_uint hash;
    assert(sscanf(argv[3], "%08x", &hash) == 1);
    jebp_image_t image = {0, 0, NULL};
    jebp_uint image_hash;

    // jebp_error_string
    const char *unknown = jebp_error_string(JEBP_ERROR_UNKNOWN);
    assert(unknown != NULL);
    for (int i = -100; i < 100; i += 1) {
        const char *error = jebp_error_string(i);
        assert(error != NULL);
        if (i >= JEBP_OK && i < JEBP_ERROR_UNKNOWN) {
            assert(error != unknown);
        } else {
            assert(error == unknown);
        }
    }

#ifndef JEBP_NO_STDIO
    // jebp_read_size
    assert(jebp_read_size(NULL, path) == JEBP_ERROR_INVAL);
    assert(jebp_read_size(&image, NULL) == JEBP_ERROR_INVAL);
    assert(jebp_read_size(&image, ".") == JEBP_ERROR_IO);
    assert(jebp_read_size(&image, path) == JEBP_OK);
    printf("Image size: %ix%i\n", image.width, image.height);
    assert(image.width == width && image.height == height);
    assert(image.pixels == NULL);
    image.width = 0;
    image.height = 0;

    // jebp_read
    assert(jebp_read(NULL, path) == JEBP_ERROR_INVAL);
    assert(jebp_read(&image, NULL) == JEBP_ERROR_INVAL);
    assert(jebp_read(&image, ".") == JEBP_ERROR_IO);
    assert(jebp_read(&image, path) == JEBP_OK);
    printf("Image size: %ix%i\n", image.width, image.height);
    assert(image.width == width && image.height == height);
    assert(image.pixels != NULL);
    image_hash = test_image_hash(&image);
    printf("Image hash: %08x\n", image_hash);
    assert(image_hash == hash);

    // jebp_free_image
    jebp_free_image(NULL);
    jebp_free_image(&image);
    assert(image.width == 0 && image.height == 0);
    assert(image.pixels == NULL);
#endif // JEBP_NO_STDIO

    FILE *file = fopen(path, "rb");
    assert(file != NULL);
    assert(fseek(file, 0, SEEK_END) == 0);
    size_t size = ftell(file);
    assert(size > 32);
    void *data = malloc(size);
    assert(data != NULL);
    assert(fseek(file, 0, SEEK_SET) == 0);
    assert(fread(data, 1, size, file) == size);
    assert(fclose(file) == 0);

    // jebp_decode_size
    assert(jebp_decode_size(NULL, size, data) == JEBP_ERROR_INVAL);
    assert(jebp_decode_size(&image, 0, data) == JEBP_ERROR_EOF);
    assert(jebp_decode_size(&image, size, NULL) == JEBP_ERROR_INVAL);
    assert(jebp_decode_size(&image, 32, data) == JEBP_OK);
    printf("Image size: %ix%i\n", image.width, image.height);
    assert(image.width == width && image.height == height);
    assert(image.pixels == NULL);
    image.width = 0;
    image.height = 0;

    // jebp_decode
    assert(jebp_decode(NULL, size, data) == JEBP_ERROR_INVAL);
    assert(jebp_decode(&image, 0, data) == JEBP_ERROR_EOF);
    assert(jebp_decode(&image, size, NULL) == JEBP_ERROR_INVAL);
    assert(jebp_decode(&image, size, data) == JEBP_OK);
    printf("Image size: %ix%i\n", image.width, image.height);
    assert(image.width == width && image.height == height);
    assert(image.pixels != NULL);
    image_hash = test_image_hash(&image);
    printf("Image hash: %08x\n", image_hash);
    assert(image_hash == hash);

    // jebp_free_image
    jebp_free_image(NULL);
    jebp_free_image(&image);
    assert(image.width == 0 && image.height == 0);
    assert(image.pixels == NULL);

    free(data);
    return EXIT_SUCCESS;
}
