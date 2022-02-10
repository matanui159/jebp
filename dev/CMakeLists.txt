include(CheckCSourceCompiles)

# Formating
set(format_files
    ../jebp.h
    ../jebp.c
    ../jebpview.c
    jebptest.c
    jebpfuzz.c
)
find_program(CLANG_FORMAT clang-format)
if(CLANG_FORMAT)
    add_custom_target(
        format
        COMMAND "${CLANG_FORMAT}" -style=file -i ${format_files}
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    )
endif()

# Testing
function(add_test_image name image size hash)
    add_test(
        NAME ${name}
        COMMAND jebptest ${image} ${size} ${hash}
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    )
endfunction()
if(BUILD_TESTING)
    add_executable(jebptest jebptest.c)
    add_test_image(lossless_rose lossless/rose.webp 512x384 943882e6)
    add_test_image(lossless_tux lossless/tux.webp 386x395 dd77ded2)
    add_test_image(lossless_dice lossless/dice.webp 800x600 f3285d5a)
    add_test_image(lossless_compass lossless/compass.webp 593x593 72c1b232)
endif()

# Fuzzing
set(fuzzer_flag -fsanitize=fuzzer)
set(CMAKE_REQUIRED_FLAGS ${fuzzer_flag})
set(CMAKE_REQUIRED_LIBRARIES ${fuzzer_flag})
check_c_source_compiles([[
#include <stddef.h>
#include <stdint.h>
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    (void)data;
    (void)size;
    return 0;
}
]] HAVE_FUZZER)
if(HAVE_FUZZER)
    set(fuzzer_dir "${CMAKE_BINARY_DIR}/fuzzer")
    file(MAKE_DIRECTORY "${fuzzer_dir}")
    add_executable(jebpfuzz EXCLUDE_FROM_ALL jebpfuzz.c)
    target_compile_options(jebpfuzz PRIVATE ${fuzzer_flag})
    target_link_options(jebpfuzz PRIVATE ${fuzzer_flag})
    add_custom_target(
        fuzzer
        COMMAND jebpfuzz "${fuzzer_dir}" lossless
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    )
endif()
