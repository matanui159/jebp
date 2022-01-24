project('jebp', 'c', default_options: [
    'c_std=c99',
    'warning_level=3'
])

cc = meson.get_compiler('c')
c_args = cc.get_supported_arguments(
    '-Wconversion',
    '-Wstrict-prototypes',
    '-Wmissing-prototypes'
)
jebp_stdio = get_option('jebp_stdio')
if not jebp_stdio
    c_args += ['-DJEBP_NO_STDIO']
endif
if not get_option('jebp_simd')
    c_args += ['-DJEBP_NO_SIMD']
endif
jebp_log_errors = get_option('jebp_log_errors')
if jebp_log_errors.enabled()
    log_errors = true
elif jebp_log_errors.auto()
    log_errors = jebp_stdio and get_option('debug')
endif
if log_errors
    c_args += ['-DJEBP_LOG_ERRORS']
endif
if not get_option('jebp_vp8l')
    c_args += ['-DJEBP_NO_VP8L']
endif
sdl2 = dependency('sdl2', required: get_option('jebp_sdl2'))

static_library(
    'jebp', ['jebp.h', 'jebp.c'],
    c_args: c_args
)
if sdl2.found()
    executable(
        'jebpview', ['jebp.h', 'jebpview.c'],
        c_args: c_args,
        dependencies: sdl2
    )
endif
