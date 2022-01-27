project('jebp', 'c', default_options: [
    'c_std=c99',
    'warning_level=3'
])

c_args = []
if not get_option('jebp_simd')
    c_args += ['-DJEBP_NO_SIMD']
endif
jebp_log_errors = get_option('jebp_log_errors')
if jebp_log_errors.enabled()
    log_errors = true
elif jebp_log_errors.auto()
    log_errors = get_option('debug')
endif
if log_errors
    c_args += ['-DJEBP_LOG_ERRORS']
endif
if not get_option('jebp_vp8l')
    c_args += ['-DJEBP_NO_VP8L']
endif
sdl2 = dependency('sdl2', required: get_option('jebp_sdl2'))
if sdl2.found()
    executable(
        'jebpview', 'jebpview.c',
        c_args: c_args,
        dependencies: sdl2
    )
endif

##
# Tests
##
if get_option('jebp_test')
    test_file = executable(
        'test_file', 'test/test_file.c',
        c_args: c_args,
        override_options: ['werror=false']
    )
    test_memory = executable(
        'test_memory', 'test/test_memory.c',
        c_args: c_args,
        override_options: ['werror=false'],
        include_directories: 'test/sys/stdio'
    )
    test_alloc = executable(
        'test_alloc', 'test/test_alloc.c',
        c_args: c_args,
        override_options: ['werror=false'],
        include_directories: 'test/sys/stdlib'
    )
    tests = [
        { 'name': 'lossless-rose', 'file': 'test/lossless/rose.webp', 'size': '400x301', 'hash': '9f24f39d' },
        { 'name': 'lossless-tux', 'file': 'test/lossless/tux.webp', 'size': '386x395', 'hash': 'dd77ded2' },
        { 'name': 'lossless-dice', 'file': 'test/lossless/dice.webp', 'size': '800x600', 'hash': 'cb524cc8' },
        { 'name': 'lossless-compass', 'file': 'test/lossless/compass.webp', 'size': '300x300', 'hash': '6588b58e' }
    ]
    foreach test : tests
        test(
            'file-'+test['name'], test_file,
            args: [test['file'], test['size'], test['hash']],
            workdir: meson.current_source_dir()
        )
        test(
            'memory-'+test['name'], test_memory,
            args: [test['file'], test['size'], test['hash']],
            workdir: meson.current_source_dir()
        )
        test(
            'alloc-'+test['name'], test_memory,
            args: [test['file'], test['size'], test['hash']],
            workdir: meson.current_source_dir()
        )
    endforeach
endif
