# JebP - Single header WebP decoder
Don't let all the [files](#what-are-all-these-files) scare you away, infact only [one header file](/jebp.h) is required to use this project.

Currently this project only supports lossless (VP8L) images. This project:
- Does not support decoding lossy files with VP8.
- Does not support extended file-formats with VP8X.
- Does not support VP8L lossless images with the color-indexing transform
  (palleted images).
- Does not support VP8L images with more than 256 huffman groups. This is an
  arbitrary limit to prevent bad images from using too much memory. In theory,
  images requiring more groups should be very rare. This limit may be increased
  in the future.

This project is still very new so there is very likely bugs in it. Be kind and
report [any issues](https://github.com/matanui159/jebp/issues) you find.

For usage and documentation, see the [header file](/jebp.h#L132).

## Why?
I genuinely think WebP is a really cool format. Both PNG and JPEG (that are
still in wide use) still use ancient technologies. Such technologies have
improved alot since when they were released, and while there have been many
attempts to invent the "new PNG" or the "new JPEG" most of the fall flat. WebP
seems to be the only one that has made a name for itself and has gotten a
following, especially in the web. But, despite the name, I do believe WebP could
be used in so many more scenarios, not just the web.

However, not everyone might want to import the entire `libwebp` library,
especially if they're used to something like
[`stb_image.h`](https://github.com/nothings/stb/blob/master/stb_image.h) (which
doesn't support WebP). And no one else seemed to be doing it, which is
understandable being how large the WebP specification is using two different
codecs for lossless and lossy. So I decided to try and put one together myself.
It may never get used but it was fun making anyway, and I learnt alot along the
way :)

## What are all these files?
Do not worry, these are all just files to help with development, none (except
`jebp.h`) are needed to use the library.
- `jebp.h` is the single-header library you're probably looking for.
- `jebp.c` is a "source file" you can use. All it does is define
  `JEBP_IMPLEMENTATION` and then include `jebp.h`.
- `jebpview.c` is a demo program using SDL2 to show a WebP image. Use it with
  `jebpview <WebP image>`.
- `meson.build`, `meson_options.txt`, `.clang-format` and `cross` are Meson and
  Clang-format files to help with development and CI. They build `jebpview`, E2E
  tests and the fuzz test, along with making it easier to run tests and format
  code. The cross files are designed to run in the CI.
- `.gitignore`, `.gitattributes` and `.github` are you standard git and GitHub
  information files. Notably, included inside of `.github` is a CI to test JebP
  on various supported platforms (see below).
- `test` and `fuzz` are where the E2E tests and fuzz test are (using
  `libFuzzer`).

## What platforms are supported?
Any compiler that is configured to support at-least C99 (VLA support is not
required) is supported on any architecture, operating-system and endianness
(including PDP-endian technically, see below). If you find a compiler issue or
bug with any compiler that 100% supports C99 (without VLA) including support for
the required system headers documented in the source, then I will be very happy
to fix it, no matter how obscure the compiler is.

However, certain operating-systems, architectures and compilers are explicitly
detected by the code to enable better support, extended features or
optimizations. Some of these supported platforms also are tested by the CI for
every change. The full list of macros used to detect the platform is documented
in the source file. The detected platforms are:
- The compilers GCC, Clang and MSVC. Only GCC currently has version detection,
  the other two assume everything is supported.
- The architectures IA-32 (x86, x86-32, i386), AMD64 (x86-64), AArch32 (arm32,
  armhf) and AArch64 (arm64).
- The SIMD variants SSE2 (x86) and Neon (AArch). Currently unused.
- Any little-endian architecture. Any other form of endianness, including
  big-endian, are not detected and do not have optimized functions. Instead,
  they use naive approaches.
- The operating system Windows. This is only used to detect Neon support on
  AArch32. There is currently no need for any OS-specific code.

As a subset of these, the following platforms are tested by the CI:
- GCC on Ubuntu.
- Clang on Ubuntu.
- MSVC on Windows.
- Apple-Clang on macOS.
- Cross MinGW x86-64 and i686 on Ubuntu.
- Cross GCC i686, aarch64, arm32 and armhf on Ubuntu.
- Non little-endian tests are emulated on all architectures by removing the
  predefined macros used for detecting little-endian.

Finally, the following is also supported:
- Transgender guys, gals, and non-binary pals :transgender_flag: because
  everyone needs a bit of support in their life :heart:
