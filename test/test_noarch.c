#include "test_util.h"

// Include setjmp.h early since it requires the macros we are about to disable
#include <setjmp.h>

// Disable everything that can be used to test the architecture or endiannes
#undef __i386
#undef __i386__
#undef _M_IX86
#undef __x86_64
#undef __x86_64__
#undef _M_X64
#undef __arm
#undef __arm__
#undef _M_ARM
#undef __aarch64
#undef __aarch64__
#undef _M_ARM64
#undef __LITTLE_ENDIAN__
// Reenable SIMD so that it doesn't remove any potentially-detected macros
#undef JEBP_NO_SIMD

#define JEBP_IMPLEMENTATION
#include "../jebp.h"

// Make sure the architecture or endianness was not detected
#if defined(JEBP__SIMD_SSE2) || defined(JEBP__SIMD_NEON) ||                    \
    defined(JEBP__LITTLE_ENDIAN)
#error "Architecture or endiannes was still detected"
#endif

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
