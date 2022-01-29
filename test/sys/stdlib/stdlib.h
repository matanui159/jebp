#if defined(TEST_INVALID_HEADERS)
#error "stdlib was included"
#elif defined(__GNUC__)
#include_next <stdlib.h>
#elif defined(_MSC_VER)
#include <../ucrt/stdlib.h>
#else
#include <../include/stdlib.h>
#endif
