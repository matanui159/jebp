#if defined(TEST_INVALID_HEADERS)
#error stdlib was included
#elif defined(__GNUC__)
#include_next <stdlib.h>
#else
#include <../include/stdlib.h>
#endif
