/**
 * JebP - Single header WebP decoder
 */

/**
 * LICENSE
 **
 * Creative Commons Legal Code
 *
 * CC0 1.0 Universal
 *
 *     CREATIVE COMMONS CORPORATION IS NOT A LAW FIRM AND DOES NOT PROVIDE
 *     LEGAL SERVICES. DISTRIBUTION OF THIS DOCUMENT DOES NOT CREATE AN
 *     ATTORNEY-CLIENT RELATIONSHIP. CREATIVE COMMONS PROVIDES THIS
 *     INFORMATION ON AN "AS-IS" BASIS. CREATIVE COMMONS MAKES NO WARRANTIES
 *     REGARDING THE USE OF THIS DOCUMENT OR THE INFORMATION OR WORKS
 *     PROVIDED HEREUNDER, AND DISCLAIMS LIABILITY FOR DAMAGES RESULTING FROM
 *     THE USE OF THIS DOCUMENT OR THE INFORMATION OR WORKS PROVIDED
 *     HEREUNDER.
 *
 * Statement of Purpose
 *
 * The laws of most jurisdictions throughout the world automatically confer
 * exclusive Copyright and Related Rights (defined below) upon the creator
 * and subsequent owner(s) (each and all, an "owner") of an original work of
 * authorship and/or a database (each, a "Work").
 *
 * Certain owners wish to permanently relinquish those rights to a Work for
 * the purpose of contributing to a commons of creative, cultural and
 * scientific works ("Commons") that the public can reliably and without fear
 * of later claims of infringement build upon, modify, incorporate in other
 * works, reuse and redistribute as freely as possible in any form whatsoever
 * and for any purposes, including without limitation commercial purposes.
 * These owners may contribute to the Commons to promote the ideal of a free
 * culture and the further production of creative, cultural and scientific
 * works, or to gain reputation or greater distribution for their Work in
 * part through the use and efforts of others.
 *
 * For these and/or other purposes and motivations, and without any
 * expectation of additional consideration or compensation, the person
 * associating CC0 with a Work (the "Affirmer"), to the extent that he or she
 * is an owner of Copyright and Related Rights in the Work, voluntarily
 * elects to apply CC0 to the Work and publicly distribute the Work under its
 * terms, with knowledge of his or her Copyright and Related Rights in the
 * Work and the meaning and intended legal effect of CC0 on those rights.
 *
 * 1. Copyright and Related Rights. A Work made available under CC0 may be
 * protected by copyright and related or neighboring rights ("Copyright and
 * Related Rights"). Copyright and Related Rights include, but are not
 * limited to, the following:
 *
 *   i. the right to reproduce, adapt, distribute, perform, display,
 *      communicate, and translate a Work;
 *  ii. moral rights retained by the original author(s) and/or performer(s);
 * iii. publicity and privacy rights pertaining to a person's image or
 *      likeness depicted in a Work;
 *  iv. rights protecting against unfair competition in regards to a Work,
 *      subject to the limitations in paragraph 4(a), below;
 *   v. rights protecting the extraction, dissemination, use and reuse of data
 *      in a Work;
 *  vi. database rights (such as those arising under Directive 96/9/EC of the
 *      European Parliament and of the Council of 11 March 1996 on the legal
 *      protection of databases, and under any national implementation
 *      thereof, including any amended or successor version of such
 *      directive); and
 * vii. other similar, equivalent or corresponding rights throughout the
 *      world based on applicable law or treaty, and any national
 *      implementations thereof.
 *
 * 2. Waiver. To the greatest extent permitted by, but not in contravention
 * of, applicable law, Affirmer hereby overtly, fully, permanently,
 * irrevocably and unconditionally waives, abandons, and surrenders all of
 * Affirmer's Copyright and Related Rights and associated claims and causes
 * of action, whether now known or unknown (including existing as well as
 * future claims and causes of action), in the Work (i) in all territories
 * worldwide, (ii) for the maximum duration provided by applicable law or
 * treaty (including future time extensions), (iii) in any current or future
 * medium and for any number of copies, and (iv) for any purpose whatsoever,
 * including without limitation commercial, advertising or promotional
 * purposes (the "Waiver"). Affirmer makes the Waiver for the benefit of each
 * member of the public at large and to the detriment of Affirmer's heirs and
 * successors, fully intending that such Waiver shall not be subject to
 * revocation, rescission, cancellation, termination, or any other legal or
 * equitable action to disrupt the quiet enjoyment of the Work by the public
 * as contemplated by Affirmer's express Statement of Purpose.
 *
 * 3. Public License Fallback. Should any part of the Waiver for any reason
 * be judged legally invalid or ineffective under applicable law, then the
 * Waiver shall be preserved to the maximum extent permitted taking into
 * account Affirmer's express Statement of Purpose. In addition, to the
 * extent the Waiver is so judged Affirmer hereby grants to each affected
 * person a royalty-free, non transferable, non sublicensable, non exclusive,
 * irrevocable and unconditional license to exercise Affirmer's Copyright and
 * Related Rights in the Work (i) in all territories worldwide, (ii) for the
 * maximum duration provided by applicable law or treaty (including future
 * time extensions), (iii) in any current or future medium and for any number
 * of copies, and (iv) for any purpose whatsoever, including without
 * limitation commercial, advertising or promotional purposes (the
 * "License"). The License shall be deemed effective as of the date CC0 was
 * applied by Affirmer to the Work. Should any part of the License for any
 * reason be judged legally invalid or ineffective under applicable law, such
 * partial invalidity or ineffectiveness shall not invalidate the remainder
 * of the License, and in such case Affirmer hereby affirms that he or she
 * will not (i) exercise any of his or her remaining Copyright and Related
 * Rights in the Work or (ii) assert any associated claims and causes of
 * action with respect to the Work, in either case contrary to Affirmer's
 * express Statement of Purpose.
 *
 * 4. Limitations and Disclaimers.
 *
 *  a. No trademark or patent rights held by Affirmer are waived, abandoned,
 *     surrendered, licensed or otherwise affected by this document.
 *  b. Affirmer offers the Work as-is and makes no representations or
 *     warranties of any kind concerning the Work, express, implied,
 *     statutory or otherwise, including without limitation warranties of
 *     title, merchantability, fitness for a particular purpose, non
 *     infringement, or the absence of latent or other defects, accuracy, or
 *     the present or absence of errors, whether or not discoverable, all to
 *     the greatest extent permissible under applicable law.
 *  c. Affirmer disclaims responsibility for clearing rights of other persons
 *     that may apply to the Work or any use thereof, including without
 *     limitation any person's Copyright and Related Rights in the Work.
 *     Further, Affirmer disclaims responsibility for obtaining any necessary
 *     consents, permissions or other rights required for any use of the
 *     Work.
 *  d. Affirmer understands and acknowledges that Creative Commons is not a
 *     party to this document and has no duty or obligation with respect to
 *     this CC0 or use of the Work.
 */

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
 *   `JEBP_ERROR` can be defined to a custom error handling. JebP uses `longjmp`
 *                to jump back to the top-level API function on error, to
 *                simplify error handling and checking. This might not be
 *                desirable for certain systems so this function allows for an
 *                alternative method. The provided function must not return and
 *                should be marked as non-returning. Alternatively it could be
 *                marked as unreachable to improve performance and code-size.
 *                However, it should not need to be said that THIS IS A VERY
 *                DUMB AND INSECURE IDEA so be very careful.
 *   `JEBP_LOG_ERRORS` will log a message to `stdout` as soon as an error occurs
 *                     with the line-number it happened on. Note that this will
 *                     include `stdio.h` even if `JEBP_NO_STDIO` is defined.
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
 *   `setjmp.h` is used for the default implementation of `JEBP_ERROR`, using
 *              `longjmp` and `setjmp`. If that macro is already defined, this
 *              will not be included.
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

// We don't do any runtime detection since that causes alot of
// heavily-documented issues that I won't go into here. Instead, if the compiler
// supports it (and requests it) we will use it. It helps that both x86-64 and
// AArch64 always support the SIMD from their 32-bit counterparts.
#if defined(__i386) || defined(__i386__) || defined(_M_IX86)
#define JEBP__LITTLE_ENDIAN
#if defined(__SSE2__) || _M_IX86_FP == 2
#define JEBP__SIMD_SSE2
#endif
#elif defined(__x86_64) || defined(__x86_64__) || defined(_M_X64)
#define JEBP__LITTLE_ENDIAN
#define JEBP__SIMD_SSE2
#elif defined(__arm) || defined(__arm__) || defined(_M_ARM)
#if !defined(__ARM_BIG_ENDIAN) || defined(__LITTLE_ENDIAN__)
// Is Windows always little-endian? I get alot of conflicting results...
#define JEBP__LITTLE_ENDIAN
#endif
#ifdef __ARM_NEON
// There used to be a check for Windows here since I believed that Windows
// always required Neon support to be installed but I cannot find that mentioned
// anywhere.
#define JEBP__SIMD_NEON
#endif // __ARM_NEON
#elif defined(__aarch64) || defined(__aarch64__) || defined(_M_ARM64)
#if !defined(__ARM_BIG_ENDIAN) || defined(__LITTLE_ENDIAN__)
#define JEBP__LITTLE_ENDIAN
#endif // __ARM_BIG_ENDIAN
#define JEBP__SIMD_NEON
#else
#ifdef __LITTLE_ENDIAN__
#define JEBP__LITTLE_ENDIAN
#endif // __LITTLE_ENDIAN__
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
// TODO: Maybe we should instead have a logging flag and add custom logs with
//       more information to each error (and maybe other stuff like allocations)
#ifdef JEBP_LOG_ERRORS
#define JEBP__LOG(err)                                                         \
    (printf("line %i: %s\n", __LINE__, jebp_error_string(err)), err)
#define JEBP_ERROR_INVAL JEBP__LOG(1)
#define JEBP_ERROR_INVDATA JEBP__LOG(2)
#define JEBP_ERROR_INVDATA_HEADER JEBP__LOG(3)
#define JEBP_ERROR_EOF JEBP__LOG(4)
#define JEBP_ERROR_NOSUP JEBP__LOG(5)
#define JEBP_ERROR_NOSUP_CODEC JEBP__LOG(6)
#define JEBP_ERROR_NOSUP_PALETTE JEBP__LOG(7)
#define JEBP_ERROR_NOMEM JEBP__LOG(8)
#define JEBP_ERROR_IO JEBP__LOG(9)
#endif // JEBP_LOG_ERRORS

#define JEBP__MIN(a, b) ((a) < (b) ? (a) : (b))
#define JEBP__MAX(a, b) ((a) > (b) ? (a) : (b))
#define JEBP__ABS(a) ((a) < 0 ? -(a) : (a))
#define JEBP__AVG(a, b) (((a) + (b)) / 2)
#define JEBP__CEIL_SHIFT(a, b) (((a) + (1 << (b)) - 1) >> (b))
#define JEBP__CLAMP(x, min, max) JEBP__MIN(JEBP__MAX(x, min), max)
#define JEBP__CLAMP_UBYTE(x) JEBP__CLAMP(x, 0, 255)
#define JEBP__CLEAR(ptr, size) memset(ptr, 0, size)
#define JEBP__LOOP_IMAGE(image)                                                \
    for (jebp_color_t *pixel = (image)->pixels,                                \
                      *end = pixel + (image)->width * (image)->height;         \
         pixel != end;)

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
// TODO: consider renaming to `jebp__read_byte`?
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
    *err = jebp__read_bytes(ctx, 4, bytes);
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
    for (; *code & inc; inc >>= 1)
        ;
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
        return *err;
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
    jebp_error_t err = JEBP_OK;
    jebp_int nb_groups = 1;
    jebp__huffman_group_t *groups = &(jebp__huffman_group_t){0};
    if (huffman_image != NULL) {
        JEBP__LOOP_IMAGE(huffman_image) {
            if (pixel->r != 0) {
                // Currently only 256 huffman groups are supported
                return JEBP_ERROR_NOSUP;
            }
            nb_groups = JEBP__MAX(nb_groups, pixel->g + 1);
            pixel += 1;
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

    jebp_int x = 0;
    jebp_int y = 0;
    jebp__huffman_group_t *group = groups;
    jebp_int huffman_x = 0;
    jebp_int huffman_y = 0;
    jebp_color_t *huffman_pixel = NULL;
    jebp_color_t *huffman_row = NULL;
    if (huffman_image != NULL) {
        huffman_pixel = huffman_image->pixels;
        huffman_row = huffman_pixel;
        group = &groups[huffman_pixel->g];
    }
    JEBP__LOOP_IMAGE(image) {
        jebp_int main = jebp__read_symbol(group->main, bits, &err);
        if (main < JEBP__NB_COLOR_SYMBOLS) {
            pixel->g = main;
            pixel->r = jebp__read_symbol(group->red, bits, &err);
            pixel->b = jebp__read_symbol(group->blue, bits, &err);
            pixel->a = jebp__read_symbol(group->alpha, bits, &err);
            jebp__colcache_insert(colcache, pixel);
            pixel += 1;
            x += 1;
        } else if (main < JEBP__NB_MAIN_SYMBOLS) {
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
            jebp_color_t *repeat_end = repeat + length;
            if (repeat < image->pixels || pixel + length > end) {
                jebp__error(&err, JEBP_ERROR_INVDATA);
                break;
            }
            while (repeat != repeat_end) {
                jebp__colcache_insert(colcache, repeat);
                *(pixel++) = *(repeat++);
            }
            x += length;
        } else {
            *(pixel++) = colcache->colors[main - JEBP__NB_MAIN_SYMBOLS];
            x += 1;
        }

        // Update the huffman group if needed
        if (huffman_image != NULL && pixel != end) {
            jebp_int delta_y = 0;
            if (x >= image->width) {
                y += x / image->width;
                x %= image->width;
                jebp_int huff_y = y >> huffman_image->block_bits;
                if (huff_y != huffman_y) {
                    delta_y = huff_y - huffman_y;
                    huffman_row += delta_y * huffman_image->width;
                    huffman_y = huff_y;
                }
            }
            jebp_int huff_x = x >> huffman_image->block_bits;
            if (huff_x != huffman_x || delta_y > 0) {
                huffman_pixel = huffman_row + huff_x;
                huffman_x = huff_x;
                group = &groups[huffman_pixel->g];
            }
        }
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

typedef void (*jebp__vp8l_pred_t)(jebp_color_t *pixel, jebp_color_t *end,
                                  jebp_color_t *top);

typedef struct jebp__short_color_t {
    jebp_short r;
    jebp_short g;
    jebp_short b;
    jebp_short a;
} jebp__short_color_t;

JEBP__INLINE void jebp__vp8l_pred_black(jebp_color_t *pixel) {
    pixel->a += 0xff;
}

static void jebp__vp8l_pred0(jebp_color_t *pixel, jebp_color_t *end,
                             jebp_color_t *top) {
    (void)top;
    for (; pixel != end; pixel += 1) {
        jebp__vp8l_pred_black(pixel);
    }
}

JEBP__INLINE void jebp__vp8l_pred_left(jebp_color_t *pixel) {
    pixel->r += pixel[-1].r;
    pixel->g += pixel[-1].g;
    pixel->b += pixel[-1].b;
    pixel->a += pixel[-1].a;
}

static void jebp__vp8l_pred1(jebp_color_t *pixel, jebp_color_t *end,
                             jebp_color_t *top) {
    (void)top;
    for (; pixel != end; pixel += 1) {
        jebp__vp8l_pred_left(pixel);
    }
}

JEBP__INLINE void jebp__vp8l_pred_top(jebp_color_t *pixel, jebp_color_t *top) {
    pixel->r += top->r;
    pixel->g += top->g;
    pixel->b += top->b;
    pixel->a += top->a;
}

static void jebp__vp8l_pred2(jebp_color_t *pixel, jebp_color_t *end,
                             jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        jebp__vp8l_pred_top(pixel, top);
    }
}

static void jebp__vp8l_pred3(jebp_color_t *pixel, jebp_color_t *end,
                             jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        pixel->r += top[1].r;
        pixel->g += top[1].g;
        pixel->b += top[1].b;
        pixel->a += top[1].a;
    }
}

static void jebp__vp8l_pred4(jebp_color_t *pixel, jebp_color_t *end,
                             jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        pixel->r += top[-1].r;
        pixel->g += top[-1].g;
        pixel->b += top[-1].b;
        pixel->a += top[-1].a;
    }
}

static void jebp__vp8l_pred5(jebp_color_t *pixel, jebp_color_t *end,
                             jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        pixel->r += JEBP__AVG(JEBP__AVG(pixel[-1].r, top[1].r), top->r);
        pixel->g += JEBP__AVG(JEBP__AVG(pixel[-1].g, top[1].g), top->g);
        pixel->b += JEBP__AVG(JEBP__AVG(pixel[-1].b, top[1].b), top->b);
        pixel->a += JEBP__AVG(JEBP__AVG(pixel[-1].a, top[1].a), top->a);
    }
}

static void jebp__vp8l_pred6(jebp_color_t *pixel, jebp_color_t *end,
                             jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        pixel->r += JEBP__AVG(pixel[-1].r, top[-1].r);
        pixel->g += JEBP__AVG(pixel[-1].g, top[-1].g);
        pixel->b += JEBP__AVG(pixel[-1].b, top[-1].b);
        pixel->a += JEBP__AVG(pixel[-1].a, top[-1].a);
    }
}

static void jebp__vp8l_pred7(jebp_color_t *pixel, jebp_color_t *end,
                             jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        pixel->r += JEBP__AVG(pixel[-1].r, top->r);
        pixel->g += JEBP__AVG(pixel[-1].g, top->g);
        pixel->b += JEBP__AVG(pixel[-1].b, top->b);
        pixel->a += JEBP__AVG(pixel[-1].a, top->a);
    }
}

static void jebp__vp8l_pred8(jebp_color_t *pixel, jebp_color_t *end,
                             jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        pixel->r += JEBP__AVG(top[-1].r, top->r);
        pixel->g += JEBP__AVG(top[-1].g, top->g);
        pixel->b += JEBP__AVG(top[-1].b, top->b);
        pixel->a += JEBP__AVG(top[-1].a, top->a);
    }
}

static void jebp__vp8l_pred9(jebp_color_t *pixel, jebp_color_t *end,
                             jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        pixel->r += JEBP__AVG(top->r, top[1].r);
        pixel->g += JEBP__AVG(top->g, top[1].g);
        pixel->b += JEBP__AVG(top->b, top[1].b);
        pixel->a += JEBP__AVG(top->a, top[1].a);
    }
}

static void jebp__vp8l_pred10(jebp_color_t *pixel, jebp_color_t *end,
                              jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        pixel->r += JEBP__AVG(JEBP__AVG(pixel[-1].r, top[-1].r),
                              JEBP__AVG(top->r, top[1].r));
        pixel->g += JEBP__AVG(JEBP__AVG(pixel[-1].g, top[-1].g),
                              JEBP__AVG(top->g, top[1].g));
        pixel->b += JEBP__AVG(JEBP__AVG(pixel[-1].b, top[-1].b),
                              JEBP__AVG(top->b, top[1].b));
        pixel->a += JEBP__AVG(JEBP__AVG(pixel[-1].a, top[-1].a),
                              JEBP__AVG(top->a, top[1].a));
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

static void jebp__vp8l_pred11(jebp_color_t *pixel, jebp_color_t *end,
                              jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        jebp__short_color_t paeth = jebp__vp8l_pred_paeth(pixel, top);
        jebp_int ldist = jebp__vp8l_pred_dist(pixel - 1, &paeth);
        jebp_int tdist = jebp__vp8l_pred_dist(top, &paeth);
        if (ldist < tdist) {
            jebp__vp8l_pred_left(pixel);
        } else {
            jebp__vp8l_pred_top(pixel, top);
        }
    }
}

static void jebp__vp8l_pred12(jebp_color_t *pixel, jebp_color_t *end,
                              jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        jebp__short_color_t paeth = jebp__vp8l_pred_paeth(pixel, top);
        pixel->r += JEBP__CLAMP_UBYTE(paeth.r);
        pixel->g += JEBP__CLAMP_UBYTE(paeth.g);
        pixel->b += JEBP__CLAMP_UBYTE(paeth.b);
        pixel->a += JEBP__CLAMP_UBYTE(paeth.a);
    }
}

static void jebp__vp8l_pred13(jebp_color_t *pixel, jebp_color_t *end,
                              jebp_color_t *top) {
    for (; pixel != end; pixel += 1, top += 1) {
        jebp_color_t avg = {
            JEBP__AVG(pixel[-1].r, top->r), JEBP__AVG(pixel[-1].g, top->g),
            JEBP__AVG(pixel[-1].b, top->b), JEBP__AVG(pixel[-1].a, top->a)};
        pixel->r += JEBP__CLAMP_UBYTE(avg.r + (avg.r - top[-1].r) / 2);
        pixel->g += JEBP__CLAMP_UBYTE(avg.g + (avg.g - top[-1].g) / 2);
        pixel->b += JEBP__CLAMP_UBYTE(avg.b + (avg.b - top[-1].b) / 2);
        pixel->a += JEBP__CLAMP_UBYTE(avg.a + (avg.a - top[-1].a) / 2);
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
                                                  jebp_color_t *end,
                                                  jebp_color_t *top,
                                                  jebp_color_t *predict_pixel) {
    if (predict_pixel->g < JEBP__NB_VP8L_PRED_TYPES) {
        return JEBP_ERROR_INVDATA;
    }
    jebp__vp8l_preds[predict_pixel->g](pixel, end, top);
    return JEBP_OK;
}

JEBP__INLINE jebp_error_t jebp__apply_predict_transform(
    jebp_image_t *image, jebp__subimage_t *predict_image) {
    jebp_int block_size = 1 << predict_image->block_bits;
    jebp_int block_y = 0;
    jebp_color_t *predict_pixel = predict_image->pixels;
    jebp_color_t *top = image->pixels;
    JEBP__LOOP_IMAGE(image) {
        if (pixel == image->pixels) {
            jebp_color_t *row_end = pixel + image->width;
            // Use opaque-black prediction for the top-left pixel
            jebp__vp8l_pred_black(pixel++);
            for (; pixel != row_end; pixel += 1) {
                // Use left prediction for the top row
                jebp__vp8l_pred_left(pixel);
            }
            block_y += 1;
            continue;
        }

        jebp_color_t *row_end = pixel + image->width;
        // Use top prediction for the left column
        jebp__vp8l_pred_top(pixel++, top++);
        jebp_int size = JEBP__MIN((jebp_int)(row_end - pixel), block_size - 1);
        while (pixel != row_end) {
            if (predict_pixel->g >= JEBP__NB_VP8L_PRED_TYPES) {
                return JEBP_ERROR_INVDATA;
            }
            jebp__vp8l_preds[predict_pixel->g](pixel, pixel + size, top);
            pixel += size;
            top += size;
            predict_pixel += 1;
            size = JEBP__MIN((jebp_int)(row_end - pixel), block_size);
        }
        block_y += 1;
        if (block_y < block_size) {
            predict_pixel -= predict_image->width;
        } else {
            block_y = 0;
        }
    }
    return JEBP_OK;
}

JEBP__INLINE void jebp__apply_color_row(jebp_color_t *pixel, jebp_color_t *end,
                                        jebp_color_t *color_pixel) {
    for (; pixel != end; pixel += 1) {
        pixel->r += ((jebp_byte)pixel->g * (jebp_byte)color_pixel->b) >> 5;
        pixel->b += ((jebp_byte)pixel->g * (jebp_byte)color_pixel->g) >> 5;
        pixel->b += ((jebp_byte)pixel->r * (jebp_byte)color_pixel->r) >> 5;
    }
}

JEBP__INLINE jebp_error_t jebp__apply_color_transform(
    jebp_image_t *image, jebp__subimage_t *color_image) {
    jebp_int block_size = 1 << color_image->block_bits;
    jebp_int block_y = 0;
    jebp_color_t *color_pixel = color_image->pixels;
    JEBP__LOOP_IMAGE(image) {
        jebp_color_t *row_end = pixel + image->width;
        while (pixel != row_end) {
            jebp_int size = JEBP__MIN((jebp_int)(row_end - pixel), block_size);
            jebp__apply_color_row(pixel, pixel + size, color_pixel);
            pixel += size;
            color_pixel += 1;
        }
        block_y += 1;
        if (block_y < block_size) {
            color_pixel -= color_image->width;
        } else {
            block_y = 0;
        }
    }
    return JEBP_OK;
}

JEBP__INLINE jebp_error_t jebp__apply_green_transform(jebp_image_t *image) {
    JEBP__LOOP_IMAGE(image) {
        pixel->r += pixel->g;
        pixel->b += pixel->g;
        pixel += 1;
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
        break;
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
    case JEBP__VP8L_TAG:;
        jebp__bit_reader_t bits;
        return jebp__read_vp8l_header(image, reader, &bits, &chunk);
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
