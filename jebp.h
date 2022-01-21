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
 * Todo lmao
 */

/**
 * HEADER
 */
#ifndef JEBP__HEADER
#define JEBP__HEADER
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#include <stddef.h>
#include <limits.h>

typedef signed char jebp_byte;
typedef unsigned char jebp_ubyte;
#if UINT_MAX >= 0xffffffff
typedef int jebp_int;
typedef unsigned int jebp_uint;
#else
typedef long jebp_int;
typedef unsigned long jebp_uint;
#endif

typedef enum jebp_error_t {
    JEBP_OK,
    JEBP_ERROR_INVAL, // Invalid value
    JEBP_ERROR_INVDATA, // Invalid data
    JEBP_ERROR_EOF, // End of file
    JEBP_ERROR_NOSUP, // Not supported
    JEBP_ERROR_NOMEM, // No memory
    JEBP_ERROR_IO, // I/O error
    JEBP_ERROR_UNKNOWN, // Unknown error
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
jebp_error_t jebp_decode_size(jebp_image_t *image, size_t size, const void *data);
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
#include <stdlib.h>
#include <string.h>
#if !defined(JEBP_NO_STDIO) || defined(JEBP_LOG_ERRORS)
#include <stdio.h>
#endif
#ifndef JEBP_ERROR
#include <setjmp.h>
#endif

/**
 * Predefined macro detection
 */
#ifdef __has_attribute
#define JEBP__HAS_ATTRIBUTE __has_attribute
#else // __has_attribute
#define JEBP__HAS_ATTRIBUTE(attr) 0
#endif // __has_attribute
#if JEBP__HAS_ATTRIBUTE(always_inline)
#define JEBP__INLINE __attribute__((always_inline))
#elif defined(_MSC_VER)
#define JEBP__INLINE __forceinline
#else
#define JEBP__INLINE inline
#endif
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#define JEBP__NORETURN _Noreturn
#elif JEBP__HAS_ATTRIBUTE(noreturn)
#define JEBP__NORETURN __attribute__((noreturn))
#elif defined(_MSC_VER)
#define JEBP__NORETURN __declspec(noreturn)
#else
#define JEBP__NORETURN
#endif

#if defined(__i386) || defined(__i386__) || defined(_M_IX86)
#define JEBP__LITTLE_ENDIAN
#if defined(__SSE2__)
#define JEBP__SIMD_SSE2
#elif defined (_M_IX86_FP) && _M_IX86_FP == 2
#define JEBP__SIMD_SSE2
#endif
#elif defined(__amd64) || defined(__amd64__) || defined(_M_AMD64)
#define JEBP__LITTLE_ENDIAN
#define JEBP__SIMD_SSE2
#elif defined(__arm) || defined(__arm__) || defined(_M_ARM)
#ifndef __ARM_BIG_ENDIAN
#define JEBP__LITTLE_ENDIAN
#endif // __ARM_BIG_ENDIAN
#if defined(_WIN32) || defined(__ARM_NEON)
#define JEBP__SIMD_NEON
#endif
#elif defined(__aarch64) || defined(__aarch64__) || defined(_M_ARM64)
#ifndef __ARM_BIG_ENDIAN
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
//
// There are faster/nicer ways to decode huffman codes but they often require 
// peeking the next n bits which is not easy with how the reader was designed.
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

/**
 * Common utilities
 */
static JEBP__INLINE JEBP__NORETURN void jebp__error(jebp__context_t *ctx, jebp_error_t error, const char *file, jebp_int line) {
#ifdef JEBP_LOG_ERRORS
    fprintf(stderr, "%s:%i: %s\n", file, line, jebp_error_string(error));
#else // JEBP_LOG_ERRORS
    (void)file;
    (void)line;
#endif // JEBP_LOG_ERRORS
#ifdef JEBP_ERROR
    JEBP_ERROR(error);
    abort();
#else // JEBP_ERROR
    ctx->error = error;
    longjmp(ctx->jump, 1);
#endif // JEBP_ERROR
}
#define JEBP__ERROR(error) jebp__error(ctx, JEBP_ERROR_##error, __FILE__, __LINE__)

#if !defined(JEBP_ALLOC) && !defined(JEBP_FREE)
#include <stdlib.h>
#define JEBP_ALLOC malloc
#define JEBP_FREE free
#elif !defined(JEBP_ALLOC) || !defined(JEBP_FREE)
#error Both JEBP_ALLOC and JEBP_FREE have to be defined
#endif

#define JEBP__CLEAR(ptr, size) memset(ptr, 0, size)
#define JEBP__MIN(a, b) ((a) < (b) ? (a) : (b))
#define JEBP__MAX(a, b) ((a) > (b) ? (a) : (b))
#define JEBP__CEIL_SHIFT(a, b) (((a) + (1 << (b)) - 1) >> (b))

static void jebp__alloc_image(jebp__context_t *ctx, jebp_image_t *image) {
    image->pixels = JEBP_ALLOC((size_t)image->width * (size_t)image->height * sizeof(jebp_color_t));
    if (image->pixels == NULL) {
        JEBP__ERROR(NOMEM);
    }
}

static void jebp__free_context(jebp__context_t *ctx) {
#ifndef JEBP_NO_STDIO
    if (ctx->file != NULL) {
        fclose(ctx->file);
    }
    JEBP_FREE(ctx->buffer);
#endif // JEBP_NO_STDIO
#ifndef JEBP_NO_VP8L
    JEBP_FREE(ctx->colcache);
    JEBP_FREE(ctx->lengths);
    for (jebp_int i = 0; i < ctx->nb_groups; i += 1) {
        jebp__huffman_group_t *group = &ctx->groups[i];
        JEBP_FREE(group->main.tables->values);
        JEBP_FREE(group->red.tables->values);
        JEBP_FREE(group->blue.tables->values);
        JEBP_FREE(group->alpha.tables->values);
        JEBP_FREE(group->dist.tables->values);
    }
    JEBP_FREE(ctx->groups);
    for (jebp_int i = 0; i < 4; i += 1) {
        JEBP_FREE(ctx->transforms[i].image.pixels);
    }
    JEBP_FREE(ctx->huffman_image.pixels);
#endif // JEBP_NO_VP8L
}

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

static void jebp__check_chunk(jebp__context_t *ctx, jebp__chunk_t *chunk, size_t size) {
    if (chunk->tag != 0) {
        if (size > chunk->size) {
            JEBP__ERROR(INVDATA);
        }
        chunk->size -= size;
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

static jebp_ubyte jebp__read_uint8(jebp__context_t *ctx) {
    ctx->nb_bits = 0;
    jebp__check_chunk(ctx, &ctx->webp_chunk, 1);
    jebp__check_chunk(ctx, &ctx->codec_chunk, 1);
    jebp__check_buffer(ctx);
    ctx->nb_bytes -= 1;
    return (jebp_ubyte)*(ctx->bytes++);
}

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

/**
 * RIFF container
 */
#define JEBP__RIFF_TAG 0x46464952
#define JEBP__WEBP_TAG 0x50424557

static jebp_uint jebp__read_uint32(jebp__context_t *ctx) {
#ifdef JEBP__LITTLE_ENDIAN
    jebp_uint value = 0;
    jebp__read_bytes(ctx, 4, &value);
    return value;
#else // JEBP__LITTLE_ENDIAN
    jebp_ubyte bytes[4];
    jebp__read_bytes(4, bytes);
    return (jebp_uint)(bytes[0] | ((bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24)));
#endif // JEBP__LITTLE_ENDIAN
}

static void jebp__read_chunk(jebp__context_t *ctx, jebp__chunk_t *chunk) {
    chunk->tag = 0;
    jebp_uint tag = jebp__read_uint32(ctx);
    chunk->size = jebp__read_uint32(ctx);
    chunk->tag = tag;
}

static void jebp__read_header(jebp__context_t *ctx) {
    jebp__read_chunk(ctx, &ctx->webp_chunk);
    if (ctx->webp_chunk.tag != JEBP__RIFF_TAG) {
        JEBP__ERROR(INVDATA);
    }
    if (jebp__read_uint32(ctx) != JEBP__WEBP_TAG) {
        JEBP__ERROR(INVDATA);
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

static const jebp_int jebp__meta_length_order[JEBP__NB_META_SYMBOLS] = {
    17, 18, 0, 1, 2, 3, 4, 5, 16, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
};

static void jebp__build_huffman(jebp__context_t *ctx, jebp__huffman_t *huffman, jebp_int nb_lengths) {
    jebp__huffman_table_t *table = huffman->tables;
    table->min_code = 0;
    table->max_code = 0;
    if (nb_lengths > huffman->nb_values) {
        JEBP_FREE(table->values);
        table->values = JEBP_ALLOC((size_t)nb_lengths * sizeof(jebp_int));
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

static jebp_int jebp__read_symbol(jebp__context_t *ctx, jebp__huffman_t *huffman) {
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

static void jebp__read_huffman(jebp__context_t *ctx, jebp__huffman_t *huffman, jebp_int nb_lengths) {
    // This part of the spec is INCREDIBLY wrong and partly missing
    // Using libwebp as a reference
    size_t lengths_size = (size_t)nb_lengths * sizeof(jebp_int);
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
        for (jebp_int i = 0; i < nb_lengths && nb_symbols > 0; nb_symbols -= 1) {
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
                ctx->lengths[i++] = symbol;
                prev_length = symbol;
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

static jebp_byte jebp__vp8l_offsets[JEBP__NB_VP8L_OFFSETS][2] = {
{0,1},{1,0},{1,1},{-1,1},{0,2},{2,0},{1,2},{-1,2},{2,1},{-2,1},{2,2},{-2,2},{0,3
},{3,0},{1,3},{-1,3},{3,1},{-3,1},{2,3},{-2,3},{3,2},{-3,2},{0,4},{4,0},{1,4},{
-1,4},{4,1},{-4,1},{3,3},{-3,3},{2,4},{-2,4},{4,2},{-4,2},{0,5},{3,4},{-3,4},{4,
3},{-4,3},{5,0},{1,5},{-1,5},{5,1},{-5,1},{2,5},{-2,5},{5,2},{-5,2},{4,4},{-4,4}
,{3,5},{-3,5},{5,3},{-5,3},{0,6},{6,0},{1,6},{-1,6},{6,1},{-6,1},{2,6},{-2,6},{6
,2},{-6,2},{4,5},{-4,5},{5,4},{-5,4},{3,6},{-3,6},{6,3},{-6,3},{0,7},{7,0},{1,7}
,{-1,7},{5,5},{-5,5},{7,1},{-7,1},{4,6},{-4,6},{6,4},{-6,4},{2,7},{-2,7},{7,2},{
-7,2},{3,7},{-3,7},{7,3},{-7,3},{5,6},{-5,6},{6,5},{-6,5},{8,0},{4,7},{-4,7},{7,
4},{-7,4},{8,1},{8,2},{6,6},{-6,6},{8,3},{5,7},{-5,7},{7,5},{-7,5},{8,4},{6,7},{
-6,7},{7,6},{-7,6},{8,5},{7,7},{-7,7},{8,6},{8,7}
};

static jebp_int jebp__read_colcache(jebp__context_t *ctx) {
    if (jebp__read_bits(ctx, 1)) {
        // color cache
        jebp_int colcache_bits = jebp__read_bits(ctx, 4);
        if (colcache_bits < 1 || colcache_bits > 11) {
            JEBP__ERROR(INVDATA);
        }
        JEBP__ERROR(NOSUP);
        // return colcache_bits;
    } else {
        return 0;
    }
}

static jebp_int jebp__read_vp8l_extrabits(jebp__context_t *ctx, jebp_int symbol) {
    if (symbol < 4) {
        return symbol + 1;
    }
    jebp_int extrabits = symbol / 2 - 1;
    symbol = ((symbol % 2 + 2) << extrabits) + 1;
    return symbol + jebp__read_bits(ctx, extrabits);
}

static void jebp__read_vp8l_image(jebp__context_t *ctx, jebp_image_t *image) {
    jebp_int nb_groups = 1;
    if (nb_groups > ctx->nb_groups) {
        JEBP_FREE(ctx->groups);
        size_t groups_size = (size_t)nb_groups * sizeof(jebp__huffman_t);
        ctx->groups = JEBP_ALLOC(groups_size);
        if (ctx->groups == NULL) {
            JEBP__ERROR(NOMEM);
        }
        JEBP__CLEAR(ctx->groups, groups_size);
        ctx->nb_groups = nb_groups;
    }

    for (jebp_int i = 0; i < nb_groups; i += 1) {
        jebp__huffman_group_t *group = &ctx->groups[i];
        // TODO: add colcache symbols
        jebp__read_huffman(ctx, &group->main, JEBP__NB_MAIN_SYMBOLS);
        jebp__read_huffman(ctx, &group->red, JEBP__NB_COLOR_SYMBOLS);
        jebp__read_huffman(ctx, &group->blue, JEBP__NB_COLOR_SYMBOLS);
        jebp__read_huffman(ctx, &group->alpha, JEBP__NB_COLOR_SYMBOLS);
        jebp__read_huffman(ctx, &group->dist, JEBP__NB_DIST_SYMBOLS);
    }

    jebp__alloc_image(ctx, image);
    jebp_color_t *pixel = image->pixels;
    jebp_color_t *end = pixel + image->width * image->height;
    while (pixel != end) {
        jebp__huffman_group_t *group = ctx->groups;
        jebp_int main = jebp__read_symbol(ctx, &group->main);
        if (main < JEBP__NB_COLOR_SYMBOLS) {
            pixel->g = (jebp_ubyte)main;
            pixel->r = (jebp_ubyte)jebp__read_symbol(ctx, &group->red);
            pixel->b = (jebp_ubyte)jebp__read_symbol(ctx, &group->blue);
            pixel->a = (jebp_ubyte)jebp__read_symbol(ctx, &group->alpha);
            pixel += 1;
        } else if (main < JEBP__NB_MAIN_SYMBOLS) {
            jebp_int length = jebp__read_vp8l_extrabits(ctx, main - JEBP__NB_COLOR_SYMBOLS);
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
            while (pixel != end && repeat != repeat_end) {
                *(pixel++) = *(repeat++);
            }
        } else {
            JEBP__ERROR(NOSUP);
        }
    }
}

static void jebp__read_vp8l_subimage(jebp__context_t *ctx, jebp__subimage_t *image) {
    image->block_bits = jebp__read_bits(ctx, 3) + 2;
    image->width = JEBP__CEIL_SHIFT(ctx->image->width, image->block_bits);
    image->height = JEBP__CEIL_SHIFT(ctx->image->height, image->block_bits);
    jebp__read_colcache(ctx);
    jebp__read_vp8l_image(ctx, (jebp_image_t *)image);
}

/**
 * VP8L transforms
 */
// returns 0 if there are no more transforms to read
static jebp_int jebp__read_transform(jebp__context_t *ctx, jebp__transform_t *transform) {
    if (!jebp__read_bits(ctx, 1)) {
        // no more transforms to read
        transform->type = JEBP__TRANSFORM_NONE;
        return 0;
    }
    if (transform == NULL) {
        JEBP__ERROR(INVDATA);
    }
    transform->type = (jebp__transform_type_t)jebp__read_bits(ctx, 2);
    if (transform->type == JEBP__TRANSFORM_PALETTE) {
        // TODO: support palette images
        JEBP__ERROR(NOSUP);
    } else if (transform->type != JEBP__TRANSFORM_GREEN) {
        jebp__read_vp8l_subimage(ctx, &transform->image);
    }
    return 1;
}

/**
 * VP8L lossless codec
 */
#define JEBP__VP8L_TAG 0x4c385056
#define JEBP__VP8L_MAGIC 0x2f

static void jebp__read_vp8l_header(jebp__context_t *ctx) {
    if (jebp__read_uint8(ctx) != JEBP__VP8L_MAGIC) {
        JEBP__ERROR(INVDATA);
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
    if (cont) {
        // If we attempt to read a 5th transform this will fail
        jebp__read_transform(ctx, NULL);
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
static const char *jebp__error_strings[JEBP_NB_ERRORS] = {
    "Ok",
    "Invalid value or argument",
    "Invalid data or corrupted file",
    "End of file",
    "Feature not supported",
    "Not enough memory",
    "I/O error",
    "Unknown error"
};

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

static void jebp__memory_context(jebp__context_t *ctx, jebp_image_t *image, size_t size, const void *data) {
    JEBP__CLEAR(ctx, sizeof(jebp__context_t));
    ctx->image = image;
    ctx->nb_bytes = size;
    ctx->bytes = data;
}

static jebp_error_t jebp__read_size(jebp__context_t *ctx) {
#ifndef JEBP_ERROR
    if (setjmp(ctx->jump)) {
        jebp__free_context(ctx);
        jebp_free_image(ctx->image);
        return ctx->error;
    }
#endif // JEBP_ERROR
    ctx->image->pixels = NULL;
    jebp__read_header(ctx);
#ifndef JEBP_NO_VP8L
    if (ctx->codec_chunk.tag == JEBP__VP8L_TAG) {
        jebp__read_vp8l_header(ctx);
    } else
#endif // JEBP_NO_VP8L
    {
        JEBP__ERROR(NOSUP);
    }
    jebp__free_context(ctx);
    return JEBP_OK;
}

jebp_error_t jebp_decode_size(jebp_image_t *image, size_t size, const void *data) {
    if (image == NULL || data == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__context_t ctx;
    jebp__memory_context(&ctx, image, size, data);
    return jebp__read_size(&ctx);
}

static jebp_error_t jebp__read(jebp__context_t *ctx) {
#ifndef JEBP_ERROR
    if (setjmp(ctx->jump)) {
        jebp__free_context(ctx);
        jebp_free_image(ctx->image);
        return ctx->error;
    }
#endif // JEBP_ERROR
    ctx->image->pixels = NULL;
    jebp__read_header(ctx);
#ifndef JEBP_NO_VP8L
    if (ctx->codec_chunk.tag == JEBP__VP8L_TAG) {
        jebp__read_vp8l(ctx);
    } else
#endif // JEBP_NO_VP8L
    {
        JEBP__ERROR(NOSUP);
    }
    jebp__free_context(ctx);
    return JEBP_OK;
}

jebp_error_t jebp_decode(jebp_image_t *image, size_t size, const void *data) {
    if (image == NULL || data == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__context_t ctx;
    jebp__memory_context(&ctx, image, size, data);
    return jebp__read(&ctx);
}

#ifndef JEBP_NO_STDIO
static jebp_error_t jebp__file_context(jebp__context_t *ctx, jebp_image_t *image, const char *path) {
    JEBP__CLEAR(ctx, sizeof(jebp__context_t));
    ctx->image = image;
    ctx->file = fopen(path, "rb");
    if (ctx->file == NULL) {
        return JEBP_ERROR_IO;
    }
    ctx->buffer = JEBP_ALLOC(JEBP__BUFFER_SIZE);
    if (ctx->buffer == NULL) {
        fclose(ctx->file);
        return JEBP_ERROR_NOMEM;
    }
    return JEBP_OK;
}

jebp_error_t jebp_read_size(jebp_image_t *image, const char *path) {
    if (image == NULL || path == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__context_t ctx;
    jebp_error_t err = jebp__file_context(&ctx, image, path);
    if (err != JEBP_OK) {
        return err;
    }
    return jebp__read_size(&ctx);
}

jebp_error_t jebp_read(jebp_image_t *image, const char *path) {
    if (image == NULL || path == NULL) {
        return JEBP_ERROR_INVAL;
    }
    jebp__context_t ctx;
    jebp_error_t err = jebp__file_context(&ctx, image, path);
    if (err != JEBP_OK) {
        return err;
    }
    return jebp__read(&ctx);
}
#endif // JEBP_NO_STDIO

#endif // JEBP_IMPLEMENTATION
