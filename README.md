# JebP - Single header WebP decoder
Don't let all the [files](#what-are-all-these-files) scare you away, infact only [one header file](/jebp.h) is required to use this project.

Currently this project only supports lossless (VP8L) images. This project:
- Does not support decoding lossy files with VP8.
- Does not support extended file-formats with VP8X.
- Does not support VP8L lossless images with the color-indexing transform (palleted images).
Does not support VP8L images with more than 256 huffman groups. This is an arbitrary limit to prevent bad images from using too much memory. In theory, images requiring more groups should be very rare. This limit may be increased in the future.

This project is still very new so there is very likely bugs in it. Be kind and report [any issues](https://github.com/matanui159/jebp/issues) you find.

For usage and documentation, see the [header file](/jebp.h#L132).

## Why?
I genuinely think WebP is a really cool format. Both PNG and JPEG (that are still in wide use) still use ancient technologies. Such technologies have improved alot since when they were released, and while there have been many attempts to invent the "new PNG" or the "new JPEG" most of the fall flat. WebP seems to be the only one that has made a name for itself and has gotten a following, especially in the web. But, despite the name, I do believe WebP could be used in so many more scenarios, not just the web. However, not everyone might want to import the entire `libwebp` library, especially if they're used to something like [`stb_image.h`](https://github.com/nothings/stb/blob/master/stb_image.h) (which doesn't support WebP). And no one else seemed to be doing it, which is understandable being how large the WebP specification is using two different codecs for lossless and lossy. So I decided to try and put one together myself. It may never get used but it was fun making anyway, and I learnt alot along the way :)

## What are all these files?
Do not worry, these are all just files to help with development, none (except `jebp.h`) are needed to use the library.
- `jebp.h` is the single-header library you're probably looking for.
- `jebp.c` is a "source file" you can use. All it does is define `JEBP_IMPLEMENTATION` and then include `jebp.h`.
- `jebpview.c` is a demo program using SDL2 to show a WebP image. Use it with `jebpview <WebP image>`.
- `meson.build`, `meson_options.txt` and `.clang-format` are Meson and Clang-format files to help with development and CI. They build `jebpview`, E2E tests and the fuzz test, along with making it easier to run tests and format code.
- `.gitignore`, `.gitattributes` and `.github` are you standard git and GitHub information files. Notably, included inside of `.github` is a CI to test JebP on Ubuntu with GCC and Windows with MSVC.
- `test` and `fuzz` are where the E2E tests and fuzz test are (using `libFuzzer`).
