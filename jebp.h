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
#include <stdint.h>

typedef enum jebp_error_t {
    JEBP_OK,
    JEBP_ERROR_INVAL, // Invalid value
    JEBP_ERROR_INVDATA, // Invalid data
    JEBP_ERROR_EOF, // End of file
    JEBP_ERROR_NOSUP, // Not supported
    JEBP_ERROR_NOMEM, // No memory
    JEBP_ERROR_IO, // I/O error
    JEBP_ERROR_UNKNOWN, // Unknown error
} jebp_error_t;

typedef struct jebp_image_t {
    uint16_t width;
    uint16_t height;
    uint8_t *rgba;
} jebp_image_t;

const char *jebp_error(jebp_error_t err);
void jebp_image_free(jebp_image_t *image);
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
#include <string.h>
#ifndef JEBP_NO_STDIO
#include <stdio.h>
#endif // JEBP_NO_STDIO

// errror logging
#ifdef JEBP_LOG_ERRORS
#include <stdio.h>

static jebp_error_t jebp__log(jebp_error_t err, const char *file, int line) {
    fprintf(stderr, "%s:%i: %s\n", file, line, jebp_error(err));
    return err;
}
#define JEBP__LOG(err) jebp__log(err, __FILE__, __LINE__)
#else // JEBP_LOG_ERRORS
#define JEBP__LOG(err) err
#endif // JEBP_LOG_ERRORS
#define JEBP__LOG_INVAL JEBP__LOG(JEBP_ERROR_INVAL)
#define JEBP__LOG_INVDATA JEBP__LOG(JEBP_ERROR_INVDATA)
#define JEBP__LOG_EOF JEBP__LOG(JEBP_ERROR_EOF)
#define JEBP__LOG_NOSUP JEBP__LOG(JEBP_ERROR_NOSUP)
#define JEBP__LOG_NOMEM JEBP__LOG(JEBP_ERROR_NOMEM)
#define JEBP__LOG_IO JEBP__LOG(JEBP_ERROR_IO)
#define JEBP__LOG_UNKNOWN JEBP__LOG(JEBP_ERROR_UNKNOWN)

// malloc/free
#if !defined(JEBP_ALLOC) && !defined(JEBP_FREE)
#include <stdlib.h>
#define JEBP_ALLOC malloc
#define JEBP_FREE free
#elif !defined(JEBP_ALLOC) || !defined(JEBP_FREE)
#error Both JEBP_ALLOC and JEBP_FREE have to be defined
#endif

/**
 * Architecture detection
 */
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
#undef JEBP_SIMD_SSE2
#undef JEBP_SIMD_NEON
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
#define JEBP__CLEAR(ptr, size) memset(ptr, 0, size)
#define JEBP__MIN(a, b) ((a) < (b) ? (a) : (b))
#define JEBP__MAX(a, b) ((a) > (b) ? (a) : (b))
#define JEBP__CEIL_SHIFT(a, b) (((a) + (1 << (b)) - 1) >> (b))

static size_t jebp__image_size(const jebp_image_t *image) {
    return (size_t)image->width * (size_t)image->height * 4;
}

static jebp_error_t jebp__image_alloc(jebp_image_t *image) {
    image->rgba = JEBP_ALLOC(jebp__image_size(image));
    if (image->rgba == NULL) {
        return JEBP__LOG_NOMEM;
    }
    return JEBP_OK;
}

/**
 * Reader abstraction
 */
#define JEBP__READER_BUFSIZE 4096

typedef struct jebp__reader_t {
    jebp_error_t error;
    size_t read;
    size_t size;
    uint8_t bits;
    const uint8_t *data;
    uint8_t *buffer;
#ifdef JEBP_NO_STDIO
    void *file;
#else // JEBP_NO_STDIO
    FILE *file;
#endif // JEBP_NO_STDIO
} jebp__reader_t;

static void jebp__reader_init(jebp__reader_t *reader, size_t size, const void *data) {
    reader->error = JEBP_OK;
    reader->read = 0;
    reader->size = size;
    reader->bits = 0;
    reader->data = data;
    reader->file = NULL;
}

#ifndef JEBP_NO_STDIO
static jebp_error_t jebp__reader_open(jebp__reader_t *reader, const char *path) {
    reader->file = fopen(path, "rb");
    if (reader->file == NULL) {
        return JEBP__LOG_IO;
    }
    reader->buffer = JEBP_ALLOC(JEBP__READER_BUFSIZE);
    if (reader->buffer == NULL) {
        fclose(reader->file);
        return JEBP__LOG_NOMEM;
    }
    reader->error = JEBP_OK;
    reader->read = 0;
    reader->size = 0;
    reader->bits = 0;
    return JEBP_OK;
}

static void jebp__reader_close(jebp__reader_t *reader) {
    JEBP_FREE(reader->buffer);
    fclose(reader->file);
}
#endif // JEBP_NO_STDIO

static jebp_error_t jebp__reader_buffer(jebp__reader_t *reader) {
    if (reader->error != JEBP_OK) {
        goto error;
    }
    if (reader->size == 0 && reader->bits == 0) {
        if (reader->file == NULL) {
            reader->error = JEBP__LOG_EOF;
            goto error;
        }
#ifndef JEBP_NO_STDIO
        size_t read = fread(reader->buffer, 1, JEBP__READER_BUFSIZE, reader->file);
        if (ferror(reader->file)) {
            reader->error = JEBP__LOG_IO;
            goto error;
        }
        if (read == 0) {
            reader->error = JEBP__LOG_EOF;
            goto error;
        }
        reader->size = read;
        reader->data = reader->buffer;
#endif // JEBP_NO_STDIO
    }
error:
    return reader->error;
}

static size_t jebp__read_bytes(jebp__reader_t *reader, size_t size, void *data) {
    if (reader->bits > 0) {
        reader->bits = 0;
    }
    size_t read = 0;
    uint8_t *data8 = data;
    while (size > 0) {
        if (jebp__reader_buffer(reader) != JEBP_OK) {
            break;
        }
        size_t chunk = JEBP__MIN(size, reader->size);
        if (data8 != NULL) {
            memcpy(data8, reader->data, chunk);
            data8 += chunk;
        }
        reader->read += chunk;
        reader->size -= chunk;
        reader->data += chunk;
        read += chunk;
        size -= chunk;
    }
    return read;
}

// Bit-reading is currently only used by VP8L
#ifndef JEBP_NO_VP8L
static uint32_t jebp__read_bits(jebp__reader_t *reader, uint8_t size) {
    uint32_t value = 0;
    uint8_t read = 0;
    while (size > 0) {
        if (jebp__reader_buffer(reader) != JEBP_OK) {
            return 0;
        }
        if (reader->bits == 0) {
            reader->read += 1;
            reader->size -= 1;
            reader->data += 1;
            reader->bits = 8;
        }
        uint8_t data = reader->data[-1] >> (8 - reader->bits);
        uint8_t chunk = JEBP__MIN(size, reader->bits);
        value |= (uint32_t)((data & ((1 << chunk) - 1)) << read);
        reader->bits -= chunk;
        read += chunk;
        size -= chunk;
    }
    return value;
}
#endif // JEBP_NO_VP8L

/**
 * RIFF container
 */
typedef struct jebp__riff_chunk_t {
    size_t offset;
    uint32_t tag;
    uint32_t size;
} jebp__riff_chunk_t;

static uint32_t jebp__riff_uint32(jebp__reader_t *reader) {
#ifdef JEBP__LITTLE_ENDIAN
    uint32_t value = 0;
    if (jebp__read_bytes(reader, 4, &value) < 4) {
        return 0;
    }
    return value;
#else // JEBP__LITTLE_ENDIAN
    uint8_t bytes[4];
    if (jebp__read_bytes(reader, 4, bytes) < 4) {
        return 0;
    }
    return (uint32_t)(bytes[0] | ((bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24)));
#endif // JEBP__LITTLE_ENDIAN
}

static jebp_error_t jebp__riff_start_chunk(jebp__riff_chunk_t *chunk, jebp__reader_t *reader) {
    chunk->tag = jebp__riff_uint32(reader);
    chunk->size = jebp__riff_uint32(reader);
    chunk->offset = reader->read;
    return reader->error;
}

static jebp_error_t jebp__riff_end_chunk(jebp__riff_chunk_t *chunk, jebp__reader_t *reader) {
    size_t read = reader->read - chunk->offset;
    if (read > chunk->size) {
        return JEBP__LOG_INVDATA;
    }
    size_t skip = chunk->size - read;
    if ((chunk->size % 2) != 0) {
        // If the size is odd we have to read an extra byte
        skip += 1;
    }
    jebp__read_bytes(reader, skip, NULL);
    return reader->error;
}

static jebp_error_t jebp__riff_header(jebp__riff_chunk_t *chunk, jebp__reader_t *reader) {
    jebp_error_t err;
    if ((err = jebp__riff_start_chunk(chunk, reader)) != JEBP_OK) {
        return err;
    }
    if (chunk->tag != 0x46464952 /* RIFF */) {
        return JEBP__LOG_INVDATA;
    }
    if (jebp__riff_uint32(reader) != 0x50424557 /* WEBP */) {
        return JEBP__LOG_INVDATA;
    }
    return reader->error;
}

/**
 * Huffman coding
 */
#ifndef JEBP_NO_VP8L
// A nice property about canonical huffman codes is that all codes of the same
// length are increments of the previous code, meaning we can create a table
// for each length which we can index to get the value.
//
// There are faster/nicer ways to read decode huffman codes but they often
// require peeking the next n bits which is not easy with how the reader was
// designed.
typedef struct jebp__huffman_table_t {
    uint16_t offset;
    uint16_t size;
    uint16_t *values;
} jebp__huffman_table_t;

typedef struct jebp__huffman_t {
    uint16_t size;
    jebp__huffman_table_t tables[15];
} jebp__huffman_t;

typedef struct jebp__huffman_group_t {
    jebp__huffman_t main;
    jebp__huffman_t red;
    jebp__huffman_t blue;
    jebp__huffman_t alpha;
    jebp__huffman_t dist;
} jebp__huffman_group_t;

static const uint8_t jebp__huffman_length_order[] = {
    17, 18, 0, 1, 2, 3, 4, 5, 16, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
};

static jebp_error_t jebp__huffman_create(jebp__huffman_t *huffman, size_t size, const uint8_t *lengths) {
    uint16_t *values = JEBP_ALLOC(size * sizeof(uint16_t));
    if (values == NULL) {
        return JEBP__LOG_NOMEM;
    }

    // TODO: do we have to check for invalid huffman trees?
    //       hypothetically it should still generate "valid" codes...
    uint16_t offset = 0;
    for (int i = 0; i < 15; i += 1) {
        jebp__huffman_table_t *table = &huffman->tables[i];
        table->offset = offset;
        table->size = 0;
        table->values = values;
        for (uint16_t j = 0; j < size; j += 1) {
            if (lengths[j] == i + 1) {
                *values = j;
                values += 1;
                table->size += 1;
                huffman->size += 1;
            }
        }
        offset = (uint16_t)((offset + table->size) << 1);
    }
    return JEBP_OK;
}

static void jebp__huffman_destroy(jebp__huffman_t *huffman) {
    JEBP_FREE(huffman->tables[0].values);
    huffman->tables[0].values = NULL;
}

static uint16_t jebp__huffman_read(jebp__huffman_t *huffman, jebp__reader_t *reader) {
    uint16_t code = 0;
    for (int i = 0; i < 15; i += 1) {
        jebp__huffman_table_t *table = &huffman->tables[i];
        if (huffman->size > 1) {
            // Don't read any bits if there is only 1 value in the table
            // This is also not mentioned in the spec
            // I wasted so much time figuring this out
            code = (uint16_t)(code << 1) | (uint16_t)jebp__read_bits(reader, 1);
        }
        uint16_t index = code - table->offset;
        if (index < table->size) {
            return table->values[index];
        }
    }
    if (reader->error == JEBP_OK) {
        reader->error = JEBP__LOG_INVDATA;
    }
    return 0;
}

static jebp_error_t jebp__huffman_read_tree(jebp__huffman_t *huffman, jebp__reader_t *reader, size_t size, uint8_t *lengths) {
    // This part of the spec is INCREDIBLY wrong and partly missing
    // Using libwebp as a reference
    jebp_error_t err;
    JEBP__CLEAR(lengths, size * sizeof(uint8_t));
    if (jebp__read_bits(reader, 1)) {
        // simple length storage
        uint32_t second = jebp__read_bits(reader, 1);
        uint8_t first_bits = jebp__read_bits(reader, 1) ? 8 : 1;
        lengths[jebp__read_bits(reader, first_bits)] = 1;
        if (second) {
            lengths[jebp__read_bits(reader, 8)] = 1;
        }
    } else {
        uint8_t len_lengths[19] = { 0 };
        uint32_t len_size = jebp__read_bits(reader, 4) + 4;
        if (len_size > 19) {
            return JEBP__LOG_INVDATA;
        }
        for (uint32_t i = 0; i < len_size; i += 1) {
            len_lengths[jebp__huffman_length_order[i]] = (uint8_t)jebp__read_bits(reader, 3);
        }
        jebp__huffman_t len_huffman;
        if ((err = jebp__huffman_create(&len_huffman, 19, len_lengths)) != JEBP_OK) {
            return err;
        }

        size_t max_codes = size;
        if (jebp__read_bits(reader, 1)) {
            // limit codes
            uint8_t max_bits = (uint8_t)(jebp__read_bits(reader, 3) * 2 + 2);
            max_codes = jebp__read_bits(reader, max_bits) + 2;
        }
        uint8_t prev_len = 8;
        for (size_t i = 0; i < size && max_codes > 0; max_codes -= 1) {
            uint16_t code = jebp__huffman_read(&len_huffman, reader);
            uint8_t len;
            uint32_t repeat;
            switch (code) {
            case 16:
                len = prev_len;
                repeat = jebp__read_bits(reader, 2) + 3;
                break;
            case 17:
                len = 0;
                repeat = jebp__read_bits(reader, 3) + 3;
                break;
            case 18:
                len = 0;
                repeat = jebp__read_bits(reader, 7) + 11;
                break;
            default:
                prev_len = (uint8_t)code;
                lengths[i] = (uint8_t)code;
                i += 1;
                repeat = 0;
                break;
            }
            if (repeat > 0) {
                if (i + repeat > size) {
                    err = JEBP__LOG_INVDATA;
                    break;
                }
                memset(&lengths[i], len, repeat);
                i += repeat;
            }
        }
        jebp__huffman_destroy(&len_huffman);
        if (err != JEBP_OK) {
            return err;
        }
    }

    if ((err = jebp__huffman_create(huffman, size, lengths)) != JEBP_OK) {
        return err;
    }
    return reader->error;
}

static void jebp__huffman_destroy_group(jebp__huffman_group_t *group);
static jebp_error_t jebp__huffman_read_group(jebp__huffman_group_t *group, jebp__reader_t *reader, uint32_t colcache_bits) {
    jebp_error_t err;
    JEBP__CLEAR(group, sizeof(jebp__huffman_group_t));
    size_t main_size = 256 + 24;
    if (colcache_bits != 0) {
        main_size += 1 << colcache_bits;
    }
    uint8_t *lengths = JEBP_ALLOC(main_size);
    if (lengths == NULL) {
        return JEBP__LOG_NOMEM;
    }

    if ((err = jebp__huffman_read_tree(&group->main, reader, main_size, lengths)) != JEBP_OK) {
        goto error;
    }
    if ((err = jebp__huffman_read_tree(&group->red, reader, 256, lengths)) != JEBP_OK) {
        goto error;
    }
    if ((err = jebp__huffman_read_tree(&group->blue, reader, 256, lengths)) != JEBP_OK) {
        goto error;
    }
    if ((err = jebp__huffman_read_tree(&group->alpha, reader, 256, lengths)) != JEBP_OK) {
        goto error;
    }
    if ((err = jebp__huffman_read_tree(&group->dist, reader, 40, lengths)) != JEBP_OK) {
        goto error;
    }

    err = reader->error;
error:
    JEBP_FREE(lengths);
    if (err != JEBP_OK) {
        jebp__huffman_destroy_group(group);
    }
    return err;
}

static void jebp__huffman_destroy_group(jebp__huffman_group_t *group) {
    jebp__huffman_destroy(&group->main);
    jebp__huffman_destroy(&group->red);
    jebp__huffman_destroy(&group->blue);
    jebp__huffman_destroy(&group->alpha);
    jebp__huffman_destroy(&group->dist);
}

/**
 * VP8L image
 */
typedef struct jebp__vp8l_meta_t {
    uint8_t block_bits;
    jebp_image_t image;
} jebp__vp8l_meta_t;

// Not actually part of LZ77 but I'm calling it LZ77 and no one can stop me
static int8_t jebp__lz77_offsets[] = {
0,1,1,0,1,1,-1,1,0,2,2,0,1,2,-1,2,2,1,-2,1,2,2,-2,2,0,3,3,0,1,3,-1,3,3,1,-3,1,2,
3,-2,3,3,2,-3,2,0,4,4,0,1,4,-1,4,4,1,-4,1,3,3,-3,3,2,4,-2,4,4,2,-4,2,0,5,3,4,-3,
4,4,3,-4,3,5,0,1,5,-1,5,5,1,-5,1,2,5,-2,5,5,2,-5,2,4,4,-4,4,3,5,-3,5,5,3,-5,3,0,
6,6,0,1,6,-1,6,6,1,-6,1,2,6,-2,6,6,2,-6,2,4,5,-4,5,5,4,-5,4,3,6,-3,6,6,3,-6,3,0,
7,7,0,1,7,-1,7,5,5,-5,5,7,1,-7,1,4,6,-4,6,6,4,-6,4,2,7,-2,7,7,2,-7,2,3,7,-3,7,7,
3,-7,3,5,6,-5,6,6,5,-6,5,8,0,4,7,-4,7,7,4,-7,4,8,1,8,2,6,6,-6,6,8,3,5,7,-5,7,7,
5,-7,5,8,4,6,7,-6,7,7,6,-7,6,8,5,7,7,-7,7,8,6,8,7
};

static uint32_t jebp__lz77_read_extrabits(jebp__reader_t *reader, uint16_t code) {
    if (code < 4) {
        return code + 1;
    }
    uint8_t extra_bits = (uint8_t)(code / 2 - 1);
    uint32_t offset = (uint32_t)((code % 2 + 2) << extra_bits);
    return offset + jebp__read_bits(reader, extra_bits) + 1;
}

static jebp_error_t jebp__vp8l_read_image(jebp_image_t *image, jebp__reader_t *reader, const jebp__vp8l_meta_t *meta) {
    jebp_error_t err;
    uint32_t *colcache = NULL;
    uint32_t colcache_bits = 0;
    if (jebp__read_bits(reader, 1)) {
        // color cache
        colcache_bits = jebp__read_bits(reader, 4);
        if (colcache_bits < 1 || colcache_bits > 11) {
            return JEBP__LOG_INVDATA;
        }
        (void)colcache;
        return JEBP__LOG_NOSUP;
        // colcache = JEBP_ALLOC((1 << colcache_bits) * sizeof(uint32_t));
        // if (colcache == NULL) {
        //     return JEBP__LOG_NOMEM;
        // }
    }

    size_t num_groups = 1;
    if (meta != NULL) {
        size_t meta_size = jebp__image_size(&meta->image);
        for (size_t i = 0; i < meta_size; i += 4) {
            size_t group = (size_t)((meta->image.rgba[i] << 8) | meta->image.rgba[i + 1]);
            if (group >= num_groups) {
                num_groups = group + 1;
            }
        }
    }
    jebp__huffman_group_t *groups = JEBP_ALLOC(num_groups * sizeof(jebp__huffman_group_t));
    if (groups == NULL) {
        JEBP_FREE(colcache);
        return JEBP__LOG_NOMEM;
    }
    err = JEBP_OK;
    for (size_t i = 0; i < num_groups; i += 1) {
        if (err == JEBP_OK) {
            err = jebp__huffman_read_group(&groups[i], reader, colcache_bits);
        } else {
            JEBP__CLEAR(&groups[i], sizeof(jebp__huffman_group_t));
        }
    }
    if (err != JEBP_OK) {
        goto error;
    }
    if ((err = jebp__image_alloc(image)) != JEBP_OK) {
        goto error;
    }

    size_t size = jebp__image_size(image) / 4;
    uint8_t *rgba = image->rgba;
    size_t block_mask;
    if (meta != NULL) {
        block_mask = ~(size_t)((1 << meta->block_bits) - 1);
    }
    for (size_t i = 0; i < size; ) {
        jebp__huffman_group_t *group = groups;
        if (meta != NULL) {
            size_t y = i / image->width;
            size_t x = i % image->width;
            size_t index = ((y & block_mask) + (x >> meta->block_bits)) * 4 + 1;
            group = &groups[meta->image.rgba[index]];
        }
        uint16_t main = jebp__huffman_read(&group->main, reader);
        if (main < 256) {
            rgba[1] = (uint8_t)main;
            rgba[0] = (uint8_t)jebp__huffman_read(&group->red, reader);
            rgba[2] = (uint8_t)jebp__huffman_read(&group->blue, reader);
            rgba[3] = (uint8_t)jebp__huffman_read(&group->alpha, reader);
            rgba += 4;
            i += 1;
        } else if (main < 256 + 24) {
            uint32_t length = jebp__lz77_read_extrabits(reader, main - 256);
            uint32_t dist = jebp__huffman_read(&group->dist, reader);
            dist = jebp__lz77_read_extrabits(reader, (uint16_t)dist);
            if (dist > 120) {
                dist -= 120;
            } else {
                const int8_t *offset = &jebp__lz77_offsets[dist * 2 - 2];
                int sdist = offset[1] * image->width + offset[0];
                dist = (uint32_t)JEBP__MAX(sdist, 1);
            }
            if (dist > i || i + length > size) {
                err = JEBP__LOG_INVDATA;
                goto error;
            }

            uint32_t *dest = (uint32_t *)rgba;
            uint32_t *src = dest - dist;
            uint32_t *end = src + length;
            while (src < end) {
                *(dest++) = *(src++);
            }
            rgba = (uint8_t *)dest;
            i += length;
        } else {
            err = JEBP__LOG_NOSUP;
            goto error;
        }
    }

    err = reader->error;
error:
    // jebp__huffman_destroy_group(&group);
    return reader->error;
}

/**
 * VP8L transforms
 */
typedef enum jebp__transform_type_t {
    JEBP__TRANSFORM_NONE = -1,
    JEBP__TRANSFORM_PREDICT,
    JEBP__TRANSFORM_COLOR,
    JEBP__TRANSFORM_GREEN,
    JEBP__TRANSFORM_PALETTE
} jebp__transform_type_t;

typedef struct jebp__transform_t {
    jebp__transform_type_t type;
    uint8_t block_bits;
    jebp_image_t image;
} jebp__transform_t;

// ret < 0: no more transforms to read
// ret = 0: successfully decoded a transform
// ret > 0: error code
static int jebp__transform_read(jebp__transform_t *transform, jebp__reader_t *reader, const jebp_image_t *image) {
    jebp_error_t err;
    if (!jebp__read_bits(reader, 1)) {
        // no more transforms to read
        transform->type = JEBP__TRANSFORM_NONE;
        return -1;
    }
    if (transform == NULL) {
        return (int)JEBP__LOG_INVDATA;
    }
    transform->type = (jebp__transform_type_t)jebp__read_bits(reader, 2);
    if (transform->type == JEBP__TRANSFORM_PALETTE) {
        // TODO: support palette images
        return (int)JEBP__LOG_NOSUP;
    } else if (transform->type != JEBP__TRANSFORM_GREEN) {
        transform->block_bits = (uint8_t)jebp__read_bits(reader, 3) + 2;
        transform->image.width = (uint16_t)JEBP__CEIL_SHIFT(image->width, transform->block_bits);
        transform->image.height = (uint16_t)JEBP__CEIL_SHIFT(image->height, transform->block_bits);
        if ((err = jebp__vp8l_read_image(&transform->image, reader, NULL)) != JEBP_OK) {
            return (int)err;
        }
    }
    if ((err = reader->error) != JEBP_OK) {
        jebp_image_free(&transform->image);
        return (int)err;
    }
    return 0;
}

static void jebp__transform_destroy(jebp__transform_t *transform) {
    if (transform->type != JEBP__TRANSFORM_NONE) {
        if (transform->type != JEBP__TRANSFORM_GREEN) {
            jebp_image_free(&transform->image);
        }
        transform->type = JEBP__TRANSFORM_NONE;
    }
}

/**
 * VP8L lossless codec
 */
#define JEBP__VP8L_TAG 0x4c385056 // VP8L

static jebp_error_t jebp__vp8l_header(jebp_image_t *image, jebp__reader_t *reader) {
    uint8_t magic;
    if (jebp__read_bytes(reader, 1, &magic) == 0) {
        return reader->error;
    }
    if (magic != 0x2f) {
        return JEBP__LOG_INVDATA;
    }
    image->width = (uint16_t)jebp__read_bits(reader, 14) + 1;
    image->height = (uint16_t)jebp__read_bits(reader, 14) + 1;
    jebp__read_bits(reader, 1); // alpha does not impact decoding
    if (jebp__read_bits(reader, 3) != 0) {
        // version must be 0
        return JEBP__LOG_NOSUP;
    }
    return reader->error;
}

static jebp_error_t jebp__vp8l_read_nohead(jebp_image_t *image, jebp__reader_t *reader, jebp__riff_chunk_t *chunk) {
    jebp_error_t err;
    jebp__transform_t transforms[4];
    int ret = 0;
    for (int i = 0; i < 4; i += 1) {
        if (ret == 0) {
            ret = jebp__transform_read(&transforms[i], reader, image);
        } else {
            transforms[i].type = JEBP__TRANSFORM_NONE;
        }
    }
    if (ret == 0) {
        ret = jebp__transform_read(NULL, reader, NULL);
    }
    if (ret > 0) {
        err = (jebp_error_t)ret;
        goto error;
    }

    jebp__vp8l_meta_t meta = { 0 };
    if (jebp__read_bits(reader, 1)) {
        // meta image
        meta.block_bits = (uint8_t)jebp__read_bits(reader, 3) + 2;
        meta.image.width = (uint16_t)JEBP__CEIL_SHIFT(image->width, meta.block_bits);
        meta.image.height = (uint16_t)JEBP__CEIL_SHIFT(image->height, meta.block_bits);
        if ((jebp__vp8l_read_image(&meta.image, reader, NULL)) != JEBP_OK) {
            goto error;
        }
    }
    if ((err = jebp__vp8l_read_image(image, reader, &meta)) != JEBP_OK) {
        goto error;
    }
    if ((err = jebp__riff_end_chunk(chunk, reader)) != JEBP_OK) {
        goto error;
    }

    err = reader->error;
error:
    jebp_image_free(&meta.image);
    for (int i = 0; i < 4; i += 1) {
        jebp__transform_destroy(&transforms[i]);
    }
    return err;
}

static jebp_error_t jebp__vp8l_read(jebp_image_t *image, jebp__reader_t *reader, jebp__riff_chunk_t *chunk) {
    jebp_error_t err;
    if ((err = jebp__vp8l_header(image, reader)) != JEBP_OK) {
        return err;
    }
    if ((err = jebp__vp8l_read_nohead(image, reader, chunk)) != JEBP_OK) {
        return err;
    }
    return reader->error;
}
#endif // JEBP_NO_VP8L

/**
 * Public API
 */
static const char *jebp__error_strings[] = {
    "Ok",
    "Invalid value or argument",
    "Invalid data or corrupted file",
    "End of file",
    "Feature not supported",
    "Not enough memory",
    "I/O error",
    "Unknown error"
};

const char *jebp_error(jebp_error_t err) {
    if (err < 0 || err > JEBP_ERROR_UNKNOWN) {
        err = JEBP_ERROR_UNKNOWN;
    }
    return jebp__error_strings[err];
}

void jebp_image_free(jebp_image_t *image) {
    if (image != NULL) {
        JEBP_FREE(image->rgba);
        JEBP__CLEAR(image, sizeof(jebp_image_t));
    }
}

static jebp_error_t jebp__read_size(jebp_image_t *image, jebp__reader_t *reader) {
    jebp_error_t err;
    image->rgba = NULL;
    jebp__riff_chunk_t header, codec;
    if ((err = jebp__riff_header(&header, reader)) != JEBP_OK) {
        goto error;
    }
    if ((err = jebp__riff_start_chunk(&codec, reader)) != JEBP_OK) {
        goto error;
    }
#ifndef JEBP_NO_VP8L
    if (codec.tag == JEBP__VP8L_TAG) {
        if ((err = jebp__vp8l_header(image, reader)) != JEBP_OK) {
            goto error;
        }
    } else
#endif // JEBP_NO_VP8L
    {
        err = JEBP__LOG_NOSUP;
        goto error;
    }

error:
    if (reader->error != JEBP_OK) {
        err = reader->error;
    }
    if (err != JEBP_OK) {
        jebp_image_free(image);
    }
    return err;
}

jebp_error_t jebp_decode_size(jebp_image_t *image, size_t size, const void *data) {
    if (image == NULL || data == NULL) {
        return JEBP__LOG_INVAL;
    }
    jebp__reader_t reader;
    jebp__reader_init(&reader, size, data);
    return jebp__read_size(image, &reader);
}

static jebp_error_t jebp__read(jebp_image_t *image, jebp__reader_t *reader) {
    jebp_error_t err;
    image->rgba = NULL;
    jebp__riff_chunk_t header, codec;
    if ((err = jebp__riff_header(&header, reader)) != JEBP_OK) {
        goto error;
    }
    if ((err = jebp__riff_start_chunk(&codec, reader)) != JEBP_OK) {
        goto error;
    }
#ifndef JEBP_NO_VP8L
    if (codec.tag == JEBP__VP8L_TAG) {
        if ((err = jebp__vp8l_read(image, reader, &codec)) != JEBP_OK) {
            goto error;
        }
    } else
#endif // JEBP_NO_VP8L
    {
        err = JEBP__LOG_NOSUP;
        goto error;
    }
    if ((err = jebp__riff_end_chunk(&header, reader)) != JEBP_OK) {
        goto error;
    }

error:
    if (reader->error != JEBP_OK) {
        err = reader->error;
    }
    if (err != JEBP_OK) {
        jebp_image_free(image);
    }
    return err;
}

jebp_error_t jebp_decode(jebp_image_t *image, size_t size, const void *data) {
    if (image == NULL || data == NULL) {
        return JEBP__LOG_INVAL;
    }
    jebp__reader_t reader;
    jebp__reader_init(&reader, size, data);
    return jebp__read(image, &reader);
}

#ifndef JEBP_NO_STDIO
jebp_error_t jebp_read_size(jebp_image_t *image, const char *path) {
    jebp_error_t err;
    if (image == NULL || path == NULL) {
        return JEBP__LOG_INVAL;
    }
    jebp__reader_t reader;
    if ((err = jebp__reader_open(&reader, path)) != JEBP_OK) {
        return err;
    }
    err = jebp__read_size(image, &reader);
    jebp__reader_close(&reader);
    return err;
}

jebp_error_t jebp_read(jebp_image_t *image, const char *path) {
    jebp_error_t err;
    if (image == NULL || path == NULL) {
        return JEBP__LOG_INVAL;
    }
    jebp__reader_t reader;
    if ((err = jebp__reader_open(&reader, path)) != JEBP_OK) {
        return err;
    }
    err = jebp__read(image, &reader);
    jebp__reader_close(&reader);
    return err;
}
#endif // JEBP_NO_STDIO

#endif // JEBP_IMPLEMENTATION
