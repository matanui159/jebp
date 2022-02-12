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
        COMMAND ${CLANG_FORMAT} -style=file -i ${format_files}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()

# Tests
function(add_test_image name image size hash)
    add_test(
        NAME ${name}
        COMMAND jebptest ${image} ${size} ${hash}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    if(HAVE_FSANITIZE_LEAK)
        set_tests_properties(${name} PROPERTIES ENVIRONMENT ASAN_OPTIONS=detect_leaks=1)
    endif()
endfunction()
if(BUILD_TESTING)
    add_executable(jebptest jebptest.c)
    target_link_libraries(jebptest PRIVATE ${link_options})
    add_test_image(lossless_rose lossless/rose.webp 512x384 943882e6)
    add_test_image(lossless_tux lossless/tux.webp 386x395 dd77ded2)
    add_test_image(lossless_dice lossless/dice.webp 800x600 f3285d5a)
    add_test_image(lossless_compass lossless/compass.webp 593x593 72c1b232)
endif()

# Fuzz test
if(JEBP_SANITIZE)
    add_c_flag(-fsanitize=fuzzer HAVE_FSANITIZE_FUZZER)
    if(HAVE_FSANITIZE_FUZZER)
        set(fuzz_dir ${CMAKE_BINARY_DIR}/fuzz)
        file(MAKE_DIRECTORY ${fuzz_dir})
        add_executable(jebpfuzz jebpfuzz.c)
        target_link_libraries(jebpfuzz PRIVATE ${link_options})
        add_custom_target(
            fuzz
            COMMAND jebpfuzz ${fuzz_dir} lossless
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endif()
endif()
