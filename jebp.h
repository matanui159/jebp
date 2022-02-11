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
#ifndef JEBP_ERROR
#include <setjmp.h>
#endif // JEBP_ERROR
#define JEBP__CLEAR(ptr, size) memset(ptr, 0, size)

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
 * JebP context
 */
typedef struct jebp__chunk_t {
    jebp_uint tag;
    jebp_uint size;
} jebp__chunk_t;

#ifndef JEBP_NO_VP8L
#define JEBP__NB_HUFFMAN_LENGTHS 16

// A nice property about canonical huffman codes is that all codes of the same
// length are increments of the previous code, meaning we can create a table
// for each length which we can index to get the value.
typedef struct jebp__huffman_table_t {
    jebp_int min_code;
    jebp_int max_code;
    jebp_int *values;
} jebp__huffman_table_t;

typedef struct jebp__huffman_t {
    jebp_int nb_values;
    jebp__huffman_table_t tables[JEBP__NB_HUFFMAN_LENGTHS];
} jebp__huffman_t;

typedef struct jebp__huffman_group_t {
    jebp__huffman_t main;
    jebp__huffman_t red;
    jebp__huffman_t blue;
    jebp__huffman_t alpha;
    jebp__huffman_t dist;
} jebp__huffman_group_t;

typedef struct jebp__subimage_t {
    jebp_int width;
    jebp_int height;
    jebp_color_t *pixels;
    jebp_int block_bits;
} jebp__subimage_t;

typedef enum jebp__transform_type_t {
    JEBP__TRANSFORM_NONE = -1,
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
#endif // JEBP_NO_VP8L

typedef struct jebp__context_t {
#ifndef JEBP_ERROR
    jebp_error_t error;
    jmp_buf jump;
#endif // JEBP_ERROR
    jebp_image_t *image;
    size_t nb_bytes;
    const jebp_byte *bytes;
#ifndef JEBP_NO_STDIO
    FILE *file;
    void *buffer;
#endif // JEBP_NO_STDIO
    jebp_int nb_bits;
    jebp_ubyte bits;

    // RIFF
    jebp__chunk_t webp_chunk;
    jebp__chunk_t codec_chunk;

#ifndef JEBP_NO_VP8L
    jebp_int colcache_bits;
    jebp_color_t *colcache;
    jebp_int nb_lengths;
    jebp_int *lengths;
    jebp_int nb_groups;
    jebp__huffman_group_t *groups;
    jebp__transform_t transforms[JEBP__NB_TRANSFORMS];
    jebp__subimage_t huffman_image;
#endif // JEBP_NO_VP8L
} jebp__context_t;

static jebp__context_t *jebp__alloc_context(void) {
    jebp__context_t *ctx = JEBP_ALLOC(sizeof(jebp__context_t));
    if (ctx == NULL) {
        return NULL;
    }
    JEBP__CLEAR(ctx, sizeof(jebp__context_t));
    return ctx;
}

static void jebp__free_context_groups(jebp__context_t *ctx) {
    for (jebp_int i = 0; i < ctx->nb_groups; i += 1) {
        jebp__huffman_group_t *group = &ctx->groups[i];
        JEBP_FREE(group->main.tables->values);
        JEBP_FREE(group->red.tables->values);
        JEBP_FREE(group->blue.tables->values);
        JEBP_FREE(group->alpha.tables->values);
        JEBP_FREE(group->dist.tables->values);
    }
    JEBP_FREE(ctx->groups);
}

static void jebp__free_context(jebp__context_t *ctx) {
    (void)ctx;
#ifndef JEBP_NO_STDIO
    if (ctx->file != NULL) {
        fclose(ctx->file);
    }
    JEBP_FREE(ctx->buffer);
#endif // JEBP_NO_STDIO

#ifndef JEBP_NO_VP8L
    JEBP_FREE(ctx->colcache);
    JEBP_FREE(ctx->lengths);
    jebp__free_context_groups(ctx);
    for (jebp_int i = 0; i < 4; i += 1) {
        JEBP_FREE(ctx->transforms[i].image.pixels);
    }
    JEBP_FREE(ctx->huffman_image.pixels);
#endif // JEBP_NO_VP8L
    JEBP_FREE(ctx);
}

/**
 * Common utilities
 */
JEBP__INLINE JEBP__NORETURN void jebp__error(jebp__context_t *ctx,
                                             jebp_error_t err, jebp_int line) {
#ifdef JEBP_LOG_ERRORS
    fprintf(stderr, "line %i: %s\n", line, jebp_error_string(err));
#else  // JEBP_LOG_ERRORS
    (void)line;
#endif // JEBP_LOG_ERRORS
    jebp_free_image(ctx->image);
#ifdef JEBP_ERROR
    jebp__free_context(ctx);
    JEBP_ERROR(err);
#else  // JEBP_ERROR
    ctx->error = err;
    longjmp(ctx->jump, 1);
#endif // JEBP_ERROR
}
#define JEBP__ERROR(err) jebp__error(ctx, JEBP_ERROR_##err, __LINE__)

#define JEBP__MIN(a, b) ((a) < (b) ? (a) : (b))
#define JEBP__MAX(a, b) ((a) > (b) ? (a) : (b))
#define JEBP__ABS(a) ((a) < 0 ? -(a) : (a))
#define JEBP__AVG(a, b) (((a) + (b)) / 2)
#define JEBP__CEIL_SHIFT(a, b) (((a) + (1 << (b)) - 1) >> (b))
#define JEBP__CLAMP_COLOR(c) JEBP__MIN(JEBP__MAX(c, 0), 255)
#define JEBP__LOOP_IMAGE(image)                                                \
    for (jebp_color_t *pixel = (image)->pixels,                                \
                      *end = pixel + (image)->width * (image)->height;         \
         pixel != end;)

// Currently only used by VP8L
// TODO: after VP8(no-L) support is added, make it an error to remove both
//       VP8 and VP8L
#ifndef JEBP_NO_VP8L
static void jebp__alloc_image(jebp__context_t *ctx, jebp_image_t *image) {
    image->pixels =
        JEBP_ALLOC(image->width * image->height * sizeof(jebp_color_t));
    if (image->pixels == NULL) {
        JEBP__ERROR(NOMEM);
    }
}
#endif // JEBP_NO_VP8L

/**
 * Reader abstraction
 */
#define JEBP__BUFFER_SIZE 4096

static void jebp__check_buffer(jebp__context_t *ctx) {
    if (ctx->nb_bytes == 0) {
#ifndef JEBP_NO_STDIO
        if (ctx->file == NULL) {
#endif // JEBP_NO_STDIO
            JEBP__ERROR(EOF);
#ifndef JEBP_NO_STDIO
        }
        ctx->nb_bytes = fread(ctx->buffer, 1, JEBP__BUFFER_SIZE, ctx->file);
        ctx->bytes = ctx->buffer;
        if (ferror(ctx->file)) {
            JEBP__ERROR(IO);
        }
        if (ctx->nb_bytes == 0) {
            JEBP__ERROR(EOF);
        }
#endif // JEBP_NO_STDIO
    }
}

static void jebp__check_chunk(jebp__context_t *ctx, jebp__chunk_t *chunk,
                              size_t size) {
    if (chunk->tag != 0) {
        if (size > chunk->size) {
            JEBP__ERROR(INVDATA);
        }
        chunk->size -= (jebp_uint)size;
    }
}

static void jebp__read_bytes(jebp__context_t *ctx, size_t size, void *data) {
    ctx->nb_bits = 0;
    jebp__check_chunk(ctx, &ctx->webp_chunk, size);
    jebp__check_chunk(ctx, &ctx->codec_chunk, size);
    jebp_byte *bytes = data;
    while (size > 0) {
        jebp__check_buffer(ctx);
        size_t nb_bytes = JEBP__MIN(size, ctx->nb_bytes);
        if (bytes != NULL) {
            memcpy(bytes, ctx->bytes, nb_bytes);
            bytes += nb_bytes;
        }
        size -= nb_bytes;
        ctx->bytes += nb_bytes;
        ctx->nb_bytes -= nb_bytes;
    }
}

// 8-bit uint reading is currently only used by the bit-reader
#ifndef JEBP_NO_VP8L
static jebp_ubyte jebp__read_uint8(jebp__context_t *ctx) {
    ctx->nb_bits = 0;
    jebp__check_chunk(ctx, &ctx->webp_chunk, 1);
    jebp__check_chunk(ctx, &ctx->codec_chunk, 1);
    jebp__check_buffer(ctx);
    ctx->nb_bytes -= 1;
    return *(ctx->bytes++);
}
#endif // JEBP_NO_VP8L

static jebp_uint jebp__read_uint32(jebp__context_t *ctx) {
#ifdef JEBP__LITTLE_ENDIAN
    jebp_uint value = 0;
    jebp__read_bytes(ctx, 4, &value);
    return value;
#else  // JEBP__LITTLE_ENDIAN
    jebp_ubyte bytes[4];
    jebp__read_bytes(ctx, 4, bytes);
    return (jebp_uint)bytes[0] | ((jebp_uint)bytes[1] << 8) |
           ((jebp_uint)bytes[2] << 16) | ((jebp_uint)bytes[3] << 24);
#endif // JEBP__LITTLE_ENDIAN
}

// Bit-reading is only used by VP8L
#ifndef JEBP_NO_VP8L
static jebp_int jebp__read_bits(jebp__context_t *ctx, jebp_int size) {
    jebp_int bits = 0;
    jebp_int shift = 0;
    while (size > 0) {
        if (ctx->nb_bits == 0) {
            ctx->bits = jebp__read_uint8(ctx);
            ctx->nb_bits = 8;
        }
        jebp_int nb_bits = JEBP__MIN(size, ctx->nb_bits);
        bits |= (ctx->bits & ((1 << nb_bits) - 1)) << shift;
        shift += nb_bits;
        size -= nb_bits;
        ctx->bits >>= nb_bits;
        ctx->nb_bits -= nb_bits;
    }
    return bits;
}
#endif // JEBP_NO_VP8L

/**
 * RIFF container
 */
#define JEBP__RIFF_TAG 0x46464952
#define JEBP__WEBP_TAG 0x50424557

static void jebp__read_chunk(jebp__context_t *ctx, jebp__chunk_t *chunk) {
    chunk->tag = 0;
    jebp_uint tag = jebp__read_uint32(ctx);
    chunk->size = jebp__read_uint32(ctx);
    chunk->tag = tag;
}

static void jebp__read_header(jebp__context_t *ctx) {
    jebp__read_chunk(ctx, &ctx->webp_chunk);
    if (ctx->webp_chunk.tag != JEBP__RIFF_TAG) {
        JEBP__ERROR(INVDATA_HEADER);
    }
    if (jebp__read_uint32(ctx) != JEBP__WEBP_TAG) {
        JEBP__ERROR(INVDATA_HEADER);
    }
    jebp__read_chunk(ctx, &ctx->codec_chunk);
}

/**
 * Huffman coding
 */
#ifndef JEBP_NO_VP8L
#define JEBP__NB_META_SYMBOLS 19
#define JEBP__NB_COLOR_SYMBOLS 256
#define JEBP__NB_LENGTH_SYMBOLS 24
#define JEBP__NB_DIST_SYMBOLS 40
#define JEBP__NB_MAIN_SYMBOLS (JEBP__NB_COLOR_SYMBOLS + JEBP__NB_LENGTH_SYMBOLS)

static const jebp_int jebp__meta_length_order[JEBP__NB_META_SYMBOLS];

static void jebp__build_huffman(jebp__context_t *ctx, jebp__huffman_t *huffman,
                                jebp_int nb_lengths) {
    jebp__huffman_table_t *table = huffman->tables;
    table->min_code = 0;
    table->max_code = 0;
    if (nb_lengths > huffman->nb_values) {
        JEBP_FREE(table->values);
        table->values = JEBP_ALLOC(nb_lengths * sizeof(jebp_int));
        if (table->values == NULL) {
            JEBP__ERROR(NOMEM);
        }
        huffman->nb_values = nb_lengths;
    }

    // TODO: do we have to check for invalid huffman trees?
    //       hypothetically it should still generate "valid" codes...
    jebp_int *values = table->values;
    jebp_int nb_used = 0;
    for (jebp_int i = 1; i < JEBP__NB_HUFFMAN_LENGTHS; i += 1) {
        table[1].min_code = table->max_code << 1;
        table += 1;
        table->max_code = table->min_code;
        table->values = values;
        for (jebp_int j = 0; j < nb_lengths; j += 1) {
            if (ctx->lengths[j] == i) {
                *(values++) = j;
                table->max_code += 1;
                nb_used += 1;
            }
        }
    }
    if (nb_used <= 1) {
        // Special case: if there is only one value, it will have length 0
        huffman->tables[0].max_code = nb_used;
    }
}

// There are faster/nicer ways to decode huffman codes but they often require
// peeking the next n bits which is not easy with how the reader was designed.
static jebp_int jebp__read_symbol(jebp__context_t *ctx,
                                  jebp__huffman_t *huffman) {
    jebp__huffman_table_t *table = huffman->tables;
    if (table->max_code > 0) {
        return table->values[0];
    }
    jebp_int code = 0;
    for (jebp_int i = 1; i < JEBP__NB_HUFFMAN_LENGTHS; i += 1) {
        table += 1;
        code = (code << 1) | jebp__read_bits(ctx, 1);
        if (code < table->max_code) {
            return table->values[code - table->min_code];
        }
    }
    JEBP__ERROR(INVDATA);
}

static void jebp__read_huffman(jebp__context_t *ctx, jebp__huffman_t *huffman,
                               jebp_int nb_lengths) {
    // This part of the spec is INCREDIBLY wrong and partly missing
    size_t lengths_size = nb_lengths * sizeof(jebp_int);
    if (nb_lengths > ctx->nb_lengths) {
        JEBP_FREE(ctx->lengths);
        ctx->lengths = JEBP_ALLOC(lengths_size);
        if (ctx->lengths == NULL) {
            JEBP__ERROR(NOMEM);
        }
        ctx->nb_lengths = nb_lengths;
    }
    JEBP__CLEAR(ctx->lengths, lengths_size);

    if (jebp__read_bits(ctx, 1)) {
        // simple length storage
        jebp_int has_second = jebp__read_bits(ctx, 1);
        jebp_int first_bits = jebp__read_bits(ctx, 1) ? 8 : 1;
        ctx->lengths[jebp__read_bits(ctx, first_bits)] = 1;
        if (has_second) {
            ctx->lengths[jebp__read_bits(ctx, 8)] = 1;
        }
    } else {
        jebp_int nb_meta_lengths = jebp__read_bits(ctx, 4) + 4;
        for (jebp_int i = 0; i < nb_meta_lengths; i += 1) {
            ctx->lengths[jebp__meta_length_order[i]] = jebp__read_bits(ctx, 3);
        }
        jebp__build_huffman(ctx, huffman, JEBP__NB_META_SYMBOLS);
        jebp_int nb_symbols = nb_lengths;
        if (jebp__read_bits(ctx, 1)) {
            // limit codes
            jebp_int symbols_bits = jebp__read_bits(ctx, 3) * 2 + 2;
            nb_symbols = jebp__read_bits(ctx, symbols_bits) + 2;
        }

        jebp_int prev_length = 8;
        for (jebp_int i = 0; i < nb_lengths && nb_symbols > 0;
             nb_symbols -= 1) {
            jebp_int symbol = jebp__read_symbol(ctx, huffman);
            jebp_int length;
            jebp_int repeat;
            switch (symbol) {
            case 16:
                length = prev_length;
                repeat = jebp__read_bits(ctx, 2) + 3;
                break;
            case 17:
                length = 0;
                repeat = jebp__read_bits(ctx, 3) + 3;
                break;
            case 18:
                length = 0;
                repeat = jebp__read_bits(ctx, 7) + 11;
                break;
            default:
                prev_length = symbol;
                /* fallthrough */
            case 0:
                // We don't ever repeat 0 values.
                ctx->lengths[i++] = symbol;
                continue;
            }
            for (jebp_int j = 0; i < nb_lengths && j < repeat; j += 1) {
                ctx->lengths[i++] = length;
            }
        }
    }
    jebp__build_huffman(ctx, huffman, nb_lengths);
}

/**
 * VP8L image
 */
#define JEBP__NB_VP8L_OFFSETS 120

static jebp_byte jebp__vp8l_offsets[JEBP__NB_VP8L_OFFSETS][2];

static jebp_int jebp__read_colcache(jebp__context_t *ctx) {
    if (jebp__read_bits(ctx, 1)) {
        // color cache
        jebp_int colcache_bits = jebp__read_bits(ctx, 4);
        if (colcache_bits < 1 || colcache_bits > 11) {
            JEBP__ERROR(INVDATA);
        }
        return colcache_bits;
    } else {
        return 0;
    }
}

JEBP__INLINE void jebp__colcache_insert(jebp__context_t *ctx,
                                        jebp_color_t *color,
                                        jebp_int colcache_bits) {
    if (colcache_bits == 0) {
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
    hash = (0x1e35a7bd * hash) >> (32 - colcache_bits);
    ctx->colcache[hash] = *color;
}

JEBP__INLINE jebp_int jebp__read_vp8l_extrabits(jebp__context_t *ctx,
                                                jebp_int symbol) {
    if (symbol < 4) {
        return symbol + 1;
    }
    jebp_int extrabits = symbol / 2 - 1;
    symbol = ((symbol % 2 + 2) << extrabits) + 1;
    return symbol + jebp__read_bits(ctx, extrabits);
}

JEBP__INLINE jebp_color_t *jebp__index_subimage(jebp_image_t *image,
                                                jebp_color_t *pixel,
                                                jebp__subimage_t *subimage) {
    jebp_int i = (jebp_int)(pixel - image->pixels);
    jebp_int x = i % image->width;
    jebp_int y = i / image->width;
    jebp_int j = (y >> subimage->block_bits) * subimage->width +
                 (x >> subimage->block_bits);
    return &subimage->pixels[j];
}

static void jebp__read_vp8l_image(jebp__context_t *ctx, jebp_image_t *image,
                                  jebp_int colcache_bits,
                                  jebp__subimage_t *huffman_image) {
    jebp_int nb_colcache_symbols = colcache_bits == 0 ? 0 : 1 << colcache_bits;
    size_t colcache_size = nb_colcache_symbols * sizeof(jebp_color_t);
    if (colcache_bits > ctx->colcache_bits) {
        JEBP_FREE(ctx->colcache);
        ctx->colcache = JEBP_ALLOC(colcache_size);
        if (ctx->colcache == NULL) {
            JEBP__ERROR(NOMEM);
        }
        ctx->colcache_bits = colcache_bits;
    }
    if (colcache_bits > 0) {
        JEBP__CLEAR(ctx->colcache, colcache_size);
    }

    jebp_int nb_groups = 1;
    if (huffman_image != NULL) {
        JEBP__LOOP_IMAGE(huffman_image) {
            if (pixel->r != 0) {
                // Currently only 256 huffman groups are supported
                JEBP__ERROR(NOSUP);
            }
            if (pixel->g >= nb_groups) {
                nb_groups = pixel->g + 1;
            }
            pixel += 1;
        }
    }
    if (nb_groups > ctx->nb_groups) {
        jebp__free_context_groups(ctx);
        size_t groups_size = nb_groups * sizeof(jebp__huffman_group_t);
        ctx->groups = JEBP_ALLOC(groups_size);
        if (ctx->groups == NULL) {
            ctx->nb_groups = 0;
            JEBP__ERROR(NOMEM);
        }
        JEBP__CLEAR(ctx->groups, groups_size);
        ctx->nb_groups = nb_groups;
    }
    for (jebp_int i = 0; i < nb_groups; i += 1) {
        jebp__huffman_group_t *group = &ctx->groups[i];
        jebp__read_huffman(ctx, &group->main,
                           JEBP__NB_MAIN_SYMBOLS + nb_colcache_symbols);
        jebp__read_huffman(ctx, &group->red, JEBP__NB_COLOR_SYMBOLS);
        jebp__read_huffman(ctx, &group->blue, JEBP__NB_COLOR_SYMBOLS);
        jebp__read_huffman(ctx, &group->alpha, JEBP__NB_COLOR_SYMBOLS);
        jebp__read_huffman(ctx, &group->dist, JEBP__NB_DIST_SYMBOLS);
    }

    jebp__alloc_image(ctx, image);
    JEBP__LOOP_IMAGE(image) {
        jebp__huffman_group_t *group = ctx->groups;
        if (huffman_image != NULL) {
            jebp_int index =
                jebp__index_subimage(image, pixel, huffman_image)->g;
            group = &ctx->groups[index];
        }
        jebp_int main = jebp__read_symbol(ctx, &group->main);
        if (main < JEBP__NB_COLOR_SYMBOLS) {
            pixel->g = main;
            pixel->r = jebp__read_symbol(ctx, &group->red);
            pixel->b = jebp__read_symbol(ctx, &group->blue);
            pixel->a = jebp__read_symbol(ctx, &group->alpha);
            jebp__colcache_insert(ctx, pixel, colcache_bits);
            pixel += 1;
        } else if (main < JEBP__NB_MAIN_SYMBOLS) {
            jebp_int length =
                jebp__read_vp8l_extrabits(ctx, main - JEBP__NB_COLOR_SYMBOLS);
            jebp_int dist = jebp__read_symbol(ctx, &group->dist);
            dist = jebp__read_vp8l_extrabits(ctx, dist);
            if (dist > JEBP__NB_VP8L_OFFSETS) {
                dist -= JEBP__NB_VP8L_OFFSETS;
            } else {
                const jebp_byte *offset = jebp__vp8l_offsets[dist - 1];
                dist = offset[1] * image->width + offset[0];
                dist = JEBP__MAX(dist, 1);
            }
            jebp_color_t *repeat = pixel - dist;
            jebp_color_t *repeat_end = repeat + length;
            if (repeat < image->pixels || repeat_end >= end) {
                JEBP__ERROR(INVDATA);
            }
            while (pixel != end && repeat != repeat_end) {
                jebp__colcache_insert(ctx, repeat, colcache_bits);
                *(pixel++) = *(repeat++);
            }
        } else {
            *(pixel++) = ctx->colcache[main - JEBP__NB_MAIN_SYMBOLS];
        }
    }
}

static void jebp__read_subimage(jebp__context_t *ctx, jebp__subimage_t *image) {
    image->block_bits = jebp__read_bits(ctx, 3) + 2;
    image->width = JEBP__CEIL_SHIFT(ctx->image->width, image->block_bits);
    image->height = JEBP__CEIL_SHIFT(ctx->image->height, image->block_bits);
    jebp_int colcache_bits = jebp__read_colcache(ctx);
    jebp__read_vp8l_image(ctx, (jebp_image_t *)image, colcache_bits, NULL);
}

/**
 * VP8L predictions
 */
#define JEBP__NB_VP8L_PREDICTIONS 14

typedef void (*jebp__vp8l_predict_t)(jebp_color_t *p, jebp_color_t *l,
                                     jebp_color_t *t);

typedef struct jebp__short_color_t {
    jebp_short r;
    jebp_short g;
    jebp_short b;
    jebp_short a;
} jebp__short_color_t;

JEBP__INLINE void jebp__vp8l_predict_black(jebp_color_t *p) {
    p->a += 0xff;
}

static void jebp__vp8l_predict0(jebp_color_t *p, jebp_color_t *l,
                                jebp_color_t *t) {
    (void)l;
    (void)t;
    jebp__vp8l_predict_black(p);
}

JEBP__INLINE void jebp__vp8l_predict_left(jebp_color_t *p, jebp_color_t *l) {
    p->r += l->r;
    p->g += l->g;
    p->b += l->b;
    p->a += l->a;
}

static void jebp__vp8l_predict1(jebp_color_t *p, jebp_color_t *l,
                                jebp_color_t *t) {
    (void)t;
    jebp__vp8l_predict_left(p, l);
}

JEBP__INLINE void jebp__vp8l_predict_top(jebp_color_t *p, jebp_color_t *t) {
    p->r += t->r;
    p->g += t->g;
    p->b += t->b;
    p->a += t->a;
}

static void jebp__vp8l_predict2(jebp_color_t *p, jebp_color_t *l,
                                jebp_color_t *t) {
    (void)l;
    jebp__vp8l_predict_top(p, t);
}

static void jebp__vp8l_predict3(jebp_color_t *p, jebp_color_t *l,
                                jebp_color_t *t) {
    (void)l;
    p->r += t[1].r;
    p->g += t[1].g;
    p->b += t[1].b;
    p->a += t[1].a;
}

static void jebp__vp8l_predict4(jebp_color_t *p, jebp_color_t *l,
                                jebp_color_t *t) {
    (void)l;
    p->r += t[-1].r;
    p->g += t[-1].g;
    p->b += t[-1].b;
    p->a += t[-1].a;
}

static void jebp__vp8l_predict5(jebp_color_t *p, jebp_color_t *l,
                                jebp_color_t *t) {
    p->r += JEBP__AVG(JEBP__AVG(l->r, t[1].r), t->r);
    p->g += JEBP__AVG(JEBP__AVG(l->g, t[1].g), t->g);
    p->b += JEBP__AVG(JEBP__AVG(l->b, t[1].b), t->b);
    p->a += JEBP__AVG(JEBP__AVG(l->a, t[1].a), t->a);
}

static void jebp__vp8l_predict6(jebp_color_t *p, jebp_color_t *l,
                                jebp_color_t *t) {
    p->r += JEBP__AVG(l->r, t[-1].r);
    p->g += JEBP__AVG(l->g, t[-1].g);
    p->b += JEBP__AVG(l->b, t[-1].b);
    p->a += JEBP__AVG(l->a, t[-1].a);
}

static void jebp__vp8l_predict7(jebp_color_t *p, jebp_color_t *l,
                                jebp_color_t *t) {
    p->r += JEBP__AVG(l->r, t->r);
    p->g += JEBP__AVG(l->g, t->g);
    p->b += JEBP__AVG(l->b, t->b);
    p->a += JEBP__AVG(l->a, t->a);
}

static void jebp__vp8l_predict8(jebp_color_t *p, jebp_color_t *l,
                                jebp_color_t *t) {
    (void)l;
    p->r += JEBP__AVG(t[-1].r, t->r);
    p->g += JEBP__AVG(t[-1].g, t->g);
    p->b += JEBP__AVG(t[-1].b, t->b);
    p->a += JEBP__AVG(t[-1].a, t->a);
}

static void jebp__vp8l_predict9(jebp_color_t *p, jebp_color_t *l,
                                jebp_color_t *t) {
    (void)l;
    p->r += JEBP__AVG(t->r, t[1].r);
    p->g += JEBP__AVG(t->g, t[1].g);
    p->b += JEBP__AVG(t->b, t[1].b);
    p->a += JEBP__AVG(t->a, t[1].a);
}

static void jebp__vp8l_predict10(jebp_color_t *p, jebp_color_t *l,
                                 jebp_color_t *t) {
    p->r += JEBP__AVG(JEBP__AVG(l->r, t[-1].r), JEBP__AVG(t->r, t[1].r));
    p->g += JEBP__AVG(JEBP__AVG(l->g, t[-1].g), JEBP__AVG(t->g, t[1].g));
    p->b += JEBP__AVG(JEBP__AVG(l->b, t[-1].b), JEBP__AVG(t->b, t[1].b));
    p->a += JEBP__AVG(JEBP__AVG(l->a, t[-1].a), JEBP__AVG(t->a, t[1].a));
}

// I know that technically "paeth" refers to the full filter below (11) but I
// could not find a better name for this
JEBP__INLINE jebp__short_color_t jebp__vp8l_predict_paeth(jebp_color_t *l,
                                                          jebp_color_t *t) {
    return (jebp__short_color_t){l->r + t->r - t[-1].r, l->g + t->g - t[-1].g,
                                 l->b + t->b - t[-1].b, l->a + t->a - t[-1].a};
}

JEBP__INLINE jebp_int jebp__vp8l_predict_dist(jebp_color_t *a,
                                              jebp__short_color_t *b) {
    return JEBP__ABS(a->r - b->r) + JEBP__ABS(a->g - b->g) +
           JEBP__ABS(a->b - b->b) + JEBP__ABS(a->a - b->a);
}

static void jebp__vp8l_predict11(jebp_color_t *p, jebp_color_t *l,
                                 jebp_color_t *t) {
    jebp__short_color_t paeth = jebp__vp8l_predict_paeth(l, t);
    jebp_int ldist = jebp__vp8l_predict_dist(l, &paeth);
    jebp_int tdist = jebp__vp8l_predict_dist(t, &paeth);
    if (ldist < tdist) {
        jebp__vp8l_predict_left(p, l);
    } else {
        jebp__vp8l_predict_top(p, t);
    }
}

static void jebp__vp8l_predict12(jebp_color_t *p, jebp_color_t *l,
                                 jebp_color_t *t) {
    jebp__short_color_t paeth = jebp__vp8l_predict_paeth(l, t);
    p->r += JEBP__CLAMP_COLOR(paeth.r);
    p->g += JEBP__CLAMP_COLOR(paeth.g);
    p->b += JEBP__CLAMP_COLOR(paeth.b);
    p->a += JEBP__CLAMP_COLOR(paeth.a);
}

static void jebp__vp8l_predict13(jebp_color_t *p, jebp_color_t *l,
                                 jebp_color_t *t) {
    jebp_color_t avg = {JEBP__AVG(l->r, t->r), JEBP__AVG(l->g, t->g),
                        JEBP__AVG(l->b, t->b), JEBP__AVG(l->a, t->a)};
    p->r += JEBP__CLAMP_COLOR(avg.r + (avg.r - t[-1].r) / 2);
    p->g += JEBP__CLAMP_COLOR(avg.g + (avg.g - t[-1].g) / 2);
    p->b += JEBP__CLAMP_COLOR(avg.b + (avg.b - t[-1].b) / 2);
    p->a += JEBP__CLAMP_COLOR(avg.a + (avg.a - t[-1].a) / 2);
}

static jebp__vp8l_predict_t jebp__vp8l_predictions[JEBP__NB_VP8L_PREDICTIONS] =
    {
        jebp__vp8l_predict0,  jebp__vp8l_predict1,  jebp__vp8l_predict2,
        jebp__vp8l_predict3,  jebp__vp8l_predict4,  jebp__vp8l_predict5,
        jebp__vp8l_predict6,  jebp__vp8l_predict7,  jebp__vp8l_predict8,
        jebp__vp8l_predict9,  jebp__vp8l_predict10, jebp__vp8l_predict11,
        jebp__vp8l_predict12, jebp__vp8l_predict13,
};

/**
 * VP8L transforms
 */
// returns 0 if there are no more transforms to read
static jebp_int jebp__read_transform(jebp__context_t *ctx,
                                     jebp__transform_t *transform) {
    if (!jebp__read_bits(ctx, 1)) {
        // no more transforms to read
        transform->type = JEBP__TRANSFORM_NONE;
        return 0;
    }
    transform->type = (jebp__transform_type_t)jebp__read_bits(ctx, 2);
    if (transform->type == JEBP__TRANSFORM_PALETTE) {
        // TODO: support palette images
        JEBP__ERROR(NOSUP_PALETTE);
    } else if (transform->type != JEBP__TRANSFORM_GREEN) {
        jebp__read_subimage(ctx, &transform->image);
    }
    return 1;
}

JEBP__INLINE void jebp__apply_predict_transform(jebp__context_t *ctx,
                                                jebp__subimage_t *image) {
    JEBP__LOOP_IMAGE(ctx->image) {
        jebp_color_t *l = pixel - 1;
        jebp_color_t *t = pixel - ctx->image->width;
        if (pixel == ctx->image->pixels) {
            // Use opaque-black prediction for top-left pixel
            jebp__vp8l_predict_black(pixel);
        } else if (t < ctx->image->pixels) {
            // Use left prediction for the top row
            jebp__vp8l_predict_left(pixel, l);
        } else if ((pixel - ctx->image->pixels) % ctx->image->width == 0) {
            // Use top prediction for left row
            jebp__vp8l_predict_top(pixel, t);
        } else {
            jebp_int predict =
                jebp__index_subimage(ctx->image, pixel, image)->g;
            if (predict >= JEBP__NB_VP8L_PREDICTIONS) {
                JEBP__ERROR(INVDATA);
            }
            jebp__vp8l_predictions[predict](pixel, l, t);
        }
        pixel += 1;
    }
}

JEBP__INLINE jebp_ubyte jebp__apply_color_delta(jebp_ubyte color,
                                                jebp_ubyte delta) {
    return ((jebp_byte)color * (jebp_byte)delta) >> 5;
}

JEBP__INLINE void jebp__apply_color_transform(jebp__context_t *ctx,
                                              jebp__subimage_t *image) {
    JEBP__LOOP_IMAGE(ctx->image) {
        jebp_color_t *delta = jebp__index_subimage(ctx->image, pixel, image);
        pixel->r += jebp__apply_color_delta(pixel->g, delta->b);
        pixel->b += jebp__apply_color_delta(pixel->g, delta->g);
        pixel->b += jebp__apply_color_delta(pixel->r, delta->r);
        pixel += 1;
    }
}

JEBP__INLINE void jebp__apply_green_transform(jebp__context_t *ctx) {
    JEBP__LOOP_IMAGE(ctx->image) {
        pixel->r += pixel->g;
        pixel->b += pixel->g;
        pixel += 1;
    }
}

static void jebp__apply_transform(jebp__context_t *ctx,
                                  jebp__transform_t *transform) {
    switch (transform->type) {
    case JEBP__TRANSFORM_NONE:
        break;
    case JEBP__TRANSFORM_PREDICT:
        jebp__apply_predict_transform(ctx, &transform->image);
        break;
    case JEBP__TRANSFORM_COLOR:
        jebp__apply_color_transform(ctx, &transform->image);
        break;
    case JEBP__TRANSFORM_GREEN:
        jebp__apply_green_transform(ctx);
        break;
    default:
        JEBP__ERROR(NOSUP);
    }
}

/**
 * VP8L lossless codec
 */
#define JEBP__VP8L_TAG 0x4c385056
#define JEBP__VP8L_MAGIC 0x2f

static void jebp__read_vp8l_header(jebp__context_t *ctx) {
    if (jebp__read_uint8(ctx) != JEBP__VP8L_MAGIC) {
        JEBP__ERROR(INVDATA_HEADER);
    }
    ctx->image->width = jebp__read_bits(ctx, 14) + 1;
    ctx->image->height = jebp__read_bits(ctx, 14) + 1;
    jebp__read_bits(ctx, 1); // alpha does not impact decoding
    if (jebp__read_bits(ctx, 3) != 0) {
        // version must be 0
        JEBP__ERROR(NOSUP);
    }
}

static void jebp__read_vp8l_nohead(jebp__context_t *ctx) {
    jebp_int cont = 1;
    for (int i = 0; i < JEBP__NB_TRANSFORMS; i += 1) {
        if (cont) {
            cont = jebp__read_transform(ctx, &ctx->transforms[i]);
        } else {
            ctx->transforms[i].type = JEBP__TRANSFORM_NONE;
        }
    }
    if (cont && jebp__read_bits(ctx, 1)) {
        // there can only be 4 transforms at most
        JEBP__ERROR(INVDATA);
    }

    jebp_int colcache_bits = jebp__read_colcache(ctx);
    jebp__subimage_t *huffman_image = NULL;
    if (jebp__read_bits(ctx, 1)) {
        // there is a huffman image
        huffman_image = &ctx->huffman_image;
        jebp__read_subimage(ctx, huffman_image);
    }
    jebp__read_vp8l_image(ctx, ctx->image, colcache_bits, huffman_image);
    for (int i = JEBP__NB_TRANSFORMS - 1; i >= 0; i -= 1) {
        jebp__apply_transform(ctx, &ctx->transforms[i]);
    }
}

static void jebp__read_vp8l(jebp__context_t *ctx) {
    jebp__read_vp8l_header(ctx);
    jebp__read_vp8l_nohead(ctx);
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

static jebp_error_t jebp__memory_context(jebp__context_t **ptr,
                                         jebp_image_t *image, size_t size,
                                         const void *data) {
    jebp__context_t *ctx = jebp__alloc_context();
    if (ctx == NULL) {
        return JEBP_ERROR_NOMEM;
    }
    ctx->image = image;
    ctx->nb_bytes = size;
    ctx->bytes = data;
    *ptr = ctx;
    return JEBP_OK;
}

static jebp_error_t jebp__read_size(jebp__context_t *ctx) {
#ifndef JEBP_ERROR
    if (setjmp(ctx->jump)) {
        jebp_error_t err = ctx->error;
        jebp__free_context(ctx);
        return err;
    }
#endif // JEBP_ERROR
    ctx->image->pixels = NULL;
    jebp__read_header(ctx);
    switch (ctx->codec_chunk.tag) {
#ifndef JEBP_NO_VP8L
    case JEBP__VP8L_TAG:
        jebp__read_vp8l_header(ctx);
        break;
#endif // JEBP_NO_VP8L
    default:
        JEBP__ERROR(NOSUP_CODEC);
    }
    jebp__free_context(ctx);
    return JEBP_OK;
}

jebp_error_t jebp_decode_size(jebp_image_t *image, size_t size,
                              const void *data) {
    if (image == NULL || data == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__context_t *ctx;
    jebp_error_t err = jebp__memory_context(&ctx, image, size, data);
    if (err != JEBP_OK) {
        return err;
    }
    return jebp__read_size(ctx);
}

static jebp_error_t jebp__read(jebp__context_t *ctx) {
#ifndef JEBP_ERROR
    if (setjmp(ctx->jump)) {
        jebp_error_t err = ctx->error;
        jebp__free_context(ctx);
        return err;
    }
#endif // JEBP_ERROR
    ctx->image->pixels = NULL;
    jebp__read_header(ctx);
    switch (ctx->codec_chunk.tag) {
#ifndef JEBP_NO_VP8L
    case JEBP__VP8L_TAG:
        jebp__read_vp8l(ctx);
        break;
#endif // JEBP_NO_VP8L
    default:
        JEBP__ERROR(NOSUP_CODEC);
    }
    jebp__free_context(ctx);
    return JEBP_OK;
}

jebp_error_t jebp_decode(jebp_image_t *image, size_t size, const void *data) {
    if (image == NULL || data == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__context_t *ctx;
    jebp_error_t err = jebp__memory_context(&ctx, image, size, data);
    if (err != JEBP_OK) {
        return err;
    }
    return jebp__read(ctx);
}

#ifndef JEBP_NO_STDIO
static jebp_error_t jebp__file_context(jebp__context_t **ptr,
                                       jebp_image_t *image, const char *path) {
    jebp__context_t *ctx = jebp__alloc_context();
    if (ctx == NULL) {
        return JEBP_ERROR_NOMEM;
    }
    ctx->image = image;
    ctx->file = fopen(path, "rb");
    if (ctx->file == NULL) {
        jebp__free_context(ctx);
        return JEBP_ERROR_IO;
    }
    ctx->buffer = JEBP_ALLOC(JEBP__BUFFER_SIZE);
    if (ctx->buffer == NULL) {
        jebp__free_context(ctx);
        return JEBP_ERROR_NOMEM;
    }
    *ptr = ctx;
    return JEBP_OK;
}

jebp_error_t jebp_read_size(jebp_image_t *image, const char *path) {
    if (image == NULL || path == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__context_t *ctx;
    jebp_error_t err = jebp__file_context(&ctx, image, path);
    if (err != JEBP_OK) {
        return err;
    }
    return jebp__read_size(ctx);
}

jebp_error_t jebp_read(jebp_image_t *image, const char *path) {
    if (image == NULL || path == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__context_t *ctx;
    jebp_error_t err = jebp__file_context(&ctx, image, path);
    if (err != JEBP_OK) {
        return err;
    }
    return jebp__read(ctx);
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
static const jebp_int jebp__meta_length_order[JEBP__NB_META_SYMBOLS] = {
    17, 18, 0, 1, 2, 3, 4, 5, 16, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

// {X, Y} offsets from the pixel when decoding short distance codes
static jebp_byte jebp__vp8l_offsets[JEBP__NB_VP8L_OFFSETS][2] = {
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
