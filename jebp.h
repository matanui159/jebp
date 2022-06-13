/**
 * JebP - Single header WebP decoder
 */

/**
 * LICENSE
 **
 * MIT No Attribution
 *
 * Copyright 2022 Jasmine Minter
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

// Attribution is not required, but would be appreciated :)

/**
 * DOCUMENTATION
 **
 * First and foremost, this project uses some custom types:
 *   `jebp_byte`/`jebp_ubyte` is a singular byte.
 *   `jebp_short`/jebp_ushort` is an integer of atleast 16-bits.
 *   `jebp_int`/`jebp_uint` is an integer of atleast 32-bits.
 *
 * This is a header only file. This means that it operates as a standard header
 * and to generate the source file you define `JEBP_IMPLEMENTATION` in ONE file
 * only. For example:
 * ```c
 * #define JEBP_IMPLEMENTATION
 * #include "jebp.h"
 * ```
 *
 * The most basic API call in this library is:
 * ```c
 * err = jebp_decode(&image, size, data);
 * ```
 * where:
 *   `jebp_image_t *image` is a pointer to an image structure to receive the
 *                         decoded data.
 *   `size_t size` is the size of the WebP-encoded data buffer.
 *   `const void *data` is a pointer to the WebP encoded data buffer, `size`
 *                      bytes large.
 *   `jebp_error_t err` is the result of the operation (OK or an error code).
 *
 * For reading from a provided file path, this API call can be used instead:
 * ```c
 * err = jebp_read(&image, path);
 * ```
 * where:
 *   `const char *path` is the path of the file to be read.
 *
 * It is currently not possible to read from a `FILE *` object.
 * If you only want to get the size of the image without a full read, these
 * functions can be used instead:
 * ```c
 * err = jebp_decode_size(&image, size, data);
 * err = jebp_read_size(&image, path);
 * ```
 *
 * The `jebp_image_t` structure has the following properties:
 *   `jebp_int width` is the width of the image.
 *   `jebp_int height` is the height of the image.
 *   `jebp_color_t *pixels` is a pointer to an array pixels. Each `jebp_color_t`
 *                          structure contains four `jebp_ubyte` values for `r`,
 *                          `g`, `b` and `a`. This allows the `pixels` pointer
 *                          to be cast to `jebp_ubyte *` to get an RGBA pixel
 *                          buffer.
 * The allocated data in the image can be free'd with:
 * ```c
 * jebp_free_image(&image);
 * ```
 * This function will also clear the structure, notably width and height will be
 * set to 0.
 *
 * The `jebp_error_t` enumeration has the following values:
 *   `JEBP_OK` means the operation completed successfully.
 *   `JEBP_ERROR_INVAL` means one of the arguments provided is invalid, usually
 *                      this refers to a NULL pointer.
 *   `JEBP_ERROR_INVDATA` means the WebP-encoded data is invalid or corrupted.
 *   `JEBP_ERROR_INVDATA_HEADER` is a suberror of `INVDATA` that indicates that
 *                      the header bytes are invalid. This file is likely not a
 *                      WebP file.
 *   `JEBP_ERROR_EOF` means the end of the file (or data buffer) was reached
 *                    before the operation could successfully complete.
 *   `JEBP_ERROR_NOSUP` means there is a feature in the WebP stream that is not
 *                      currently supported (see below). This can also represent
 *                      new features, versions or RIFF-chunks that were not in
 *                      the specification when writing.
 *   `JEBP_ERROR_NOSUP_CODEC` is a suberror of `NOSUP` that indicates that the
 *                      RIFF chunk that is most likely for the codec is not
 *                      recognized. Currently lossy images are not supported
 *                      (see below) and lossless image support can be disabled
 *                      (see `JEBP_NO_VP8L`).
 *   `JEBP_ERROR_NOSUP_PALETTE` is a suberror of `NOSUP` that indicates that the
 *                      image has a color-index transform (in WebP terminology,
 *                      this would be a paletted image). Color-indexing
 *                      transforms are not currently supported (see below). Note
 *                      that this error code might be removed after
 *                      color-indexing transform support is added, this is only
 *                      here for now to help detecting common issues.
 *   `JEBP_ERROR_NOMEM` means that a memory allocation failed, indicating that
 *                      there is no more memory available.
 *   `JEBP_ERROR_IO` represents any generic I/O error, usually from
 *                   file-reading.
 *   `JEBP_ERROR_UNKNOWN` means any unknown error. Currently this is only used
 *                        when an unknown value is passed into
 *                        `jebp_error_string`.
 * To get a human-readable string of the error, the following function can be
 * used:
 * ```c
 * const char *error = jebp_error_string(err);
 * ```
 *
 * This is not a feature-complete WebP decoder and has the following
 * limitations:
 *   - Does not support decoding lossy files with VP8.
 *   - Does not support extended file-formats with VP8X.
 *   - Does not support VP8L lossless images with the color-indexing transform
 *     (palleted images).
 *   - Does not support VP8L images with more than 256 huffman groups. This is
 *     an arbitrary limit to prevent bad images from using too much memory. In
 *     theory, images requiring more groups should be very rare. This limit may
 *     be increased in the future.
 *
 * Features that will probably never be supported due to complexity or API
 * constraints:
 *   - Decoding color profiles.
 *   - Decoding metadata.
 *   - Full color-indexing/palette support will be a bit of a mess, so don't
 *     expect full support of that coming anytime soon. Simple color-indexing
 *     support (more than 16 colors, skipping the need for bit-packing) is
 *     definitely alot more do-able.
 *
 * Along with `JEBP_IMPLEMENTATION` defined above, there are a few other macros
 * that can be defined to change how JebP operates:
 *   `JEBP_NO_STDIO` will disable the file-reading API.
 *   `JEBP_NO_SIMD` will disable SIMD optimizations. These are currently
 *                  not-used but the detection is there ready for further work.
 *   `JEBP_NO_VP8L` will disable VP8L (lossless) decoding support. Note that
 *                  currently this will make all images fail since VP8L is the
 *                  only supported codec right now.
 *   `JEBP_ALLOC` and `JEBP_FREE` can be defined to functions for a custom
 *                allocator. They either both have to be defined or neither
 *                defined.
 *
 * This single-header library requires C99 to be supported. Along with this it
 * requires the following headers from the system to successfully compile. Some
 * of these can be disabled with the above macros:
 *   `stddef.h` is used for the definition of the `size_t` type.
 *   `limits.h` is used for the `UINT_MAX` macro to check the size of `int`. If
 *              `int` is not 32-bits, `long` will be used for `jebp_int`
 *              instead.
 *   `string.h` is used for `memset` to clear out memory.
 *   `stdio.h` is used for I/O support and logging errors. If `JEBP_NO_STDIO` is
 *             defined and `JEBP_LOG_ERRORS` is not defined, this will not be
 *             included.
 *   `stdlib.h` is used for the default implementations of `JEBP_ALLOC`
 *              and `JEBP_FREE`, using `malloc` and `free` respectively. If
 *              those macros are already defined to something else, this will
 *              not be included.
 *   `emmintrin.h` and `arm_neon.h` is used for SIMD intrinsice. If
 *                 `JEBP_NO_SIMD` is defined these will not be included.
 *
 * The following predefined macros are also used for compiler-feature, SIMD and
 * endianness detection. These can be changed or modified before import to
 * change JebP's detection logic:
 *   `__STDC_VERSION__` is used to detect if the compiler supports C99 and also
 *                      checks for C11 support to use `_Noreturn`.
 *   `__has_attribute` and `__has_builtin` are used to detect the `noreturn` and
 *                     `always_inline` attributes, along with the
 *                     `__builtin_bswap32` builtin. Note that `__has_attribute`
 *                     does not fallback to compiler-version checks since most
 *                     compilers already support `__has_attribute`.
 *   `__GNUC__` and `__GNUC_MINOR__` are used to detect if the compiler is GCC
 *              (or GCC compatible) and what version of GCC it is. This, in
 *              turn, is used to polyfill `__has_builtin` on older compilers
 *              that may not support it.
 *   `__clang__` is used to detect the Clang compiler. This is only used to set
 *               the detected GCC version higher since Clang still marks itself
 *               as GCC 4.2 by default. No Clang version detection is done.
 *   `_MSC_VER` is used to detect the MSVC compiler. This is used to check
 *              support for `__declspec(noreturn)`, `__forceinline` and
 *              `_byteswap_ulong`. No MSVC version detection is done.
 *   `__LITTLE_ENDIAN__` is used to check if the architecture is little-endian.
 *                       Note that this is only checked either if the
 *                       architecture cannot be detected or, in special cases,
 *                       where there is not enough information from the
 *                       architecture or compiler to detect endianness. Also
 *                       note that big-endian and other more-obscure endian
 *                       types are not detected. Little-endian is the only
 *                       endianness detected and is used for optimization in a
 *                       few areas. If the architecture is not little-endian or
 *                       cannot be detected as such, a naive solution is used
 *                       instead.
 *   `__i386`, `__i386__` and `_M_IX86` are used to detect if this is being
 *           compiled for x86-32 (also known as x86, IA-32, or i386). If one of
 *           these are defined, it is also assumed that the architecture is
 *           little-endian. `_M_IX86` is usually present on MSVC, while
 *           the other two are usually present on most other compilers.
 *   `__SSE2__` and `_M_IX86_FP` are used to detect SSE2 support on x86-32.
 *              `_M_IX86`, which is usually present on MSVC, must equal 2 to
 *              indicate that the code is being compiled for a SSE2-compatible
 *              floating-point unit. `__SSE2__` is usually present on most other
 *              compilers.
 *   `__x86_64`, `__x86_64__` and `_M_X64` are used to detect if this is being
 *            compiled for x86-64 (also known as AMD64). If one of these are
 *            defined, it is also assumed that the architecture is little-endian
 *            and that SSE2 is supported (which is required for x86-64 support).
 *            `_M_X64` is usually present on MSVC, while the other two are
 *            usually present on most other compilers.
 *   `__arm`, `__arm__` and `_M_ARM` are used to detect if this is being
 *            compiled for AArch32 (also known as arm32 or armhf). If one of
 *            these are defined on Windows, it is also assumed that Neon is
 *            supported (which is required for Windows). `_M_ARM` is usually
 *            present on MSVC while the other two are usually present on most
 *            other compilers.
 *   `__ARM_NEON` is used to detect Neon support on AArch32. MSVC doesn't seem
 *                to support this and I can't find any info on detecting Neon
 *                support for MSVC. I have found mentions of Windows requiring
 *                Neon support but cannot find any concrete proof anywhere.
 *   `__aarch64`, `__aarch64__` and `_M_ARM64` are used to detect if this is
 *                being compiled for AArch64 (also known as arm64). If one of
 *                these are defined, it is also assumed that Neon is supported
 *                (which is required for AArch64 support). `_M_ARM64` is usually
 *                present on MSVC, while the other two are usually present on
 *                most other compilers.
 *   `__ARM_BIG_ENDIAN` is used to detect, on AArch/ARM architectures, if it is
 *                      in big-endian mode. However, as mentioned above, there
 *                      is no special code for big-endian and it's worth noting
 *                      that this is just used to force-disable little-endian.
 *                      If this is not present, it falls back to using
 *                      `__LITTLE_ENDIAN__`. It is also worth noting that MSVC
 *                      does not seem to provide a way to detect endianness. It
 *                      may be that Windows requires little-endian but I can't
 *                      find any concrete sources on this so currently
 *                      little-endian detection is not supported on MSVC.
 */

/**
 * HEADER
 */
#ifndef JEBP__HEADER
#define JEBP__HEADER
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#include <limits.h>
#include <stddef.h>

#if UINT_MAX >= 0xffffffff
#define JEBP__INT int
#else
#define JEBP_INT long
#endif
typedef signed char jebp_byte;
typedef unsigned char jebp_ubyte;
typedef short jebp_short;
typedef unsigned short jebp_ushort;
typedef JEBP__INT jebp_int;
typedef unsigned JEBP__INT jebp_uint;

typedef enum jebp_error_t {
    JEBP_OK,
    JEBP_ERROR_INVAL,
    JEBP_ERROR_INVDATA,
    JEBP_ERROR_INVDATA_HEADER,
    JEBP_ERROR_EOF,
    JEBP_ERROR_NOSUP,
    JEBP_ERROR_NOSUP_CODEC,
    JEBP_ERROR_NOSUP_PALETTE,
    JEBP_ERROR_NOMEM,
    JEBP_ERROR_IO,
    JEBP_ERROR_UNKNOWN,
    JEBP_NB_ERRORS
} jebp_error_t;

typedef struct jebp_color_t {
    jebp_ubyte r;
    jebp_ubyte g;
    jebp_ubyte b;
    jebp_ubyte a;
} jebp_color_t;

typedef struct jebp_image_t {
    jebp_int width;
    jebp_int height;
    jebp_color_t *pixels;
} jebp_image_t;

const char *jebp_error_string(jebp_error_t err);
void jebp_free_image(jebp_image_t *image);
jebp_error_t jebp_decode_size(jebp_image_t *image, size_t size,
                              const void *data);
jebp_error_t jebp_decode(jebp_image_t *image, size_t size, const void *data);

// I/O API
#ifndef JEBP_NO_STDIO
jebp_error_t jebp_read_size(jebp_image_t *image, const char *path);
jebp_error_t jebp_read(jebp_image_t *image, const char *path);
#endif // JEBP_NO_STDIO

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // JEBP__HEADER

/**
 * IMPLEMENTATION
 */
#ifdef JEBP_IMPLEMENTATION
#include <string.h>
#if !defined(JEBP_NO_STDIO) || defined(JEBP_LOG_ERRORS)
#include <stdio.h>
#endif
#if !defined(JEBP_ALLOC) && !defined(JEBP_FREE)
#include <stdlib.h>
#define JEBP_ALLOC malloc
#define JEBP_FREE free
#elif !defined(JEBP_ALLOC) || !defined(JEBP_FREE)
#error "Both JEBP_ALLOC and JEBP_FREE have to be defined"
#endif

/**
 * Predefined macro detection
 */
#ifdef __STDC_VERSION__
#if __STDC_VERSION__ < 199901
#error "Standard C99 support is required"
#endif
#else // __STDC_VERSION__
#if defined(__GNUC__)
#warning "C version cannot be checked, compilation may fail"
#elif defined(_MSC_VER)
#pragma message(                                                               \
    "MSVC by default is C89 'with extensions', use /std:c11 to ensure there are no errors")
#endif
#endif // __STDC_VERSION__
#if defined(__clang__)
// The default GNUC version provided by Clang is just short of what we need
#define JEBP__GNU_VERSION 403
#elif defined(__GNUC__)
#define JEBP__GNU_VERSION ((__GNUC__ * 100) + __GNUC_MINOR__)
#else
#define JEBP__GNU_VERSION 0
#endif // __GNUC__

#ifdef __has_attribute
#define JEBP__HAS_ATTRIBUTE __has_attribute
#else // __has_attribute
// We don't add GCC version checks since, unlike __has_builtin, __has_attribute
// has been out for so long that its more likely that the compiler supports it.
#define JEBP__HAS_ATTRIBUTE(attr) 0
#endif // __has_attribute
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#define JEBP__NORETURN _Noreturn
#elif JEBP__HAS_ATTRIBUTE(noreturn)
#define JEBP__NORETURN __attribute__((noreturn))
#elif defined(_MSC_VER)
#define JEBP__NORETURN __declspec(noreturn)
#else
#define JEBP__NORETURN
#endif
#if JEBP__HAS_ATTRIBUTE(always_inline)
#define JEBP__ALWAYS_INLINE __attribute__((always_inline))
#elif defined(_MSC_VER)
#define JEBP__ALWAYS_INLINE __forceinline
#else
#define JEBP__ALWAYS_INLINE
#endif
#define JEBP__INLINE static inline JEBP__ALWAYS_INLINE

#ifdef __has_builtin
#define JEBP__HAS_BUILTIN __has_builtin
#else // __has_builtin
#define JEBP__HAS_BUILTIN(builtin)                                             \
    JEBP__VERSION##builtin != 0 && JEBP__GNU_VERSION >= JEBP__VERSION##builtin
// I believe this was added earlier but GCC 4.3 is the first time it was
// mentioned in the changelog and manual.
#define JEBP__VERSION__builtin_bswap32 403
#endif // __has_builtin
#if JEBP__HAS_BUILTIN(__builtin_bswap32)
#define JEBP__SWAP32(value) __builtin_bswap32(value)
#elif defined(_MSC_VER)
#define JEBP__SWAP32(value) _byteswap_ulong(value)
#endif

// We don't do any SIMD runtime detection since that causes alot of
// heavily-documented issues that I won't go into here. Instead, if the compiler
// supports it (and requests it) we will use it. It helps that both x86-64 and
// AArch64 always support the SIMD from their 32-bit counterparts.
#if defined(__i386) || defined(__i386__) || defined(_M_IX86)
#define JEBP__ARCH_X86
#if defined(__SSE2__) || _M_IX86_FP == 2
#define JEBP__SIMD_SSE2
#endif
#elif defined(__x86_64) || defined(__x86_64__) || defined(_M_X64)
#define JEBP__ARCH_X86
#define JEBP__SIMD_SSE2
#elif defined(__arm) || defined(__arm__) || defined(_M_ARM)
#define JEBP__ARCH_ARM
#if defined(__ARM_NEON) || defined(_MSC_VER)
// According to the following article, MSVC requires Neon support
// https://docs.microsoft.com/en-us/cpp/build/overview-of-arm-abi-conventions
#define JEBP__SIMD_NEON
#endif
#elif defined(__aarch64) || defined(__aarch64__) || defined(_M_ARM64)
#define JEBP__ARCH_ARM
#define JEBP__SIMD_NEON
#endif

#if defined(JEBP__ARCH_X86)
// x86 is always little-endian
#define JEBP__LITTLE_ENDIAN
#elif defined(JEBP__ARCH_ARM) && defined(__ARM_BIG_ENDIAN)
// The ACLE big-endian define overrules everything else, including the defualt
// endianness detection
#elif defined(JEBP__ARCH_ARM) && (defined(__ARM_ACLE) || defined(_MSC_VER))
// If ACLE is supported and big-endian is not defined, it must be little-endian
// According to the article linked above, MSVC only supports little-endian
#define JEBP__LITTLE_ENDIAN
#elif defined(__LITTLE_ENDIAN__) || __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define JEBP__LITTLE_ENDIAN
#endif

#ifdef JEBP_NO_SIMD
#undef JEBP__SIMD_SSE2
#undef JEBP__SIMD_NEON
#endif // JEBP_NO_SIMD
#ifdef JEBP__SIMD_SSE2
#include <emmintrin.h>
#endif // JEBP__SIMD_SSE2
#ifdef JEBP__SIMD_NEON
#include <arm_neon.h>
#endif // JEBP__SIMD_NEON

/**
 * Common utilities
 */
// TODO: Maybe we should  have a logging flag and add custom logs with more
//       information to each error (and maybe other stuff like allocations)
#define JEBP__MIN(a, b) ((a) < (b) ? (a) : (b))
#define JEBP__MAX(a, b) ((a) > (b) ? (a) : (b))
#define JEBP__ABS(a) ((a) < 0 ? -(a) : (a))
#define JEBP__AVG(a, b) (((a) + (b)) / 2)
#define JEBP__CEIL_SHIFT(a, b) (((a) + (1 << (b)) - 1) >> (b))
#define JEBP__CLAMP(x, min, max) JEBP__MIN(JEBP__MAX(x, min), max)
#define JEBP__CLAMP_UBYTE(x) JEBP__CLAMP(x, 0, 255)
#define JEBP__CLEAR(ptr, size) memset(ptr, 0, size)

// A simple utility that updates an error pointer if it currently does not have
// an error
JEBP__INLINE jebp_error_t jebp__error(jebp_error_t *err, jebp_error_t error) {
    if (*err == JEBP_OK) {
        *err = error;
    }
    return *err;
}

// Currently only used by VP8L
// TODO: after VP8(no-L) support is added, make it an error to remove both
//       VP8 and VP8L
#ifndef JEBP_NO_VP8L
static jebp_error_t jebp__alloc_image(jebp_image_t *image) {
    image->pixels =
        JEBP_ALLOC(image->width * image->height * sizeof(jebp_color_t));
    if (image->pixels == NULL) {
        return JEBP_ERROR_NOMEM;
    }
    return JEBP_OK;
}
#endif // JEBP_NO_VP8L

/**
 * Reader abstraction
 */
#define JEBP__BUFFER_SIZE 4096

typedef struct jebp__reader_t {
    size_t nb_bytes;
    const jebp_ubyte *bytes;
#ifndef JEBP_NO_STDIO
    FILE *file;
    void *buffer;
#endif // JEBP_NO_STDIO
} jebp__reader_t;

static void jebp__init_memory(jebp__reader_t *reader, size_t size,
                              const void *data) {
    reader->nb_bytes = size;
    reader->bytes = data;
#ifndef JEBP_NO_STDIO
    reader->file = NULL;
#endif // JEBP_NO_STDIO
}

#ifndef JEBP_NO_STDIO
static jebp_error_t jebp__open_file(jebp__reader_t *reader, const char *path) {
    reader->nb_bytes = 0;
    reader->file = fopen(path, "rb");
    if (reader->file == NULL) {
        return JEBP_ERROR_IO;
    }
    reader->buffer = JEBP_ALLOC(JEBP__BUFFER_SIZE);
    if (reader->buffer == NULL) {
        fclose(reader->file);
        return JEBP_ERROR_NOMEM;
    }
    return JEBP_OK;
}

static void jebp__close_file(jebp__reader_t *reader) {
    JEBP_FREE(reader->buffer);
    fclose(reader->file);
}
#endif // JEBP_NO_STDIO

static jebp_error_t jebp__buffer_bytes(jebp__reader_t *reader) {
    if (reader->nb_bytes > 0) {
        return JEBP_OK;
    }
#ifndef JEBP_NO_STDIO
    if (reader->file != NULL) {
        reader->nb_bytes =
            fread(reader->buffer, 1, JEBP__BUFFER_SIZE, reader->file);
        reader->bytes = reader->buffer;
        if (ferror(reader->file)) {
            return JEBP_ERROR_IO;
        }
    }
#endif // JEBP_NO_STDIO
    if (reader->nb_bytes == 0) {
        return JEBP_ERROR_EOF;
    }
    return JEBP_OK;
}

// TODO: Most reads are only a few bytes so maybe I should optimize for that
static jebp_error_t jebp__read_bytes(jebp__reader_t *reader, size_t size,
                                     void *data) {
    jebp_error_t err;
    jebp_ubyte *bytes = data;
    while (size > 0) {
        if ((err = jebp__buffer_bytes(reader)) != JEBP_OK) {
            return err;
        }
        size_t nb_bytes = JEBP__MIN(size, reader->nb_bytes);
        if (bytes != NULL) {
            memcpy(bytes, reader->bytes, nb_bytes);
            bytes += nb_bytes;
        }
        size -= nb_bytes;
        reader->nb_bytes -= nb_bytes;
        reader->bytes += nb_bytes;
    }
    return JEBP_OK;
}

// 8-bit uint reading is currently only used by the bit-reader
#ifndef JEBP_NO_VP8L
static jebp_ubyte jebp__read_uint8(jebp__reader_t *reader, jebp_error_t *err) {
    if (*err != JEBP_OK) {
        return 0;
    }
    if ((*err = jebp__buffer_bytes(reader)) != JEBP_OK) {
        return 0;
    }
    reader->nb_bytes -= 1;
    return *(reader->bytes++);
}
#endif // JEBP_NO_VP8L

static jebp_uint jebp__read_uint32(jebp__reader_t *reader, jebp_error_t *err) {
    if (*err != JEBP_OK) {
        return 0;
    }
#ifdef JEBP__LITTLE_ENDIAN
    jebp_uint value = 0;
    *err = jebp__read_bytes(reader, 4, &value);
    return value;
#else  // JEBP__LITTLE_ENDIAN
    jebp_ubyte bytes[4];
    *err = jebp__read_bytes(reader, 4, bytes);
    return (jebp_uint)bytes[0] | ((jebp_uint)bytes[1] << 8) |
           ((jebp_uint)bytes[2] << 16) | ((jebp_uint)bytes[3] << 24);
#endif // JEBP__LITTLE_ENDIAN
}

/**
 * RIFF container
 */
#define JEBP__RIFF_TAG 0x46464952
#define JEBP__WEBP_TAG 0x50424557

typedef struct jebp__chunk_t {
    jebp_uint tag;
    jebp_uint size;
} jebp__chunk_t;

typedef struct jebp__riff_reader_t {
    jebp__reader_t *reader;
    jebp__chunk_t header;
} jebp__riff_reader_t;

static jebp_error_t jebp__read_chunk(jebp__riff_reader_t *riff,
                                     jebp__chunk_t *chunk) {
    jebp_error_t err = JEBP_OK;
    chunk->tag = jebp__read_uint32(riff->reader, &err);
    chunk->size = jebp__read_uint32(riff->reader, &err);
    chunk->size += chunk->size % 2; // round up to even
    return err;
}

static jebp_error_t jebp__read_riff_header(jebp__riff_reader_t *riff,
                                           jebp__reader_t *reader) {
    jebp_error_t err;
    riff->reader = reader;
    if ((err = jebp__read_chunk(riff, &riff->header)) != JEBP_OK) {
        return err;
    }
    if (riff->header.tag != JEBP__RIFF_TAG) {
        return JEBP_ERROR_INVDATA_HEADER;
    }
    if (jebp__read_uint32(reader, &err) != JEBP__WEBP_TAG) {
        return jebp__error(&err, JEBP_ERROR_INVDATA_HEADER);
    }
    return err;
}

static jebp_error_t jebp__read_riff_chunk(jebp__riff_reader_t *riff,
                                          jebp__chunk_t *chunk) {
    jebp_error_t err;
    if ((err = jebp__read_chunk(riff, chunk)) != JEBP_OK) {
        return err;
    }
    if (chunk->size > riff->header.size) {
        return JEBP_ERROR_INVDATA;
    }
    riff->header.size -= chunk->size;
    return JEBP_OK;
}

/**
 * Bit reader
 */
#ifndef JEBP_NO_VP8L
typedef struct jebp__bit_reader_t {
    jebp__reader_t *reader;
    size_t nb_bytes;
    jebp_int nb_bits;
    jebp_uint bits;
} jebp__bit_reader_t;

static void jepb__init_bit_reader(jebp__bit_reader_t *bits,
                                  jebp__reader_t *reader, size_t size) {
    bits->reader = reader;
    bits->nb_bytes = size;
    bits->nb_bits = 0;
    bits->bits = 0;
}

// buffer/peek/skip should be used together to optimize bit-reading
static jebp_error_t jebp__buffer_bits(jebp__bit_reader_t *bits, jebp_int size) {
    jebp_error_t err = JEBP_OK;
    while (bits->nb_bits < size && bits->nb_bytes > 0) {
        bits->bits |= jebp__read_uint8(bits->reader, &err) << bits->nb_bits;
        bits->nb_bits += 8;
        bits->nb_bytes -= 1;
    }
    return err;
}

JEBP__INLINE jebp_int jepb__peek_bits(jebp__bit_reader_t *bits, jebp_int size) {
    return bits->bits & ((1 << size) - 1);
}

JEBP__INLINE jebp_error_t jebp__skip_bits(jebp__bit_reader_t *bits,
                                          jebp_int size) {
    if (size > bits->nb_bits) {
        return JEBP_ERROR_INVDATA;
    }
    bits->nb_bits -= size;
    bits->bits >>= size;
    return JEBP_OK;
}

static jebp_uint jebp__read_bits(jebp__bit_reader_t *bits, jebp_int size,
                                 jebp_error_t *err) {
    if (*err != JEBP_OK) {
        return 0;
    }
    if ((*err = jebp__buffer_bits(bits, size)) != JEBP_OK) {
        return 0;
    }
    jebp_uint value = jepb__peek_bits(bits, size);
    if ((*err = jebp__skip_bits(bits, size)) != JEBP_OK) {
        return 0;
    }
    return value;
}

/**
 * Huffman coding
 */
#define JEBP__MAX_HUFFMAN_LENGTH 15
#define JEBP__MAX_PRIMARY_LENGTH 8
#define JEBP__MAX_SECONDARY_LENGTH                                             \
    (JEBP__MAX_HUFFMAN_LENGTH - JEBP__MAX_PRIMARY_LENGTH)
#define JEBP__NB_PRIMARY_HUFFMANS (1 << JEBP__MAX_PRIMARY_LENGTH)
#define JEBP__NO_HUFFMAN_SYMBOL 0xffff

#define JEBP__NB_META_SYMBOLS 19
#define JEBP__NB_COLOR_SYMBOLS 256
#define JEBP__NB_LENGTH_SYMBOLS 24
#define JEBP__NB_DIST_SYMBOLS 40
#define JEBP__NB_MAIN_SYMBOLS (JEBP__NB_COLOR_SYMBOLS + JEBP__NB_LENGTH_SYMBOLS)

// The huffman decoding is done in one or two steps, both using a lookup table.
// These tables are called the "primary" table and "secondary" tables. First
// 8-bits are peeked from the stream to index the primary table. If the symbol
// is in this table (indicated by length <= 8) then the symbol from that is used
// and the length is used to skip that many bits. Codes which are smaller than
// 8-bits are represented by filling the table such that any index with a prefix
// of the given code will have the same entry. If the symbol requires more bits
// (indiciated by length > 8) then the symbol is used as an offset pointing to
// the secondary table which has an index size of (length - 8) bits.
typedef struct jebp__huffman_t {
    // <= 8: length is the number of bits actually used, and symbol is the
    //       decoded symbol or `JEBP__NO_HUFFMAN_SYMBOL` for an invalid code.
    // >  8: length is the maximum number of bits for any code with this prefix,
    //       and symbol is the offset in the array to the secondary table.
    jebp_short length;
    jebp_ushort symbol;
} jebp__huffman_t;

typedef struct jebp__huffman_group_t {
    jebp__huffman_t *main;
    jebp__huffman_t *red;
    jebp__huffman_t *blue;
    jebp__huffman_t *alpha;
    jebp__huffman_t *dist;
} jebp__huffman_group_t;

static const jebp_byte jebp__meta_length_order[JEBP__NB_META_SYMBOLS];

// Reverse increment, returns truthy on overflow
JEBP__INLINE jebp_int jebp__increment_code(jebp_int *code, jebp_int length) {
    jebp_int inc = 1 << (length - 1);
    while (*code & inc) {
        inc >>= 1;
    }
    if (inc == 0) {
        return 1;
    }
    *code = (*code & (inc - 1)) + inc;
    return 0;
}

// This function is a bit confusing so I have attempted to document it well
static jebp_error_t jebp__alloc_huffman(jebp__huffman_t **huffmans,
                                        jebp_int nb_lengths,
                                        const jebp_byte *lengths) {
    // Stack allocate the primary table and set it all to invalid values
    jebp__huffman_t primary[JEBP__NB_PRIMARY_HUFFMANS];
    for (jebp_int i = 0; i < JEBP__NB_PRIMARY_HUFFMANS; i += 1) {
        primary[i].symbol = JEBP__NO_HUFFMAN_SYMBOL;
    }

    // Fill in the 8-bit codes in the primary table
    jebp_int len = 1;
    jebp_int code = 0;
    jebp_int overflow = 0;
    jebp_ushort symbol = JEBP__NO_HUFFMAN_SYMBOL;
    jebp_int nb_symbols = 0;
    for (; len <= JEBP__MAX_PRIMARY_LENGTH; len += 1) {
        for (jebp_int i = 0; i < nb_lengths; i += 1) {
            if (lengths[i] != len) {
                continue;
            }
            if (overflow) {
                // Fail now if the last increment overflowed
                return JEBP_ERROR_INVDATA;
            }
            for (jebp_int c = code; c < JEBP__NB_PRIMARY_HUFFMANS;
                 c += 1 << len) {
                primary[c].length = len;
                primary[c].symbol = i;
            }
            overflow = jebp__increment_code(&code, len);
            symbol = i;
            nb_symbols += 1;
        }
    }

    // Fill in the secondary table lengths in the primary table
    jebp_int secondary_code = code;
    for (; len <= JEBP__MAX_HUFFMAN_LENGTH; len += 1) {
        for (jebp_int i = 0; i < nb_lengths; i += 1) {
            if (lengths[i] != len) {
                continue;
            }
            if (overflow) {
                return JEBP_ERROR_INVDATA;
            }
            jebp_int prefix = code & (JEBP__NB_PRIMARY_HUFFMANS - 1);
            primary[prefix].length = len;
            overflow = jebp__increment_code(&code, len);
            symbol = i;
            nb_symbols += 1;
        }
    }

    // Calculate the total no. of huffman entries and fill in the secondary
    // table offsets
    jebp_int nb_huffmans = JEBP__NB_PRIMARY_HUFFMANS;
    for (jebp_int i = 0; i < JEBP__NB_PRIMARY_HUFFMANS; i += 1) {
        if (nb_symbols <= 1) {
            // Special case: if there is only one symbol, use this iteration to
            //               instead fill the primary table with 0-length
            //               entries
            primary[i].length = 0;
            primary[i].symbol = symbol;
            continue;
        }
        jebp_int suffix_length = primary[i].length - JEBP__MAX_PRIMARY_LENGTH;
        if (suffix_length > 0) {
            primary[i].symbol = nb_huffmans;
            nb_huffmans += 1 << suffix_length;
        }
    }

    // Allocate, copy over the primary table, and assign the rest to invalid
    // values
    *huffmans = JEBP_ALLOC(nb_huffmans * sizeof(jebp__huffman_t));
    if (*huffmans == NULL) {
        return JEBP_ERROR_NOMEM;
    }
    memcpy(*huffmans, primary, sizeof(primary));
    if (nb_huffmans == JEBP__NB_PRIMARY_HUFFMANS) {
        // Special case: we can stop here if we don't have to fill any secondary
        //               tables
        return JEBP_OK;
    }
    for (jebp_int i = JEBP__NB_PRIMARY_HUFFMANS; i < nb_huffmans; i += 1) {
        (*huffmans)[i].symbol = JEBP__NO_HUFFMAN_SYMBOL;
    }

    // Fill in the secondary tables
    len = JEBP__MAX_PRIMARY_LENGTH + 1;
    code = secondary_code;
    for (; len <= JEBP__MAX_HUFFMAN_LENGTH; len += 1) {
        for (jebp_int i = 0; i < nb_lengths; i += 1) {
            if (lengths[i] != len) {
                continue;
            }
            jebp_int prefix = code & (JEBP__NB_PRIMARY_HUFFMANS - 1);
            jebp_int nb_secondary_huffmans = 1 << primary[prefix].length;
            jebp__huffman_t *secondary = *huffmans + primary[prefix].symbol;
            for (jebp_int c = code; c < nb_secondary_huffmans; c += 1 << len) {
                secondary[c >> JEBP__MAX_PRIMARY_LENGTH].length = len;
                secondary[c >> JEBP__MAX_PRIMARY_LENGTH].symbol = i;
            }
            jebp__increment_code(&code, len);
        }
    }
    return JEBP_OK;
}

static jebp_int jebp__read_symbol(jebp__huffman_t *huffmans,
                                  jebp__bit_reader_t *bits, jebp_error_t *err) {
    if (*err != JEBP_OK) {
        return 0;
    }
    if ((*err = jebp__buffer_bits(bits, JEBP__MAX_HUFFMAN_LENGTH)) != JEBP_OK) {
        return 0;
    }
    jebp_int code = jepb__peek_bits(bits, JEBP__MAX_PRIMARY_LENGTH);
    if (huffmans[code].symbol == JEBP__NO_HUFFMAN_SYMBOL) {
        *err = JEBP_ERROR_INVDATA;
        return 0;
    }
    jebp_int length = huffmans[code].length;
    jebp_int skip = JEBP__MIN(length, JEBP__MAX_PRIMARY_LENGTH);
    if ((*err = jebp__skip_bits(bits, skip)) != JEBP_OK) {
        return 0;
    }
    if (skip == length) {
        return huffmans[code].symbol;
    }

    huffmans += huffmans[code].symbol;
    code = jepb__peek_bits(bits, length - skip);
    if (huffmans[code].symbol == JEBP__NO_HUFFMAN_SYMBOL) {
        *err = JEBP_ERROR_INVDATA;
        return 0;
    }
    if ((*err = jebp__skip_bits(bits, huffmans[code].length - skip)) !=
        JEBP_OK) {
        return 0;
    }
    return huffmans[code].symbol;
}

static jebp_error_t jebp__read_huffman(jebp__huffman_t **huffmans,
                                       jebp__bit_reader_t *bits,
                                       jebp_int nb_lengths,
                                       jebp_byte *lengths) {
    // This part of the spec is INCREDIBLY wrong and partly missing
    jebp_error_t err = JEBP_OK;
    JEBP__CLEAR(lengths, nb_lengths);

    if (jebp__read_bits(bits, 1, &err)) {
        // simple length storage with only 1 (first) or 2 (second) symbols, both
        // with a length of 1
        jebp_int has_second = jebp__read_bits(bits, 1, &err);
        jebp_int first_bits = jebp__read_bits(bits, 1, &err) ? 8 : 1;
        jebp_int first = jebp__read_bits(bits, first_bits, &err);
        if (first >= nb_lengths) {
            return jebp__error(&err, JEBP_ERROR_INVDATA);
        }
        lengths[first] = 1;
        if (has_second) {
            jebp_int second = jebp__read_bits(bits, 8, &err);
            if (second >= nb_lengths) {
                return jebp__error(&err, JEBP_ERROR_INVDATA);
            }
            lengths[second] = 1;
        }

    } else {
        jebp_byte meta_lengths[JEBP__NB_META_SYMBOLS] = {0};
        jebp_int nb_meta_lengths = jebp__read_bits(bits, 4, &err) + 4;
        for (jebp_int i = 0; i < nb_meta_lengths; i += 1) {
            meta_lengths[jebp__meta_length_order[i]] =
                jebp__read_bits(bits, 3, &err);
        }
        if (err != JEBP_OK) {
            return err;
        }
        jebp__huffman_t *meta_huffmans;
        if ((err = jebp__alloc_huffman(&meta_huffmans, JEBP__NB_META_SYMBOLS,
                                       meta_lengths)) != JEBP_OK) {
            return err;
        }

        jebp_int nb_meta_symbols = nb_lengths;
        if (jebp__read_bits(bits, 1, &err)) {
            // limit codes
            jebp_int symbols_bits = jebp__read_bits(bits, 3, &err) * 2 + 2;
            nb_meta_symbols = jebp__read_bits(bits, symbols_bits, &err) + 2;
        }

        jebp_int prev_length = 8;
        for (jebp_int i = 0; i < nb_lengths && nb_meta_symbols > 0;
             nb_meta_symbols -= 1) {
            jebp_int symbol = jebp__read_symbol(meta_huffmans, bits, &err);
            jebp_int length;
            jebp_int repeat;
            switch (symbol) {
            case 16:
                length = prev_length;
                repeat = jebp__read_bits(bits, 2, &err) + 3;
                break;
            case 17:
                length = 0;
                repeat = jebp__read_bits(bits, 3, &err) + 3;
                break;
            case 18:
                length = 0;
                repeat = jebp__read_bits(bits, 7, &err) + 11;
                break;
            default:
                prev_length = symbol;
                /* fallthrough */
            case 0:
                // We don't ever repeat 0 values.
                lengths[i++] = symbol;
                continue;
            }
            if (i + repeat > nb_lengths) {
                jebp__error(&err, JEBP_ERROR_INVDATA);
                break;
            }
            for (jebp_int j = 0; j < repeat; j += 1) {
                lengths[i++] = length;
            }
        }
        JEBP_FREE(meta_huffmans);
    }

    if (err != JEBP_OK) {
        return err;
    }
    return jebp__alloc_huffman(huffmans, nb_lengths, lengths);
}

static jebp_error_t jebp__read_huffman_group(jebp__huffman_group_t *group,
                                             jebp__bit_reader_t *bits,
                                             jebp_int nb_main_symbols,
                                             jebp_byte *lengths) {
    jebp_error_t err;
    if ((err = jebp__read_huffman(&group->main, bits, nb_main_symbols,
                                  lengths)) != JEBP_OK) {
        return err;
    }
    if ((err = jebp__read_huffman(&group->red, bits, JEBP__NB_COLOR_SYMBOLS,
                                  lengths)) != JEBP_OK) {
        return err;
    }
    if ((err = jebp__read_huffman(&group->blue, bits, JEBP__NB_COLOR_SYMBOLS,
                                  lengths)) != JEBP_OK) {
        return err;
    }
    if ((err = jebp__read_huffman(&group->alpha, bits, JEBP__NB_COLOR_SYMBOLS,
                                  lengths)) != JEBP_OK) {
        return err;
    }
    if ((err = jebp__read_huffman(&group->dist, bits, JEBP__NB_DIST_SYMBOLS,
                                  lengths)) != JEBP_OK) {
        return err;
    }
    return JEBP_OK;
}

static void jebp__free_huffman_group(jebp__huffman_group_t *group) {
    JEBP_FREE(group->main);
    JEBP_FREE(group->red);
    JEBP_FREE(group->blue);
    JEBP_FREE(group->alpha);
    JEBP_FREE(group->dist);
}

/**
 * Color cache
 */
typedef struct jebp__colcache_t {
    jebp_int bits;
    jebp_color_t *colors;
} jebp__colcache_t;

static jebp_error_t jebp__read_colcache(jebp__colcache_t *colcache,
                                        jebp__bit_reader_t *bits) {
    jebp_error_t err = JEBP_OK;
    if (!jebp__read_bits(bits, 1, &err)) {
        // no color cache
        colcache->bits = 0;
        return err;
    }
    colcache->bits = jebp__read_bits(bits, 4, &err);
    if (err != JEBP_OK || colcache->bits < 1 || colcache->bits > 11) {
        return jebp__error(&err, JEBP_ERROR_INVDATA);
    }

    size_t colcache_size = ((size_t)1 << colcache->bits) * sizeof(jebp_color_t);
    colcache->colors = JEBP_ALLOC(colcache_size);
    if (colcache->colors == NULL) {
        return JEBP_ERROR_NOMEM;
    }
    JEBP__CLEAR(colcache->colors, colcache_size);
    return JEBP_OK;
}

static void jebp__free_colcache(jebp__colcache_t *colcache) {
    if (colcache->bits > 0) {
        JEBP_FREE(colcache->colors);
    }
}

static void jebp__colcache_insert(jebp__colcache_t *colcache,
                                  jebp_color_t *color) {
    if (colcache->bits == 0) {
        return;
    }
#if defined(JEBP__LITTLE_ENDIAN) && defined(JEBP__SWAP32)
    jebp_uint hash = *(jebp_uint *)color; // ABGR due to little-endian
    hash = JEBP__SWAP32(hash);            // RGBA
    hash = (hash >> 8) | (hash << 24);    // ARGB
#else
    jebp_uint hash = ((jebp_uint)color->a << 24) | ((jebp_uint)color->r << 16) |
                     ((jebp_uint)color->g << 8) | (jebp_uint)color->b;
#endif
    hash = (0x1e35a7bd * hash) >> (32 - colcache->bits);
    colcache->colors[hash] = *color;
}

/**
 * VP8L image
 */
#define JEBP__NB_VP8L_OFFSETS 120

typedef struct jebp__subimage_t {
    jebp_int width;
    jebp_int height;
    jebp_color_t *pixels;
    jebp_int block_bits;
} jebp__subimage_t;

static const jebp_byte jebp__vp8l_offsets[JEBP__NB_VP8L_OFFSETS][2];

JEBP__INLINE jebp_int jebp__read_vp8l_extrabits(jebp__bit_reader_t *bits,
                                                jebp_int symbol,
                                                jebp_error_t *err) {
    if (*err != JEBP_OK) {
        return 1;
    }
    if (symbol < 4) {
        return symbol + 1;
    }
    jebp_int extrabits = symbol / 2 - 1;
    symbol = ((symbol % 2 + 2) << extrabits) + 1;
    return symbol + jebp__read_bits(bits, extrabits, err);
}

static jebp_error_t jebp__read_vp8l_image(jebp_image_t *image,
                                          jebp__bit_reader_t *bits,
                                          jebp__colcache_t *colcache,
                                          jebp__subimage_t *huffman_image) {
    jebp_error_t err;
    jebp_int nb_groups = 1;
    jebp__huffman_group_t *groups = &(jebp__huffman_group_t){0};
    if (huffman_image != NULL) {
        for (jebp_int i = 0; i < huffman_image->width * huffman_image->height;
             i += 1) {
            jebp_color_t *huffman = &huffman_image->pixels[i];
            if (huffman->r != 0) {
                // Currently only 256 huffman groups are supported
                return JEBP_ERROR_NOSUP;
            }
            nb_groups = JEBP__MAX(nb_groups, huffman->g + 1);
            huffman += 1;
        }
        if (nb_groups > 1) {
            groups = JEBP_ALLOC(nb_groups * sizeof(jebp__huffman_group_t));
            if (groups == NULL) {
                return JEBP_ERROR_NOMEM;
            }
        }
    }

    jebp_int nb_main_symbols = JEBP__NB_MAIN_SYMBOLS;
    if (colcache->bits > 0) {
        nb_main_symbols += 1 << colcache->bits;
    }
    jebp_byte *lengths = JEBP_ALLOC(nb_main_symbols);
    if (lengths == NULL) {
        err = JEBP_ERROR_NOMEM;
        goto free_groups;
    }
    jebp_int nb_read_groups = 0;
    for (; nb_read_groups < nb_groups; nb_read_groups += 1) {
        if ((err = jebp__read_huffman_group(&groups[nb_read_groups], bits,
                                            nb_main_symbols, lengths)) !=
            JEBP_OK) {
            break;
        }
    }
    JEBP_FREE(lengths);
    if (err != JEBP_OK) {
        goto free_read_groups;
    }
    if ((err = jebp__alloc_image(image)) != JEBP_OK) {
        goto free_read_groups;
    }

    jebp_color_t *pixel = image->pixels;
    jebp_color_t *end = pixel + image->width * image->height;
    jebp_int x = 0;
    for (jebp_int y = 0; y < image->height;) {
        jebp_color_t *huffman_row = NULL;
        if (huffman_image != NULL) {
            huffman_row =
                &huffman_image->pixels[(y >> huffman_image->block_bits) *
                                       huffman_image->width];
        }
        do {
            jebp__huffman_group_t *group;
            if (huffman_image == NULL) {
                group = groups;
            } else {
                jebp_color_t *huffman =
                    &huffman_row[x >> huffman_image->block_bits];
                group = &groups[huffman->g];
            }

            jebp_int main = jebp__read_symbol(group->main, bits, &err);
            if (main < JEBP__NB_COLOR_SYMBOLS) {
                pixel->g = main;
                pixel->r = jebp__read_symbol(group->red, bits, &err);
                pixel->b = jebp__read_symbol(group->blue, bits, &err);
                pixel->a = jebp__read_symbol(group->alpha, bits, &err);
                jebp__colcache_insert(colcache, pixel++);
                x += 1;
            } else if (main >= JEBP__NB_MAIN_SYMBOLS) {
                *(pixel++) = colcache->colors[main - JEBP__NB_MAIN_SYMBOLS];
                x += 1;
            } else {
                jebp_int length = jebp__read_vp8l_extrabits(
                    bits, main - JEBP__NB_COLOR_SYMBOLS, &err);
                jebp_int dist = jebp__read_symbol(group->dist, bits, &err);
                dist = jebp__read_vp8l_extrabits(bits, dist, &err);
                if (dist > JEBP__NB_VP8L_OFFSETS) {
                    dist -= JEBP__NB_VP8L_OFFSETS;
                } else {
                    const jebp_byte *offset = jebp__vp8l_offsets[dist - 1];
                    dist = offset[1] * image->width + offset[0];
                    dist = JEBP__MAX(dist, 1);
                }
                jebp_color_t *repeat = pixel - dist;
                if (repeat < image->pixels || pixel + length > end) {
                    jebp__error(&err, JEBP_ERROR_INVDATA);
                    break;
                }
                for (jebp_int i = 0; i < length; i += 1) {
                    jebp__colcache_insert(colcache, repeat);
                    *(pixel++) = *(repeat++);
                }
                x += length;
            }
        } while (x < image->width);
        y += x / image->width;
        x %= image->width;
    }

    if (err != JEBP_OK) {
        jebp_free_image(image);
    }
free_read_groups:
    for (nb_read_groups -= 1; nb_read_groups >= 0; nb_read_groups -= 1) {
        jebp__free_huffman_group(&groups[nb_read_groups]);
    }
free_groups:
    if (nb_groups > 1) {
        JEBP_FREE(groups);
    }
    return err;
}

static jebp_error_t jebp__read_subimage(jebp__subimage_t *subimage,
                                        jebp__bit_reader_t *bits,
                                        jebp_image_t *image) {
    jebp_error_t err = JEBP_OK;
    subimage->block_bits = jebp__read_bits(bits, 3, &err) + 2;
    subimage->width = JEBP__CEIL_SHIFT(image->width, subimage->block_bits);
    subimage->height = JEBP__CEIL_SHIFT(image->height, subimage->block_bits);
    if (err != JEBP_OK) {
        return err;
    }
    jebp__colcache_t colcache;
    if ((err = jebp__read_colcache(&colcache, bits)) != JEBP_OK) {
        return err;
    }
    err =
        jebp__read_vp8l_image((jebp_image_t *)subimage, bits, &colcache, NULL);
    jebp__free_colcache(&colcache);
    return err;
}

/**
 * VP8L predictions
 */
#define JEBP__NB_VP8L_PRED_TYPES 14

typedef void (*jebp__vp8l_pred_t)(jebp_color_t *pixel, jebp_color_t *top,
                                  jebp_int width);

typedef struct jebp__short_color_t {
    jebp_short r;
    jebp_short g;
    jebp_short b;
    jebp_short a;
} jebp__short_color_t;

JEBP__INLINE void jebp__vp8l_pred_black(jebp_color_t *pixel, jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].a += 0xff;
    }
}

static void jebp__vp8l_pred0(jebp_color_t *pixel, jebp_color_t *top,
                             jebp_int width) {
    (void)top;
    jebp__vp8l_pred_black(pixel, width);
}

JEBP__INLINE void jebp__vp8l_pred_left(jebp_color_t *pixel, jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r += pixel[x - 1].r;
        pixel[x].g += pixel[x - 1].g;
        pixel[x].b += pixel[x - 1].b;
        pixel[x].a += pixel[x - 1].a;
    }
}

static void jebp__vp8l_pred1(jebp_color_t *pixel, jebp_color_t *top,
                             jebp_int width) {
    (void)top;
    jebp__vp8l_pred_left(pixel, width);
}

JEBP__INLINE void jebp__vp8l_pred_top(jebp_color_t *pixel, jebp_color_t *top,
                                      jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r += top[x].r;
        pixel[x].g += top[x].g;
        pixel[x].b += top[x].b;
        pixel[x].a += top[x].a;
    }
}

static void jebp__vp8l_pred2(jebp_color_t *pixel, jebp_color_t *top,
                             jebp_int width) {
    jebp__vp8l_pred_top(pixel, top, width);
}

static void jebp__vp8l_pred3(jebp_color_t *pixel, jebp_color_t *top,
                             jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r += top[x + 1].r;
        pixel[x].g += top[x + 1].g;
        pixel[x].b += top[x + 1].b;
        pixel[x].a += top[x + 1].a;
    }
}

static void jebp__vp8l_pred4(jebp_color_t *pixel, jebp_color_t *top,
                             jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r += top[x - 1].r;
        pixel[x].g += top[x - 1].g;
        pixel[x].b += top[x - 1].b;
        pixel[x].a += top[x - 1].a;
    }
}

static void jebp__vp8l_pred5(jebp_color_t *pixel, jebp_color_t *top,
                             jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r +=
            JEBP__AVG(JEBP__AVG(pixel[x - 1].r, top[x + 1].r), top[x].r);
        pixel[x].g +=
            JEBP__AVG(JEBP__AVG(pixel[x - 1].g, top[x + 1].g), top[x].g);
        pixel[x].b +=
            JEBP__AVG(JEBP__AVG(pixel[x - 1].b, top[x + 1].b), top[x].b);
        pixel[x].a +=
            JEBP__AVG(JEBP__AVG(pixel[x - 1].a, top[x + 1].a), top[x].a);
    }
}

static void jebp__vp8l_pred6(jebp_color_t *pixel, jebp_color_t *top,
                             jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r += JEBP__AVG(pixel[x - 1].r, top[x - 1].r);
        pixel[x].g += JEBP__AVG(pixel[x - 1].g, top[x - 1].g);
        pixel[x].b += JEBP__AVG(pixel[x - 1].b, top[x - 1].b);
        pixel[x].a += JEBP__AVG(pixel[x - 1].a, top[x - 1].a);
    }
}

static void jebp__vp8l_pred7(jebp_color_t *pixel, jebp_color_t *top,
                             jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r += JEBP__AVG(pixel[x - 1].r, top[x].r);
        pixel[x].g += JEBP__AVG(pixel[x - 1].g, top[x].g);
        pixel[x].b += JEBP__AVG(pixel[x - 1].b, top[x].b);
        pixel[x].a += JEBP__AVG(pixel[x - 1].a, top[x].a);
    }
}

static void jebp__vp8l_pred8(jebp_color_t *pixel, jebp_color_t *top,
                             jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r += JEBP__AVG(top[x - 1].r, top[x].r);
        pixel[x].g += JEBP__AVG(top[x - 1].g, top[x].g);
        pixel[x].b += JEBP__AVG(top[x - 1].b, top[x].b);
        pixel[x].a += JEBP__AVG(top[x - 1].a, top[x].a);
    }
}

static void jebp__vp8l_pred9(jebp_color_t *pixel, jebp_color_t *top,
                             jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r += JEBP__AVG(top[x].r, top[x + 1].r);
        pixel[x].g += JEBP__AVG(top[x].g, top[x + 1].g);
        pixel[x].b += JEBP__AVG(top[x].b, top[x + 1].b);
        pixel[x].a += JEBP__AVG(top[x].a, top[x + 1].a);
    }
}

static void jebp__vp8l_pred10(jebp_color_t *pixel, jebp_color_t *top,
                              jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r += JEBP__AVG(JEBP__AVG(pixel[x - 1].r, top[x - 1].r),
                                JEBP__AVG(top[x].r, top[x + 1].r));
        pixel[x].g += JEBP__AVG(JEBP__AVG(pixel[x - 1].g, top[x - 1].g),
                                JEBP__AVG(top[x].g, top[x + 1].g));
        pixel[x].b += JEBP__AVG(JEBP__AVG(pixel[x - 1].b, top[x - 1].b),
                                JEBP__AVG(top[x].b, top[x + 1].b));
        pixel[x].a += JEBP__AVG(JEBP__AVG(pixel[x - 1].a, top[x - 1].a),
                                JEBP__AVG(top[x].a, top[x + 1].a));
    }
}

// I know that technically "paeth" refers to the full filter below (11) but I
// could not find a better name for this
JEBP__INLINE jebp__short_color_t jebp__vp8l_pred_paeth(jebp_color_t *pixel,
                                                       jebp_color_t *top) {
    return (jebp__short_color_t){
        pixel[-1].r + top->r - top[-1].r, pixel[-1].g + top->g - top[-1].g,
        pixel[-1].b + top->b - top[-1].b, pixel[-1].a + top->a - top[-1].a};
}

JEBP__INLINE jebp_int jebp__vp8l_pred_dist(jebp_color_t *pixel,
                                           jebp__short_color_t *paeth) {
    return JEBP__ABS(pixel->r - paeth->r) + JEBP__ABS(pixel->g - paeth->g) +
           JEBP__ABS(pixel->b - paeth->b) + JEBP__ABS(pixel->a - paeth->a);
}

static void jebp__vp8l_pred11(jebp_color_t *pixel, jebp_color_t *top,
                              jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        jebp__short_color_t paeth = jebp__vp8l_pred_paeth(&pixel[x], &top[x]);
        jebp_int ldist = jebp__vp8l_pred_dist(&pixel[x - 1], &paeth);
        jebp_int tdist = jebp__vp8l_pred_dist(&top[x], &paeth);
        if (ldist < tdist) {
            jebp__vp8l_pred_left(&pixel[x], 1);
        } else {
            jebp__vp8l_pred_top(&pixel[x], &top[x], 1);
        }
    }
}

static void jebp__vp8l_pred12(jebp_color_t *pixel, jebp_color_t *top,
                              jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        jebp__short_color_t paeth = jebp__vp8l_pred_paeth(&pixel[x], &top[x]);
        pixel[x].r += JEBP__CLAMP_UBYTE(paeth.r);
        pixel[x].g += JEBP__CLAMP_UBYTE(paeth.g);
        pixel[x].b += JEBP__CLAMP_UBYTE(paeth.b);
        pixel[x].a += JEBP__CLAMP_UBYTE(paeth.a);
    }
}

static void jebp__vp8l_pred13(jebp_color_t *pixel, jebp_color_t *top,
                              jebp_int width) {
    for (jebp_int x = 0; x < width; x += 1) {
        jebp_color_t avg = {JEBP__AVG(pixel[x - 1].r, top[x].r),
                            JEBP__AVG(pixel[x - 1].g, top[x].g),
                            JEBP__AVG(pixel[x - 1].b, top[x].b),
                            JEBP__AVG(pixel[x - 1].a, top[x].a)};
        pixel[x].r += JEBP__CLAMP_UBYTE(avg.r + (avg.r - top[x - 1].r) / 2);
        pixel[x].g += JEBP__CLAMP_UBYTE(avg.g + (avg.g - top[x - 1].g) / 2);
        pixel[x].b += JEBP__CLAMP_UBYTE(avg.b + (avg.b - top[x - 1].b) / 2);
        pixel[x].a += JEBP__CLAMP_UBYTE(avg.a + (avg.a - top[x - 1].a) / 2);
    }
}

static const jebp__vp8l_pred_t jebp__vp8l_preds[JEBP__NB_VP8L_PRED_TYPES] = {
    jebp__vp8l_pred0,  jebp__vp8l_pred1, jebp__vp8l_pred2,  jebp__vp8l_pred3,
    jebp__vp8l_pred4,  jebp__vp8l_pred5, jebp__vp8l_pred6,  jebp__vp8l_pred7,
    jebp__vp8l_pred8,  jebp__vp8l_pred9, jebp__vp8l_pred10, jebp__vp8l_pred11,
    jebp__vp8l_pred12, jebp__vp8l_pred13};

/**
 * VP8L transforms
 */
typedef enum jebp__transform_type_t {
    JEBP__TRANSFORM_PREDICT,
    JEBP__TRANSFORM_COLOR,
    JEBP__TRANSFORM_GREEN,
    JEBP__TRANSFORM_PALETTE,
    JEBP__NB_TRANSFORMS
} jebp__transform_type_t;

typedef struct jebp__transform_t {
    jebp__transform_type_t type;
    jebp__subimage_t image;
} jebp__transform_t;

static jebp_error_t jebp__read_transform(jebp__transform_t *transform,
                                         jebp__bit_reader_t *bits,
                                         jebp_image_t *image) {
    jebp_error_t err = JEBP_OK;
    transform->type = jebp__read_bits(bits, 2, &err);
    if (err != JEBP_OK) {
        return err;
    }
    if (transform->type == JEBP__TRANSFORM_PALETTE) {
        // TODO: support palette images
        return JEBP_ERROR_NOSUP_PALETTE;
    } else if (transform->type != JEBP__TRANSFORM_GREEN) {
        err = jebp__read_subimage(&transform->image, bits, image);
    }
    return err;
}

static void jebp__free_transform(jebp__transform_t *transform) {
    if (transform->type != JEBP__TRANSFORM_GREEN) {
        jebp_free_image((jebp_image_t *)&transform->image);
    }
}

JEBP__INLINE jebp_error_t jebp__apply_predict_row(jebp_color_t *pixel,
                                                  jebp_color_t *top,
                                                  jebp_int width,
                                                  jebp_color_t *predict_pixel) {
    if (predict_pixel->g >= JEBP__NB_VP8L_PRED_TYPES) {
        return JEBP_ERROR_INVDATA;
    }
    jebp__vp8l_preds[predict_pixel->g](pixel, top, width);
    return JEBP_OK;
}

JEBP__INLINE jebp_error_t jebp__apply_predict_transform(
    jebp_image_t *image, jebp__subimage_t *predict_image) {
    jebp_error_t err;
    jebp_color_t *pixel = image->pixels;
    jebp_color_t *top = pixel;
    jebp_int predict_width = predict_image->width - 1;
    jebp_int block_size = 1 << predict_image->block_bits;
    jebp_int end_size =
        image->width - (predict_width << predict_image->block_bits);
    if (predict_width == 0) {
        // Special case: if there is only one block the first block which is
        //               shortened by one pixel (due to the left prediction)
        //               needs to be `end_size` and the proper end block then
        //               needs to be skipped.
        block_size = end_size;
        end_size = 0;
    }
    // Use opaque-black prediction for the top-left pixel
    jebp__vp8l_pred_black(pixel, 1);
    // Use left prediction for the top row
    jebp__vp8l_pred_left(pixel + 1, image->width - 1);
    pixel += image->width;
    for (jebp_int y = 1; y < image->height; y += 1) {
        jebp_color_t *predict_row =
            &predict_image->pixels[(y >> predict_image->block_bits) *
                                   predict_image->width];
        // Use top prediction for the left column
        jebp__vp8l_pred_top(pixel, top, 1);
        // Finish the rest of the first block
        if ((err = jebp__apply_predict_row(pixel + 1, top + 1, block_size - 1,
                                           predict_row)) != JEBP_OK) {
            return err;
        }
        pixel += block_size;
        top += block_size;
        for (jebp_int x = 1; x < predict_width; x += 1) {
            if ((err = jebp__apply_predict_row(pixel, top, block_size,
                                               &predict_row[x])) != JEBP_OK) {
                return err;
            }
            pixel += block_size;
            top += block_size;
        }
        jebp__apply_predict_row(pixel, top, end_size,
                                &predict_row[predict_width]);
        pixel += end_size;
        top += end_size;
    }
    return JEBP_OK;
}

JEBP__INLINE void jebp__apply_color_row(jebp_color_t *pixel, jebp_int width,
                                        jebp_color_t *color_pixel) {
    for (jebp_int x = 0; x < width; x += 1) {
        pixel[x].r += ((jebp_byte)pixel[x].g * (jebp_byte)color_pixel->b) >> 5;
        pixel[x].b += ((jebp_byte)pixel[x].g * (jebp_byte)color_pixel->g) >> 5;
        pixel[x].b += ((jebp_byte)pixel[x].r * (jebp_byte)color_pixel->r) >> 5;
    }
}

JEBP__INLINE jebp_error_t jebp__apply_color_transform(
    jebp_image_t *image, jebp__subimage_t *color_image) {
    jebp_color_t *pixel = image->pixels;
    jebp_int color_width = color_image->width - 1;
    jebp_int block_size = 1 << color_image->block_bits;
    jebp_int end_size = image->width - (color_width << color_image->block_bits);
    for (jebp_int y = 0; y < image->height; y += 1) {
        jebp_color_t *color_row =
            &color_image
                 ->pixels[(y >> color_image->block_bits) * color_image->width];
        for (jebp_int x = 0; x < color_width; x += 1) {
            jebp__apply_color_row(pixel, block_size, &color_row[x]);
            pixel += block_size;
        }
        jebp__apply_color_row(pixel, end_size, &color_row[color_width]);
        pixel += end_size;
    }
    return JEBP_OK;
}

JEBP__INLINE jebp_error_t jebp__apply_green_transform(jebp_image_t *image) {
    for (jebp_int i = 0; i < image->width * image->height; i += 1) {
        jebp_color_t *pixel = &image->pixels[i];
        pixel->r += pixel->g;
        pixel->b += pixel->g;
    }
    return JEBP_OK;
}

static jebp_error_t jebp__apply_transform(jebp__transform_t *transform,
                                          jebp_image_t *image) {
    switch (transform->type) {
    case JEBP__TRANSFORM_PREDICT:
        return jebp__apply_predict_transform(image, &transform->image);
    case JEBP__TRANSFORM_COLOR:
        return jebp__apply_color_transform(image, &transform->image);
    case JEBP__TRANSFORM_GREEN:
        return jebp__apply_green_transform(image);
    default:
        return JEBP_ERROR_NOSUP;
    }
}

/**
 * VP8L lossless codec
 */
#define JEBP__VP8L_TAG 0x4c385056
#define JEBP__VP8L_MAGIC 0x2f

static jebp_error_t jebp__read_vp8l_header(jebp_image_t *image,
                                           jebp__reader_t *reader,
                                           jebp__bit_reader_t *bits,
                                           jebp__chunk_t *chunk) {
    jebp_error_t err = JEBP_OK;
    if (chunk->size < 5) {
        return JEBP_ERROR_INVDATA_HEADER;
    }
    if (jebp__read_uint8(reader, &err) != JEBP__VP8L_MAGIC) {
        return jebp__error(&err, JEBP_ERROR_INVDATA_HEADER);
    }
    jepb__init_bit_reader(bits, reader, chunk->size - 1);
    image->width = jebp__read_bits(bits, 14, &err) + 1;
    image->height = jebp__read_bits(bits, 14, &err) + 1;
    jebp__read_bits(bits, 1, &err); // alpha does not impact decoding
    if (jebp__read_bits(bits, 3, &err) != 0) {
        // version must be 0
        return jebp__error(&err, JEBP_ERROR_NOSUP);
    }
    return err;
}

static jebp_error_t jebp__read_vp8l_size(jebp_image_t *image,
                                         jebp__reader_t *reader,
                                         jebp__chunk_t *chunk) {
    jebp__bit_reader_t bits;
    return jebp__read_vp8l_header(image, reader, &bits, chunk);
}

static jebp_error_t jebp__read_vp8l_nohead(jebp_image_t *image,
                                           jebp__bit_reader_t *bits) {
    jebp_error_t err = JEBP_OK;
    jebp__transform_t transforms[4];
    jebp_int nb_transforms = 0;
    for (; nb_transforms <= JEBP__NB_TRANSFORMS; nb_transforms += 1) {
        if (!jebp__read_bits(bits, 1, &err)) {
            // no more transforms to read
            break;
        }
        if (err != JEBP_OK || nb_transforms == JEBP__NB_TRANSFORMS) {
            // too many transforms
            jebp__error(&err, JEBP_ERROR_INVDATA);
            goto free_transforms;
        }
        if ((err = jebp__read_transform(&transforms[nb_transforms], bits,
                                        image)) != JEBP_OK) {
            goto free_transforms;
        }
    }
    if (err != JEBP_OK) {
        goto free_transforms;
    }

    jebp__colcache_t colcache;
    if ((err = jebp__read_colcache(&colcache, bits)) != JEBP_OK) {
        goto free_transforms;
    }
    jebp__subimage_t *huffman_image = &(jebp__subimage_t){0};
    if (!jebp__read_bits(bits, 1, &err)) {
        // there is no huffman image
        huffman_image = NULL;
    }
    if (err != JEBP_OK) {
        jebp__free_colcache(&colcache);
        goto free_transforms;
    }
    if (huffman_image != NULL) {
        if ((err = jebp__read_subimage(huffman_image, bits, image)) !=
            JEBP_OK) {
            jebp__free_colcache(&colcache);
            goto free_transforms;
        }
    }
    err = jebp__read_vp8l_image(image, bits, &colcache, huffman_image);
    jebp__free_colcache(&colcache);
    jebp_free_image((jebp_image_t *)huffman_image);

free_transforms:
    for (nb_transforms -= 1; nb_transforms >= 0; nb_transforms -= 1) {
        if (err == JEBP_OK) {
            err = jebp__apply_transform(&transforms[nb_transforms], image);
        }
        jebp__free_transform(&transforms[nb_transforms]);
    }
    return err;
}

static jebp_error_t jebp__read_vp8l(jebp_image_t *image, jebp__reader_t *reader,
                                    jebp__chunk_t *chunk) {
    jebp_error_t err;
    jebp__bit_reader_t bits;
    if ((err = jebp__read_vp8l_header(image, reader, &bits, chunk)) !=
        JEBP_OK) {
        return err;
    }
    if ((err = jebp__read_vp8l_nohead(image, &bits)) != JEBP_OK) {
        return err;
    }
    return JEBP_OK;
}
#endif // JEBP_NO_VP8L

/**
 * Public API
 */
static const char *const jebp__error_strings[JEBP_NB_ERRORS];

const char *jebp_error_string(jebp_error_t err) {
    if (err < 0 || err >= JEBP_NB_ERRORS) {
        err = JEBP_ERROR_UNKNOWN;
    }
    return jebp__error_strings[err];
}

void jebp_free_image(jebp_image_t *image) {
    if (image != NULL) {
        JEBP_FREE(image->pixels);
        JEBP__CLEAR(image, sizeof(jebp_image_t));
    }
}

static jebp_error_t jebp__read_size(jebp_image_t *image,
                                    jebp__reader_t *reader) {
    jebp_error_t err;
    jebp__riff_reader_t riff;
    JEBP__CLEAR(image, sizeof(jebp_image_t));
    if ((err = jebp__read_riff_header(&riff, reader)) != JEBP_OK) {
        return err;
    }
    jebp__chunk_t chunk;
    if ((err = jebp__read_riff_chunk(&riff, &chunk)) != JEBP_OK) {
        return err;
    }

    switch (chunk.tag) {
#ifndef JEBP_NO_VP8L
    case JEBP__VP8L_TAG:
        return jebp__read_vp8l_size(image, reader, &chunk);
#endif // JEBP_NO_VP8L
    default:
        return JEBP_ERROR_NOSUP_CODEC;
    }
}

jebp_error_t jebp_decode_size(jebp_image_t *image, size_t size,
                              const void *data) {
    if (image == NULL || data == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__reader_t reader;
    jebp__init_memory(&reader, size, data);
    return jebp__read_size(image, &reader);
}

static jebp_error_t jebp__read(jebp_image_t *image, jebp__reader_t *reader) {
    jebp_error_t err;
    jebp__riff_reader_t riff;
    JEBP__CLEAR(image, sizeof(jebp_image_t));
    if ((err = jebp__read_riff_header(&riff, reader)) != JEBP_OK) {
        return err;
    }
    jebp__chunk_t chunk;
    if ((err = jebp__read_riff_chunk(&riff, &chunk)) != JEBP_OK) {
        return err;
    }

    switch (chunk.tag) {
#ifndef JEBP_NO_VP8L
    case JEBP__VP8L_TAG:
        return jebp__read_vp8l(image, reader, &chunk);
#endif // JEBP_NO_VP8L
    default:
        return JEBP_ERROR_NOSUP_CODEC;
    }
}

jebp_error_t jebp_decode(jebp_image_t *image, size_t size, const void *data) {
    if (image == NULL || data == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__reader_t reader;
    jebp__init_memory(&reader, size, data);
    return jebp__read(image, &reader);
}

#ifndef JEBP_NO_STDIO
jebp_error_t jebp_read_size(jebp_image_t *image, const char *path) {
    jebp_error_t err;
    if (image == NULL || path == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__reader_t reader;
    if ((err = jebp__open_file(&reader, path)) != JEBP_OK) {
        return err;
    }
    err = jebp__read_size(image, &reader);
    jebp__close_file(&reader);
    return err;
}

jebp_error_t jebp_read(jebp_image_t *image, const char *path) {
    jebp_error_t err;
    if (image == NULL || path == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__reader_t reader;
    if ((err = jebp__open_file(&reader, path)) != JEBP_OK) {
        return err;
    }
    err = jebp__read(image, &reader);
    jebp__close_file(&reader);
    return err;
}
#endif // JEBP_NO_STDIO

/**
 * Lookup tables
 */
// These are moved to the end of the file since some of them are very large and
// putting them in the middle of the code would disrupt the flow of reading.
// Especially since in most situations the values in these tables are
// unimportant to the developer.
#ifndef JEBP_NO_VP8L
// The order that meta lengths are read
static const jebp_byte jebp__meta_length_order[JEBP__NB_META_SYMBOLS] = {
    17, 18, 0, 1, 2, 3, 4, 5, 16, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

// {X, Y} offsets from the pixel when decoding short distance codes
static const jebp_byte jebp__vp8l_offsets[JEBP__NB_VP8L_OFFSETS][2] = {
    {0, 1},  {1, 0},  {1, 1},  {-1, 1}, {0, 2},  {2, 0},  {1, 2},  {-1, 2},
    {2, 1},  {-2, 1}, {2, 2},  {-2, 2}, {0, 3},  {3, 0},  {1, 3},  {-1, 3},
    {3, 1},  {-3, 1}, {2, 3},  {-2, 3}, {3, 2},  {-3, 2}, {0, 4},  {4, 0},
    {1, 4},  {-1, 4}, {4, 1},  {-4, 1}, {3, 3},  {-3, 3}, {2, 4},  {-2, 4},
    {4, 2},  {-4, 2}, {0, 5},  {3, 4},  {-3, 4}, {4, 3},  {-4, 3}, {5, 0},
    {1, 5},  {-1, 5}, {5, 1},  {-5, 1}, {2, 5},  {-2, 5}, {5, 2},  {-5, 2},
    {4, 4},  {-4, 4}, {3, 5},  {-3, 5}, {5, 3},  {-5, 3}, {0, 6},  {6, 0},
    {1, 6},  {-1, 6}, {6, 1},  {-6, 1}, {2, 6},  {-2, 6}, {6, 2},  {-6, 2},
    {4, 5},  {-4, 5}, {5, 4},  {-5, 4}, {3, 6},  {-3, 6}, {6, 3},  {-6, 3},
    {0, 7},  {7, 0},  {1, 7},  {-1, 7}, {5, 5},  {-5, 5}, {7, 1},  {-7, 1},
    {4, 6},  {-4, 6}, {6, 4},  {-6, 4}, {2, 7},  {-2, 7}, {7, 2},  {-7, 2},
    {3, 7},  {-3, 7}, {7, 3},  {-7, 3}, {5, 6},  {-5, 6}, {6, 5},  {-6, 5},
    {8, 0},  {4, 7},  {-4, 7}, {7, 4},  {-7, 4}, {8, 1},  {8, 2},  {6, 6},
    {-6, 6}, {8, 3},  {5, 7},  {-5, 7}, {7, 5},  {-7, 5}, {8, 4},  {6, 7},
    {-6, 7}, {7, 6},  {-7, 6}, {8, 5},  {7, 7},  {-7, 7}, {8, 6},  {8, 7}};
#endif // JEBP_NO_VP8L

// Error strings to return from jebp_error_string
static const char *const jebp__error_strings[JEBP_NB_ERRORS] = {
    "Ok",
    "Invalid value or argument",
    "Invalid data or corrupted file",
    "Invalid WebP header or corrupted file",
    "End of file",
    "Feature not supported",
    "Codec not supported",
    "Color-indexing or palettes are not supported",
    "Not enough memory",
    "I/O error",
    "Unknown error"};
#endif // JEBP_IMPLEMENTATION
