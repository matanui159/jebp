#define JEBP_IMPLEMENTATION
#include "../jebp.h"

int LLVMFuzzerTestOneInput(const jebp_ubyte *data, size_t size) {
    jebp_image_t image;
    jebp_decode(&image, size, data);
    jebp_free_image(&image);
    return 0;
}
