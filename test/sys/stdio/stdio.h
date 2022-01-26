#if defined(TEST_INVALID_HEADERS)
#error stdio was included
#elif defined(__GNUC__)
#include_next <stdio.h>
#elif defined(_MSC_VER)
#include <../ucrt/stdio.h>
#else
#include <../include/stdio.h>
#endif
